#include <stdio.h>

#define GET_BIT(reg, bitPos) ((reg & (1<<bitPos))!= 0)
#define SET_BIT(reg, bitPos) (reg | (1<<bitPos))
#define CLEAR_BIT(reg, bitPos) (reg & ~(1<<bitPos))
#define TOGGLE_BIT(reg, bitPos) (reg ^ (1<<bitPos))


int main()
{
    unsigned char num = 0b10101010; // Example number

    printf("Binary representation of %d: ", num);
    for (int i = 7; i >= 0; i--) {
        printf("%d", GET_BIT(num, i) ? 1 : 0);
    }
    printf("\n");

    SET_BIT(num, 0); // Set the least significant bit
    printf("After setting bit 0: ");
    for (int i = 7; i >= 0; i--) {


    return 0;
}