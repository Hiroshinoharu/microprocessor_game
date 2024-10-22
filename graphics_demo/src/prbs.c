#include <stdio.h>
#include <stdint.h>
uint32_t prbs(void);

uint32_t random(uint32_t lower,uint32_t upper)
{
    return (prbs()%(upper-lower))+lower;
}
uint32_t shift_register=1234;

void initprbs(uint32_t seed)
{
	shift_register = seed;
}

uint32_t prbs()
{
	// This is an unverified 31 bit PRBS generator
	// It should be maximum length but this has not been verified 
	unsigned long new_bit=0;
	
	
	new_bit= ((shift_register & (1<<27))>>27) ^ ((shift_register & (1<<30))>>30);
	new_bit= ~new_bit;
	new_bit = new_bit & 1;
	shift_register=shift_register << 1;
	shift_register = shift_register | (new_bit);
	return shift_register & 0x7fffffff; // return 31 LSB's 
}

