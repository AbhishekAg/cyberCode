#include <stdio.h>
#define CHAR_BIT 8

unsigned int reverse(unsigned int v)
{
    //unsigned int v;     // input bits to be reversed
    unsigned int r = v; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end

    for (v >>= 1; v; v >>= 1)
    {   
	r <<= 1;
	r |= v & 1;
	s--;
    }
    r <<= s; // shift when v's highest bits are zero
    return r;
}

int countBits(int x)
{
    int count = 0;
    while(x) {
	count ++;
	x = x&(x-1);
    }
    return count;
}

#define uint32_t unsigned int

uint32_t reverse_byte(uint32_t num) {
    uint32_t res = 0;

    res = num & 0xFF; num >>= 8; res <<= 8;
    res |= num & 0xFF; num >>= 8; res <<= 8;
    res |= num & 0xFF; num >>= 8; res <<= 8;
    res |= num & 0xFF; 

    return res;
}

int main()
{
    int x, count=0, opt=0;

    while(1) {
	printf("Input option: ");
	scanf("%d", &opt);
	printf("Input num: ");
	scanf("%d", &x);
        switch(opt) {
	    case 1:
	      printf("Count of bits: %d\n", countBits(x));
	      break;
	    case 2:
	      printf("Reverse bits: %d\n", reverse(x));
	      break;
	    case 3:
	      printf("Reverse bytes: %d\n", reverse_byte(x));
	      break;
	    default:
	      break;
	}
    }
    return 0;
}
