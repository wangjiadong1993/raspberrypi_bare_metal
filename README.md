#README

##CREDIT

the first.c file is copied from http://www.valvers.com/embedded-linux/raspberry-pi/step01-bare-metal-programming-in-cpt1.

##COMMAND LINE

**to compile** arm-none-eabi-gcc -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles armc-2.c -o kernel.elf

**to convert to img** arm-none-eabi-objcopy kernel.elf -O binary kernel.img
	
