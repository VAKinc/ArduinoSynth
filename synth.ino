#include "src/drivers/dac.hh"
#include "src/core/time.hh"

using namespace synth;

DAC dac;

// Sine Wave
const uint16_t SineLookup_5bits[32]
{
    2048, 2447, 2831, 3185, 3495, 3750, 3939, 4056,
    4095, 4056, 3939, 3750, 3495, 3185, 2831, 2447,
    2048, 1648, 1264,  910,  600,  345,  156,   39,
    0,   39,  156,  345,  600,  910, 1264, 1648
};

void setup() {
    // Set Serial Baud rate
    Serial.begin(9600);

    dac.init();
}

// the loop function runs over and over again forever
void loop() {
    Time::tick();

    for (int i = 0; i < pow(2, 5); i++) {
        dac.write( 0, SineLookup_5bits[i] );
    }
}