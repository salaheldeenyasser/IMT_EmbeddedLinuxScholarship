#include <stdio.h>

#define GET_BIT(reg, bitPos) ((reg >> bitPos) & 1)
#define SET_BIT(reg, bitPos) (reg |= (1<<bitPos))
#define CLEAR_BIT(reg, bitPos) (reg &= ~(1<<bitPos))
#define TOGGLE_BIT(reg, bitPos) (reg ^= (1<<bitPos))


int main()
{
    size_t num = 0b10101010; // Example number

    printf("Binary representation of %zu: ", num);
    for (int i = 7; i >= 0; i--) {
        printf("%d", GET_BIT(num, i) ? 1 : 0);
    }
    printf("\n");

    SET_BIT(num, 0); // Set the least significant bit
    printf("After setting bit 0: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", GET_BIT(num, i) ? 1 : 0);
    }
    printf("\n");

    CLEAR_BIT(num, 1); // Clear the second least significant bit
    printf("After clearing bit 1: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", GET_BIT(num, i) ? 1 : 0);
    }
    printf("\n");

    TOGGLE_BIT(num, 2); // Toggle the third least significant bit
    printf("After toggling bit 2: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", GET_BIT(num, i) ? 1 : 0);
    }
    printf("\n");

    return 0;
}