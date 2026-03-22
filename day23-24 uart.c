#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BAUD_RATE 115200
#define CLOCK_HZ  24000000

uint32_t calculate_baud_divider(uint32_t clock, uint32_t baud) {
    return clock / baud;
}

void uart_send_byte(uint8_t data) {
    printf("[UART TX] Sending: 0x%02X ('%c')\n", data, data);
    printf("  Start bit: 0\n");
    for (int i = 0; i < 8; i++) {
        printf("  Bit %d: %d\n", i, (data >> i) & 1);
    }
    printf("  Stop bit: 1\n\n");
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send_byte(*str++);
    }
}

int main() {
    uint32_t divider = calculate_baud_divider(CLOCK_HZ, BAUD_RATE);
    printf("Clock: %d Hz\n", CLOCK_HZ);
    printf("Baud rate: %d\n", BAUD_RATE);
    printf("Baud divider: %d\n\n", divider);

    uart_send_byte('A');

    printf("Sending 'Hi':\n\n");
    uart_send_string("Hi");

    return 0;
}