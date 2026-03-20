#include <stdio.h>
#include <stdint.h>

volatile int flag = 0;

void ISR_handler() {
    flag = 1;
}

int main() {
    printf("Waiting for flag...\n");
    ISR_handler();
    if (flag == 1) {
        printf("Flag was set!\n");
    }
    return 0;
}