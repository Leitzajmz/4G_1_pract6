#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(d)

int controlGndDisplay = 0x01;
int numero = 51;

void busDeControl();

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0x00); //PORTA puerto de salida
   set_tris_d(0x00); //PORTD puerto de salida
   int decenas, unidades;
   int display[10] = {63,6,91,79,102,109,125,7,127,103};
   while(1){
      decenas = numero / 10;
      unidades = numero % 10;
      output_a(0x08);
      output_d(display[5]);
      delay_ms(10);
      output_a(0x04);
      output_d(display[9]);
      delay_ms(10);
   }
}

/*void busDeControl(){
   output_a(controlGndDisplay);
   controlGndDisplay <<= 0x01;
   //delay_ms(10);
   if(controlGndDisplay == 0x10)
      controlGndDisplay = 0x01;
}*/


