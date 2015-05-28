gcc/bin/arm-none-eabi-gcc -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles -g -Wl,-verbose -Wl,-T,code/rpi.x code/first.c code/start.s code/startup.c -o kernel.elf 
gcc/bin/arm-none-eabi-objcopy kernel.elf -O binary kernel.img
