#include <stdio.h>
#include <stdint.h>

// ── SPI SIMULATION ──
void spi_transfer(uint8_t *mosi_data, uint8_t *miso_data, int len) {
    printf("CS LOW -> slave selected\n");
    for (int i = 0; i < len; i++) {
        printf("MOSI: 0x%02X -> MISO: 0x%02X\n", mosi_data[i], miso_data[i]);
    }
    printf("CS HIGH -> slave deselected\n\n");
}

// ── I2C SIMULATION ──
void i2c_write(uint8_t addr, uint8_t reg, uint8_t data) {
    printf("START\n");
    printf("Address: 0x%02X + WRITE -> ACK\n", addr);
    printf("Register: 0x%02X -> ACK\n", reg);
    printf("Data: 0x%02X -> ACK\n", data);
    printf("STOP\n\n");
}

uint8_t i2c_read(uint8_t addr, uint8_t reg) {
    printf("START\n");
    printf("Address: 0x%02X + WRITE -> ACK\n", addr);
    printf("Register: 0x%02X -> ACK\n", reg);
    printf("START (repeated)\n");
    printf("Address: 0x%02X + READ -> ACK\n", addr);
    uint8_t data = 0x42;
    printf("Data: 0x%02X -> NACK\n", data);
    printf("STOP\n\n");
    return data;
}

int main() {
    // SPI example
    printf("=== SPI Transfer ===\n");
    uint8_t send[] = {0x01, 0x02, 0x03};
    uint8_t recv[] = {0xAA, 0xBB, 0xCC};
    spi_transfer(send, recv, 3);

    // I2C write example
    printf("=== I2C Write ===\n");
    i2c_write(0x48, 0x01, 0xFF);

    // I2C read example
    printf("=== I2C Read ===\n");
    uint8_t result = i2c_read(0x48, 0x00);
    printf("Read value: 0x%02X\n", result);

    return 0;
}
