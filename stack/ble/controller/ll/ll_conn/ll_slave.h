/********************************************************************************************************
 * @file	ll_slave.h
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
#ifndef LL_SLAVE_H_
#define LL_SLAVE_H_








/**
 * @brief      for user to initialize ACL connection slave role.
 * @param	   none
 * @return     none
 */
void 		blc_ll_initSlaveRole_module(void);


/**
 * @brief      for user to terminate an existing connection slave role.
 * @param[in]  reason - indicates the reason for ending the connection
 * @return     status, 0x00:  succeed
 * 			           other: failed
 */
ble_sts_t  	bls_ll_terminateConnection (u8 reason);


/**
 * @brief      for user to read current slave connection  interval
 * @param	   none
 * @return     0    :  LinkLayer not in connection state
 * 			   other:  connection interval, unit: 1.25mS
 */
u16			bls_ll_getConnectionInterval(void);


/**
 * @brief      for user to read current slave connection latency
 * @param	   none
 * @return     0    :  LinkLayer not in connection state
 * 			   other:  connection latency
 */
u16			bls_ll_getConnectionLatency(void);


/**
 * @brief      for user to read current slave connection supervision timeout
 * @param	   none
 * @return     0    :  LinkLayer not in connection state
 * 			   other:  connection supervision timeout, unit: 10 mS
 */
u16			bls_ll_getConnectionTimeout(void);



/**
 * @brief      used to set telink defined event mask for BLE module only.
 * @param[in]  evtMask - event mask
 * @return     status, 0x00:  succeed
 * 			           other: failed
 */
ble_sts_t 	bls_hci_mod_setEventMask_cmd(u32 evtMask);





#define blc_ll_disconnect(conn, reason)     	bls_ll_terminateConnection(reason)



#endif /* LL_SLAVE_H_ */
