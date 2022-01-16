/********************************************************************************************************
 * @file	default_config.h
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
#pragma once


#include "config.h"

//////////// product  Infomation  //////////////////////////////
#ifndef ID_VENDOR
#define ID_VENDOR			0x248a			// for report 
#endif
#ifndef ID_PRODUCT_BASE
#define ID_PRODUCT_BASE		0x8800
#endif
#ifndef STRING_VENDOR
#define STRING_VENDOR		L"Telink"
#endif
#ifndef STRING_PRODUCT
#define STRING_PRODUCT		L"2.4G Wireless Audio"
#endif

#ifndef STRING_SERIAL
#define STRING_SERIAL		L"TLSR9518"
#endif




#ifndef PM_DEEPSLEEP_RETENTION_ENABLE
#define PM_DEEPSLEEP_RETENTION_ENABLE	0
#endif







#if(APPLICATION_DONGLE)
	#ifndef MODULE_MOUSE_ENABLE
	#define MODULE_MOUSE_ENABLE		0
	#endif
	#ifndef MODULE_KEYBOARD_ENABLE
	#define MODULE_KEYBOARD_ENABLE	0
	#endif
	#ifndef MODULE_MIC_ENABLE
	#define MODULE_MIC_ENABLE		0
	#endif
	#ifndef MODULE_SPEAKER_ENABLE
	#define MODULE_SPEAKER_ENABLE	0			// device , not dongle
	#endif
	#ifndef MODULE_USB_ENABLE
	#define MODULE_USB_ENABLE		1
	#endif
#else
	#ifndef MODULE_MOUSE_ENABLE
	#define MODULE_MOUSE_ENABLE		1
	#endif
	#ifndef MODULE_KEYBOARD_ENABLE
	#define MODULE_KEYBOARD_ENABLE	1
	#endif

	#ifndef MODULE_MIC_ENABLE
	#define MODULE_MIC_ENABLE		0
	#endif
	#ifndef MODULE_SPEAKER_ENABLE
	#define MODULE_SPEAKER_ENABLE	0			// device , not dongle
	#endif

	#ifndef MODULE_USB_ENABLE
	#define MODULE_USB_ENABLE		0
	#endif
#endif








///////////////////  USB   /////////////////////////////////
#ifndef IRQ_USB_PWDN_ENABLE
#define	IRQ_USB_PWDN_ENABLE  	0
#endif


#ifndef USB_PRINTER_ENABLE
#define	USB_PRINTER_ENABLE 		0
#endif
#ifndef USB_SPEAKER_ENABLE
#define	USB_SPEAKER_ENABLE 		0
#endif
#ifndef USB_MIC_ENABLE
#define	USB_MIC_ENABLE 			0
#endif
#ifndef USB_MOUSE_ENABLE
#define	USB_MOUSE_ENABLE 			0
#endif
#ifndef USB_KEYBOARD_ENABLE
#define	USB_KEYBOARD_ENABLE 		0
#endif
#ifndef USB_SOMATIC_ENABLE
#define	USB_SOMATIC_ENABLE 		0
#endif
#ifndef USB_CUSTOM_HID_REPORT
#define	USB_CUSTOM_HID_REPORT 		0
#endif
#ifndef USB_AUDIO_441K_ENABLE
#define USB_AUDIO_441K_ENABLE  	0
#endif
#ifndef USB_MASS_STORAGE_ENABLE
#define USB_MASS_STORAGE_ENABLE  	0
#endif
#ifndef MIC_CHANNEL_COUNT
#define MIC_CHANNEL_COUNT  			2
#endif

#ifndef USB_DESCRIPTER_CONFIGURATION_FOR_KM_DONGLE
#define USB_DESCRIPTER_CONFIGURATION_FOR_KM_DONGLE  			0
#endif

#ifndef USB_ID_AND_STRING_CUSTOM
#define USB_ID_AND_STRING_CUSTOM  								0
#endif

#define KEYBOARD_RESENT_MAX_CNT			3
#define KEYBOARD_REPEAT_CHECK_TIME		300000	// in us	
#define KEYBOARD_REPEAT_INTERVAL		100000	// in us	
#define KEYBOARD_SCAN_INTERVAL			16000	// in us
#define MOUSE_SCAN_INTERVAL				8000	// in us	
#define SOMATIC_SCAN_INTERVAL     		8000

#define USB_KEYBOARD_POLL_INTERVAL		10		// in ms	USB_KEYBOARD_POLL_INTERVAL < KEYBOARD_SCAN_INTERVAL to ensure PC no missing key
#define USB_MOUSE_POLL_INTERVAL			4		// in ms
#define USB_SOMATIC_POLL_INTERVAL     	8		// in ms

#define USB_KEYBOARD_RELEASE_TIMEOUT    (450000) // in us
#define USB_MOUSE_RELEASE_TIMEOUT       (200000) // in us
#define USB_SOMATIC_RELEASE_TIMEOUT     (200000) // in us

