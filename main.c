/*********************************/
/* Author   :   Spectrum         */
/* Date     :   13 Oct 2021      */
/* Version  :   V01              */
/*********************************/
#define F_CPU	1000000UL
#include "GPIO/GPIO.h"
#include "ADC/ADC.h"
#include "DC MOTOR/DC_MOTOR.h"
#include "LCD/LCD.h"
#include "LM35_Temp_Sensor/lm35_sensor.h"
#include "avr/delay.h"

int main(void)
{
	u8 temp;

	/*Init LCD to power ON correctly*/
	LCD_init();

	/*Init ADC with specified Configuration Which Are Clock = F_CPU/8
	 * and Setting reference voltage to internal voltage 2.56v*/
	ADC_config ADCConfig = {FCPU_8, IntVoltage};
	ADC_init(&ADCConfig);

	/*Display a sentence*/
	LCD_Displaystring("Temp =    C");

	/*Init the motor by setting the directions and pin value on its connections*/
	DC_Motor_Init();


	while(1)
	{
		/*reading the temperature from sensor*/
	  	temp = LM35_getTemperature();
		LCD_MoveCursor(0,7);

		if(temp >= 100)
		{
			LCD_Int_to_Str(temp);
		}
		else
		{
			LCD_Int_to_Str(temp);
			LCD_DisplayCharacter(' ');
		}

		/*If temp < 30 then stop the fan */
		if (temp < 30)
		{
			LCD_MoveCursor(1,3);
			LCD_Displaystring("Fan is off");
			TMR0_PWM_Stop();
		}

		else
		{
			LCD_MoveCursor(1,3);
			LCD_Displaystring("Fan is on");
			LCD_DisplayCharacter(' ');

			/*if temp is > 120 then switch the fan with its 100% of power*/
			if(temp >= 120)
			{
				DC_Motor_Rotate(CW,100);
			}

			/*if temp is > 90 then switch the fan with its 75% of power*/
			else if(temp >= 90)
			{
				DC_Motor_Rotate(CW,75);
			}

			/*if temp is > 60 then switch the fan with its 50% of power*/
			else if(temp >= 60)
			{
				DC_Motor_Rotate(CW,128);
			}

			/*if temp is > 30 then switch the fan with its 25% of power*/
			else if(temp >= 30)
			{
				DC_Motor_Rotate(CW,64);;
			}

		}
	}
	return 0;
}
