#ifndef MBED_BARGRAPHE
#define MBED_BARGRAPHE
#include "mbed.h"

class Bargraph8{
    public:
        Bargraph8(PinName, PinName, PinName, PinName, PinName, PinName, PinName, PinName);
        void display(float value);
    private:
        BusOut _bargraph;
};

#endif