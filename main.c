#include "Calculator.h"
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
#include "Basic_Calc.h"



////////////////





  
int main()
{
  /*  
     IntMasterEnable();
     __asm("CPSIE I"); 
      GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_4) ;
       GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_0) ;
     //MAP_IntEnable(INT_GPIOF);
 //GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_4) ;
if (isEnter == true ){
  //GPIOIntRegisterPin(GPIO_PORTF_BASE ,GPIO_INT_PIN_4,Timer0IntHandler) ;  
 GPIOIntRegister(GPIO_PORTF_BASE,Timer0IntHandler); 
//GPIOIntRegisterPin(GPIO_PORTF_BASE,GPIO_INT_PIN_0,Timer1IntHandler);

}
isEnter = true ; 
*/
  mode_flag=false;
  calculator_Init();
  calculator_welcomeMsg();
/////////////////
     //  __asm("CPSIE I") ; 
 //GPIOIntEnable(GPIO_PORTF_BASE,
//GPIO_INT_PIN_4) ;
//IntMasterEnable();

//  while (1){
  getStarted();
//}
///////////////////
  return 0;
}