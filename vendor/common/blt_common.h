/********************************************************************************************************
 * @file	blt_common.h
 *
 * @brief	This is the header file for BLE SDK
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
#ifndef BLT_COMMON_H_
#define BLT_COMMON_H_

#include "drivers.h"




//////////////////////////// Flash  Address Configuration ///////////////////////////////

/**************************** 128 K Flash *****************************/
#ifndef		CFG_ADR_MAC_128K_FLASH
#define		CFG_ADR_MAC_128K_FLASH								0x1F000
#endif

#ifndef		CFG_ADR_CALIBRATION_128K_FLASH
#define		CFG_ADR_CALIBRATION_128K_FLASH						0x1E000
#endif

/**************************** 512 K Flash *****************************/
#ifndef		CFG_ADR_MAC_512K_FLASH
#define		CFG_ADR_MAC_512K_FLASH								0x7F000	//Eagle and later IC
#endif

#ifndef		CFG_ADR_CALIBRATION_512K_FLASH
#define		CFG_ADR_CALIBRATION_512K_FLASH						0x7E000	//Eagle and later IC
#endif

/**************************** 1 M Flash *******************************/
#ifndef		CFG_ADR_MAC_1M_FLASH
#define		CFG_ADR_MAC_1M_FLASH		   						0xFF000
#endif


#ifndef		CFG_ADR_CALIBRATION_1M_FLASH
#define		CFG_ADR_CALIBRATION_1M_FLASH						0xFE000
#endif

/**************************** 2 M Flash *******************************/
#ifndef		CFG_ADR_MAC_2M_FLASH
#define		CFG_ADR_MAC_2M_FLASH		   						0x1FF000
#endif


#ifndef		CFG_ADR_CALIBRATION_2M_FLASH
#define		CFG_ADR_CALIBRATION_2M_FLASH						0x1FE000
#endif

/** Calibration Information FLash Address Offset of  CFG_ADR_CALIBRATION_xx_FLASH ***/
#define		CALIB_OFFSET_CAP_INFO								0x0
#define		CALIB_OFFSET_TP_INFO								0x40

#define		CALIB_OFFSET_ADC_VREF								0xC0

#define		CALIB_OFFSET_FIRMWARE_SIGNKEY						0x180







extern u32 flash_sector_mac_address;
extern u32 flash_sector_calibration;




/**
 * @brief		This function is used to enable the external crystal capacitor
 * @param[in]	en - enable the external crystal capacitor
 * @return      none
 */
static inline void blc_app_setExternalCrystalCapEnable(u8  en)
{
	blt_miscParam.ext_cap_en = en;

	analog_write_reg8(0x8a,analog_read_reg8(0x8a)|0x80);//close internal cap

}


/**
 * @brief		This function is used to load customized parameters from flash sector for application
 * @param[in]	none
 * @return      none
 */
static inline void blc_app_loadCustomizedParameters(void)
{
	 if(!blt_miscParam.ext_cap_en)
	 {
		 //customize freq_offset adjust cap value, if not customized, default ana_8A is 0x60
		 //for 1M  Flash, flash_sector_calibration equals to 0xFE000
		 if(flash_sector_calibration){
			 u8 cap_frqoft;
			 flash_read_page(flash_sector_calibration + CALIB_OFFSET_CAP_INFO, 1, &cap_frqoft);
			 if( cap_frqoft != 0xff ){
				 analog_write_reg8(0x8A, (analog_read_reg8(0x8A) & 0xc0)|(cap_frqoft & 0x3f));
			 }
		 }
	 }
}

/**
 * @brief		This function can automatically recognize the flash size,
 * 				and the system selects different customized sector according
 * 				to different sizes.
 * @param[in]	none
 * @return      none
 */
void blc_readFlashSize_autoConfigCustomFlashSector(void);

/**
 * @brief		This function is used to initialize the MAC address
 * @param[in]	flash_addr - flash address for MAC address
 * @param[in]	mac_public - public address
 * @param[in]	mac_random_static - random static MAC address
 * @return      none
 */
void blc_initMacAddress(int flash_addr, u8 *mac_public, u8 *mac_random_static);




#endif /* BLT_COMMON_H_ */
