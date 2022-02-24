#include "Arduino.h"
#include "led.hh"
#include "../core/time.hh"

namespace synth{
    /** 
     * Cycles through illumination modes:
     * Off
     * On
     * Slow blink
     * Fast blink
    */
    void LED::toggle(){
        switch(_state){
            default:
            case LED_OFF:
                _state = LED_ON;
                break;
            case LED_ON:
                _state = LED_BLINK_SLOW;
                break;
            case LED_BLINK_SLOW:
                _state = LED_BLINK_FAST;
                break;
            case LED_BLINK_FAST:
                _state = LED_OFF;
                break;
        }
    }

    /** 
     * Illuminates the LED. Should be called in the main loop of the sketch.
    */
    void LED::glow(){
        switch (_state){
            default:
            case LED_OFF:
                digitalWrite(_pin, LOW);
                break;
            case LED_ON:
                digitalWrite(_pin, HIGH);
                break;
            case LED_BLINK_SLOW:
                blink(_blink_rate_slow);
                break;
            case LED_BLINK_FAST:
                blink(_blink_rate_fast);
                break;
        }
    }

    /** 
     * Blinks at a set rate
     * 
     * @param rate the rate at which to blink in milliseconds
    */
    void LED::blink(int rate){
        unsigned long d_time = Time::deltaTime();
        if(d_time - _last_update >= rate){
            _last_update = d_time;
            _blink_value = _blink_value == HIGH ? LOW : HIGH;
            digitalWrite(_pin, _blink_value);
        }
    }
}