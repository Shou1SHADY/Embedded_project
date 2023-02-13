#include "DIO.h"
#include "Stopwatch.h"
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
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
#include "Calculator_Base.h"



#define sw1_on (DIO_ReadPin(&GPIO_PORTF_DATA_R,4) & 0x1)==0x0

#define sw2_on (DIO_ReadPin(&GPIO_PORTF_DATA_R,0) & 0x1)==0x0


#define sw1_off (DIO_ReadPin(&GPIO_PORTF_DATA_R,4) & 0x1)!=0x0

#define sw2_off (DIO_ReadPin(&GPIO_PORTF_DATA_R,0) & 0x1)!=0x0
/****************************************************
*  @file    Stopwatch.c
*
*  Functions to
*
*  @author  Group Alpha
*
*  @date    9/12/2018 10:30 PM
*
****************************************************/ 

bool isEnter1 = true ; 
/*
void Timerdelay (float delay){
  //unsigned long ulPeriod;
  
  float ulPeriod ; 
TimerConfigure(TIMER0_BASE, TIMER_CFG_ONE_SHOT);
////TimerConfigure(TIMER0_BASE, TIMER_CFG_32_BIT_PER);
 ulPeriod = (SysCtlClockGet()  *delay);
 TimerLoadSet(TIMER0_BASE, TIMER_A, ulPeriod -1);
 IntEnable(INT_TIMER0A);
 //TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
 IntMasterEnable();
 TimerEnable(TIMER0_BASE, TIMER_A);
// TimerIntRegister(TIMER0_BASE, TIMER_A, Timer0IntHandler);
}
*/
void start_stopwatch (void)
{
  LCD_command(CLEAR_DISPLAY);
  LCD_setcursorRowCol(2, 0);
  LCD_printString("Start-> Hold Key");
  LCD_setcursorRowCol(3, 0);
  LCD_printString("Reset-> Press *");
}

/**
*  @detailed  
*
*  @param     
*/







void 
KeyInt (void)
{
  //char c = '0' ;
  //while (c == '0'){
  //c=  
  while (1){
 char key__1 = keypad_getkey() ; 
 if (key__1 == '1'){
 break ; 
 }
  
  }
 // while (((GPIO_PORTE_DATA_R & 0x1E) & (1U << 1)) !=1)  {} 
  /*
  bool flag_Int = false ; 
  while(1)
  {
    for(int i = 0; i < 4; i++)                        //columns traverse
    {
      GPIO_PORTC_DATA_R = (1U << i+4);
      delay_us(2);
      for(int j = 0; j < 4; j++)                     //raws traverse
      {
        /////////////////////////////
        
        ///////////////////////////////
        if((GPIO_PORTE_DATA_R & 0x1E) & (1U << j+1)){
          flag_Int = true; 
        break;
        }
      
      }
        if (flag_Int == true){
        break ; 
        }
    }
     if (flag_Int == true){
        break ; 
        }
  }
  //} 
*/
  /*
 if (switch_flag == true) {
   TimerDisable(TIMER0_BASE, TIMER_A);
     switch_flag = false;
  } else {
    TimerEnable(TIMER0_BASE, TIMER_A);
    switch_flag = true;
  }
*/
 
  GPIOIntClear(GPIO_PORTE_BASE,GPIO_INT_PIN_3);
  GPIOIntClear(GPIO_PORTE_BASE,GPIO_INT_PIN_4);
}


void
Timer1IntHandler(void)
{  

 if ( sw1_on && sw2_off )
  {
  //Delay(); 
 //   LCD_command(CLEAR_DISPLAY);
//delay_ms(300);
    states_2=0;
   //  LCD_command(CLEAR_DISPLAY);
       
    while (sw1_on && sw2_off) ;
    
  }
  else if  ( sw1_off && sw2_on )
  {
    states_2=1;
  //Delay(); 
 //   LCD_command(CLEAR_DISPLAY);
//delay_ms(300);
   //  LCD_command(CLEAR_DISPLAY);
       
    while (sw1_off && sw2_on) ;
    
  }   
 
 
 mode_flag=true;
 
 
  GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_0);
   GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_4);
/*
  
  isEnter1 =false ;
  
  while (sw1_on || sw2_on){
  states() ;
  }
//states() ; 

   // DIO_WritePin (PortF , 2, 0);
   //DIO_ReadPin(PortF,0x04) ==1 ; 
 

   GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_0);
  // GPIOIntDisable(GPIO_PORTF_BASE,GPIO_INT_PIN_4 | GPIO_INT_PIN_0 );
 GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_4);
 
  isEnter1 =true ;
     */
}




