/********************************************************************************************************
 * @file	ll_adv.h
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


#ifndef LL_ADV_H_
#define LL_ADV_H_

#include "stack/ble/ble_format.h"




/**
 * @brief      for user to initialize advertising module
 * @param[in]  *public_adr -  public address pointer
 * @return     none
 */
void 		blc_ll_initAdvertising_module(void);


/**
 * @brief	   set the data used in advertising packets that have a data field.
 * @param[in]  *data -  advertising data buffer
 * @param[in]  len - The number of significant octets in the Advertising_Data.
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t	bls_ll_setAdvData(u8 *data, u8 len);


/**
 * @brief	   This function is used to provide data used in Scanning Packets that have a data field.
 * @param[in]  *data -  Scan_Response_Data buffer
 * @param[in]  len - The number of significant octets in the Scan_Response_Data.
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t 	bls_ll_setScanRspData(u8 *data, u8 len);



/**
 * @brief      This function is used to set the advertising parameters.
 * @param[in]  intervalMin - Minimum advertising interval(Time = N * 0.625 ms, Range: 0x0020 to 0x4000)
 * @param[in]  intervalMin - Maximum advertising interval(Time = N * 0.625 ms, Range: 0x0020 to 0x4000)
 * @param[in]  advType - Advertising_Type
 * @param[in]  ownAddrType - Own_Address_Type
 * @param[in]  peerAddrType - Peer_Address_Type
 * @param[in]  *peerAddr - Peer_Address
 * @param[in]  adv_channelMap - Advertising_Channel_Map
 * @param[in]  advFilterPolicy - Advertising_Filter_Policy
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t   bls_ll_setAdvParam( u16 intervalMin,  u16 intervalMax,  adv_type_t advType,  		 	  own_addr_type_t ownAddrType,  \
							     u8 peerAddrType, u8  *peerAddr,    adv_chn_map_t 	adv_channelMap,   adv_fp_type_t   advFilterPolicy);




/**
 * @brief      This function is used to request the Controller to start or stop advertising.
 * @param[in]  adv_enable - Advertising_Enable
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t   bls_ll_setAdvEnable(int adv_enable);






/**
 * @brief      This function is used to set advertise duration time.
 * @param[in]  duration_us - the length of duration, the unit is us.
 * @param[in]  duration_en - Duration_Enable
 * @return     Status - 0x00: BLE success; 0x01-0xFF: fail
 */
ble_sts_t   bls_ll_setAdvDuration (u32 duration_us, u8 duration_en);





/**
 * @brief      This function is used to set some other channel to replace advertising chn37/38/39.
 * @param[in]  chn0 - channel to replace channel 37
 * @param[in]  chn1 - channel to replace channel 38
 * @param[in]  chn2 - channel to replace channel 39
 * @return     none
 */
void 		blc_ll_setAdvCustomedChannel (u8 chn0, u8 chn1, u8 chn2);


extern u8 blc_continue_adv_en;//default stop sending legacy advertising packets when receiving scan request in the current adv interval.
/**
 * @brief      this function is used to set whether to continue sending legacy advertising packets when receiving scan request in the current adv interval.
 * @param[in]  enable - enable:continue sending broadcast packets when receiving scan request.
 * @return     none.
 */
static inline void bls_ll_continue_adv_after_scan_req(u8 enable){
	blc_continue_adv_en = enable;
}


#endif /* LL_ADV_H_ */
