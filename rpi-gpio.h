/*

    Part of the Raspberry-Pi Bare Metal Tutorials
    Copyright (c) 2013, Brian Sidebotham
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
        this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef RPI_GPIO_H
#define RPI_GPIO_H

/** The base address of the GPIO peripheral (ARM Physical Address) */
#define GPIO_BASE       0x20200000UL
/*
        The function select registers are used to define the operation of the general-purpose I/O
        pins. Each of the 54 GPIO pins has at least two alternative functions as defined in section
        16.2. The FSEL{n} field determines the functionality of the nth GPIO pin. All unused
        alternative function lines are tied to ground and will output a “0” if selected. All pins reset
        to normal GPIO input operation.
*/

/*
    31-30 --- Reserved 
    29-27 FSEL9 FSEL9 - Function Select 9
                        000 = GPIO Pin 9 is an input
                        001 = GPIO Pin 9 is an output
                        100 = GPIO Pin 9 takes alternate function 0
                        101 = GPIO Pin 9 takes alternate function 1
                        110 = GPIO Pin 9 takes alternate function 2
                        111 = GPIO Pin 9 takes alternate function 3
                        011 = GPIO Pin 9 takes alternate function 4
                        010 = GPIO Pin 9 takes alternate function 5 
    26-24 FSEL8 FSEL8 - Function Select 
    23-21 FSEL7 FSEL7 - Function Select 7
    20-18 FSEL6 FSEL6 - Function Select 6
    17-15 FSEL5 FSEL5 - Function Select 5
    14-12 FSEL4 FSEL4 - Function Select 4
    11-9  FSEL3 FSEL3 - Function Select 3
    8-6   FSEL2 FSEL2 - Function Select 2
    5-3   FSEL1 FSEL1 - Function Select 1
    2-0   FSEL0 FSEL0 - Function Select 0
*/
#define GPIO_GPFSEL0    0
#define GPIO_GPFSEL1    1
#define GPIO_GPFSEL2    2
#define GPIO_GPFSEL3    3
#define GPIO_GPFSEL4    4
#define GPIO_GPFSEL5    5
/*
        The output set registers are used to set a GPIO pin. The SET{n} field defines the
        respective GPIO pin to set, writing a “0” to the field has no effect. If the GPIO pin is
        being used as in input (by default) then the value in the SET{n} field is ignored.
        However, if the pin is subsequently defined as an output then the bit will be set
        according to the last set/clear operation. Separating the set and clear functions
        removes the need for read-modify-write operations 
*/
#define GPIO_GPSET0     7
#define GPIO_GPSET1     8

#define GPIO_GPCLR0     10
#define GPIO_GPCLR1     11

#define GPIO_GPLEV0     13
#define GPIO_GPLEV1     14

#define GPIO_GPEDS0     16
#define GPIO_GPEDS1     17

#define GPIO_GPREN0     19
#define GPIO_GPREN1     20

#define GPIO_GPFEN0     22
#define GPIO_GPFEN1     23

#define GPIO_GPHEN0     25
#define GPIO_GPHEN1     26

#define GPIO_GPLEN0     28
#define GPIO_GPLEN1     29

#define GPIO_GPAREN0    31
#define GPIO_GPAREN1    32

#define GPIO_GPAFEN0    34
#define GPIO_GPAFEN1    35

#define GPIO_GPPUD      37
#define GPIO_GPPUDCLK0  38
#define GPIO_GPPUDCLK1  39

#endif
