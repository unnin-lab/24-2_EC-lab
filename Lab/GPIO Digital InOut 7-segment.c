
/**
******************************************************************************
* @author  HGU
* @Mod		 2024-09-23 by Soyoon Choi 	
* @brief   Embedded Controller:  Tutorial Digital In/Out 7-segment Display
* 
******************************************************************************
*/
#include "stm32f4xx.h"
#include "ecGPIO2.h"
#include "ecRCC2.h"


void setup(void);
	
int main(void) { 
	// Initialiization --------------------------------------------------------
	setup();
	unsigned int cnt = 0;
	
	// Inifinite Loop ----------------------------------------------------------
	
	
	
	while(1){
		sevensegment_display(cnt % 10);
		if(GPIO_read(BUTTON_PIN) == 0) 
				cnt++; 
        if (cnt > 9) cnt = 0;

		for(int i = 0; i < 500000;i++){}  // delay_ms(500);
	}
}


// Initialiization 
void setup(void)
{
	RCC_HSI_init();	
	GPIO_init(BUTTON_PIN, INPUT); // calls RCC_GPIOC_enable()
	sevensegment_display_init(PA_7, PB_6, PC_7, PA_9);  // Decoder input A,B,C,D
	
}
