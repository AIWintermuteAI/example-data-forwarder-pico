#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define INTERVAL 25

int main() {
    stdio_init_all();
    adc_init();

    adc_gpio_init(26);
    adc_select_input(0);

    while (1) {
        float result = adc_read();
        printf("%f \n", result);
        sleep_ms(INTERVAL);
    }
}
