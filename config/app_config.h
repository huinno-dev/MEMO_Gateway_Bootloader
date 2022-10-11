/**
 * Copyright (c) 2022 huinno application feature configration
 */



#ifndef APP_CONFIG_H
#define APP_CONFIG_H
/***********************************************************************************
* Huinno Model Defined config
***********************************************************************************/
//#define HUINNO_PATCH3_P //battery replaceable 
#define HUINNO_PATCH_C //battery rechargeable

/***********************************************************************************
* Huinno HW Revision Define config
***********************************************************************************/
// HW_REV_XX - hardware revision number. 
#if defined(HUINNO_PATCH3_P)
//#define HW_REV_01 //CP1 board
//#define HW_REV_02 //CP2 board 2022-05-23
#define HW_REV_03 // PP board 2022-07-21
#elif defined(HUINNO_PATCH_C)
#define HW_REV_01 //CP1 board
#endif

/***********************************************************************************
* Huinno General config
***********************************************************************************/
#if defined(HUINNO_PATCH3_P)
#ifndef UART_DFU_BOOTLOADER
#define UART_DFU_BOOTLOADER
//#undef UART_DFU_BOOTLOADER
#endif
#elif defined(HUINNO_PATCH_C)
#ifndef USBD_DFU_BOOTLOADER
#define USBD_DFU_BOOTLOADER
//#undef USBD_DFU_BOOTLOADER
#endif
#endif

// <<< end of configuration section >>>
#endif //APP_CONFIG_H

