/***********************************************************/
/* Author 	: Khaled Elsayed							   */ 
/* Date  	: 21 May 2023								   */
/* Version  :  V01										   */
/***********************************************************/
#ifndef MSTK_PRIVATE_H
#define MSTK_PRIVATE_H
 
 void (*Callback)(void);
 
#define STK_CTRL   				*((volatile u32*)(0xE000E010+0x00))
#define STK_LOAD				*((volatile u32*)(0xE000E010+0x04))
#define STK_VAL					*((volatile u32*)(0xE000E010+0x08))


#define CLKSOURCE_AHB_DIV            0
#define CLKSOURCE_AHB_DIV_8          1







#endif