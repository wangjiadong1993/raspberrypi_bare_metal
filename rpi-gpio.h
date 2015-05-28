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

    Modified by Jiadong Wang
    2015-05-27
    

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
/*
        31-0    SETn (n=0..31)  0 = No effect
                                1 = Set GPIO pin n
*/
#define GPIO_GPSET0     7
/*
        31-22   Reserved 
        21-0    SETn(n=32..53)  0 = No effect
                                1 = Set GPIO pin n.
*/
#define GPIO_GPSET1     8

/*
        The output clear registers) are used to clear a GPIO pin. The CLR{n} field defines
        the respective GPIO pin to clear, writing a “0” to the field has no effect. If the GPIO
        pin is being used as in input (by default) then the value in the CLR{n} field is
        ignored. However, if the pin is subsequently defined as an output then the bit will
        be set according to the last set/clear operation. Separating the set and clear
        functions removes the need for read-modify-write operations. 
*/

/*
        31-3    Clearn (n=0..31)    0 = No effect
                                    1 = Clear GPIO pin n
*/
#define GPIO_GPCLR0     10
/*
        31-22   Reserved 
        21-0    Clearn(n=32..53)    0 = No effect
                                    1 = Clear GPIO pin n.
*/
#define GPIO_GPCLR1     11

/*
        The pin level registers return the actual value of the pin. The LEV{n} field gives the
        value of the respective GPIO pin. 
*/
/*
        31-0 LEVn (n=0..31)     0 = GPIO pin n is low
                                1 = GPIO pin n is high 
*/        
#define GPIO_GPLEV0     13
/*
        31-22 - Reserved 
        21-0 LEVn (n=32..53)    0 = GPIO pin n is low
                                1 = GPIO pin n is high 
*/                            
#define GPIO_GPLEV1     14
/*
        The event detect status registers are used to record level and edge events on the
        GPIO pins. The relevant bit in the event detect status registers is set whenever: 1)
        an edge is detected that matches the type of edge programmed in the rising/falling
        edge detect enable registers, or 2) a level is detected that matches the type of level
        programmed in the high/low level detect enable registers. The bit is cleared by
        writing a “1” to the relevant bit.
        The interrupt controller can be programmed to interrupt the processor when any of
        the status bits are set. The GPIO peripheral has three dedicated interrupt lines.
        Each GPIO bank can generate an independent interrupt. The third line generates a
        single interrupt whenever any bit is set. 
*/
/*
        31-0 EDSn (n=0..31)     0 = Event not detected on GPIO pin n
                                1 = Event detected on GPIO pin n 
*/
#define GPIO_GPEDS0     16
/*
        31-22 - Reserved R 0
        21-0    EDSn(n=32..53)  0 = Event not detected on GPIO pin n
                                1 = Event detected on GPIO pin n 
*/
#define GPIO_GPEDS1     17

/*
        S The rising edge detect enable registers define the pins for which a rising edge
        transition sets a bit in the event detect status registers (GPEDSn). When the
        relevant bits are set in both the GPRENn and GPFENn registers, any transition (1
        to 0 and 0 to 1) will set a bit in the GPEDSn registers. The GPRENn registers use
        synchronous edge detection. This means the input signal is sampled using the
        system clock and then it is looking for a “011” pattern on the sampled signal. This
        has the effect of suppressing glitches. 
*/
/*
    31-0 RENn (n=0..31) 0 = Rising edge detect disabled on GPIO pin n.
                        1 = Rising edge on GPIO pin n sets corresponding bit in EDSn. 
*/        
#define GPIO_GPREN0     19
/*
    31-22 - Reserved R 0
    21-0 RENn(n=32..53) 0 = Rising edge detect disabled on GPIO pin n.
                        1 = Rising edge on GPIO pin n sets corresponding bit in EDSn. 
*/
#define GPIO_GPREN1     20
/*
        The falling edge detect enable registers define the pins for which a falling edge
        transition sets a bit in the event detect status registers (GPEDSn). When the relevant
        bits are set in both the GPRENn and GPFENn registers, any transition (1 to 0 and 0
        to 1) will set a bit in the GPEDSn registers. The GPFENn registers use synchronous
        edge detection. This means the input signal is sampled using the system clock and
        then it is looking for a “100” pattern on the sampled signal. This has the effect of
        suppressing glitches. 
*/
/*
        31-0 FENn (n=0..31) 0 = Falling edge detect disabled on GPIO pin n.
                            1 = Falling edge on GPIO pin n sets corresponding bit in EDSn. 
*/
#define GPIO_GPFEN0     22
/*  
        31-22 - Reserved R 0
        21-0 RENn(n=32..53) 0 = Failing edge detect disabled on GPIO pin n.
                            1 = Failing edge on GPIO pin n sets corresponding bit in EDSn. 
*/
#define GPIO_GPFEN1     23

