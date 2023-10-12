#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Dio_interface.h"
#include"MSTK_interface.h"
#include"STP_interface.h"
#include"STP_private.h"
#include"STP_config.h"






void STP_voidSendData(u8 Copy_u8Data)
{
	
	s8 i;
	u8 Local_u8Bit=0;
	for(i=7;i>=0;i--)
	{
		Local_u8Bit=GET_BIT(Copy_u8Data,i);
		Mgpio_voidSetPinValue(STP_SERIAL_DATA,Local_u8Bit);
		Mgpio_voidSetPinValue(STP_SHIFT_CLOCK,1);
		MSTK_voidSetBusyWait(1);
		Mgpio_voidSetPinValue(STP_SHIFT_CLOCK,0);
		MSTK_voidSetBusyWait(1);
		
	}
	
		Mgpio_voidSetPinValue(STP_STORAGE_CLOCK,1);
		MSTK_voidSetBusyWait(1);
		Mgpio_voidSetPinValue(STP_STORAGE_CLOCK,0);
		MSTK_voidSetBusyWait(1);
	
}
