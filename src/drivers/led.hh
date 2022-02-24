#ifndef SYNTH_LED_H_
#define SYNTH_LED_H_

#include "Arduino.h"

namespace synth {

    enum LEDState {
        LED_OFF,
        LED_ON,
        LED_BLINK_SLOW,
        LED_BLINK_FAST
    };

    // LEDs require a resistor before recieving current

    /** 
     * Class that controls LEDs
     * 
     * @param p The pin number that corresponds to this LED
     * @param fast_rate The rate at which the LED should blink in milliseconds when in fast blink mode
     * @param slow_rate The rate at which the LED should blink in milliseconds when in slow blink mode
    */
    class LED {
        public:
            LED (int p, int fast_rate = 200, int slow_rate = 1000){
                _pin = p;
                _blink_rate_fast = fast_rate;
                _blink_rate_slow = slow_rate;
                
                pinMode(_pin, OUTPUT);
            }
            ~LED (){}

            void glow();
            void toggle();
        
        private:
            int _pin;
            LEDState _state = LED_OFF;
            int _blink_rate_fast;
            int _blink_rate_slow;
            int _blink_value = LOW;
            unsigned long _last_update = 0;
            // unsigned long _delta_time = 0;

            void blink(int rate);
    };

}

#endif