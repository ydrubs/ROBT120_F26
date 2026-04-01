/*
 * -----------------------------------------------------------------------------
 * Description:
 *   This program blinks an LED connected to Arduino Digital Pin 12 (PB4)
 *   using direct register manipulation (low-level AVR programming).
 *
 *   - PB4 (Port B, Bit 4) is configured as an output by writing to DDRB.
 *   - The LED is toggled by setting and clearing PORTB bit 4.
 *   - A 500 ms delay is generated using _delay_ms() from <util/delay.h>.
 *
 *   Pin Mapping:
 *     Arduino Pin 12 → ATmega328P PB4 → PORTB bit 4
 *
 *   Clock Assumption:
 *     F_CPU must be defined correctly (typically 16 MHz for Arduino Uno).
 *     Example:
 *         #define F_CPU 16000000UL
 *
 *   This code runs in a standard C main() loop and does not use the
 *   Arduino framework (no setup() or loop()).
 * -----------------------------------------------------------------------------
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set PB4 (Arduino Digital Pin 12) as output
    DDRB |= (1 << DDB4);


    while (1)
    {
        // Set PB4 HIGH
        PORTB |= (1 << PORTB4);
        _delay_ms(1000);

        // Set PB4 LOW
        PORTB &= ~(1 << PORTB4);
        _delay_ms(1000);
    }

    return 0;
}