#include "Arduino.h"
#include "button.hh"
#include "../core/time.hh"

namespace synth{
    /** 
     * Executes the callback function when the button is pressed.
     * The callback is executed on negative edge.
     * 
     * @param buttonCallback the callback function
    */
    bool Button::getButton(){
        unsigned long d_time = Time::deltaTime();

        if(d_time - _last_debounce_time >= _debounce_rate){
            _last_debounce_time = d_time;
            int button_value = digitalRead(_pin);

            if(_state == BTN_NEUTRAL && button_value == LOW){
                _state = BTN_PRESSED;

                return false;
            }
            else if(_state == BTN_PRESSED && button_value == HIGH){
                _state = BTN_NEUTRAL;

                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
}