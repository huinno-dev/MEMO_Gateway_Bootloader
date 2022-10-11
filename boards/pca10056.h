/**
 * Copyright (c) 2016 - 2021, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef PCA10056_H
#define PCA10056_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nrf_gpio.h"

#define MEMO_PATCH3

// SISEO (220323)
#define MEMO_PATCH3_BLE_MODEL		0
#define MEMO_PATCH3_LTE_MODEL		1
#define MEMO_PATCH3_WIFI_MODEL		2

#ifndef MEMO_PATCH3_MODEL
//#define MEMO_PATCH3_MODEL			MEMO_PATCH3_WIFI_MODEL	/* WiFi model */
#define MEMO_PATCH3_MODEL			MEMO_PATCH3_LTE_MODEL	/* LTE model  */
#endif

#ifdef MEMO_PATCH3

#define BUTTONS_NUMBER 				2
#define BUTTON_1       				NRF_GPIO_PIN_MAP(0,4)
#define BUTTON_2       				NRF_GPIO_PIN_MAP(0,27)
#define BUTTONS_LIST 				{ BUTTON_1, BUTTON_2 }
#define BUTTON_PULL    				NRF_GPIO_PIN_PULLUP
#define BUTTONS_ACTIVE_STATE 		0

// POWER
#define SYS_PWR_EN       			NRF_GPIO_PIN_MAP(1,01)
#define LED_3V3_EN       			NRF_GPIO_PIN_MAP(1,02)
#define EXT_PWR_IND      			NRF_GPIO_PIN_MAP(1,04)

// SPI
#define SPI_SCK_PIN       			NRF_GPIO_PIN_MAP(0,12)
#define SPI_MOSI_PIN      			NRF_GPIO_PIN_MAP(0,11)
#define SPI_MISO_PIN      			NRF_GPIO_PIN_MAP(1,9)

// ADS1292
#define ADS1292_CS_PIN        		NRF_GPIO_PIN_MAP(0,1)
#define ADS1292_RESET_PIN     		NRF_GPIO_PIN_MAP(0,7)  
#define ADS1292_READY_PIN     		NRF_GPIO_PIN_MAP(1,8)  

#define ADS1292_SCK_PIN       		SPI_SCK_PIN
#define ADS1292_MOSI_PIN      		SPI_MOSI_PIN
#define ADS1292_MISO_PIN      		SPI_MISO_PIN

// MAX30003
#define MAX30003_CS_PIN				NRF_GPIO_PIN_MAP(0,1)
#define MAX30003_INT1_PIN 			NRF_GPIO_PIN_MAP(0,7)  
#define MAX30003_INT2_PIN			NRF_GPIO_PIN_MAP(1,8)  

#define MAX30003_SCK_PIN			SPI_SCK_PIN
#define MAX30003_MOSI_PIN			SPI_MOSI_PIN
#define MAX30003_MISO_PIN			SPI_MISO_PIN

//BMA400
#define BMA400_INT1					NRF_GPIO_PIN_MAP(0,16)
#define BMA400_INT2					NRF_GPIO_PIN_MAP(0,17)
#define BMA400_CS					NRF_GPIO_PIN_MAP(0,26)
#define BMA400_SCK					SPI_SCK_PIN
#define BMA400_MOSI					SPI_MOSI_PIN
#define BMA400_MISO					SPI_MISO_PIN

// I2C interface (TWI interface)
#define SCK_PIN    					NRF_GPIO_PIN_MAP(0, 14)    // SCL signal pin
#define SDA_PIN    					NRF_GPIO_PIN_MAP(0, 15)    // SDA signal pin

//Battery
//#define BATT_MONITOR_EN     		NRF_GPIO_PIN_MAP(0,25)
#define BATT_MONITOR        		NRF_GPIO_PIN_MAP(0,3)

//FT4222H
#define FT_FLASH_SEL				NRF_GPIO_PIN_MAP(0,5)
#define FT_DL_STATE					NRF_GPIO_PIN_MAP(1,03)

// SPI Flash
#define BSP_SPI_SCK_PIN   			NRF_GPIO_PIN_MAP(0,19)
#define BSP_SPI_CSN_PIN   			NRF_GPIO_PIN_MAP(0,20)
#define BSP_SPI_MOSI_PIN   			NRF_GPIO_PIN_MAP(0,21)
#define BSP_SPI_MISO_PIN   			NRF_GPIO_PIN_MAP(0,22)

// QSPI Flash
//#define BSP_QSPI_SCK_PIN   		NRF_GPIO_PIN_MAP(0,19)
//#define BSP_QSPI_CSN_PIN   		NRF_GPIO_PIN_MAP(0,20)
//#define BSP_QSPI_IO0_PIN   		NRF_GPIO_PIN_MAP(0,21)
//#define BSP_QSPI_IO1_PIN   		NRF_GPIO_PIN_MAP(0,22)
//#define BSP_QSPI_IO2_PIN   		NRF_GPIO_PIN_MAP(0,23)
//#define BSP_QSPI_IO3_PIN   		NRF_GPIO_PIN_MAP(0,24)

