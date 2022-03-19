/*======================================================================================
========================    - NVIC_Config.h					 ===========================
========================    - Created: 19/3/2022			 ===========================
========================    - Author: Mohammed Magdy         ===========================
========================    - Version : 1.0				     ===========================
======================================================================================*/

/***************************** HEADER GUARD *****************************/
#ifndef	_NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_

/***************************** LIB INCLUDES *****************************/
#include "STD_TYPES.h"


typedef struct {
	volatile u32 ISER[8];					/* NVIC interrupt set enable register		*/
	volatile u32 ICER[8];                   /* NVIC interrupt clear enable register		*/
	volatile u32 ISPR[8];                   /* NVIC interrupt set pending register		*/
	volatile u32 ICPR[8];                   /* NVIC interrupt clear pending register	*/
	volatile u32 IABR[8];                   /* NVIC interrupt active bit register		*/
	volatile u32 IPR[60];                   /* NVIC interrupt priority register			*/
}NVIC_t;

/***************************** MACROS *****************************/
/*	 BASE ADDRESS	*/
#define NVIC_BASE_ADDRESS		0xE000E100

/*	 NVIC Software trigger interrupt register			*/
#define STIR		*(volatile u32*(0xE000EF00))

/*	 Application interrupt and reset control register	*/
#define AIRCR		*(volatile u32*(0xE000ED0C))

/*	 NVIC Registers pointer								*/
#define NVIC		(NVIC_t*)(NVIC_BASE_ADDRESS)

#endif
