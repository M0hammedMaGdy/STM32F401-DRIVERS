/*======================================================================================
========================    - DMA.c	  					 	 ===========================
========================    - Created: 21/3/2022			 ===========================
========================    - Author: Mohammed Magdy         ===========================
========================    - Version : 1.0				     ===========================
======================================================================================*/

/***************************** MCAL INCLUDES *****************************/
#include "DMA_config.h"
#include "DMA_interface.h"
#include "DMA_private.h"
/************************************************************************/


/***************************** LIB INCLUDES *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/************************************************************************/

/****************************************************************************************************/
/*	Description : Function initializes the DMA .													*/
/*	Arguments : 1- DMAID			(DMA0 - DMA1) 	 												*/
/* 				2- StreamID			(STREAM_0 : STREAM_7)											*/
/*	Returns   :	Void        																		*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/
void MDMA_vSTREAM_INIT(u8 copy_u8DMAID,u8 copy_u8StreamID)
{
	switch (copy_u8DMAID)
	{
	case DMA0:
		/* Must disable Stream before config */
		CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,0);
		switch (copy_u8StreamID)
		{
		case STREAM_0:
			/* SW priority */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_0_PRIOROTY<<16);
			/* SET Direction mode */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_0_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_0_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_0_PERIPHERAL_SIZE<<11);
			/*	SELECT CHANNEL	*/
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_0_CHANNEL<<25);
			/*	DIRECT MODE */
			#if			STREAM_0_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_0_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_0_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_0_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_0_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_0_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_0_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_0_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_0_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#endif

			break;
		case STREAM_1:
				/* SW priority */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_1_PRIOROTY<<16);
				/* SET Direction mode */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_1_DIRECTION<<6);
				/* SET THE MEMORY SIZE */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_1_MEMORY_SIZE<<13);
				/* SET THE PERIPHERAL SIZE */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_1_PERIPHERAL_SIZE<<11);

				/*	DIRECT MODE */
				#if			STREAM_1_DIRECT_MODE        	    ==           ENABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

				#elif		STREAM_1_DIRECT_MODE        	    ==           DISABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

				/* FIFO	THRESHOLD CONFIG */

				DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_1_FIFO_THRESHOLD);

				#endif

				/* INCREAMENT */
				#if 	STREAM_1_PREPHIRAL_INCREAMENT			==			ENABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

				#elif 	STREAM_1_PREPHIRAL_INCREAMENT			==			DISABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

				#endif

				#if 	STREAM_1_MEMORY_INCREAMENT				==			ENABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

				#elif 	STREAM_1_MEMORY_INCREAMENT				==			DISABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

				#endif

				#if 	STREAM_1_TX_COMPLETE_INTERRUPT			==			ENABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

				#elif 	STREAM_1_TX_COMPLETE_INTERRUPT			==			DISABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

				#endif

			break;
		case STREAM_2:
				/* SW priority */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_2_PRIOROTY<<16);
				/* SET Direction mode */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_2_DIRECTION<<6);
				/* SET THE MEMORY SIZE */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_2_MEMORY_SIZE<<13);
				/* SET THE PERIPHERAL SIZE */
				DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_2_PERIPHERAL_SIZE<<11);

				/*	DIRECT MODE */
				#if			STREAM_2_DIRECT_MODE        	    ==           ENABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

				#elif		STREAM_2_DIRECT_MODE        	    ==           DISABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

				/* FIFO	THRESHOLD CONFIG */

				DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_2_FIFO_THRESHOLD);

				#endif

				/* INCREAMENT */
				#if 	STREAM_2_PREPHIRAL_INCREAMENT			==			ENABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

				#elif 	STREAM_2_PREPHIRAL_INCREAMENT			==			DISABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

				#endif

				#if 	STREAM_2_MEMORY_INCREAMENT				==			ENABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

				#elif 	STREAM_2_MEMORY_INCREAMENT				==			DISABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

				#endif

				#if 	STREAM_2_TX_COMPLETE_INTERRUPT			==			ENABLE

				SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

				#elif 	STREAM_2_TX_COMPLETE_INTERRUPT			==			DISABLE

				CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

				#endif

			break;
		case STREAM_3:
			/* SW priority */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_3_PRIOROTY<<16);
			/* SET Direction mode */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_3_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_3_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_3_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_3_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_3_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_3_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_3_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_3_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_3_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_3_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_3_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_3_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_4:
			/* SW priority */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_4_PRIOROTY<<16);
			/* SET Direction mode */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_4_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_4_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_4_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_4_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_4_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_4_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_4_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_4_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_4_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_4_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_4_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_4_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_5:
			/* SW priority */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_5_PRIOROTY<<16);
			/* SET Direction mode */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_5_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_5_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_5_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_5_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_5_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_5_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_5_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_5_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_5_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_5_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_5_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_5_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_6:
			/* SW priority */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_6_PRIOROTY<<16);
			/* SET Direction mode */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_6_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_6_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_6_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_6_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_6_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_6_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_6_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_6_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_6_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_6_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_6_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_6_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_7:
			/* SW priority */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_7_PRIOROTY<<16);
			/* SET Direction mode */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_7_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_7_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA0->Stream[copy_u8StreamID].SCR |= (STREAM_7_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_7_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_7_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA0->Stream[copy_u8StreamID].SFCR |= (STREAM_7_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_7_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_7_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_7_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_7_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_7_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_7_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA0->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		default : /* ERROR   */ break;
		}
		break;
	case DMA1:
		/* Must disable Stream before config */
		CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,0);
		switch (copy_u8StreamID)
		{
		case STREAM_0:
			/* SW priority */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_0_PRIOROTY<<16);
			/* SET Direction mode */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_0_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_0_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_0_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_0_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_0_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_0_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_0_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_0_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_0_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_0_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_0_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_0_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#endif

		break;
		case STREAM_1:
			/* SW priority */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_1_PRIOROTY<<16);
			/* SET Direction mode */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_1_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_1_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_1_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_1_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_1_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_1_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_1_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_1_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_1_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_1_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_1_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_1_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#endif

		break;
		case STREAM_2:
				/* SW priority */
				DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_2_PRIOROTY<<16);
				/* SET Direction mode */
				DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_2_DIRECTION<<6);
				/* SET THE MEMORY SIZE */
				DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_2_MEMORY_SIZE<<13);
				/* SET THE PERIPHERAL SIZE */
				DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_2_PERIPHERAL_SIZE<<11);

				/*	DIRECT MODE */
				#if			STREAM_2_DIRECT_MODE        	    ==           ENABLE

				CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

				#elif		STREAM_2_DIRECT_MODE        	    ==           DISABLE

				SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

				/* FIFO	THRESHOLD CONFIG */

				DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_2_FIFO_THRESHOLD);

				#endif

				/* INCREAMENT */
				#if 	STREAM_2_PREPHIRAL_INCREAMENT			==			ENABLE

				SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

				#elif 	STREAM_2_PREPHIRAL_INCREAMENT			==			DISABLE

				CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

				#endif

				#if 	STREAM_2_MEMORY_INCREAMENT				==			ENABLE

				SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

				#elif 	STREAM_2_MEMORY_INCREAMENT				==			DISABLE

				CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

				#endif

				#if 	STREAM_2_TX_COMPLETE_INTERRUPT			==			ENABLE

				SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

				#elif 	STREAM_2_TX_COMPLETE_INTERRUPT			==			DISABLE

				CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

				#endif

			break;
		case STREAM_3:
			/* SW priority */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_3_PRIOROTY<<16);
			/* SET Direction mode */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_3_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_3_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_3_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_3_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_3_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_3_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_3_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_3_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_3_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_3_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_3_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_3_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_4:
			/* SW priority */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_4_PRIOROTY<<16);
			/* SET Direction mode */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_4_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_4_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_4_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_4_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_4_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_4_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_4_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_4_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_4_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_4_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_4_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_4_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_5:
			/* SW priority */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_5_PRIOROTY<<16);
			/* SET Direction mode */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_5_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_5_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_5_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_5_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_5_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_5_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_5_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_5_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_5_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_5_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_5_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_5_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_6:
			/* SW priority */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_6_PRIOROTY<<16);
			/* SET Direction mode */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_6_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_6_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_6_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_6_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_6_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_6_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_6_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_6_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_6_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_6_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_6_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_6_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#endif
			break;
		case STREAM_7:
			/* SW priority */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_7_PRIOROTY<<16);
			/* SET Direction mode */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_7_DIRECTION<<6);
			/* SET THE MEMORY SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_7_MEMORY_SIZE<<13);
			/* SET THE PERIPHERAL SIZE */
			DMA1->Stream[copy_u8StreamID].SCR |= (STREAM_7_PERIPHERAL_SIZE<<11);

			/*	DIRECT MODE */
			#if			STREAM_7_DIRECT_MODE        	    ==           ENABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			#elif		STREAM_7_DIRECT_MODE        	    ==           DISABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SFCR,2);

			/* FIFO	THRESHOLD CONFIG */

			DMA1->Stream[copy_u8StreamID].SFCR |= (STREAM_7_FIFO_THRESHOLD);

			#endif

			/* INCREAMENT */
			#if 	STREAM_7_PREPHIRAL_INCREAMENT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#elif 	STREAM_7_PREPHIRAL_INCREAMENT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,9);

			#endif

			#if 	STREAM_7_MEMORY_INCREAMENT				==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#elif 	STREAM_7_MEMORY_INCREAMENT				==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,10);

			#endif

			#if 	STREAM_7_TX_COMPLETE_INTERRUPT			==			ENABLE

			SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#elif 	STREAM_7_TX_COMPLETE_INTERRUPT			==			DISABLE

			CLR_BIT(DMA1->Stream[copy_u8StreamID].SCR,4);

			#endif

		break;

	default : /* ERROR   */ break;
	}
}
}
/***************************** End of Function *****************************/

