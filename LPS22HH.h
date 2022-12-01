/*
 * LPS22HH.h
 *
 *  Created on: Sep 15, 2022
 *      Author: evanl
 */

#ifndef SRC_EXTERNALHARDWARE_LPS22HH_H_
#define SRC_EXTERNALHARDWARE_LPS22HH_H_
#include <stdint.h>
#include "LPS22HH_Registers.h"

//Dummy value used to indicate "Use factory default setting"
#define LPS22HH_DefaultSetting (0U)

//Return status codes
#define LPS22HH_Ok (0U)
#define LPS22HH_HandleError (-1)
#define LPS22HH_IOError (-2)
#define LPS22HH_InitError (-3)
#define LPS22HH_RefPError (-4)
#define LPS22HH_OneShotError (-5)
#define LPS22HH_Timeout (-6)

//Codes returned from read pressure function
#define LPS22HH_NewData (0)
#define LPS22HH_NoNewData (1)

//IRQ Trigger Settings
typedef enum
{
	LPS22HH_AUTOREFP = 1 << 7,
	LPS22HH_RESET_ARP = 1 << 6,
	LPS22HH_AUTO_ZERO = 1 << 5,
	LPS22HH_RESET_AZ = 1 << 4,
	LPS22HH_DIFF_EN = 1 << 3,
	LPS22HH_LIR = 1 << 2,
	LPS22HH_PLE = 1 << 1,
	LPS22HH_PHE = 1 << 0
}LPS22HH_IRQTriggerConfig_t;

//Pressure threshold settings
typedef uint16_t LPS22HH_ThresholdPressure_t;

//Interface control settings
typedef enum
{
	LPS22HH_INT_EN_I3C = 1 << 7,
	LPS22HH_SDA_PU_EN = 1 << 4,
	LPS22HH_SDO_PU_EN = 1 << 3,
	LPS22HH_PD_DIS_INT1 = 1 << 2,
	LPS22HH_I3C_DISABLE = 1 << 1,
	LPS22HH_I2C_DISABLE = 1 << 0
}LPR22HH_InterfaceControl_t;

//ODR Frequency
typedef enum
{
	LPS22HH_OneShot = 0,
	LPS22HH_1Hz = 1 << 4,
	LPS22HH_10Hz = 2 << 4,
	LPS22HH_25Hz = 3 << 4,
	LPS22HH_50Hz = 4 << 4,
	LPS22HH_75Hz = 5 << 4,
	LPS22HH_100Hz = 6 << 4,
	LPS22HH_200Hz = 7 << 4
}LPS22HH_OutputDataRate_t;

//LPF Settings
typedef enum
{
	LPS22HH_ODRDiv2 = 0,
	LPS22HH_ODRDiv9 = 2 << 2,
	LPS22H_ODR_Div20 = 3 << 2
}LPS22HH_LowPassConfig_t;

//SPI Settings
typedef enum
{
    LPS22HH_4WireSPI = 0,
	LPS22HH_3WireSPI = 1
}LPS22HH_SPIInterfaceMode_t;

//Control Reg 2 Settings
typedef enum
{
	LPS22HH_IRQActiveLow = 1 << 6,
	LPS22HH_IRQOpenDrain = 1 << 5,
	LPS22HH_IncrementAddress = 1 << 4,
	LPS22HH_LowNoiseMode = 1 << 1
}LPS22HH_ControlReg2Config_t;

//DRDY -> Int Pin Settings
typedef enum
{
	LPS22HH_INT_F_FULL = 1 << 5,
	LPS22HH_INT_F_WTM = 1 << 4,
	LPS22HH_INT_F_OVR = 1 << 3,
	LPS22HH_DRDY = 1 << 2
}LPS22HH_IntDRDY_Control_t;

//IRQ Source Settings
typedef enum
{
	LPS22HH_DataReady = 0,
	LPS22HH_HighPres,
	LPS22HH_LowPres,
	LPS22HH_HighOrLowPres
}LPS22HH_IRQ_Source_t;

//Watermark Stop Settings
typedef enum
{
    LPS22HH_StopOnWatermark = 1 << 3,
	LPS22HH_IgnoreWatermark = 0
}LPS22HH_FifoWaterMarkMode_t;

//FIFO Settings
typedef enum
{
	LPS22HH_FifoBypass = 0,
	LPS22HH_FifoMode = 1,
	LPS22HH_FifoContinuous = 2,
	LPS22HH_BypassToFifo = 5,
	LPS22HH_BypassToContinuous = 6,
	LPS22HH_ContinuousToFifo = 7
}LPS22HH_FifoMode_t; //See AN5209 Section 9.3

//Watermark threshold settings
typedef uint8_t LPS22HH_FifoWatermark_t; //7 bit number

//Init status enum
typedef enum{
	LPS22HH_Initialized = 1,
	LPS22HH_Uninitialized = 0
}LPS22HH_Init_Status_t;

//Low level IO Struct
typedef struct
{
	void (*Init)(void);
	void (*DeInit)(void);
	int32_t (*Read)(uint8_t,uint8_t*,uint8_t);
	int32_t (*Write)(uint8_t,uint8_t*,uint8_t);
	uint32_t (*GetTick)(void);
	int32_t (*ReadPin)(void);
}LPS22HH_IO_t;

//Init settings struct
typedef struct
{
	LPS22HH_IRQTriggerConfig_t INTERRUPT_CFG;
	LPS22HH_ThresholdPressure_t THS_P; //Limit to 15 bit number
	LPR22HH_InterfaceControl_t IF_CTRL;
	LPS22HH_OutputDataRate_t ODR;
	LPS22HH_LowPassConfig_t LPFP;
	LPS22HH_SPIInterfaceMode_t SIM;
	LPS22HH_ControlReg2Config_t CTRL_REG2;
	LPS22HH_IntDRDY_Control_t INT_DRDY_Control;
	LPS22HH_IRQ_Source_t INT_S;
	LPS22HH_FifoWaterMarkMode_t STOP_ON_WTM;
	LPS22HH_FifoMode_t F_MODE;
	uint8_t WTM; //7 Bits
	float REF_P; //In hPA
}LPS22HH_Init_Struct_t;

//Handle struct
typedef struct
{
	LPS22HH_IO_t IO;
	LPS22HH_Context_t Context;
	LPS22HH_Init_Status_t Status;
	LPS22HH_OutputDataRate_t DataRate;
}LPS22HH_Handle_t;

//Public function prototypes
int32_t LPS22HH_Init(LPS22HH_Handle_t *Handle, LPS22HH_Init_Struct_t Settings, LPS22HH_IO_t *IO);
int32_t LPS22HH_DeInit(LPS22HH_Handle_t *Handle);
int32_t LPS22HH_ResetDevice(LPS22HH_Handle_t *Handle);
int32_t LPS22HH_SetReferencePressure(LPS22HH_Handle_t *Handle, float Pressure);
int32_t LPS22HH_GetReferencePressure(LPS22HH_Handle_t *Handle, float *Pressure);
int32_t LPS22HH_StartConversion(LPS22HH_Handle_t *Handle);
int32_t LPS22HH_ReadPressure(LPS22HH_Handle_t *Handle, float *Pressure);
int32_t LPS22HH_GetSamplePeriod(LPS22HH_Handle_t *Handle, uint32_t *Period);


#endif /* SRC_EXTERNALHARDWARE_LPS22HH_H_ */
