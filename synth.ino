#include "src/drivers/button.hh"
#include "src/drivers/led.hh"
#include "src/core/time.hh"

using namespace synth;

Button toggle_button(2);
LED light(13, 50, 200);

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    // Set Serial Baud rate
    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
    Time::tick();

    if(toggle_button.getButton()){
        light.toggle();
    }
    
    light.glow();
}