//UART
#if (MEMO_PATCH3_MODEL == MEMO_PATCH3_LTE_MODEL)
#define RX_PIN_NUMBER  				NRF_GPIO_PIN_MAP(1,6)
#define TX_PIN_NUMBER  				NRF_GPIO_PIN_MAP(1,7)
#else
#define RX_PIN_NUMBER  				NRF_GPIO_PIN_MAP(0,6)
#define TX_PIN_NUMBER  				NRF_GPIO_PIN_MAP(0,8)
#endif
#define CTS_PIN_NUMBER 				NRF_UART_PSEL_DISCONNECTED
#define RTS_PIN_NUMBER 				NRF_UART_PSEL_DISCONNECTED
#define HWFC           				false

//UART1 (SISEO, 220314)

#if (MEMO_PATCH3_MODEL == MEMO_PATCH3_LTE_MODEL)            //====================  LTE Gateway  ====================//

#ifdef WOORINET_EXTERNAL_MODEM
#define LTE_RX_PIN_NUMBER  			NRF_GPIO_PIN_MAP(1,10)
#define LTE_TX_PIN_NUMBER  			NRF_GPIO_PIN_MAP(0,23)
#else
#define LTE_RX_PIN_NUMBER  			NRF_GPIO_PIN_MAP(0,6)
#define LTE_TX_PIN_NUMBER  			NRF_GPIO_PIN_MAP(0,8)
#endif
#define LTE_CTS_PIN_NUMBER 			NRF_GPIO_PIN_MAP(0,7)
#define LTE_RTS_PIN_NUMBER 			NRF_GPIO_PIN_MAP(0,5)
#define LTE_HWFC           			true
#define LTE_PWR_ENABLE     			NRF_GPIO_PIN_MAP(1,3)
#define LTE_RESET          			NRF_GPIO_PIN_MAP(0,25)
#define LTE_WAKEUP         			NRF_GPIO_PIN_MAP(0,24)
#define LTE_ENABLE					NRF_GPIO_PIN_MAP(0,23)
#define LTE_HOST_WAKEUP    			NRF_GPIO_PIN_MAP(1,12)
#define LTE_ANT_SEL        			NRF_GPIO_PIN_MAP(0,0)

#elif (MEMO_PATCH3_MODEL == MEMO_PATCH3_WIFI_MODEL)         //====================  WiFi Gateway  ====================//

// WSCHA (220522) : MODULE_WIFI_ENABLE
#define MODULE_WIFI_EN_PIN	    	NRF_GPIO_PIN_MAP(1,2)

#define MODULE_WIFI_READY_PIN   	NRF_GPIO_PIN_MAP(1,4)
#define MODULE_WIFI_REQUEST_PIN   	NRF_GPIO_PIN_MAP(1,3)
#define MODULE_WIFI_INFO_DATA_PIN   NRF_GPIO_PIN_MAP(0,25)

#define MODULE_WIFI_SPI_HS_PIN    	NRF_GPIO_PIN_MAP(0,7)

#if 1
#define MODULE_WIFI_SPI_CS_PIN      NRF_GPIO_PIN_MAP(0,12)
#define MODULE_WIFI_SPI_SCK_PIN     NRF_GPIO_PIN_MAP(1,8)
#define MODULE_WIFI_SPI_MISO_PIN    NRF_GPIO_PIN_MAP(0,11)
#define MODULE_WIFI_SPI_MOSI_PIN    NRF_GPIO_PIN_MAP(1,9)
#else
#define MODULE_WIFI_SPI_CS_PIN      NRF_GPIO_PIN_MAP(1,8)
#define MODULE_WIFI_SPI_SCK_PIN     NRF_GPIO_PIN_MAP(0,12)
#define MODULE_WIFI_SPI_MISO_PIN    NRF_GPIO_PIN_MAP(1,9)
#define MODULE_WIFI_SPI_MOSI_PIN    NRF_GPIO_PIN_MAP(0,11)
#endif

#if 1
#define MODULE_WIFI_TASK_PIN   		NRF_GPIO_PIN_MAP(0,23) // MODULE_WIFI_TP_1_PIN // // ( 0 - Task Exit, 1 - Task Enter )
#define MODULE_WIFI_ERROR_PIN   	NRF_GPIO_PIN_MAP(0,24) // MODULE_WIFI_TP_2_PIN
#else
#define MODULE_WIFI_TP_1_PIN   		NRF_GPIO_PIN_MAP(0,23) 
#define MODULE_WIFI_TP_2_PIN   		NRF_GPIO_PIN_MAP(0,24)
#endif

#define HOST_WIFI_CMD_DATA_PIN  	NRF_GPIO_PIN_MAP(1,7)
#define HOST_WIFI_REQUEST_PIN   	NRF_GPIO_PIN_MAP(1,5)

#if 1
#define HOST_WIFI_ERROR_HS_PIN  	NRF_GPIO_PIN_MAP(1,6)
#else
#define HOST_WIFI_TP_1_PIN  		NRF_GPIO_PIN_MAP(1,6)
#endif

#else                                                       //====================  MEMO Patch3  ====================//

