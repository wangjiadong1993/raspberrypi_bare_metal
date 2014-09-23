#README

##CREDIT

the first.c file is copied from http://www.valvers.com/embedded-linux/raspberry-pi/step01-bare-metal-programming-in-cpt1.

##COMMAND LINE

**to compile** arm-none-eabi-gcc -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles armc-2.c -o kernel.elf

**to convert to img** arm-none-eabi-objcopy kernel.elf -O binary kernel.img
##STRUCTURE
**first.c**  the main c main function which does most of the work
**rpi.x** the linker script, copy and past from gcc tool chain with minor change, it starts the "_start"_method in start.s in start.s
**start.s** the assembly function which initialize the stack and call the startup method
**startup.c** the c function to initilize the bcc section and call the main function, the booter
**|*.h|**  all the headers
**|*.c|**  all the c functions
	
