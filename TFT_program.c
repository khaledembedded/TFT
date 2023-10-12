#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Dio_interface.h"
#include"MSTK_interface.h"
#include"STP_interface.h"
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"





void HTFT_voidInit(void)
{
	/*SEND RST PULSE*/
	Mgpio_voidSetPinValue(HTFT_RST_PIN,1);
	MSTK_voidSetBusyWait(100);
	Mgpio_voidSetPinValue(HTFT_RST_PIN,0);
	MSTK_voidSetBusyWait(1);
	Mgpio_voidSetPinValue(HTFT_RST_PIN,1);
	MSTK_voidSetBusyWait(100);
	Mgpio_voidSetPinValue(HTFT_RST_PIN,0);
	MSTK_voidSetBusyWait(100);
	Mgpio_voidSetPinValue(HTFT_RST_PIN,1);
	MSTK_voidSetBusyWait(120000);
	
	/*SEND SLEEP OUT COMMAND*/
	HTFT_voidSendCommand(0x11);
	
	/*DELAY 150 MS*/
	MSTK_voidSetBusyWait(150000);
	
	/*SEND COLOR MODE COMMAND*/
	HTFT_voidSendCommand(0x3A);
	HTFT_voidSendData   (0x05);
	
	/*SEND DISPLAY ON COMMAND*/
	HTFT_voidSendCommand(0x29);
	
	
}


void HTFT_voidDisplayImage(const u16 *Copy_u16Image)
{
	/*SET X COMMAND*/
	HTFT_voidSendCommand(0x2A);
	HTFT_voidSendData   (0);
	HTFT_voidSendData   (0);
	HTFT_voidSendData   (0);
	HTFT_voidSendData   (127);
	/*SET Y COMMAND*/
	HTFT_voidSendCommand(0x2B);
	HTFT_voidSendData   (0);
	HTFT_voidSendData   (0);
	HTFT_voidSendData   (0);
	HTFT_voidSendData   (159);
	
	/*RAM WRITE*/
	HTFT_voidSendCommand(0x2C);
	
	
	u16 Local_u16Counter=0;
	for(Local_u16Counter=0;Local_u16Counter<20480;Local_u16Counter++)
	{
		HTFT_voidSendData(Copy_u16Image[Local_u16Counter] >> 8);
		HTFT_voidSendData(Copy_u16Image[Local_u16Counter] & 0x00ff);
	}
	
	
}



static void HTFT_voidSendCommand(u8 Copy_u8Cmd)
{
	u8 Local_u8Dummy=0;
	/*Set A0 LOW*/
	Mgpio_voidSetPinValue(HTFT_A0_PIN,0);
	SPI_voidSendReceiveSynch(Copy_u8Cmd,&Local_u8Dummy);
}


static void HTFT_voidSendData(u8 Copy_u8Data)
{
	u8 Local_u8Dummy=0;
	/*Set A0 LOW*/
	Mgpio_voidSetPinValue(HTFT_A0_PIN,1);
	SPI_voidSendReceiveSynch(Copy_u8Data,&Local_u8Dummy);	
	
}
