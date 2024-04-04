#include "mbed.h"
#include "Buzzer.h"
#include "Led.h"
#include "Bargraph8.h"

Buzzer mybuzzer(A1);

/* OUT */
Led led(A4);

/* INT */
AnalogIn potentiometre(A5);

/* VAR */
float charge;
Bargraph8 bargraph(D2,D3,D4,D5,D6,D7,D8,D9);

/* CONST */
#define WAIT_2_MS 2
#define WAIT_100_MS 100
#define WAIT_200_MS 200
#define WAIT_500_MS 500
#define WAIT_2000_MS 2000
#define WAIT_5000_MS 5000

void init_led(){
    led.flash(500);
    thread_sleep_for(WAIT_5000_MS);
    led.arret();
    thread_sleep_for(WAIT_5000_MS);
    led.marche();
    thread_sleep_for(WAIT_5000_MS);
    led.flash(WAIT_200_MS);
    thread_sleep_for(WAIT_5000_MS);
    led.arret();
}

void gestion_buzzer(){
    thread_sleep_for(WAIT_500_MS);
    mybuzzer.start();
    thread_sleep_for(WAIT_100_MS);
    mybuzzer.stop();
    thread_sleep_for(WAIT_2000_MS);
}

void gestion_bargraph(){
    charge = potentiometre.read_u16();
    bargraph.display(charge);
}

int main(){
    init_led();

    while (true) {
        //gestion_buzzer();
        gestion_bargraph();

        thread_sleep_for(WAIT_2_MS);
    }
}