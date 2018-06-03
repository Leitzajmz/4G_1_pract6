#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(e)
int controlDisplay = 0x01;
int variableSensada = 0x00;
void busDeControl();

#int_ext
void ISR_RB(){
   variableSensada++;
}
void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0x00); //PORTA salida
   set_tris_b(0x01); // PIN_B4 entrada
   set_tris_e(0x00);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   ext_int_edge(L_TO_H); 
   
   while(1){
      if (variableSensada == 0x01){
         output_e(0x01);
      }
      else if (variableSensada == 0x02){
         output_e(0x02);
         variableSensada = 0x00;
      }
      //busDeControl();
   }
}

void busDeControl(){

   output_a(controlDisplay);
   controlDisplay <<= 0x01;
   delay_ms(50);
   if(controlDisplay == 0x10)
      controlDisplay = 0x01;
}


