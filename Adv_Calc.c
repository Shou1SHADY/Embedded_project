#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "LCD.h"
#include "delay.h"
#include "keypad.h"
#include "Calculator_Base.h"
#define sw1_on (DIO_ReadPin(&GPIO_PORTF_DATA_R,4) & 0x1)==0x0

#define sw2_on (DIO_ReadPin(&GPIO_PORTF_DATA_R,0) & 0x1)==0x0


#define sw1_off (DIO_ReadPin(&GPIO_PORTF_DATA_R,4) & 0x1)!=0x0

#define sw2_off (DIO_ReadPin(&GPIO_PORTF_DATA_R,0) & 0x1)!=0x0

int flag=0;
#define counter (*((volatile int *)0x2000074C))
int m , s ;


void start_timer(void){
  LCD_command(CURSOR_START_2ND_LINE);
  LCD_printString("00:00");
}
void
Timer(void)
{  
  if ( sw1_on && sw2_off )
  {
    states_2=2;
    while (sw1_on && sw2_off) ;
    
  }
  else if  ( sw1_off && sw2_on )
  {
    states_2=0;
    while (sw1_off && sw2_on) ;
    
  }   
  
  mode_flag=true;

  GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_0);
  GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_4);     
}

void TimerReal(void)
{
  if (counter != 0){
      printf("%d \n", counter);
    --counter;
    LCD_command(CLEAR_DISPLAY);
       LCD_setcursorRowCol(0,5); 
    LCD_printInt((counter/60)/10);
    LCD_setcursorRowCol(0,6); 
    LCD_printInt((counter/60)%10);
    LCD_setcursorRowCol(0,7); 
    LCD_printString(":");
    LCD_setcursorRowCol(0,8); 
    LCD_printInt((counter-(counter/60)*60)/10);
    LCD_setcursorRowCol(0,9); 
    LCD_printInt((counter-(counter/60)*60)%10);
    printf("%d \n", counter);
  }
  if (counter ==0)
    flag=0;
  
  // Clear the timer interrupt.
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
      
}

void Timer0_Init(void){
    // Enable the timer peripheral.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet());    
    TimerIntRegister(TIMER0_BASE, TIMER_A,TimerReal);
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    
    // Enable the timers.
   // TimerEnable(TIMER0_BASE, TIMER_A);
    
    //Enable global interrupts
     IntMasterEnable();

}


void timer(){
        
    
         //////////////////////////////////////////////////////////////////
               mode_flag=false;
  states_2 =1;
  states_1=1;
  
  
      MAP_IntEnable(INT_GPIOF);
     IntMasterEnable();
  __asm("CPSIE I");
         GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_4) ;
       GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_0) ;

 GPIOIntRegister(GPIO_PORTF_BASE,Timer); 
         

 Timer0_Init();
 while (keypad_getkey()==0){
    if (keypad_getkey() =='f'){
      if (states_2==0){
                    loading();
                   calc();
                  }
  else if(states_2==2){
  loading();
  stopwatch();
  }
         }
 }
 
 while(1){
   int m1 ,m2,s1,s2 ;
   
    while(flag ==0){
      start_timer();

      while (keypad_getkey()==0);  
              ///////////////////////////////////////////////////////
       /*
         if (keypad_getkey() =='f'){
      if (states_2==0){
                    loading();
                   calc();
                  }
  else if(states_2==2){
  loading();
  stopwatch();
  }
         }
         */
  ///////////////////////////////////////////////////////
      
       m1 = keypad_getkey() - 48;
 
      LCD_setcursorRowCol(1, 0);
      LCD_printInt(m1);
      delay_ms(250);
      
      while (keypad_getkey()==0); 
       m2 = keypad_getkey() - 48;  
      LCD_setcursorRowCol(1, 1);
      LCD_printInt(m2);
      m = m1*10+m2;
      delay_ms(250);
      
      while (keypad_getkey()==0); 
       s1 = keypad_getkey()- 48;
      LCD_setcursorRowCol(1, 3);
      LCD_printInt(s1);
      delay_ms(250);
      
      while (keypad_getkey()==0); 
       s2 = keypad_getkey() - 48;
      LCD_setcursorRowCol(1, 4);
      LCD_printInt(s2);
      s = s1*10+s2;
      
      flag =1;
      
      }
      if(flag == 1)
      {
      while (keypad_getkey()==0); 
      int key = keypad_getkey();
      if (key == '='){
  //      counter = m*60 + s ; 
      counter=((m1*10+m2)*60)+(s1*10+s2);
       printf("%d \n", counter);
      TimerEnable(TIMER0_BASE, TIMER_A);
      flag++;
      }
      }
}


  
}