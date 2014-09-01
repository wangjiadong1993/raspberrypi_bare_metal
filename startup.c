extern int __bss_start__;
extern int __bss_end__;
extern void kernal_main(unsigned int r0, unsigned int r1, unsigned int atags);
void _startup (unsigned int r0, unsigned int r1, unsigned int r2)
{
	int* bss = &__bss_start__;
	int* bss_end=&__bss_end__;
	/*clear the whole bss region*/
	while (bss < bss_end)
		*bss++ = 0;
	//call the kernal main function
	kernal_main(r0,r1,r2);
	//an infinity loop to catch in case the kernal main ends
	while(1)
	{
		/* EMPTY! */
	}
}