/****************************************************************************************************/
/*	Description : Function sets the source and destination addresses and the size data .			*/
/*	Arguments : 1- DMAID			(DMA0 - DMA1) 													*/
/* 				2- StreamID			(STREAM_0 : STREAM_7)											*/
/* 				3- source address																	*/
/* 				4- destination address																*/
/* 				5- size																				*/
/*	Returns   :	Void        																		*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/
void MDMA_vSET_ADDRESS(u8 copy_u8DMAID,u8 copy_u8StreamID,u32* ptr_src_address ,
										u32* ptr_des_address , u16 copy_u16size)
{
	switch (copy_u8DMAID)
		{
		case DMA0 :
			/* data size */
			DMA0 -> Stream[copy_u8StreamID].SNDTR = copy_u16size ;
			/* source address*/
			DMA0 -> Stream[copy_u8StreamID].SM0AR = ptr_src_address ;
			/* destination address*/
			DMA0 -> Stream[copy_u8StreamID].SM1AR = ptr_des_address ;
			break;
		case DMA1 :
			/* data size */
			DMA1 -> Stream[copy_u8StreamID].SNDTR = copy_u16size ;
			/* source address*/
			DMA1 -> Stream[copy_u8StreamID].SM0AR = ptr_src_address ;
			/* destination address*/
			DMA1 -> Stream[copy_u8StreamID].SM1AR = ptr_des_address ;
			break;
		default	: /*	ERROR	*/		break;
		}
}
/***************************** End of Function *****************************/

/****************************************************************************************************/
/*	Description : Function sets the source and destination addresses and the size data .			*/
/*	Arguments : 1- DMAID			(DMA0 - DMA1) 													*/
/* 				2- StreamID			(STREAM_0 : STREAM_7)											*/
/*	Returns   :	Void        																		*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/
void MDMA_vSTREAM_ENABLE(u8 copy_u8DMAID,u8 copy_u8StreamID)
{
	switch (copy_u8DMAID)
	{
	case DMA0 :
		DMA0 -> LISR	&= 0;
		DMA0 -> HISR	&= 0;
		SET_BIT(DMA0->Stream[copy_u8StreamID].SCR,0);
		break;
	case DMA1 :
		DMA1 -> LISR	&= 0;
		DMA1 -> HISR	&= 0;
		SET_BIT(DMA1->Stream[copy_u8StreamID].SCR,0);
		break;
	default	: /*	ERROR	*/		break;
	}
}
/***************************** End of Function *****************************/

