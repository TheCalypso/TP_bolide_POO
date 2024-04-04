#include "Bargraph8.h"
#include "mbed.h"

Bargraph8::Bargraph8(PinName pin1, PinName pin2, PinName pin3, PinName pin4, PinName pin5, PinName pin6, PinName pin7, PinName pin8):
    _bargraph(pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8){}

void Bargraph8::display(float value){
    if(value < 10000){
        _bargraph.write(0xFF);
    }
    if(value > 10000 && value < 20000){
        _bargraph.write(0xE7);
    }
    if(value > 20000 && value < 30000){
        _bargraph.write(0xC3);
    }
    if(value > 30000 && value < 40000) {
        _bargraph.write(0x81);
    }
    if(value > 40000){
        _bargraph.write(0x00);
    }
}