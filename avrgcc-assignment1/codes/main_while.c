#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd.h"

struct OurNode
{
    char x, y, z;
};


int main(void){
	struct OurNode p = {'0', '1', 'a' + 2}; // Creating 
    struct OurNode *q = &p;
    DDRB = 0xFF; // 1111.1111; set PB0-PB7 as outputs
    LCD_Init(); // Initializing LCD controller
    LCD_clear(); 
    LCD_Message(*((char *)q + 1)); // Displaying char in LCD
    _delay_ms(1000);
    LCD_clear();
    LCD_Message(*((char *)q + 2));
	return 0;
}
