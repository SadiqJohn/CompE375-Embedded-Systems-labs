/*
 * Lab1.c
 *
 * Created: 9/8/2021 8:03:07 PM
 * Author : Bassam Potros
 */ 

#define F_CPU 16000000UL  // 16MHz clock from the debug processor
#define LEDon PORTB |= (1<<PORTB5)
#define LEDoff PORTB &= ~(1<<PORTB5)
#include <avr/io.h>
#include <util/delay.h>

//Name: BASSAM POTROS
//RedID: 825190243

char str[] = "BASSAM POTROS 825190243";

void point()
{
	LEDon; //Set port bit B5 to 1 to turn on the LED
	_delay_ms(200);  //delay 200ms
	
	LEDoff; //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(200);  //delay 200ms
}

void line()
{
	
	LEDon; //Set port bit B5 to 1 to turn on the LED
	_delay_ms(600);  //delay 600ms
	
	LEDoff; //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(200);  //delay 200ms

}

void spc() //space between words
{
	//after each point and line is a 200ms delay off, adding a 1200ms delay
	//will total in the 1400ms delay off we need between each word
	
	//space between letters
	LEDoff; //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(1200);  //delay 1200ms
	
	
}


int main(void)
{
    /* Replace with your application code */
    DDRB |= (1<<DDB5);  //0x20 (hex) // Set port bit B5 in data direction register to 1: an OUTput
    while(1){
		
		for(int i = 0; str[i] != '\0'; i++)
		{
			switch(str[i])
			{
				
				//Letters
				case'A': 'a':
					point(); line();
					break;
					
				case'B': 'b':
					line(); point(); point(); point();
					break;
					
				case'C': 'c':
					line(); point(); line(); point();
					break;
					
				case'D': 'd':
					line(); point(); point();
					break;
				
				case 'E': 'e':
					point();
					break;
				
				case 'F': 'f':
					point(); point(); line(); point();
					break;
					
				case 'G': 'g':
					line(); line(); point();
					break;
					
				case 'H': 'h':
					point(); point(); point(); point();
					break;
					
				case 'I': 'i':
					point(); point(); 
					break;
				
				case 'J': 'j':
					point(); line(); line(); line(); 
					break;
					
				case 'K': 'k':
					line(); point(); line(); 
					break;
					
				case 'L': 'l':
					point(); line(); point(); point(); 
					break;
					
				case 'M': 'm':
					line(); line(); 
					break;
				
				case 'N': 'n':
					line(); point();
					break;
					
				case 'O': 'o':
					line(); line(); line(); 
					break;
				
				case 'P': 'p':
					 point(); line(); line(); point();
					 break;
				
				case 'Q': 'q':
					 line(); line(); point(); line(); 
					 break;
				
				case 'R': 'r':
					 point(); line(); point();
					 break;
				
				case 'S': 's':
					point(); point(); point(); 
					break;
				
				case 'T': 't':
					line();
					break;
				
				case 'U': 'u':
					point(); point(); line(); line();
					break;
				
				case 'V': 'v': 
					point(); point(); point(); line(); 
					break;
					
				case 'W': 'w': 
					point(); line();  line();
					break;
				
				case 'X': 'x':
					line(); point(); point(); line();
					break;
					
				case 'Y': 'y':
					line(); point(); line(); line();
					break;
					
				case 'Z': 'z':
					line(); line(); point(); point();
					break;
					
				// Numbers
				case '1':
					point(); line(); line(); line(); line();
					break;
				
				case '2':
					point(); point(); line(); line(); line();
					break;
					
				case '3':
					point(); point(); point(); line(); line();
					break;fF
					
				case '4':
					point(); point(); point(); point(); line();
					break;
					
				case '5':
					point(); point(); point(); point(); point(); 
					break;
					
				case '6':
					line(); point(); point(); point(); point();
					break;
					
				case '7':
					line(); line(); point(); point(); point();
					break;F
				
				case '8':
					line(); line(); line(); point(); point(); 
					break;
				
				case '9':
					line(); line(); line(); line(); point();
					break;
					
				case '0':
					line(); line(); line(); line(); line(); 
					break;
				
				//space between words
				case ' ': 
				spc();
				break
					
			}
		}

    }
    
}

