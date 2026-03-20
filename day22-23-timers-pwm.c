#include <stdio.h>
#include <stdint.h>

#define CLOCK_HZ    24000000  // 24MHz
#define PRESCALER   24000     // divide by 24000
#define TIMER_HZ    (CLOCK_HZ / PRESCALER)  // 1000Hz = 1ms per tick

uint32_t timer_count = 0;

void timer_tick() {
    timer_count++;
}
void pwm_simulate(int duty_cycle, int period) {
    int high_time = (duty_cycle * period) / 100;
    int low_time  = period - high_time;
    
    printf("Period: %d ms\n", period);
    printf("HIGH for: %d ms\n", high_time);
    printf("LOW for:  %d ms\n", low_time);
    printf("Duty cycle: %d%%\n", duty_cycle);
    printf("---\n");
}
int ms_elapsed(uint32_t ms) {
    return timer_count >= ms;
}
int temp_to_pwm(int temp, int min_temp, int max_temp) {
    if (temp <= min_temp) return 0;
    if (temp >= max_temp) return 100;
    return ((temp - min_temp) * 100) / (max_temp - min_temp);
}
int main() {
    // simulate 500 timer ticks = 500ms
    for (int i = 0; i < 500; i++) {
        timer_tick();
    }

    
    if (ms_elapsed(500)) {
        printf("500ms elapsed! Count = %d\n", timer_count);
    }

    if (ms_elapsed(1000)) {
        printf("1000ms elapsed!\n");
    } else {
        printf("1000ms not yet reached\n");
    }
printf("Cold (25 degrees):\n");
    pwm_simulate(10, 100);   // 10% duty cycle
    
    printf("Warm (35 degrees):\n");
    pwm_simulate(50, 100);   // 50% duty cycle
    
    printf("Hot (45 degrees):\n");
    pwm_simulate(90, 100);   // 90% duty cycle

    printf("20C -> %d%%\n", temp_to_pwm(20, 20, 50));
printf("35C -> %d%%\n", temp_to_pwm(35, 20, 50));
printf("40C -> %d%%\n", temp_to_pwm(40, 20, 50));
printf("50C -> %d%%\n", temp_to_pwm(50, 20, 50));
    
    return 0;
}