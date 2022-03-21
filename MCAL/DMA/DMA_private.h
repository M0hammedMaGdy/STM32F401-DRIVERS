/*======================================================================================
========================    - DMA_private.h					 ===========================
========================    - Created: 21/3/2022			 ===========================
========================    - Author: Mohammed Magdy         ===========================
========================    - Version : 1.0				     ===========================
======================================================================================*/

/***************************** HEADER GUARD *****************************/

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA_1_BASE_ADDRESS		0x40026400
#define DMA_0_BASE_ADDRESS		0x40026000

typedef struct {
		volatile u32 SCR		;
		volatile u32 SNDTR		;
		volatile u32 SPAR		;
		volatile u32 SM0AR		;
		volatile u32 SM1AR		;
		volatile u32 SFCR		;
	}Stream_t;

typedef struct {
	volatile u32 LISR 			;
	volatile u32 HISR 			;
	volatile u32 LIFCR 			;
	volatile u32 HIFCR 			;
	Stream_t	Stream[8]		;

}DMA_t;

#define DMA0					(DMA_t*)(0x40026000)
#define DMA1					(DMA_t*)(0x40026400)

#endif /* DMA_PRIVATE_H_ */
