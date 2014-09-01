.section ".text.startup"

.global _start
.global _get_stack_pointer

_start:
	ldr sp, =(128 * (1024 * 1024))
//the stack start from 128 MB and go backwards.
//the first word is left empty
	sub sp, sp, #04
	b _startup

_inf_loop：
//it is an infinite loop
	b _inf_loop

_get_stack_pointer:
//get the address for current stack point and put it in the r0 register
	str sp, [sp]
	ldr r0, [sp]
	mov pc, lr
	
