#include "Arduino.h"
#include "analog_led.hh"

namespace synth{
    /** 
     * Cycles through illumination modes:
     * Off
     * Low
     * Medium
     * High
    */
    void AnalogLED::toggle(){
        switch(_state){
            default:
            case LED_OFF:
                _state = LED_LOW;
                break;
            case LED_LOW:
                _state = LED_MID;
                break;
            case LED_MID:
                _state = LED_HIGH;
                break;
            case LED_HIGH:
                _state = LED_OFF;
                break;
        }

        this->glow();
    }

    /** 
     * Illuminates the AnalogLED
    */
    void AnalogLED::glow(){
        switch (_state){
            default:
            case LED_OFF:
                analogWrite(_pin, 0);
                break;
            case LED_LOW:
                analogWrite(_pin, _low_value);
                break;
            case LED_MID:
                analogWrite(_pin, _mid_value);
                break;
            case LED_HIGH:
                analogWrite(_pin, _high_value);
                break;
        }
    }
}