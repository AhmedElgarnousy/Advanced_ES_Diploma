#ifndef INC_BOOTLOADER_PRV_H_
#define INC_BOOTLOADER_PRV_H_

static uint8_t u8VerifyCRC(uint8_t *copy_pu8DataArr, uint8_t copy_u8size, uint32_t copy_u32HostCRC);
static void voidSendAck(uint8_t copy_u8ReplyLength);
static void voidSendNack(void);

#define  CRC_SUCCESS   		1U
#define  CRC_FAILED    		0U

#define  BL_VERSION    		1U

#endif /* INC_BOOTLOADER_PRV_H_ */
