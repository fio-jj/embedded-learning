#include <stdio.h>
#include <stdint.h>

typedef struct {
    int x;
    int y;
    int z;
} Point;

typedef struct {
    uint32_t LED0     : 1;
    uint32_t LED1     : 1;
    uint32_t LED2     : 1;
    uint32_t RESERVED : 3;
    uint32_t ADC_EN   : 1;
    uint32_t ADC_ST   : 1;
} GPIO_REG;

int main() {
    // Basic struct
    Point p;
    p.x = 10;
    p.y = 20;
    p.z = 30;
    printf("x = %d, y = %d, z = %d\n", p.x, p.y, p.z);
    printf("Size of Point: %d bytes\n", (int)sizeof(Point));

    // Bitfield struct
    GPIO_REG reg = {0};
    reg.ADC_EN = 1;
    reg.ADC_ST = 1;
    reg.LED1   = 1;
    reg.LED0   = 1;
    printf("LED0 before toggle: %d\n", reg.LED0);
    reg.LED0 = reg.LED0 ^ 1;
    printf("LED0 after toggle: %d\n", reg.LED0);
    reg.ADC_EN = 0;
    printf("ADC_EN: %d\n", reg.ADC_EN);
    printf("ADC_ST: %d\n", reg.ADC_ST);
    printf("LED1:   %d\n", reg.LED1);
    printf("Size of GPIO_REG: %d bytes\n", (int)sizeof(GPIO_REG));

    return 0;
}