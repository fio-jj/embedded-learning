#include <stdio.h>
#include <stdint.h>

#define PI 3.14159
#define MAX_SIZE 100
#define SQUARE(x) ((x) * (x))

#define SET_BIT(reg, n)    ((reg) |=  (1U << (n)))
#define CLEAR_BIT(reg, n)  ((reg) &= ~(1U << (n)))
#define TOGGLE_BIT(reg, n) ((reg) ^=  (1U << (n)))
#define CHECK_BIT(reg, n)  (((reg) >> (n)) & 1U)

#define DEBUG
#ifdef DEBUG
    #define LOG(msg) printf("DEBUG: %s\n", msg)
#else
    #define LOG(msg)
#endif

int main() {
    printf("PI = %f\n", PI);
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("Square of 5 = %d\n", SQUARE(5));
    printf("Square of 2+3 = %d\n", SQUARE(2+3));

    uint32_t reg = 0;
    SET_BIT(reg, 3);
    printf("After SET bit 3: %d\n", reg);
    CLEAR_BIT(reg, 3);
    printf("After CLEAR bit 3: %d\n", reg);
    TOGGLE_BIT(reg, 5);
    printf("After TOGGLE bit 5: %d\n", reg);
    printf("Bit 5 is: %d\n", CHECK_BIT(reg, 5));

    LOG("program started");
    LOG("reading sensor");

    return 0;
}