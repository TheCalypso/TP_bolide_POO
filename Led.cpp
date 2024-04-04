#include "Led.h"
#include "mbed.h"

Led::Led(PinName pin): _led(pin){
}

void Led::clignoter(){
    etat_led = !etat_led;
    _led.write(etat_led);
}

void Led::arret(){
    t_led.detach();     
    etat_led = 0;
    _led.write(etat_led);
}

void Led::marche(){
    t_led.detach(); 
    etat_led = 1;
    _led.write(etat_led);
}

void Led::flash(int periode_ms){
    t_led.attach_us(callback(this, &Led::clignoter), periode_ms*500);
}