#include <stdio.h>
#include <stdint.h>

uint32_t turnRightMostBit(uint32_t in)
{
     return (in & ~(1 << 0));
}

uint32_t swapBits(uint32_t in, uint32_t pos1, uint32_t pos2)
{
    uint32_t mask = 0;
    uint32_t firstPos =  ( in >> pos1 ) & 1; 
    uint32_t secondPos = ( in >> pos2 ) & 1;
    //clear bits at respective pos 
    in  =  ( in & ~( 1 << pos1));
    in  =  ( in & ~(1 << pos2));
    mask = (firstPos << pos2 ) | (secondPos << pos1);

    return in | mask;
}

int main()
{
    uint32_t in1 = 4 , in2 = 3 ;

    uint32_t op = swapBits(3,1,2);
    printf("after swap:%u \n",op);

    printf("Turn rightmost bit : %u \n",turnRightMostBit(15));
    printf("Turn rightmost bit : %u \n",turnRightMostBit(35));
    return 0;
}
