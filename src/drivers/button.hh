#ifndef SYNTH_BUTTON_H_
#define SYNTH_BUTTON_H_

#include "Arduino.h"

namespace synth {
    enum ButtonState {
        BTN_PRESSED,
        BTN_NEUTRAL
    };
    
    const int BTN_POLLING_RATE = 20;

    /** 
     * Class that controls buttons
     * 
     * @param p The pin number that corresponds to this button
    */
    class Button {
        public:
            Button (int p){
                _pin = p;
                
                pinMode(_pin, INPUT_PULLUP);
            }
            ~Button (){}

            bool getButton();
        
        private:
            int _pin;
            ButtonState _state = BTN_NEUTRAL;
            unsigned long _last_debounce_time = 0;
    };

}

#endif  // SYNTH_BUTTON_H_