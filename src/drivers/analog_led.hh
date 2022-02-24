#ifndef SYNTH_ANALOG_LED_H_
#define SYNTH_ANALOG_LED_H_

#include "Arduino.h"
// #include "<stdexcept>"



namespace synth {
    using namespace std;

    enum AnalogLEDState {
        LED_OFF,
        LED_LOW,
        LED_MID,
        LED_HIGH
    };

    // LEDs require a resistor before recieving current

    /** 
     * Class that controls Analog LEDs, capable of dimming
     * 
     * @param p The pin number that corresponds to this LED
    */
    class AnalogLED {
        public:
            AnalogLED (int p, int low, int mid, int high){
                _pin = p;

                if(low < 0 || low > 255){
                    // TODO: Throw error
                    // std::invalid_argument("");
                }
               
                if(mid < 0 || mid > 255){
                    // TODO: Throw error
                    // std::invalid_argument("");
                }

                if(high < 0 || high > 255){
                    // TODO: Throw error
                    // std::invalid_argument("");
                }

                _low_value = low;
                _mid_value = mid;
                _high_value = high;
                
                pinMode(_pin, OUTPUT);
            }
            ~AnalogLED (){}

            void glow();
            void toggle();
        
        private:
            int _pin;
            AnalogLEDState _state = LED_OFF;
            int _low_value;
            int _mid_value;
            int _high_value;
    };

}

#endif