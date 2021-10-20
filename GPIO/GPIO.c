/*********************************/
/* Author   :   Spectrum         */
/* Date     :   13 Oct 2020      */
/* Version  :   V01              */
/*********************************/

#include "../Common/BIT_Math.h"
#include "GPIO_private.h"
#include "GPIO.h"


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setPinDirection(GPIO_PORT port, u8 pin, GPIO_directionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin < NUM_OF_PINS_PER_PORT) || (port < NUM_OF_PORTS))
	{

		/* Setup the pin direction as required */
		switch(port)
		{
		case A:
			if(direction == OUTPUT)
			{
				SET_Bit(DDRA,pin);
			}
			else
			{
				CLR_Bit(DDRA,pin);
			}
			break;
		case B:
			if(direction == OUTPUT)
			{
				SET_Bit(DDRB,pin);
			}
			else
			{
				CLR_Bit(DDRB,pin);
			}
			break;
		case C:
			if(direction == OUTPUT)
			{
				SET_Bit(DDRC,pin);
			}
			else
			{
				CLR_Bit(DDRC,pin);
			}
			break;
		case D:
			if(direction == OUTPUT)
			{
				SET_Bit(DDRD,pin);
			}
			else
			{
				CLR_Bit(DDRD,pin);
			}
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(GPIO_PORT port, u8 pin, u8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin < NUM_OF_PINS_PER_PORT) || (port < NUM_OF_PORTS))
	{
		/* Write the pin value as required */
		switch(port)
		{
		case A:
			if(value == High)
			{
				SET_Bit(PORTA,pin);
			}
			else
			{
				CLR_Bit(PORTA,pin);
			}
			break;
		case B:
			if(value == High)
			{
				SET_Bit(PORTB,pin);
			}
			else
			{
				CLR_Bit(PORTB,pin);
			}
			break;
		case C:
			if(value == High)
			{
				SET_Bit(PORTC,pin);
			}
			else
			{
				CLR_Bit(PORTC,pin);
			}
			break;
		case D:
			if(value == High)
			{
				SET_Bit(PORTD,pin);
			}
			else
			{
				CLR_Bit(PORTD,pin);
			}
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 GPIO_readPin(GPIO_PORT port, u8 pin)
{
	u8 pin_value = Low;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin < NUM_OF_PINS_PER_PORT) || (port < NUM_OF_PORTS))
	{
		/* Read the pin value as required */
		switch(port)
		{
		case A:
			if(isSET(PINA,pin))
			{
				pin_value = High;
			}
			else
			{
				pin_value = Low;
			}
			break;
		case B:
			if(isSET(PINB,pin))
			{
				pin_value = High;
			}
			else
			{
				pin_value = Low;
			}
			break;
		case C:
			if(isSET(PINC,pin))
			{
				pin_value = High;
			}
			else
			{
				pin_value = Low;
			}
			break;
		case D:
			if(isSET(PIND,pin))
			{
				pin_value = High;
			}
			else
			{
				pin_value = Low;
			}
			break;
		}
	}

	return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setPortDirection(GPIO_PORT port, GPIO_directionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port < NUM_OF_PORTS)
	{
		/* Setup the port direction as required */
		switch(port)
		{
		case A:
			DDRA = 0xFF;
			break;
		case B:
			DDRB = 0xFF;
			break;
		case C:
			DDRC = 0xFF;
			break;
		case D:
			DDRD = 0xFF;
			break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(GPIO_PORT port, u8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port < NUM_OF_PORTS)
	{
		/* Write the port value as required */
		switch(port)
		{
		case A:
			PORTA = value;
			break;
		case B:
			PORTB = value;
			break;
		case C:
			PORTC = value;
			break;
		case D:
			PORTD = value;
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8 GPIO_readPort(GPIO_PORT port)
{
	u8 value = Low;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port < NUM_OF_PORTS)
	{
		/* Read the port value as required */
		switch(port)
		{
		case A:
			value = PINA;
			break;
		case B:
			value = PINB;
			break;
		case C:
			value = PINC;
			break;
		case D:
			value = PIND;
			break;
		}
	}

	return value;
}
