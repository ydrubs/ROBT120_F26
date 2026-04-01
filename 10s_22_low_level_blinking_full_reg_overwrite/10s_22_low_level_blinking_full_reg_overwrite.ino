#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set PB4 (pin 12) as OUTPUT
    DDRB = 0b00010000;

    while (1)
    {
        // Turn ONLY PB4 ON (everything else OFF)
        PORTB = 0b00010000;
        _delay_ms(500);

        // Turn EVERYTHING OFF
        PORTB = 0b00000000;
        _delay_ms(500);
    }

    return 0;
}