#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

int contadorD, numeroD;
long contadorRetardo;
int display[10] = {63,6,91,79,102,109,125,7,127,103};

void mostrar();
#int_timer0
void timer0(){
   contadorD++;
}
void main (void){
   setup_oscillator(OSC_16MHZ);
   setup_timer_0(RTCC_INTERNAL |RTCC_DIV_128 | T0_8_BIT);
   enable_interrupts(int_timer0);
   enable_interrupts(GLOBAL);
   
   set_tris_d(0x00); //PORTD salida
   set_tris_e(0x00);//PORTE salida
   set_tris_a(0x00);
   int indiceD = 0x00;
   numeroD = 0;
   while(1){
      numeroD = 0;
      while (numeroD < 100){
         numeroD++;
         if(contadorD > 122 ){
            if(indiceD > 9)
               indiceD = 0x00;
            mostrar();
            contadorD = 0x00;
         }
      }
   }
}

void mostrar(){
   int unidades = 0x00, decenas = 0x00;
   decenas = numeroD / 10;
   unidades = numeroD % 10;
   output_d(display[5]);
   output_a(0x01);
   delay_ms(1);
   output_d(display[4]);
   output_a(0x02);
   delay_ms(1);
}
