#ifndef MBED_BUZZER
#define MBED_BUZZER

#include "mbed.h"

class Buzzer {
    public:
        Buzzer(PinName br_buzzer);
        void start();
        void stop();

    private:
        PwmOut _buzzer;
};
#endif