/**
******************************************************************************
* @author	SoyoonChoi
* @Mod		2024-09-12
* @brief	Embedded Controller:  LAB Digital In/Out
*					 - Toggle LED LD2 by Button B1 pressing
* 
******************************************************************************
*/

#include "stm32f4xx.h"
#include "ecRCC2.h"
#include "ecGPIO2.h"

PinName_t LED_pin = PA_5;
PinName_t button_pin = PC_13;

void setup(void);
	
int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	
	int button_state =HIGH;
	int button_last = HIGH ;
	int led_state = LOW;
	
	setup();
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		
		button_state = GPIO_read(button_pin);
		
		if(button_state == LOW && button_last ==HIGH){
			led_state = !led_state;
			GPIO_write(LED_pin, led_state);
		}
		button_state = button_last;
	}
}


// Initialiization 
void setup(void)
{
	RCC_HSI_init();	
	GPIO_init(button_pin, INPUT);  // calls RCC_GPIOC_enable()
	GPIO_init(LED_pin, OUTPUT);    // calls RCC_GPIOA_enable()
	GPIO_pupd(LED_pin, EC_PU);
	GPIO_otype(LED_pin, 0);
}