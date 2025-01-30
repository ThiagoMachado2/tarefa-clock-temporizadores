#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_AZUL 12
#define LED_VERMELHO 13
#define LED_VERDE 11
#define BUTTON 5

volatile bool button_pressed = false;
volatile int led_state = 0;

int64_t turn_off_callback(alarm_id_t id, void *user_data)
{
    if (led_state == 2)
    {
        gpio_put(LED_AZUL, 0);
        printf("Desligando LED azul\n");
    }
    else if (led_state == 1)
    {
        gpio_put(LED_VERMELHO, 0);
        printf("Desligando LED vermelho\n");
    }
    else if (led_state == 0)
    {
        gpio_put(LED_VERDE, 0);
        printf("Desligando LED verde\n");
        button_pressed = false;
        printf("Sistema aguardando botão...\n");
    }
    led_state--;
    if (led_state >= 0)
    {
        add_alarm_in_ms(3000, turn_off_callback, NULL, true);
    }
    return 0;
}

void gpio_callback(uint gpio, uint32_t events)
{
    if (!button_pressed)
    {
        button_pressed = true;
        led_state = 2;
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
        printf("Todos os LEDs acesos (azul, vermelho e verde)\n");
        add_alarm_in_ms(3000, turn_off_callback, NULL, true);
    }
}

int main()
{
    stdio_init_all();

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (1)
    {
        sleep_ms(1000);
    }
}
