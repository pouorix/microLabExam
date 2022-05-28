/*
Danial Bazmandeh
97521135
*/

#include <mega32.h>
#include <delay.h>
#include <stdio.h>


void usart_send_string(char *str);
    // Declare your global variables here
    char a;
    int count = 0;
    int show_flag = 0;
    char numbers_array[6];
 
    void delay() {
        TCCR0 = (1 << CS02) | (1 << CS00);
        TCNT0 = 251;
        while ((TIFR & (1 << TOV0)) == 0);
        TIFR = (1 << TOV0);
    }

unsigned char number (unsigned char digit) {
    if (digit == 0) {
        return 0x3F;
    }
    if (digit == 1) {
        return 0x06;
    }
    if (digit == 2) {
        return 0x5B;
    }
    if (digit == 3) {
        return 0x4F;
    }
    if (digit == 4) {
        return 0x66;
    }
    if (digit == 5) {
        return 0x6D;
    }
    if (digit == 6) {
        return 0x7D;
    }
    if (digit == 7) {
        return 0x07;
    }
    if (digit == 8) {
        return 0x7F;
    }
    if (digit == 9) {
        return 0x6F;
    }
}

void set_number(char c){
    if (c == '0'){
        PORTC = number(0);
    }
    if (c == '1'){
        PORTC = number(1);
    }
    if (c == '2'){
        PORTC = number(2);
    }
    if (c == '3'){
        PORTC = number(3);
    }
    if (c == '4'){
        PORTC = number(4);
    }
    if (c == '5'){
        PORTC = number(5);
    }
    if (c == '6'){
        PORTC = number(6);
    }
    if (c == '7'){
        PORTC = number(7);
    } 
    if (c == '8'){
        PORTC = number(8);
    }
    if (c == '9'){
        PORTC = number(9);
    }
}

void main(void) {
    // Declare your local variables here

    // Input/Output Ports initialization
    // Port A initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
    PORTA = 0x00;
    DDRA = 0x00;

    // Port B initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
    PORTB = 0x0ff;
    DDRB = 0xff;

    // Port C initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
    PORTC = 0xFF;
    DDRC = 0xFF;

    // Port D initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
    PORTD = 0x00;
    DDRD = 0x00;

    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: Timer 0 Stopped
    // Mode: Normal top=0xFF
    // OC0 output: Disconnected
    TCCR0 = 0x00;
    TCNT0 = 0x00;
    OCR0 = 0x00;

    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: Timer1 Stopped
    // Mode: Normal top=0xFFFF
    // OC1A output: Discon.
    // OC1B output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
    TCCR1A = 0x00;
    TCCR1B = 0x00;
    TCNT1H = 0x00;
    TCNT1L = 0x00;
    ICR1H = 0x00;
    ICR1L = 0x00;
    OCR1AH = 0x00;
    OCR1AL = 0x00;
    OCR1BH = 0x00;
    OCR1BL = 0x00;

    // Timer/Counter 2 initialization
    // Clock source: System Clock
    // Clock value: Timer2 Stopped
    // Mode: Normal top=0xFF
    // OC2 output: Disconnected
    ASSR = 0x00;
    TCCR2 = 0x00;
    TCNT2 = 0x00;
    OCR2 = 0x00;

    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: Off
    // INT2: Off
    MCUCR = 0x00;
    MCUCSR = 0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK = 0x00;
    
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA = 0x00;
    UCSRB = 0x18;
    UCSRC = 0x86;
    UBRRH = 0x00;
    UBRRL = 0x33;

    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR = 0x80;
    SFIOR = 0x00;

    // ADC initialization
    // ADC disabled
    ADCSRA = 0x00;

    // SPI initialization
    // SPI disabled
    SPCR = 0x00;

    // TWI initialization
    // TWI disabled
    TWCR = 0x00;

    // Alphanumeric LCD initialization
    // Connections are specified in the
    // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
    // RS - PORTC Bit 0
    // RD - PORTC Bit 1
    // EN - PORTC Bit 2
    // D4 - PORTC Bit 4
    // D5 - PORTC Bit 5
    // D6 - PORTC Bit 6
    // D7 - PORTC Bit 7
    while (1) {
        a = getchar();
        
        numbers_array[count] = a; 
        if (count == 6){
            count = 0;  
        }   
        count++;
            
        if (count > 0) {
            PORTB = 0b10111111;
            set_number(numbers_array[0]);
        }
            
        if (count > 1) {
            PORTB = 0b11011111;
            set_number(numbers_array[1]);
        }
            
        if (count > 2) {
            PORTB = 0b11101111;
            set_number(numbers_array[2]);
        } 
            
        if (count > 3) {
            PORTB = 0b11110111;
            set_number(numbers_array[3]);
        } 
            
        if (count > 4) {
            PORTB = 0b11111011;
            set_number(numbers_array[4]);
        } 
            
         if (count > 5) {
            PORTB = 0b11111101;
            set_number(numbers_array[5]);
        }
    } 
} 
