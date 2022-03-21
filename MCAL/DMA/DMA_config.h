/*======================================================================================
========================    - DMA_Config.h					 ===========================
========================    - Created: 21/3/2022			 ===========================
========================    - Author: Mohammed Magdy         ===========================
========================    - Version : 1.0				     ===========================
======================================================================================*/

/***************************** HEADER GUARD *****************************/
#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_

/**** STREAM PRIORITY ****
 *  Options:
 *
 *
 * 	1-	VERY_HIGH				(default)
	2- 	HIGH
	3-	MEDIUM
	4-	LOW
 *
 *
 *
 **/
#define STREAM_0_PRIOROTY                          VERY_HIGH
#define STREAM_1_PRIOROTY                          VERY_HIGH
#define STREAM_2_PRIOROTY                          VERY_HIGH
#define STREAM_3_PRIOROTY                          VERY_HIGH
#define STREAM_4_PRIOROTY                          VERY_HIGH
#define STREAM_5_PRIOROTY                          VERY_HIGH
#define STREAM_6_PRIOROTY                          VERY_HIGH
#define STREAM_7_PRIOROTY                          VERY_HIGH
/*************************************************************************************/
/**** STREAM DIRECTION ****
 *  Options:
 *
 *
 * 	1-	MEMORY_TO_MEMORY			(default)
	2- 	PERIPHERAL_TO_MEMORY
	3-	MEMPRY_TO_PERIPHERAL
 *
 *
 *	NOTE MEMORY TO MEMORY CAN BE PERFORMED USING DMA1 ONLY
 **/
#define STREAM_0_DIRECTION						   MEMORY_TO_MEMORY
#define STREAM_1_DIRECTION                         MEMORY_TO_MEMORY
#define STREAM_2_DIRECTION                         MEMORY_TO_MEMORY
#define STREAM_3_DIRECTION                         MEMORY_TO_MEMORY
#define STREAM_4_DIRECTION                         MEMORY_TO_MEMORY
#define STREAM_5_DIRECTION                         MEMORY_TO_MEMORY
#define STREAM_6_DIRECTION                         MEMORY_TO_MEMORY
#define STREAM_7_DIRECTION                         MEMORY_TO_MEMORY
/*************************************************************************************/
/**** STREAM MEMORY SIZE ****
 *  Options:
 *
 *
 * 	1-	WORD			(default)
	2- 	HALF_WORD
	3-	BYTE
 *
 *
 *
 **/
#define STREAM_0_MEMORY_SIZE                       WORD
#define STREAM_1_MEMORY_SIZE                       WORD
#define STREAM_2_MEMORY_SIZE                       WORD
#define STREAM_3_MEMORY_SIZE                       WORD
#define STREAM_4_MEMORY_SIZE                       WORD
#define STREAM_5_MEMORY_SIZE                       WORD
#define STREAM_6_MEMORY_SIZE                       WORD
#define STREAM_7_MEMORY_SIZE                       WORD
/*************************************************************************************/
/**** STREAM PERIPHERAL SIZE ****
 *  Options:
 *
 *
 * 	1-	WORD			(default)
	2- 	HALF_WORD
	3-	BYTE
 *
 *
 *
 **/
#define STREAM_0_PERIPHERAL_SIZE                   WORD
#define STREAM_1_PERIPHERAL_SIZE                   WORD
#define STREAM_2_PERIPHERAL_SIZE                   WORD
#define STREAM_3_PERIPHERAL_SIZE                   WORD
#define STREAM_4_PERIPHERAL_SIZE                   WORD
#define STREAM_5_PERIPHERAL_SIZE                   WORD
#define STREAM_6_PERIPHERAL_SIZE                   WORD
#define STREAM_7_PERIPHERAL_SIZE                   WORD
/*************************************************************************************/
/**** STREAM CHANNEL SELECT ****
 *  Options:
 *
 *
 * 	1-	CHANNEL_0		(default)
	2- 	CHANNEL_1
	3-	CHANNEL_2
	4-	CHANNEL_3
	5-  CHANNEL_4
	6-  CHANNEL_5
	7-  CHANNEL_6
	8-	CHANNEL_7
 *
 *
 *	NOTE : Can't choose channel while direction mode is memory to memory && must be left at default option
 *
 **/
