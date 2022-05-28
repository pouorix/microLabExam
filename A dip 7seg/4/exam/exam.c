/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 7/18/2020
Author  : Acer
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega32.h>
int counter , rem= 0, index;
char	hex[2];
#include <delay.h>
char HEXVALUE[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char code[] = { 0x3F, 0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F, 0x77,0x7C, 0x39 , 0x5E, 0x79, 0x71 }  ;
// Timer 0 output compare interrupt service routine
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
    counter++;
    if (counter == 2) 
        counter=0;

}

int i = 0;
int j = 0;
unsigned int number = 0;
int  tempDecimal ;
// Declare your global variables here

void main(void)
{
PORTC=0x00;
DDRC=0xFF;
DDRD=0xFF;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: CTC top=OCR0
// OC0 output: Disconnected
TCCR0=0x0C;
TCNT0=0x00;
OCR0=0x63;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x12;

// Global enable interrupts
#asm("sei")

while (1)
      {     
       int a = PINA;
       if(PINA.0 == 1)   
       {
        number += 1;
       }  
       
       if(PINA.1 == 1)   
       {
        number += 2;
       }  
       
       if(PINA.2 == 1)   
       {
        number += 4;
       }   
       
       if(PINA.3 == 1)   
       {
        number += 8;
       }  
       
       if(PINA.4 == 1)   
       {
        number += 16;
       } 
       
       if(PINA.5 == 1)   
       {
        number += 32;
       }  
       
       if(PINA.6 == 1)   
       {
        number += 64;
       }  
          
       if(PINA.7 == 1)   
       {
        number += 128;
       }  
      
      i = number %10;
      j = number / 10;   
      
      index = 0;
      
      tempDecimal = number;
      while(tempDecimal !=0)
    {
        rem = tempDecimal % 16;

        hex[index] = HEXVALUE[rem];

        tempDecimal /= 16;

        index++;
    }
    
      if(counter == 0)
      {
        PORTD = 0b11111110;
        //PORTC = code[j];    
         
        PORTC = code[hex[1]-48]; 
        if(hex[1] == 'A')
         PORTC = code[10];
        else if(hex[1] == 'B')
         PORTC = code[11];
         else if(hex[1] == 'C')
         PORTC = code[12];
         else if(hex[1] == 'D')
         PORTC = code[13];
         else if(hex[1] == 'E')
         PORTC = code[14];
         else if(hex[1] == 'F')
         PORTC = code[15]; 
        
          
         
      }
        
      else if(counter == 1)
      { 
        PORTD = 0b11111101;
        //PORTC = code[i];
          PORTC = code[hex[0]-48]; 
        if(hex[0] == 'A')
         PORTC = code[10];
        else if(hex[0] == 'B')
         PORTC = code[11];
         else if(hex[0] == 'C')
         PORTC = code[12];
         else if(hex[0] == 'D')
         PORTC = code[13];
         else if(hex[0] == 'E')
         PORTC = code[14];
         else if(hex[0] == 'F')
         PORTC = code[15]; 
      } 
         
       delay_ms(5);
       number = 0;  
       hex[0] = '';
       hex[1] = '';
      }
}
