/*
 * Lab1.c
 *
 * Created: 2/3/2021 8:03:07 PM
 * Author : John
 */ 

#define F_CPU 16000000UL  // 16MHz clock from the debug processor
#define lighton PORTB |= (1<<PORTB5)
#define lightoff PORTB &= ~(1<<PORTB5)
#include <avr/io.h>
#include <util/delay.h>

//Name: JOHN SADIQ
//RedID: 825764388





int main(void)
{
    /* Replace with your application code */
    DDRB |= (1<<DDB5);  //0x20 (hex) // Set port bit B5 in data direction register to 1: an OUTput
    while(1){
		
// J
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms				
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms		
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms		
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms		
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms		
		
		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
		
//O
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms		

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms		

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
			
//H
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms			
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
			
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms			

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
			
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms			

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
			
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms	
		
		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms		
			
//N
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms			
		
		//space between words
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(1400);  //delay 1400ms
		
//S
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
				
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
				
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
				
		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
		
//A
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
			
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms
		
		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
			
//D
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
				
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms	

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
		
//I
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
		
//Q
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
				
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
			
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms			
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms		

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
			
			
//8
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms		

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms			

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms	
			
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms		
			
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
				
		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
		
//2
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms		

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms
		
		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms

//5
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms	
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms		

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms			
			
//7
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms

//6

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
			
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms

//4
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms

//3			
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms
		
		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms
		
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms
	
//8

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms	
	
//8
		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dash
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(600);  //delay 600ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between dot and dash
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(200);  //delay 200ms

		//dot
			lighton; //Set port bit B5 to 1 to turn on the LED
			_delay_ms(200);  //delay 200ms

		//space between letters
			lightoff; //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(600);  //delay 600ms	
    }
    
}

