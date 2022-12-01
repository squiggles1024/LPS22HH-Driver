/*
 * LPS22HH_Registers.c
 *
 *  Created on: Oct 21, 2022
 *      Author: evanl
 */

#include "LPS22HH_Registers.h"
#include <stddef.h>

/*********************************************************************************************************
 * @Brief: Helper function that checks the arguments passed to above functions.
 * @Params: Reg to read/write, write/read buffer, number of bytes to read/write.
 * @Return: Status code
 * @Pre Condition: None
 * @Post Condition: None
 *********************************************************************************************************/
static uint32_t LPS22HH_ValidateParams(LPS22HH_Context_t *Context, uint8_t Reg, uint8_t *Buffer, uint8_t Length)
{
    int32_t ret_status = LPS22HH_REG_OK;

    if(Context == NULL)
    {
    	ret_status |= LPS22HH_REG_CONTEXT_ERR;
    }

    if(Reg < LPS22HH_REG_INTERRUPT_CFG || Reg > LPS22HH_REG_FIFO_DATA_OUT_TEMP_H)
    {
    	ret_status |= LPS22HH_REG_REGADDR_ERR;
    }

    if(Buffer == NULL)
    {
    	ret_status |= LPS22HH_REG_BUFF_ERR;
    }

    if(Length == 0)
    {
    	ret_status |= LPS22HH_REG_LENGTH_ERR;
    }

    return ret_status;
}

/*********************************************************************************************************
 * @Brief: Function calls the ReadWrapper function in LPS22HH.c which calls low level IO Read function.
 * @Params: Context pointer, Reg to read from, Buffer to store bytes, number of bytes to read.
 * @Return: Status code
 * @Pre Condition: Low level IO must be initialized.
 * @Post Condition: ReadWrapper function will be called and reads from device.
 *********************************************************************************************************/
int32_t LPS22HH_ReadReg(LPS22HH_Context_t *Context, uint8_t Reg, uint8_t *Buffer, uint8_t Length)
{
	int32_t ret = LPS22HH_ValidateParams(Context,Reg,Buffer,Length);
    if(ret != LPS22HH_REG_OK)
    {
    	return ret;
    }

	ret = Context->Read(Context->Handle, Reg, Buffer, Length);
	return ret;
}

/*********************************************************************************************************
 * @Brief: Function calls the WriteWrapper function in LPS22HH.c which calls low level IO Read function.
 * @Params: Context pointer, Reg to write to, Buffer with data to write, number of bytes to write.
 * @Return: Status code
 * @Pre Condition: Low level IO must be initialized.
 * @Post Condition: WriteWrapper function will be called and writes to device registers.
 *********************************************************************************************************/
int32_t LPS22HH_WriteReg(LPS22HH_Context_t *Context, uint8_t Reg, uint8_t *Buffer, uint8_t Length)
{
	int32_t ret = LPS22HH_ValidateParams(Context,Reg,Buffer,Length);
    if(ret != LPS22HH_REG_OK)
    {
    	return ret;
    }

	ret = Context->Write(Context->Handle, Reg, Buffer, Length);
	return ret;
}
