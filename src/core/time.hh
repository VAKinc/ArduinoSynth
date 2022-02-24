#ifndef SYNTH_TIMED_OBJECT_H_
#define SYNTH_TIMED_OBJECT_H_

#include "Arduino.h"

namespace synth {
    /** 
     * Class for managing time
    */
    class Time {
        public:
            Time (){}
            ~Time (){}

            static unsigned long deltaTime();
        
        private:
            static unsigned long _delta_time;
    };

}

#endif  // SYNTH_TIMED_OBJECT_H_