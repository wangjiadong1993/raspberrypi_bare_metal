#include "rpi-gpio.h"
//@file armc-2.c
//@brief ARM C Tutorial #2 for Raspberry-Pi

//Using C without an operating system on the Raspberry-Pi BCM2835 board.

//This example lights the OK LED and then loops infinitely
//*/

/** The base address of the GPIO peripheral (ARM Physical Address) */
 
/** GPIO Register set */
volatile unsigned int* gpio;
volatile unsigned int tim;

#define LED_GPFSEL      GPIO_GPFSEL1
#define LED_GPFBIT      18
#define LED_GPSET       GPIO_GPSET0
#define LED_GPCLR       GPIO_GPCLR0
#define LED_GPIO_BIT    16


/** Main function - we'll never return from here */
int kernal_main(unsigned int r0, unsigned int r1, unsigned int stags)
{
	/* Assign the address of the GPIO peripheral (Using ARM Physical Address) */
	gpio = (unsigned int*)GPIO_BASE;

	/* Write 1 to the GPIO16 init nibble in the Function Select 1 GPIO
	 *        peripheral register to enable GPIO16 as an output */
	gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);

	/* Write 1 to the 16th bit in the Clear0 GPIO peripheral register to set
	 *        the output level of GPIO16 as 0 (logic low) */
	gpio[LED_GPSET] = (1 << LED_GPIO_BIT);


	/* Never exit as there is no OS to exit to! */
	while(1)
	{
		for(tim = 0; tim < 500000; tim++)
			;

		/* Set the GPIO16 output low ( Turn OK LED on )*/
		gpio[GPIO_GPCLR0] = (1 << LED_GPIO_BIT);

		for(tim = 0; tim < 500000; tim++)
			;

		/* Set the GPIO16 output high ( Turn OK LED off )*/
		gpio[GPIO_GPSET0] = (1 << LED_GPIO_BIT);
	}
}
