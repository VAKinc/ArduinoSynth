#include "Arduino.h"
#include "time.hh"

namespace synth{
    /** 
     * Updates delta time value and returns the updated value;
    */

    /** 
     * Increments the internal time delta value. Should only be called at the start of loop() in synth.ino
     * 
     * @return void
    */
    void Time::tick(){
        _delta_time = millis();
    }

    /** 
     * Returns the delta time value.
     * 
     * @return time in MS since the beginning of code execution
    */
    unsigned long Time::deltaTime(){
        return _delta_time;
    }

    unsigned long Time::_delta_time = 0;
}