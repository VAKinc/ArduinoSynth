#include "Arduino.h"
#include "audio_out.hh"
#include "../resources./pitches.hh"

namespace synth{
    /** 
     * Generates a tone
    */
    void AudioOut::genTone(){
      tone(_left_pin, NOTE_C4, 1000);
      tone(_right_pin, NOTE_C4, 1000);
    }
}