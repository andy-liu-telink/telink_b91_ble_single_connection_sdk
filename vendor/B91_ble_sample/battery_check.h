/********************************************************************************************************
 * @file     battery_check.h 
 *
 * @brief    This is the header file for BLE SDK
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

#ifndef BATTERY_CHECK_H_
#define BATTERY_CHECK_H_

#define BAT_LEAKAGE_PROTECT_EN				1
#define BAT_DEEP_THRES_MV				2000   // 2000 mV low battery alarm
#define BAT_SUSPEND_THRES_MV			1800   // 1800 mV low battery alarm



void battery_set_detect_enable (int en);
int  battery_get_detect_enable (void);

#if(BAT_LEAKAGE_PROTECT_EN)
_attribute_ram_code_ void app_battery_power_check(u16 threshold_deep_vol_mv, u16 threshold_suspend_vol_mv);
#else
void app_battery_power_check(u16 alram_vol_mv);
#endif

#endif /* APP_BATTDET_H_ */
