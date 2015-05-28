// #ifndef RPI_CONSTANT_H
// #define RPI_CONSTANT_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//general constants
#define PHYSICAL_ADDRESS_BASE  0x20000000  #what we use
#define RPI_BUS_ADDRESS_BASE   0x7E000000  #what is provided in the manual.

#define OFFSET_ADJUSTMENT      0x5E000000

//system timer
#define RPI_SYSTEM_TIMER_BUS_ADDRESS 			0x7E003000
#define RPI_SYSTEM_TIMER_PHYSICAL_ADRESS_BASE  	0x20003000
#define RPI_SYSTEM_TIMER_CONTROL_AND_STATUS    	0x0
#define RPI_SYSTEM_TIMER_COUNTER_LOWER_32_BITS 	0x4
#define RPI_SYSTEM_TIMER_COUNTER_HIGHER_32_BITS 0x8
#define RPI_SYSTEM_TIMER_COUNTER_COMPARE_0 		0xc
#define RPI_SYSTEM_TIMER_COUNTER_COMPARE_1 		0x10
#define RPI_SYSTEM_TIMER_COUNTER_COMPARE_2 		0x14
#define RPI_SYSTEM_TIMER_COUNTER_COMPARE_3 		0x18

typedef struct {
	uint32_t timer_control_status;
	uint32_t timer_lower_32;
	uint32_t timer_higher_32;
	uint32_t timer_compare_0;
	uint32_t timer_compare_1;
	uint32_t timer_compare_2;
	uint32_t timer_compare_3;
} rpi_system_timer_t;

void rpi_sleep_micro_sec(uint32_t us)
{
	volatile rpi_system_timer_t* rpi_system_time_pointer  =  (rpi_system_timer_t*)RPI_SYSTEM_TIMER_PHYSICAL_ADRESS_BASE;
	volatile uint32_t ts = rpi_system_time_pointer->timer_lower_32;
 
    while( ( rpi_system_time_pointer->timer_lower_32 - ts ) < us )
    {
        /* BLANK */
    }
}