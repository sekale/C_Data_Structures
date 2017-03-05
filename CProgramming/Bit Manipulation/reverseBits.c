#include <stdio.h>
#include <stdlib.h>

#define NBITS 32
#define NBYTES 4
#define BYTEBITWIDTH 8

void printBits(uint32_t * reverseValue)
{
    int ctr = 0;
    int i, j;
    uint32_t bitMask = 1;

    unsigned char *byte = (unsigned char *)reverseValue;

    for(i = NBYTES - 1 ; i >= 0; --i)
    {
        for(j = BYTEBITWIDTH - 1; j >= 0; --j)
        {
            if((byte[i] >> j) & bitMask)
                printf("1");
            else
                printf("0");
        }
    }
    printf("\n");
}

uint32_t reverseBits(uint32_t n)
{
    int j = 0;
    uint32_t temp = 0, retVal = 0;
    for(j = 0; j < 32; j++)
    {
        temp = (n >> j) & 1;
        retVal |= temp << (NBITS - j - 1);

#ifdef DEBUG
     printBits(&retVal);
     if(j == 5)
     {
         break;
     }
#endif

    }
    return retVal;
}

int main()
{
    uint32_t testVal = 0x0008;
    
    printBits(&testVal);

    uint32_t reverseValue = reverseBits(testVal);
    
    printBits(&reverseValue);

    return 0;
}