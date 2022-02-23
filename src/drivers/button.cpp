#include "Arduino.h"
#include "button.hh"

namespace synth{
    /** 
     * Executes the callback function when the button is pressed.
     * The callback is executed on negative edge.
     * 
     * @param buttonCallback the callback function
    */
    bool Button::getButton(){
        int button_value = digitalRead(_pin);

        if(_state == BTN_NEUTRAL){
            if(button_value == LOW){
                _state = BTN_PRESSED;
            }

            return false;
        }
        else if(button_value == HIGH){
            _state = BTN_NEUTRAL;

            return true;
        }
    }
}