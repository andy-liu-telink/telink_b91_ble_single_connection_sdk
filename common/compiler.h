/********************************************************************************************************
 * @file	compiler.h
 *
 * @brief	This is the header file for B91
 *
 * @author	D.M.H
 * @date	2019
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
#ifndef COMPILER_H_
#define COMPILER_H_

#define _attribute_ram_code_sec_      			__attribute__((section(".ram_code")))
#define _attribute_ram_code_sec_noinline_      	__attribute__((section(".ram_code"))) __attribute__((noinline))

#define _attribute_text_sec_   					__attribute__((section(".text")))

#define _attribute_aes_data_sec_      			__attribute__((section(".aes_data")))

#define _attribute_data_retention_sec_   		__attribute__((section(".retention_data")))

#define _attribute_aligned_(s)					__attribute__((aligned(s)))

/// Pack a structure field
#define __PACKED __attribute__ ((__packed__))

/*******************************      BLE Stack Use     ******************************/
#include "common/config/user_config.h"

#define _attribute_packed_				__attribute__((packed))
#define _attribute_session_(s)			__attribute__((section(s)))
#define _attribute_custom_code_  		_attribute_session_(".custom") volatile
#define _attribute_no_inline_   		__attribute__((noinline))
#define _inline_ 						inline
#define _attribute_data_dlm_   			_attribute_session_(".dlm_data")//dlm:Data Local Memory
#ifndef	BLC_PM_EN
#define	BLC_PM_EN							1
#endif

#ifndef	BLC_PM_DEEP_RETENTION_MODE_EN
#define	BLC_PM_DEEP_RETENTION_MODE_EN		1
#endif


#if (BLC_PM_DEEP_RETENTION_MODE_EN)
	#define _attribute_data_retention_   	_attribute_session_(".retention_data")
#else
    #define _attribute_data_retention_
#endif

#define _attribute_ram_code_      __attribute__((section(".ram_code"))) __attribute__((noinline))
#define _attribute_ram_code_without_oninline      __attribute__((section(".ram_code")))

#define _attribute_text_code_      __attribute__((section(".text")))

/// define the static keyword for this compiler
#define __STATIC static

/// define the force inlining attribute for this compiler
#define __INLINE static __attribute__((__always_inline__)) inline

/// define the IRQ handler attribute for this compiler
#define __IRQ 	__attribute__ ((interrupt ("machine"), aligned(4)))

/// define the BLE IRQ handler attribute for this compiler
#define __BTIRQ

/// define the BLE IRQ handler attribute for this compiler
#define __BLEIRQ

/// define the FIQ handler attribute for this compiler
#define __FIQ __attribute__((__interrupt__("FIQ")))

/// define size of an empty array (used to declare structure with an array size not defined)
#define __ARRAY_EMPTY

/// Function returns struct in registers (4 in rvds, var with gnuarm).
/// With Gnuarm, feature depends on command line options and
/// impacts ALL functions returning 2-words max structs
/// (check -freg-struct-return and -mabi=xxx)
#define __VIR

/// function has no side effect and return depends only on arguments
#define __PURE __attribute__((const))

/// Align instantiated lvalue or struct member on 4 bytes
#define __ALIGN4 __attribute__((aligned(4)))

/// __MODULE__ comes from the RVDS compiler that supports it
#define __MODULE__ __BASE_FILE__


/// Put a variable in a memory maintained during deep sleep
#define __LOWPOWER_SAVED

#define ASSERT_ERR(x)

#endif
