#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

volatile int estado = 0;

bool repeating_timer_callback(struct repeating_timer *t)
{
    switch (estado)
    {
    case 0:
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 0);
        printf("LED VERMELHO ACESO\n");
        break;
    case 1:
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 0);
        printf("LED AMARELO ACESO\n");
        break;
    case 2:
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 1);
        printf("LED VERDE ACESO\n");
        break;
    }
    estado = (estado + 1) % 3;
    return true;
}

int main()
{
    stdio_init_all();

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (1)
    {
        sleep_ms(1000);
    }
}
