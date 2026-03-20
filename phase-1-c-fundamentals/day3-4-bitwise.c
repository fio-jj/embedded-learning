#include <stdio.h>

void set_bit(unsigned char *reg, int n) {
    *reg |= (1 << n);
}

void clear_bit(unsigned char *reg, int n) {
    *reg &= ~(1 << n);
}

void toggle_bit(unsigned char *reg, int n) {
    *reg ^= (1 << n);
}

int check_bit(unsigned char *reg, int n) {
    return (*reg & (1 << n)) != 0;
}

int main() {
    unsigned char reg = 0;

    set_bit(&reg, 3);
    printf("After set bit 3: %d\n", reg);

    clear_bit(&reg, 3);
    printf("After clear bit 3: %d\n", reg);

    set_bit(&reg, 3);
    toggle_bit(&reg, 3);
    printf("After toggle bit 3: %d\n", reg);

    set_bit(&reg, 3);
    int result = check_bit(&reg, 3);
    printf("Bit 3 is set: %d\n", result);

    // Hardware register simulation
    unsigned char hw_reg = 0;
    set_bit(&hw_reg, 5);   // ADC enable
    set_bit(&hw_reg, 4);   // ADC start
    set_bit(&hw_reg, 1);   // LED1 on
    clear_bit(&hw_reg, 1); // LED1 off
    printf("ADC enabled: %d\n", check_bit(&hw_reg, 5));

    return 0;
}