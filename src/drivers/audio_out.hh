#ifndef SYNTH_AUDIO_OUT_H_
#define SYNTH_AUDIO_OUT_H_

#include "Arduino.h"

namespace synth {

    /** 
     * Class that controls 3.5mm audio output
     * 
     * @param l The pin number for the left channel (must us PWM pin)
     * @param r The pin number for the right channel (must us PWM pin)
    */
    class AudioOut {
        public:
            AudioOut (int l, int r){
                _left_pin = l;
                _right_pin = r;

                pinMode(_left_pin, OUTPUT);
                pinMode(_right_pin, OUTPUT);
            }
            ~AudioOut (){}

            void genTone();
        
        private:
            int _left_pin;
            int _right_pin;
    };

}

#endif