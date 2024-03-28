#include "mbed.h"

class Buzzer {
    public:
        Buzzer(PinName br_buzzer):
            _buzzer(br_buzzer){
                _buzzer.period_ms(1);
                _buzzer.write(0.0);
            }

        void start(){
            _buzzer.write(0.5);
        }

        void stop(){
            _buzzer.write(0.0);
        }

    private:
        PwmOut _buzzer;
};

Buzzer mybuzzer(A1);

/* CONST */
#define WAIT_2_MS 2
#define WAIT_100_MS 100
#define WAIT_2000_MS 2000

int main(){
    printf("Hello world\n");

    while (true) {
        mybuzzer.start();
        thread_sleep_for(WAIT_100_MS);

        mybuzzer.stop();
        thread_sleep_for(WAIT_2000_MS);

        thread_sleep_for(WAIT_2_MS);
    }
}