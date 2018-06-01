#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_c(0x00);
   int contador=0x80;//o la otra frecuencia, idk;

   while(1){
      output_c(contador);
      delay_ms(24);//o los que vayan a ser
      contador=contador>>1;
      if(contador==0)
         contador=0x80;
   }
}	
