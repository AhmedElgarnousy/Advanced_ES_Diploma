

#include <stdint.h>
#include "bootloader_prv.h"
#include "bootloader.h"
#include "main.h"

extern CRC_HandleTypeDef hcrc;
extern UART_HandleTypeDef huart1;


/*************************************/
/*********** Utilities****************/
/*************************************/

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

	HAL_UART_Transmit(&huart1, Local_u8AckBuffer, 2, HAL_MAX_DELAY);
}

static void voidSendNack(void)
{
	uint8_t Local_u8Nack = BL_NACK;

	HAL_UART_Transmit(&huart1, &Local_u8Nack, 1, HAL_MAX_DELAY);
}


/********************************************************/
/****************** Command Handlers ********************/
/********************************************************/

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
		voidSendAck(1U); /* Bootloader version has size 1 byte */

		Local_u8BLVersion = BL_VERSION;

		HAL_UART_Transmit(&huart1, &Local_u8BLVersion, 1, HAL_MAX_DELAY);
	}
	else
	{
		voidSendNack();
	}
}

void BL_voidHandleGetHelpCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		uint8_t Local_pu8BLCommands[] =
		{
				BL_GET_VER,
				BL_GET_HELP,
				BL_GET_CID,
				BL_GET_RDP_STATUS,
				BL_GO_TO_ADDR,
				BL_FLASH_ERASE,
				BL_MEM_WRITE,
				BL_EN_RW_PROTECT,
				BL_MEM_READ,
				BL_READ_SECTOR_STATUS,
				BL_OTP_READ,
				BL_DIS_RW_PROTECT,
		};

		voidSendAck(sizeof(Local_pu8BLCommands));

		HAL_UART_Transmit(&huart1, Local_pu8BLCommands, sizeof(Local_pu8BLCommands), HAL_MAX_DELAY);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleGetCIDCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleGetRDPStatusCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleGoToAddrCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleFlashEraseCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleMemWriteCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleEnRWProtectCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleMemReadCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleReadSectorStatusCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleOTPReadCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
void BL_voidHandleDisRWProtectCmd(uint8_t * copy_pu8CmdPacket)
{
	uint8_t Local_u8CRCStatus, Local_88CmdLen;
	uint32_t Local_u32HostCRC;

	Local_88CmdLen = copy_pu8CmdPacket[0] + 1; /*the first byte already includes the length to follow */

	/* Get CRC value in command packet 00*/
	Local_u32HostCRC = *( (uint32_t*)( (copy_pu8CmdPacket + Local_88CmdLen) - 4) );

	Local_u8CRCStatus = u8VerifyCRC(copy_pu8CmdPacket, (Local_88CmdLen - 4), Local_u32HostCRC);

	if(Local_u8CRCStatus == CRC_SUCCESS)
	{
		voidSendAck(1U);
	}
	else
	{
		voidSendNack();
	}
}
