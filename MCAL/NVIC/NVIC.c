/*======================================================================================
========================    - NVIC.c						 ===========================
========================    - Created: 19/3/2022			 ===========================
========================    - Author: Mohammed Magdy         ===========================
========================    - Version : 1.0				     ===========================
======================================================================================*/


/***************************** MCAL INCLUDES *****************************/

#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

/************************************************************************/


/***************************** LIB INCLUDES *****************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************************************************************************/

/****************************************************************************************************/
/*	Description :																					*/
/*	Function Enables the interrupt .													            */
/*	Arguments : interrupt ID (0 : 239) 											                    */
/*	Returns   :	Void        																		*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

void MNVIC_vENABLE_INT(u8 copy_u8int_num)
{
	NVIC->ISER[copy_u8int_num/32] = (1<<(copy_u8int_num%32));
}
/***************************** End of Function *****************************/

/****************************************************************************************************/
/****************************************************************************************************/
/*	Description :																					*/
/*	Function Disables the interrupt .													            */
/*	Arguments : interrupt ID (0 : 239) 											                    */
/*	Returns   :	Void        																		*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

void MNVIC_vDISABLE_INT(u8 copy_u8int_num)
{
	NVIC->ICER[copy_u8int_num/32] = (1<<(copy_u8int_num%32));
}

/***************************** End of Function *****************************/

/****************************************************************************************************/
/****************************************************************************************************/
/*	Description :																					*/
/*	Function Sets the pending status of the interrupt .												*/
/*	Arguments : interrupt ID (0 : 239) 											                    */
/*	Returns   :	Void        																		*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

void MNVIC_vSET_PENDING_INT(u8 copy_u8int_num)
{
	NVIC->ISPR[copy_u8int_num/32] = (1<<(copy_u8int_num%32));
}

/***************************** End of Function *****************************/

/****************************************************************************************************/
/****************************************************************************************************/
/*	Description :																					*/
/*	Function Clears the pending status of the interrupt .											*/
/*	Arguments : interrupt ID (0 : 239) 											                    */
/*	Returns   :	Void        																		*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

void MNVIC_vCLR_PENDING_INT(u8 copy_u8int_num)
{
	NVIC->ICPR[copy_u8int_num/32] = (1<<(copy_u8int_num%32));
}

/***************************** End of Function *****************************/

/****************************************************************************************************/
/****************************************************************************************************/
/*	Description :																					*/
/*	Function Gets the active status of the interrupt .		  										*/
/*	Arguments : interrupt ID (0 : 239) 											                    */
/*	Returns   :	Status (1 for Active) || (0 for Non Active)        									*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

u8 	 MNVIC_vGET_ACTIVE_INT(u8 copy_u8int_num)
{
	u8 L_u8status = 0 ;
	L_u8status = GET_BIT(NVIC->IABR[copy_u8int_num/32],copy_u8int_num%32);
	return L_u8status;
}

/***************************** End of Function *****************************/

/****************************************************************************************************/
/****************************************************************************************************/
/*	Description :																					*/
/*	Function Generates interrupt by software .		  												*/
/*	Arguments : interrupt ID (0 : 239) 											                    */
/*	Returns   :	Void									        									*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

void MNVIC_vSWI_TRIGEGR(u8 copy_u8int_num)
{
	STIR = (copy_u8int_num);
}

/***************************** End of Function *****************************/

/****************************************************************************************************/
/****************************************************************************************************/
/*	Description :																					*/
/*	Function Sets the number of groups and sub-groups available .		  							*/
/*	Arguments : Void				 											                    */
/*	Returns   :	Void									        									*/
/*	Note      :	Configuration is done in config file	      										*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

void MNVIC_vSET_GROUP_SUB(void)
{
	AIRCR = (0x05FA0000)|(GROUP_SUB_CONFIG<<8);
}

/***************************** End of Function *****************************/

/****************************************************************************************************/
/****************************************************************************************************/
/*	Description :																					*/
/*	Function Sets the priority (Group And Sub-Group) .		  										*/
/*	Arguments : 1- interrupt ID (0 : 239)                                                           */
/* 				2- Group Number                                                                     */
/* 				3- Sub-Group number											                    	*/
/*	Returns   :	Void									        									*/
/****************************************************************************************************/

/**************************** Start of Function ****************************/

/* Case no Sub-Groups	*/
#if GROUP_SUB_CONFIG	==		_4_GROUP_0_SUB_

void MNVIC_vSET_PRIORITY(u8 copy_u8int_num,u8 copy_u8group_num)
{
	NVIC->IPR[copy_u8int_num / 4]	|=		((copy_u8group_num << 4) << (copy_u8int_num % 4)*8);
}

/* Case no Groups	*/
#elif GROUP_SUB_CONFIG	==		_0_GROUP_4_SUB_

void MNVIC_vMNVIC_vSET_PRIORITY(u8 copy_u8int_num,u8 copy_u8sub_num)
{
	NVIC->IPR[copy_u8int_num / 4]	|=		((copy_u8sub_num << 4) << (copy_u8int_num % 4)*8);
}

#else
/* Case there are both groups and sub-groups */
void MNVIC_vSET_PRIORITY(u8 copy_u8int_num,u8 copy_u8group_num,u8 copy_u8sub_num)
{
	u8 L_u8SET_VALUE =0 ;
/* Case 1 group && 3 sub-groups */
#if GROUP_SUB_CONFIG	==		_1_GROUP_3_SUB_

	L_u8SET_VALUE = (copy_u8group_num<<3)|(copy_u8sub_num) ;
	NVIC->IPR[copy_u8int_num / 4]	|=		((L_u8SET_VALUE << 4) << (copy_u8int_num % 4)*8);

/* Case 2 groups && 2 sub-groups */
#elif GROUP_SUB_CONFIG	==		_2_GROUP_2_SUB_

	L_u8SET_VALUE = (copy_u8group_num<<2)|(copy_u8sub_num) ;
	NVIC->IPR[copy_u8int_num / 4]	|=		((L_u8SET_VALUE << 4) << (copy_u8int_num % 4)*8);

/* Case 3 groups && 1 sub-group */
#elif GROUP_SUB_CONFIG	==		_3_GROUP_1_SUB_

	L_u8SET_VALUE = (copy_u8group_num<<1)|(copy_u8sub_num) ;
	NVIC->IPR[copy_u8int_num / 4]	|=		((L_u8SET_VALUE << 4) << (copy_u8int_num % 4)*8);

#endif
}
#endif







