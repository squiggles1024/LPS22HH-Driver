# LPS22HH

Simple LPS22HH Pressure Sensor Driver

To use, include .c and .h files in your project. 

The user must:
1. Create a LPS22HH_Handle_t instance.
2. Create a LPS22HH_InitSettings_t struct with the desired device settings. It is recommended the user reference the data sheet for setting details.
3. Provide a Low Level IO Driver structure "LPS22HH_IO_t". At a minimum, this must include a "Read", "Write", and "GetTick" function. Unused function pointers should be set to NULL. If the user does not provide an IO Init function, the GPIO and communication bus must be initialized already.
4. Pass the created LPS22HH_Handle_t instance, LPS22HH_InitSettings_t instance, and LPS22HH_IO_t instance to the function "LPS22HH_Init" function.
