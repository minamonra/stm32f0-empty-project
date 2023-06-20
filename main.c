#include "stm32f0xx.h"
#include "f0lib/f0lib.h"

void main(void) {

	// setup a status LED
	gpio_setup(PB3, OUTPUT, PUSH_PULL, FIFTY_MHZ, NO_PULL, AF0);

	// PWM ~19,2 kHz 50/50 0...50, PB6
	timer_pwm_setup(TIM16, 50, 50, ONE_CHANNEL, PB6);
	timer_pwm_period(TIM16, 50);
	timer_pwm_value(TIM16, CH1, 25);

	// PWM ~19,2 kHz 50/50 0...50, PB7
	timer_pwm_setup(TIM17, 50, 50, ONE_CHANNEL, PB7);
	timer_pwm_period(TIM17, 50);
	timer_pwm_value(TIM17, CH1, 25);
	
	while(1) {
		gpio_high(PC2);
		gpio_low(PC2);
	}
}
