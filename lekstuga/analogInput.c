#include <pic32mx.h>

//Code from Chapter 8, Memory and I/O Systems

//Wants to read the analog value from AN11 pin on PIC32
void initadc(int channel){
	AD1CHSbits.CHOSA =channel; //select which channel to sample
	AD1PCFGCLR = 3 << channel; //stod1 istället för 3 färut configure pin for this channel to analog input

	AD1CON3bits.ON = 1; //turn ADC on
	AD1CON3bits.SAMP = 1; //begin sampling
	AD1CON3bits.DONE = 0; // clear done-flag
}

int readadc(void){
	AD1CON3bits.SAMP = 0; //end sampling, start conversion
	while(!AD1CON3bits.DONE); //wait until done converting
	AD1CON3bits.SAMP =1; // resume samplig to prepare for next conversion

	AD1CON3bits.DONE = 0 ; // clear Done-flag
	return ADC1BUF0; //return conversion result
}

int main(void){
	int sample;
	initadc(11);
	sample = readadc();
}