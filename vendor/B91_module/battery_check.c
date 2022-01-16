/********************************************************************************************************
 * @file     battery_check.c 
 *
 * @brief    This is the source file for BLE SDK
 *
 * @author	BLE GROUP
 * @date	2020.06
 *
 * @par     Copyright (c) 2020, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *******************************************************************************************************/

#include "tl_common.h"
#include "drivers.h"
#include "stack/ble/ble.h"

#include "battery_check.h"


#if (BATT_CHECK_ENABLE)




//_attribute_data_retention_	u8		adc_first_flg = 1;
_attribute_data_retention_	u8 		lowBattDet_enable = 1;
							u8      adc_hw_initialized = 0;   //note: can not be retention variable
_attribute_data_retention_  u16     batt_vol_mv;




/**
 * @brief		callback function of adjust whether allow enter to pm or not
 * @param[in]	none
 * @return      0 orbidden enter cpu_sleep_wakeup, 1 allow enter cpu_sleep_wakeup
 */
int app_suspend_enter_low_battery (void)
{
	if (!gpio_read(GPIO_WAKEUP_MODULE)) //gpio low level
	{
		analog_write(USED_DEEP_ANA_REG,  analog_read(USED_DEEP_ANA_REG)|LOW_BATT_FLG);  //mark
		return 1;//allow enter cpu_sleep_wakeup
	}

	analog_write(USED_DEEP_ANA_REG,  analog_read(USED_DEEP_ANA_REG)&(~LOW_BATT_FLG));  //clr
	return 0; //forbidden enter cpu_sleep_wakeup
}



/**
 * @brief		get the value of lowBattDet_enable
 * @param[in]	none
 * @return      the value of lowBattDet_enable
 */
int battery_get_detect_enable (void)
{
	return lowBattDet_enable;
}


/**
 * @brief		This is battery check function
 * @param[in]	alram_vol_mv - input battery calue
 * @return      0 fail 1 success
 */
_attribute_ram_code_ int app_battery_power_check(u16 alram_vol_mv)
{


	//when MCU powered up or wakeup from deep/deep with retention, adc need be initialized
	if(!adc_hw_initialized){

		adc_hw_initialized = 1;
#if VBAT_CHANNEL_EN
		adc_battery_voltage_sample_init();
#else
		adc_gpio_sample_init(ADC_INPUT_PIN_CHN,ADC_VREF_1P2V,ADC_PRESCALE_1F4,ADC_SAMPLE_FREQ_96K);
#endif
		adc_power_on();
	}


	u32 t0 = clock_time();

	while(!clock_time_exceed(t0, 25));  //wait at least 2 sample cycle(f = 96K, T = 10.4us)

	u32 adc_result;
	u32 adc_average;
	adc_average = adc_get_code();

	if(adc_average & BIT(13)){
		adc_average=0;
		return 1;
	}
#if 1
	adc_result = adc_average;
#else  	//history data filter
	if(adc_first_flg){
		adc_result = adc_average;
		adc_first_flg = 0;
	}
	else{
		adc_result = ( (adc_result*3) + adc_average + 2 )>>2;  //filter
	}
#endif
//////////////// adc sample data convert to voltage(mv) ////////////////
	batt_vol_mv  = adc_calculate_voltage(adc_result);

	if(batt_vol_mv < alram_vol_mv){

		GPIO_WAKEUP_MODULE_LOW;
		bls_pm_registerFuncBeforeSuspend( &app_suspend_enter_low_battery );
//		bls_pm_registerFuncBeforeSuspend( NULL );

		cpu_set_gpio_wakeup (GPIO_WAKEUP_MODULE, Level_High, 1);  //drive pin pad high wakeup deepsleep

		cpu_sleep_wakeup(DEEPSLEEP_MODE, PM_WAKEUP_PAD, 0);  //deepsleep
//		cpu_sleep_wakeup(DEEPSLEEP_MODE, 0, 0);  //deepsleep
		return 1;
	}
	else{ // batt level > alarm level
		analog_write(USED_DEEP_ANA_REG,  analog_read(USED_DEEP_ANA_REG)&(~LOW_BATT_FLG));  //clr
		return 0;
	}
}

#endif
