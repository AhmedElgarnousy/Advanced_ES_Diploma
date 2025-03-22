#include <stdint.h>
#include "bootloader_prv.h"
#include "bootloader.h"
#include "main.h"

extern CRC_HandleTypeDef hcrc;
extern UART_HandleTypeDef huart2;


static uint8_t u8VerifyCRC(uint8_t *copy_pu8DataArr, uint8_t copy_u8size, uint32_t copy_u32HostCRC)
{
	uint8_t Local_u8Iterator, Local_u8CRCStatus;
	uint32_t Local_u32AccCRCVal, Local_u32Temp;

	for(Local_u8Iterator = 0; Local_u8Iterator < copy_u8size ; Local_u8Iterator++)
	{
		Local_u32Temp = copy_pu8DataArr[Local_u8Iterator];
		/* SEND data by 1 byte, store previous CRC calculated to accumUlate it in register in crc peripheral */
		Local_u32AccCRCVal = HAL_CRC_Accumulate(&hcrc, &Local_u32Temp, 1);
	}

	/*so we have to reset CRC Calculation unit */
	__HAL_CRC_DR_RESET(&hcrc);

	if(Local_u32AccCRCVal == copy_u32HostCRC)
	{
		Local_u8CRCStatus = CRC_SUCCESS;
	}
	else
	{
		Local_u8CRCStatus = CRC_FAILED;
	}

	return Local_u8CRCStatus;
}

static void voidSendAck(uint8_t copy_u8ReplyLength)
{
	uint8_t Local_u8AckBuffer[2] = { BL_ACK, copy_u8ReplyLength };

	HAL_UART_Transmit(&huart2, Local_u8AckBuffer, 2, HAL_MAX_DELAY);
}

static void voidSendNack(void)
{
	uint8_t Local_u8Nack = BL_NACK;

	HAL_UART_Transmit(&huart2, &Local_u8Nack, 1, HAL_MAX_DELAY);
}

void BL_voidHandleGetVerCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8BLVersion, Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1); /* Bootloader version has size 1 byte */

		Local_u8BLVersion = BL_VERSION;

		HAL_UART_Transmit(&huart2, &Local_u8BLVersion, 1, HAL_MAX_DELAY);
	}
	else
	{
		voidSendNack();
	}
}

void BL_voidHandleGetHelpCmd(uint8_t * copy_pu8CmdPacket)
{

}
void BL_voidHandleGetCIDCmd(uint8_t * copy_pu8CmdPacket)
{

}
void BL_voidHandleGetRDPStatusCmd(uint8_t * copy_pu8CmdPacket)
{

}
void BL_voidHandleGoToAddrCmd(uint8_t * copy_pu8CmdPacket)
{

}
void BL_voidHandleFlashEraseCmd(uint8_t * copy_pu8CmdPacket)
{

}
void BL_voidHandleMemWriteCmd(uint8_t * copy_pu8CmdPacket){

}
void BL_voidHandleEnRWProtectCmd(uint8_t * copy_pu8CmdPacket){

}
void BL_voidHandleMemReadCmd(uint8_t * copy_pu8CmdPacket){

}
void BL_voidHandleReadSectorStatusCmd(uint8_t * copy_pu8CmdPacket){

}
void BL_voidHandleOTPReadCmd(uint8_t * copy_pu8CmdPacket){

}
void BL_voidHandleDisRWProtectCmd(uint8_t * copy_pu8CmdPacket){

}
