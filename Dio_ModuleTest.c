  /******************************************************************************
 *
 * Module: ModuleTest
 *
 * File Name: Dio_ModuleTest.c
 *
 * Description: Source file for the Dio Test Cases.
 *
 * Author: mhmoud ibrahim mohamed
 ******************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"

/************************************************************************************
* Test ID :TestCase1
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the two leds shall be turned on.
*                  2. Press the second button the two leds shall be turned on.
*************************************************************************************/

void TestCase1(void)
{
	uint8 button1 = STD_LOW;
	uint8 button2 = STD_LOW;

	/* Wait until the first button is pressed */
	while(button1 != STD_HIGH)
	{
		button1 = Dio_ReadChannel(DioConf_BUTTON1_CHANNEL_ID_INDEX);
	}

	/* Turn on the two Leds */
	Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);
	Dio_WriteChannel(DioConf_LED2_CHANNEL_ID_INDEX,STD_HIGH);
	Dio_WriteChannelGroup(DioConf_RGB_CHANNEL_GROUP,0b00000110);
	/* Wait until the second button is pressed */
	while(button2 != STD_HIGH)
	{
		button2 = Dio_ReadChannel(DioConf_BUTTON2_CHANNEL_ID_INDEX);
	}

	/* Turn off the two Leds */
	Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_LOW);
	Dio_WriteChannel(DioConf_LED2_CHANNEL_ID_INDEX,STD_LOW);
	Dio_WriteChannelGroup(DioConf_RGB_CHANNEL_GROUP,0b00000001);
}

/************************************************************************************
* Test ID :TestCase2
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the two leds shall be flipped (OFF --> ON).
*                  2. Press the second button the two leds shall be flipped (ON --> OFF).
*************************************************************************************/
void TestCase2(void)
{
	uint8 button1 = STD_LOW;
	uint8 button2 = STD_LOW;

	/* Wait until the first button is pressed */
	while(button1 != STD_HIGH)
	{
		button1 = Dio_ReadChannel(DioConf_BUTTON1_CHANNEL_ID_INDEX);
	}

	/* Flip the two Leds */
	Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
	Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);
	Dio_WriteChannelGroup(DioConf_RGB_CHANNEL_GROUP,0b00000110);
	/* Wait until the second button is pressed */
	while(button2 != STD_HIGH)
	{
		button2 = Dio_ReadChannel(DioConf_BUTTON2_CHANNEL_ID_INDEX);
	}

	/* Flip the two Leds */
	Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
	Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);
	Dio_WriteChannelGroup(DioConf_RGB_CHANNEL_GROUP,0b00000001);
}

int main(void)
{
	/* Configuring the direction of the pins is the responsibility of the PORT driver */

	CLEAR_BIT(DDRA_REG,2); /* Configure Button1 pin as i/p pin */
	CLEAR_BIT(DDRB_REG,4); /* Configure Button2 pin as i/p pin */
	SET_BIT(DDRC_REG,3);   /* Configure Led1 pin as o/p pin */
	SET_BIT(DDRD_REG,6);   /* Configure Led2 pin as o/p pin */
	SET_BIT(DDRA_REG,5);
	SET_BIT(DDRA_REG,6);
	SET_BIT(DDRA_REG,7);
	/* Initialize the Dio Driver */
	Dio_Init(&Dio_Configuration);

	/* Run the First Test Case */
	while(1){
		TestCase1();
	}


	/* Run the Second Test Case */
	//TestCase2();
}
