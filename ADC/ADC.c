/*********************************/
/* Author   :   Spectrum         */
/* Date     :   20 Sep 2021      */
/* Version  :   V01              */
/*********************************/

#include "ADC_private.h"
#include "ADC.h"

void ADC_init(const ADC_config * ADC_ptr)
{
	/*Set ADMUX register reference voltage (AREF or AVCC or Internal Voltage)*/
	ADMUX = ((ADMUX & 0x3F) | ((ADC_ptr -> RefVoltage) << 6));

	/*Enable ADC */
	SET_Bit(ADCSRA,ADEN);

	/*Set ADC Clock prescalar*/
	ADCSRA = ((ADCSRA & 0xF8) | ADC_ptr -> clock);

	/*if ADC interrupt is enabled then SET interrupt enable pin in ADCSRA*/
#ifdef	ADC_ENABLE_Interrupt
	SET_Bit(ADCSRA, ADIF);
#endif

}

u16 ADC_readChannel(u16 ch)
{
	/*Select Analog Channel*/
	ADMUX &= 0xE0;

	/*insert data to ADMUX*/
	ADMUX |= ch;
	/*set start conversion (ADSC) to 1*/
	SET_Bit(ADCSRA, ADSC);

	/*if interrupt is enabled then wait till flag is
	 * then set ADIF to 1 to disable interrupt*/

	while(isCLR(ADCSRA, ADIF));
	SET_Bit(ADCSRA, ADIF);

	/*Return Data*/
	return ADC;
}
