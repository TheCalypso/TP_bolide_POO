#include "Buzzer.h"
#include "mbed.h"

Buzzer::Buzzer(PinName br_buzzer):
    _buzzer(br_buzzer){
        _buzzer.period_ms(1);
        _buzzer.write(0.0);
    };

void Buzzer::start(){
    _buzzer.write(0.5);
}

void Buzzer::stop(){
    _buzzer.write(0.0);
}