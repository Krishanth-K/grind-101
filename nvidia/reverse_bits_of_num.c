#include "stdio.h"
#include <stdint.h>
#define BITS 32

// ques = Write an Efficient C Program to Reverse Bits of a Number
// Input : n = 1
// Output : 2147483648
// Explanation : On a machine with size of unsigned bit as 32. Reverse of
// 0....001 is 100....0.
//
// Input : n = 2147483648
// Output : 1

uint32_t rev_bits(uint32_t num)
{
	uint32_t res = 0;
	int i = 0;

	while (i < BITS)
	{
		res = res << 1;

		if (num & (1 << i))
			res |= 1;

		i++;
	}

	return res;
}

int main()
{
	uint32_t n = 1;
	printf("%u", rev_bits(n));

	return 0;
}