void Timerdelay( uint32 delayX){
  unsigned long ulPeriod;
TimerConfigure(TIMER0_BASE, TIMER_CFG_ONE_SHOT);
//TimerConfigure(TIMER0_BASE, TIMER_CFG_32_BIT_PER);
 ulPeriod = (SysCtlClockGet()  *delayX);
 TimerLoadSet(TIMER0_BASE, TIMER_A, ulPeriod -1);
 IntEnable(INT_TIMER0A);
 TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
 IntMasterEnable();
 TimerEnable(TIMER0_BASE, TIMER_A);
 //TimerIntRegister(TIMER0_BASE, TIMER_A, Timer0IntHandler);
}









void stopwatch(void)
{
  /////////////////////
   SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
 //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
 // GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
 SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
 float DelayS = 1 ; 
 
 
 


  
  switch_flag = true ;
  
  states_2=2;
  mode_flag=false;
 states_1 =2;
  // states_1=2;
  /////////////////////////
     //
  MAP_IntDisable(INT_GPIOF);
   
 
   MAP_IntMasterDisable();
//
    MAP_IntEnable(INT_GPIOF);
 //
     IntMasterEnable();
     __asm("CPSIE I"); 
      GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_4) ;
       GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_0) ;
     //MAP_IntEnable(INT_GPIOF);
 //GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_4) ;
                                       if (isEnter1 == true ){
  //GPIOIntRegisterPin(GPIO_PORTF_BASE ,GPIO_INT_PIN_4,Timer0IntHandler) ;  
 GPIOIntRegister(GPIO_PORTF_BASE,Timer1IntHandler); 
//GPIOIntRegisterPin(GPIO_PORTF_BASE,GPIO_INT_PIN_0,Timer1IntHandler);

                                                     }
                                       
                                       
  ////////////////////////????????????
 
  MAP_IntEnable(INT_GPIOE);
 __asm("CPSIE I") ;

 GPIOIntEnable(GPIO_PORTE_BASE,
GPIO_INT_PIN_4 ) ;
GPIOIntEnable(GPIO_PORTE_BASE,
GPIO_INT_PIN_3) ;
//GPIOIntEnable(GPIO_PORTE_BASE,
//GPIO_INT_PIN_2 ) ;
//GPIOIntEnable(GPIO_PORTE_BASE,
//GPIO_INT_PIN_3 ) ;
  GPIOIntRegister(GPIO_PORTE_BASE,
KeyInt);  
 
 
 
 
 
  ////////////////////////                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
   if (states_2==0){
                    loading();
                    calc();
                  }
  else if(states_2==1){
  loading();
 // trig();
  }
isEnter1 = true ; 
  ////////////////////
  start_stopwatch();
  int h = 0, m = 0, s = 0, ss = 0;
  //////////////////////////////////
     char c= '0';
     
  while (c == '0'){
     c= keypad_getkey();
        displayTime(h, m, s, ss);
  }
  
  while (1){
   
      ///////////////////////////////
  while(c == '5' )
  {
    while(h < 10)
    {
      while(m < 60)
      {
        while(s < 60)
        {
          while(ss < 100)
          {
            
            displayTime(h, m, s, ss);
            Timerdelay(DelayS) ; 
       //     delay_ms(10);
            ss++;
            //c= keypad_getkey();
           // char c= keypad_getkey();
       //     while (c =='4'){
        //    c= keypad_getkey();
         //   } 
            if(c == '.')
              break;
            else if (c=='f')
            {
          if (states_2==0)      {
                    loading();
                    calc();
                                }
          else if(states_2==1){
          loading();
        //  trig();
                               }
          }
          }
          s++;
          ss = 0;
//          LED_blueBlink(!x);
//          x = !x;
           //   char c= keypad_getkey();
           //   while (c =='4'){
           // c= keypad_getkey();
            //} 
            if(c == '.')
              break;
            else if (c=='f')
            {
          if (states_2==0)      {
                    loading();
                    calc();
                                }
          else if(states_2==1){
          loading();
         // trig();
                               }
          }
       //   while (c =='3'){} ;
           // else if (c != '.') {
            //  while (c != '.'){} ; 
           // } 
          
        }
        m++;
        s = 0;
        ss = 0;
           // char c= keypad_getkey();
       //    while (c =='4'){
         //   c= keypad_getkey();
          //  } 
            if(c == '.')
              break;
            else if (c=='f')
            {
          if (states_2==0)      {
                    loading();
                    calc();
                                }
          else if(states_2==1){
          loading();
          //trig();
                               }
          }
      }
      h++;
      m = 0;
      s = 0;
      ss = 0;
         // char c= keypad_getkey();
         // while (c =='4'){
           // c= keypad_getkey();
            //} 
            if(c == '.')
              break;
            else if (c=='f')
            {
          if (states_2==0)      {
                    loading();
                    calc();
                                }
          else if(states_2==1){
          loading();
      //    trig();
                               }
          }
    }
      if(c == '.')
              break;
  }
    h = 0;
    m = 0;
    s = 0;
    ss = 0;
    fini_stopwatch();
 
  }
}


void fini_stopwatch(void)
{
  LCD_command(CLEAR_DISPLAY);
  start_stopwatch();
}