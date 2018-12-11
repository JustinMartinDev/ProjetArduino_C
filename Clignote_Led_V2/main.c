#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

void setup (void);
void blinkMyLed();

void setup (void)
{
	
	DDRD = 0b01110000; // broche D4
	PORTD = 0b00000000; //Port D for D4 
}

int main (void)
{
	setup();
	while(1){	
		blinkMyLed();
	}
	
	return 0;
}

void blinkMyLed() {
		PORTD |= 0b00010000; //allumer only D4
		_delay_ms (250);
		PORTD |= 0b00100000; //allumer only D5
		_delay_ms (250);
		PORTD |= 0b01000000; //allumer only D6
		_delay_ms (250);
		
		
		PORTD &= 0b11101111; //eteindre D4
		_delay_ms (250);
		PORTD &= 0b11011111; //eteindre D5
		_delay_ms (250);
		PORTD &= 0b10111111; //eteindre D6
		_delay_ms (250);
}