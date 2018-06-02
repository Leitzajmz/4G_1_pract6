#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
   int controlDisplay = 0x01;
void busDeControl();

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0x00); //PORTA salida
   while(1){
      busDeControl();
   }
}

void busDeControl(){

   output_a(controlDisplay);
   controlDisplay <<= 0x01;
   delay_ms(50);
   if(controlDisplay == 0x10)
      controlDisplay = 0x01;
}


