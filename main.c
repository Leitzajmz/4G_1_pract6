#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(d)

int controlGndDisplay = 0x01;
int numero = 84;
int display[10] = {63,6,91,79,102,109,125,7,127,103};

void busDeControl();
void mostrarDatosDislpay(int numero);

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0x00); //PORTA puerto de salida
   set_tris_d(0x00); //PORTD puerto de salida
   int decenas, unidades;
   
   while(1){
      decenas = numero / 10;
      unidades = numero % 10;
      
      mostrarDatosDislpay(decenas);
      busDeControl();
      mostrarDatosDislpay(unidades);
      busDeControl();
      mostrarDatosDislpay(0x00);
      busDeControl();
      mostrarDatosDislpay(0x00);
      busDeControl();
   }
}

void mostrarDatosDislpay(int numero){
   output_a(controlGndDisplay);
   if (controlGndDisplay == 0x02)
      output_d(display[numero]+128);
   else
      output_d(display[numero]);
}

void busDeControl(){
   delay_ms(14);   
   controlGndDisplay <<= 0x01;
   if(controlGndDisplay == 0x10)
      controlGndDisplay = 0x01;
}




