#include <mega32.h>
#include <alcd.h>
#include <stdio.h>

unsigned char i;
void usart_send_string(char *str);
void main(void)
{
unsigned char input_char, counter = 0;
// Declare your local variables here
PORTA=0x00;
DDRA=0x00;

PORTB=0x00;
DDRB=0x00;

PORTC=0x00;
DDRC=0x00;

PORTD=0x00;
DDRD=0x00;


// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;


lcd_init(16);
lcd_clear();

while (1)
      {
        input_char = getchar(); 
        counter += 1;
        if (input_char == '8'){
            lcd_clear();
            lcd_gotoxy(0,0);
            lcd_puts("alireza safi");
            lcd_gotoxy(0,1);
            lcd_puts("alireza safi");
            counter = 28;
        }
        else if (input_char == '9'){
        
            usart_send_string("\n\r ===== alireza safi =====\n\r");   
        }
        else if (input_char == 'C')
        {
            lcd_clear();
            lcd_gotoxy(0,0);
            counter = 0;
            //usart_send_string("\n\r ===== Clear LCD =====\n\r");
        } 
        else {
            if ((input_char >= 0x61 && input_char <= 0x7A) || (input_char >= 0x41 && input_char <= 0x5A) || (input_char >= 0x30 && input_char <= 0x39)){
                if (counter == 33){
                    counter = 1;
                    lcd_clear();
                    lcd_gotoxy(0,0);
                }
                lcd_putchar(input_char);
                putchar(input_char);
            }
            
        }
        
             
      }
}
void usart_send_string(char *str)
{
    for(i=0;str[i];i++)
    putchar(str[i]);
}

