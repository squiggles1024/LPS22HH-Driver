/*
 * LPS22HH_Register.h
 *
 *  Created on: Oct 21, 2022
 *      Author: evanl
 */

#ifndef SRC_EXTERNALHARDWARE_LPS22HH_REGISTERS_H_
#define SRC_EXTERNALHARDWARE_LPS22HH_REGISTERS_H_
#include <stdint.h>
/* See LPS22HH_Register.c for more details */

//Status Codes
#define LPS22HH_REG_OK (0)
#define LPS22HH_REG_REGADDR_ERR (1)
#define LPS22HH_REG_LENGTH_ERR (2)
#define LPS22HH_REG_BUFF_ERR (4)
#define LPS22HH_REG_CONTEXT_ERR (8)


typedef struct
{
		void *Handle;                                        //Pointer to the address of the LPS22HH Handle (See LPS22HH.c/.h)
		int32_t (*Read)(void* ,uint8_t, uint8_t*, uint8_t);  //Points to the LPS22HH_WriteReg wrapper in LPS22HH.c
		int32_t (*Write)(void* ,uint8_t, uint8_t*, uint8_t); //Points to the LPS22HH_ReadReg wrapper in LPS22HH.c
}LPS22HH_Context_t;

//These functions call the Read/Write functions in the Context struct. The context struct points to the wrapper functions in LPS22HH.c
int32_t LPS22HH_ReadReg(LPS22HH_Context_t *Context, uint8_t Reg, uint8_t *Buffer, uint8_t Length);
int32_t LPS22HH_WriteReg(LPS22HH_Context_t *Context, uint8_t Reg, uint8_t *Buffer, uint8_t Length);


 //Returned from "Who am I" reg
#define LPS22HH_DEVICE_ID                          (0xB3)

//Registers
#define LPS22HH_REG_INTERRUPT_CFG                  (0x0B)
#define LPS22HH_REG_THS_P_L                        (0x0C)
#define LPS22HH_REG_THS_P_H                        (0x0D)
#define LPS22HH_REG_IF_CTRL                        (0x0E)
#define LPS22HH_REG_WHO_AM_I                       (0x0F)
#define LPS22HH_REG_CTRL_REG1                      (0x10)
#define LPS22HH_REG_CTRL_REG2                      (0x11)
#define LPS22HH_REG_CTRL_REG3                      (0x12)
#define LPS22HH_REG_FIFO_CTRL                      (0x13)
#define LPS22HH_REG_FIFO_WTM                       (0x14)
#define LPS22HH_REG_REF_P_L                        (0x15)
#define LPS22HH_REG_REF_P_H                        (0x16)
#define LPS22HH_REG_RPDS_L                         (0x18)
#define LPS22HH_REG_RPDS_H                         (0x19)
#define LPS22HH_REG_INT_SOURCE                     (0x24)
#define LPS22HH_REG_FIFO_STATUS1                   (0x25)
#define LPS22HH_REG_FIFO_STATUS2                   (0x26)
#define LPS22HH_REG_STATUS                         (0x27)
#define LPS22HH_REG_PRESSURE_OUT_XL                (0x28)
#define LPS22HH_REG_PRESSURE_OUT_L                 (0x29)
#define LPS22HH_REG_PRESSURE_OUT_H                 (0x2A)
#define LPS22HH_REG_TEMP_OUT_L                     (0x2B)
#define LPS22HH_REG_TEMP_OUT_H                     (0x2C)
#define LPS22HH_REG_FIFO_DATA_OUT_PRESS_XL         (0x78)
#define LPS22HH_REG_FIFO_DATA_OUT_PRESS_L          (0x79)
#define LPS22HH_REG_FIFO_DATA_OUT_PRESS_H          (0x7A)
#define LPS22HH_REG_FIFO_DATA_OUT_TEMP_L           (0x7B)
#define LPS22HH_REG_FIFO_DATA_OUT_TEMP_H           (0x7C)

#endif /* SRC_EXTERNALHARDWARE_LPS22HH_REGISTERS_H_ */
