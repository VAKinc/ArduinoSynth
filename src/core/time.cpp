#include "Arduino.h"
#include "time.hh"

namespace synth{
    /** 
     * Updates delta time value and returns the updated value;
    */

    void Time::tick(){
        _delta_time = millis();
    }

    unsigned long Time::deltaTime(){
        return _delta_time;
    }

    unsigned long Time::_delta_time = 0;
}