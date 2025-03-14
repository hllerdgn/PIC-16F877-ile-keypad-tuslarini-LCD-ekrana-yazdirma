#include <16f877.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(b)
#use fast_io(d)
#define use_portb_lcd TRUE
#include <lcd.c>


char tus(){
output_b(0x00);

output_high(pin_d0);
if(input(pin_d4)){delay_ms(20);printf(lcd_putc,"\f7");}
if(input(pin_d5)){delay_ms(20);printf(lcd_putc,"\f8");}
if(input(pin_d6)){delay_ms(20);printf(lcd_putc,"\f9");}
if(input(pin_d7)){delay_ms(20);printf(lcd_putc,"\f/");}
output_low(pin_d0);


output_high(pin_d1);
if(input(pin_d4)){delay_ms(20);printf(lcd_putc,"\f4");}
if(input(pin_d5)){delay_ms(20);printf(lcd_putc,"\f5");}
if(input(pin_d6)){delay_ms(20);printf(lcd_putc,"\f6");}
if(input(pin_d7)){delay_ms(20);printf(lcd_putc,"\fx");}
output_low(pin_d1);

output_high(pin_d2);
if(input(pin_d4)){delay_ms(20);printf(lcd_putc,"\f1");}
if(input(pin_d5)){delay_ms(20);printf(lcd_putc,"\f2");}
if(input(pin_d6)){delay_ms(20);printf(lcd_putc,"\f3");}
if(input(pin_d7)){delay_ms(20);printf(lcd_putc,"\f-");}
output_low(pin_d2);

output_high(pin_d3);
if(input(pin_d4)){delay_ms(20);printf(lcd_putc,"\fON");}
if(input(pin_d5)){delay_ms(20);printf(lcd_putc,"\f0");}
if(input(pin_d6)){delay_ms(20);printf(lcd_putc,"\f=");}
if(input(pin_d7)){delay_ms(20);printf(lcd_putc,"\f+");}
output_low(pin_d3);
return 0;


}

void main()
{


setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_OFF);
setup_CCP1(CCP_OFF);
setup_CCP2(CCP_OFF);

set_tris_b(0x00);
set_tris_d(0b11110000);
lcd_init();



while(true){
tus();
}
}
