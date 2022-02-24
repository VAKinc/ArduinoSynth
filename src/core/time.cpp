#include "Arduino.h"
#include "time.hh"

namespace synth{
    /** 
     * Updates delta time value and returns the updated value;
    */

    unsigned long Time::deltaTime(){
        _delta_time = millis();
        return _delta_time;
    }

    unsigned long Time::_delta_time = 0;
}