#ifdef HW_REV_01
#define UART1_RX_PIN_NUMBER  		NRF_GPIO_PIN_MAP(1,10)
#define UART1_TX_PIN_NUMBER  		NRF_GPIO_PIN_MAP(0,23)
#else
#define UART1_RX_PIN_NUMBER  		NRF_GPIO_PIN_MAP(1,13)
#define UART1_TX_PIN_NUMBER  		NRF_GPIO_PIN_MAP(1,15)
#endif
#define UART1_CTS_PIN_NUMBER 		NRF_UART_PSEL_DISCONNECTED
#define UART1_RTS_PIN_NUMBER 		NRF_UART_PSEL_DISCONNECTED
#define UART1_HWFC           		false

#endif                                                      //--------------------------------------------------------//


//LED
#if ((MEMO_PATCH3_MODEL == MEMO_PATCH3_LTE_MODEL) || (MEMO_PATCH3_MODEL == MEMO_PATCH3_WIFI_MODEL))
#define LED_GREEN  					NRF_GPIO_PIN_MAP(0,31)
#define LED_BLUE	   				NRF_GPIO_PIN_MAP(0,30)
#define LED_ORANGE   				NRF_GPIO_PIN_MAP(0,29)
#define LED_RED		   				NRF_GPIO_PIN_MAP(0,28)
#else
#ifdef HW_REV_01
#define LED_RED   					NRF_GPIO_PIN_MAP(0,31)
#define LED_GREEN   				NRF_GPIO_PIN_MAP(0,29)
#define LED_YELLOW					(LED_RED|LED_GREEN)
#else
#define LED_RED   					NRF_GPIO_PIN_MAP(0,31)
#define LED_GREEN   				NRF_GPIO_PIN_MAP(0,29)
#define LED_BLUE   					NRF_GPIO_PIN_MAP(0,02)
#endif
#endif

//Battery
#if (MEMO_PATCH3_MODEL == MEMO_PATCH3_LTE_MODEL)
#define BATT_CHARGING_STATUS        EXT_PWR_IND
#define BATT_CHARGING_DONE	        NRF_GPIO_PIN_MAP(1,5)
#else
#define BATT_CHANGING_STATUS        NRF_GPIO_PIN_MAP(1,15)
#endif

//Buzzer
#define BUZZER_PIN_NUMBER  			NRF_GPIO_PIN_MAP(0,2)

//UART detection
#define UART_DET_PIN  				NRF_GPIO_PIN_MAP(0,24)

//ETC
#define TEST2  						NRF_GPIO_PIN_MAP(1,15)
#define TEST3  						NRF_GPIO_PIN_MAP(1,13)

#define BUTTON_ACTION_PRESS      	(0)   	/**< presents pushing a button. */
#define BUTTON_ACTION_RELEASE  	 	(1) 		/**< presents releasing a button. */
#define BUTTON_ACTION_LONG_PUSH 	(2)     /**< Represents pushing and holding a button for @ref BSP_LONG_PUSH_TIMEOUT_MS milliseconds. See also @ref bsp_button_action_t. */
#define BUTTON_ACTION_FACTORY_RESET (3) 

#define TOUCH_ACTION_RELEASE  	 	(0) 		/**< presents releasing a touch. */
#define TOUCH_ACTION_PRESS      	(1)    	/**< presents pushing a touch. */
#define TOUCH_ACTION_LONG_PUSH 		(2)     /**< Represents pushing and holding a touch for @ref BSP_LONG_PUSH_TIMEOUT_MS milliseconds. See also @ref bsp_button_action_t. */

#else

#define LEDS_NUMBER    				2

#define LED_1          				NRF_GPIO_PIN_MAP(1,15) // 47
#define LED_2          				NRF_GPIO_PIN_MAP(1,10) // 42 
#define LED_START      				LED_1
#define LED_STOP       				LED_2
#define LEDS_ACTIVE_STATE 			1
#define LEDS_LIST 					{ LED_1, LED_2 }
#define LEDS_INV_MASK  				LEDS_MASK
#define BSP_LED_0      				LED_1
#define BSP_LED_1      				LED_2

#define BUTTONS_NUMBER 				1
#define BUTTON_1       				NRF_GPIO_PIN_MAP(1, 2)
#define BUTTON_PULL    				NRF_GPIO_PIN_PULLUP
#define BUTTONS_ACTIVE_STATE 		0
#define BUTTONS_LIST 				{ BUTTON_1 }
#define BSP_BUTTON_0   				BUTTON_1

#define BSP_QSPI_SCK_PIN   			19
#define BSP_QSPI_CSN_PIN   			20
#define BSP_QSPI_IO0_PIN   			17
#define BSP_QSPI_IO1_PIN   			22
#define BSP_QSPI_IO2_PIN   			23
#define BSP_QSPI_IO3_PIN   			21

#define RX_PIN_NUMBER  				24
#define TX_PIN_NUMBER  				25
#define CTS_PIN_NUMBER 				7
#define RTS_PIN_NUMBER 				5
#define HWFC           				true

#endif	// << #ifdef MEMO_PATCH3

#ifdef __cplusplus
}
#endif
#endif // PCA10056_H
