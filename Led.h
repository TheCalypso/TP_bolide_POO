#ifndef MBED_LED
#define MBED_LED
#include "mbed.h"

class Led{
    public:
        Led(PinName pin);
        void clignoter();
        void arret();
        void marche();
        void flash(int periode_ms);

    private:
        DigitalOut _led;
        Ticker t_led;
        bool etat_led;
};
#endif