/*======================================================================================
========================    - DMA_interface.h				 ===========================
========================    - Created: 21/3/2022			 ===========================
========================    - Author: Mohammed Magdy         ===========================
========================    - Version : 1.0				     ===========================
======================================================================================*/

/***************************** HEADER GUARD *****************************/

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include "STD_TYPES.h"

void MDMA_vSTREAM_INIT(u8 copy_u8DMAID,u8 copy_u8StreamID);

void MDMA_vSTREAM_ENABLE(u8 copy_u8DMAID,u8 copy_u8StreamID);

/* Priority Macros	*/
#define VERY_HIGH				3
#define HIGH					2
#define MEDIUM					1
#define LOW						0

/* Direction Macros	*/
#define MEMORY_TO_MEMORY		2
#define PERIPHERAL_TO_MEMORY	0
#define MEMPRY_TO_PERIPHERAL	1
/* TRANSFERE SIZE */
#define WORD					2
#define HALF_WORD				1
#define BYTE					0

/*	FIFO SIZE */
#define FULL_FIFO				3
#define HALF_FIFO				1
#define _3_QUARTERS				2
#define QUARTER_FIFO			0

/* stream ID */
#define STREAM_0				0
#define STREAM_1				1
#define STREAM_2				2
#define STREAM_3				3
#define STREAM_4				4
#define STREAM_5				5
#define STREAM_6				6
#define STREAM_7				7

/* CHANNEL	*/
#define CHANNEL_0				0
#define CHANNEL_1				1
#define CHANNEL_2				2
#define CHANNEL_3				3
#define CHANNEL_4				4
#define CHANNEL_5				5
#define CHANNEL_6				6
#define CHANNEL_7				7


#endif /* DMA_INTERFACE_H_ */
