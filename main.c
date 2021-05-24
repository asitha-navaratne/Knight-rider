#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR		DDRA			///< DDR of indicator LEDs.
#define LED_PORT	PORTA			///< Port of indicator LEDs.

int main(void){
	LED_DDR = 0xFF;
		
	while(1){
		for(uint8_t ledPin=0;ledPin!=8;ledPin++){
			LED_PORT = (1 << ledPin);							///< Shift 1 rightwards by a bit per turn.
			_delay_ms(100);
		}
		for(uint8_t ledPin=0;ledPin!=6;ledPin++){
			LED_PORT = (0x40 >> ledPin);						///< Shift 1 leftwards by a bit per turn.
			_delay_ms(100);
		}
	}
}