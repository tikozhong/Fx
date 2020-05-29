/******************** (C) COPYRIGHT 2015 INCUBECN *****************************
* File Name          : fbusb16x1_cmd.h
* Author             : Tiko Zhong
* Date First Issued  : 09/04/2017
* Description        : This file provides a set of functions needed to manage the
*                      communication using HAL_UARTxxx
********************************************************************************
* History:
* 09/04/2017: V0.0
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _FBUSB16X1_CMD_H
#define _FBUSB16X1_CMD_H

/* Includes ------------------------------------------------------------------*/

#include "FBUSB16X1.h"
#include "publicRsrc.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
extern const u8 FBUSB16X1_HELP[];
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
u8 fbusb16x1Cmd(FBUSB16X1_Dev_T *pDev, PAKET_T *packetIn, PAKET_T *packetOut);
//call back reference
#endif /* _MAX44009_CMD_H */

/******************* (C) COPYRIGHT 2015 INCUBECN *****END OF FILE****/
