/********************************************************************************************************
 * @file	app_ui.h
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
#ifndef VENDOR_B91_BLE_SAMPLE_APP_UI_H_
#define VENDOR_B91_BLE_SAMPLE_APP_UI_H_

#include "app_config.h"

#if (UI_KEYBOARD_ENABLE)

extern int 	key_not_released;
extern	u8 	ota_is_working;


#if (BLE_OTA_SERVER_ENABLE)
/**
 * @brief      this function is used to register the function for OTA start.
 * @param[in]  none
 * @return     none
 */
void app_enter_ota_mode(void);


/**
 * @brief      this function is used to register the function for OTA end.
 * @param[in]  result - OTA result
 * @return     none
 */
void app_ota_end_result(int result);
#endif


/**
 * @brief      this function is used to detect if key pressed or released.
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
void proc_keyboard (u8 e, u8 *p, int n);



#endif




#if (UI_BUTTON_ENABLE)

extern int button_not_released;

/**
 * @brief		this function is used to detect if button pressed or released.
 * @param[in]	e - event type when this function is triggered by LinkLayer event
 * @param[in]	p - event callback data pointer for when this function is triggered by LinkLayer event
 * @param[in]	n - event callback data length when this function is triggered by LinkLayer event
 * @return      none
 */
void proc_button (u8 e, u8 *p, int n);


#endif






#endif /* VENDOR_B91_BLE_SAMPLE_APP_UI_H_ */