#define STREAM_0_CHANNEL                          CHANNEL_0
#define STREAM_1_CHANNEL                          CHANNEL_0
#define STREAM_2_CHANNEL                          CHANNEL_0
#define STREAM_3_CHANNEL                          CHANNEL_0
#define STREAM_4_CHANNEL                          CHANNEL_0
#define STREAM_5_CHANNEL                          CHANNEL_0
#define STREAM_6_CHANNEL                          CHANNEL_0
#define STREAM_7_CHANNEL                          CHANNEL_0
/*************************************************************************************/
/**** STREAM DIRECT MODE ****
 *  Options:
 *
 *
 * 	1-	ENABLE
	2- 	DISABLE			(default)
 *
 *
 *	NOTE : Can't can't be enabled with memory to memory direction
 *
 **/
#define STREAM_0_DIRECT_MODE                       DISABLE
#define STREAM_1_DIRECT_MODE                       DISABLE
#define STREAM_2_DIRECT_MODE                       DISABLE
#define STREAM_3_DIRECT_MODE                       DISABLE
#define STREAM_4_DIRECT_MODE                       DISABLE
#define STREAM_5_DIRECT_MODE                       DISABLE
#define STREAM_6_DIRECT_MODE                       DISABLE
#define STREAM_7_DIRECT_MODE                       DISABLE
/*************************************************************************************/
/**** STREAM FIFO SIZE ****
 *  Options:
 *
 *
 * 	1-	FULL_FIFO				(default)
	2- 	HALF_FIFO
	3-	_3_QUARTERS
	4-	QUARTER_FIFO
 *
 *
 *
 **/
#define STREAM_0_FIFO_THRESHOLD                    FULL_FIFO
#define STREAM_1_FIFO_THRESHOLD                    FULL_FIFO
#define STREAM_2_FIFO_THRESHOLD                    FULL_FIFO
#define STREAM_3_FIFO_THRESHOLD                    FULL_FIFO
#define STREAM_4_FIFO_THRESHOLD                    FULL_FIFO
#define STREAM_5_FIFO_THRESHOLD                    FULL_FIFO
#define STREAM_6_FIFO_THRESHOLD                    FULL_FIFO
#define STREAM_7_FIFO_THRESHOLD                    FULL_FIFO
/*************************************************************************************/
/**** STREAM MEMORY INCREAMENT ****
 *  Options:
 *
 *
 * 	1-	ENABLE				(default)
	2- 	DISABLE
 *
 *
 *
 **/
#define STREAM_0_MEMORY_INCREAMENT                ENABLE
#define STREAM_1_MEMORY_INCREAMENT                ENABLE
#define STREAM_2_MEMORY_INCREAMENT                ENABLE
#define STREAM_3_MEMORY_INCREAMENT                ENABLE
#define STREAM_4_MEMORY_INCREAMENT                ENABLE
#define STREAM_5_MEMORY_INCREAMENT                ENABLE
#define STREAM_6_MEMORY_INCREAMENT                ENABLE
#define STREAM_7_MEMORY_INCREAMENT                ENABLE
/*************************************************************************************/
/**** STREAM PERIPHERAL INCREAMENT ****
 *  Options:
 *
 *
 * 	1-	ENABLE				(default)
	2- 	DISABLE
 *
 *
 *
 **/
#define STREAM_0_PERIPHERAL_INCREAMENT            ENABLE
#define STREAM_1_PERIPHERAL_INCREAMENT            ENABLE
#define STREAM_2_PERIPHERAL_INCREAMENT            ENABLE
#define STREAM_3_PERIPHERAL_INCREAMENT            ENABLE
#define STREAM_4_PERIPHERAL_INCREAMENT            ENABLE
#define STREAM_5_PERIPHERAL_INCREAMENT            ENABLE
#define STREAM_6_PERIPHERAL_INCREAMENT            ENABLE
#define STREAM_7_PERIPHERAL_INCREAMENT            ENABLE
/*************************************************************************************/
/**** STREAM COMPLETE INTERRUPT ****
 *  Options:
 *
 *
 * 	1-	ENABLE				(default)
	2- 	DISABLE
 *
 *
 *
 **/
#define STREAM_0_TX_COMPLETE_INTERRUPT            ENABLE
#define STREAM_1_TX_COMPLETE_INTERRUPT            ENABLE
#define STREAM_2_TX_COMPLETE_INTERRUPT            ENABLE
#define STREAM_3_TX_COMPLETE_INTERRUPT            ENABLE
#define STREAM_4_TX_COMPLETE_INTERRUPT            ENABLE
#define STREAM_5_TX_COMPLETE_INTERRUPT            ENABLE
#define STREAM_6_TX_COMPLETE_INTERRUPT            ENABLE
#define STREAM_7_TX_COMPLETE_INTERRUPT            ENABLE
/*************************************************************************************/


#endif /* DMA_CONFIG_H_ */