/*
        The high level detect enable registers define the pins for which a high level sets a bit in
        the event detect status register (GPEDSn). If the pin is still high when an attempt is
        made to clear the status bit in GPEDSn then the status bit will remain set. 
*/
/*
        31-0 HENn (n=0..31) 0 = High detect disabled on GPIO pin n
                            1 = High on GPIO pin n sets corresponding bit in GPEDS 
*/
#define GPIO_GPHEN0     25
/*
        31-22   -               Reserved R 0
        21-0    HENn(n=32..53)  0 = High detect disabled on GPIO pin n
                                1 = High on GPIO pin n sets corresponding bit in GPEDS 
*/
#define GPIO_GPHEN1     26
/*
        The low level detect enable registers define the pins for which a low level sets a bit in
        the event detect status register (GPEDSn). If the pin is still low when an attempt is
        made to clear the status bit in GPEDSn then the status bit will remain set. 
*/
/*
        31-0 LENn (n=0..31) 0 = Low detect disabled on GPIO pin n
                            1 = Low on GPIO pin n sets corresponding bit in GPEDS 
*/        
#define GPIO_GPLEN0     28
/*
        31-22   -               Reserved R 0
        21-0    LENn (n=32..53) 0 = Low detect disabled on GPIO pin n
                                1 = Low on GPIO pin n sets corresponding bit in GPEDS
*/                            
#define GPIO_GPLEN1     29
/*
        The asynchronous rising edge detect enable registers define the pins for which a
        asynchronous rising edge transition sets a bit in the event detect status registers
        (GPEDSn).
        Asynchronous means the incoming signal is not sampled by the system clock. As such
        rising edges of very short duration can be detected. 
*/
/*
        31-0 ARENn (n=0..31)    0 = Asynchronous rising edge detect disabled on GPIO pin n.
                                1 = Asynchronous rising edge on GPIO pin n sets corresponding bit in EDSn. 
*/        
#define GPIO_GPAREN0    31
/*
        31-22   -                   Reserved R 0
        21-0    ARENn(n=32..53)     0 = Asynchronous rising edge detect disabled on GPIO pin n.
                                    1 = Asynchronous rising edge on GPIO pin n sets corresponding bit in EDSn. 
*/                                
#define GPIO_GPAREN1    32
/*
        The asynchronous falling edge detect enable registers define the pins for which a
        asynchronous falling edge transition sets a bit in the event detect status registers
        (GPEDSn). Asynchronous means the incoming signal is not sampled by the system
        clock. As such falling edges of very short duration can be detected. 
*/
/*
        31-0 ARENn (n=0..31)    0 = Asynchronous failing edge detect disabled on GPIO pin n.
                                1 = Asynchronous failing edge on GPIO pin n sets corresponding bit in EDSn. 
*/ 
#define GPIO_GPAFEN0    34
/*
        31-22   -                   Reserved R 0
        21-0    ARENn(n=32..53)     0 = Asynchronous failing edge detect disabled on GPIO pin n.
                                    1 = Asynchronous failing edge on GPIO pin n sets corresponding bit in EDSn.       
*/                                
#define GPIO_GPAFEN1    35
/*
        The GPIO Pull-up/down Register controls the actuation of the internal pull-up/down
        control line to ALL the GPIO pins. This register must be used in conjunction with the 2
        GPPUDCLKn registers.
        Note that it is not possible to read back the current Pull-up/down settings and so it is the
        users’ responsibility to ‘remember’ which pull-up/downs are active. The reason for this is
        that GPIO pull-ups are maintained even in power-down mode when the core is off, when
        all register contents is lost.
        The Alternate function table also has the pull state which is applied after a power down. 
*/
/*
        31-2 --- Unused
        1-0 PUD PUD - GPIO Pin Pull-up/down
        00 = off – disable pull-up/down
        01 = Enable Pull Down control
        10 = Enable Pull Up control
        11 = Reserved
        *Use in conjunction with GPPUDCLK0/1/2 
*/        
#define GPIO_GPPUD      37
/*
        The GPIO Pull-up/down Clock Registers control the actuation of internal pull-downs on
        the respective GPIO pins. These registers must be used in conjunction with the GPPUD
        register to effect GPIO Pull-up/down changes. The following sequence of events is
        required:
        1. Write to GPPUD to set the required control signal (i.e. Pull-up or Pull-Down or neither
        to remove the current Pull-up/down)
        2. Wait 150 cycles – this provides the required set-up time for the control signal
        3. Write to GPPUDCLK0/1 to clock the control signal into the GPIO pads you wish to
        modify – NOTE only the pads which receive a clock will be modified, all others will
        retain their previous state.
        4. Wait 150 cycles – this provides the required hold time for the control signal
        5. Write to GPPUD to remove the control signal
        6. Write to GPPUDCLK0/1 to remove the clock
*/
/*
(31-0) PUDCLKn(n=0..31)     0 = No Effect
                            1 = Assert Clock on line (n)
                            *Must be used in conjunction with GPPUD 
*/        
#define GPIO_GPPUDCLK0  38
/*
31-22   -                   Reserved R 0
21-0    PUDCLKn (n=32..53)  0 = No Effect
                            1 = Assert Clock on line (n)
                            *Must be used in conjunction with GPPUD 
*/                            
#define GPIO_GPPUDCLK1  39

#endif
