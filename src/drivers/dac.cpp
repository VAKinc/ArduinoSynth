#include "Arduino.h"
#include "SPI.h"
#include "dac.hh"
#include "../resources./pitches.hh"

namespace synth{
    /**
     * @brief Initialize the DAC
     */
    void DAC::init(){
        pinMode(_cipo_pin,  OUTPUT);   // Set SPI control PINs to output.
        pinMode(_sck_pin, OUTPUT);
        pinMode(_cs_and_ldac_pin, OUTPUT);

        SPI.begin();
    }

    /**
     * @brief Write to the DAC
     * 
     * @param AB Determines whether or not to write to A or B (A when falsy, B when truthy)
     * @param v The 12-bit value to write
     */
    void DAC::write(byte AB, uint16_t v){
        /**
         * First establish the settings.
         * B15 determines whether we are writing to A(0) or B(1)/
         * B14 is a buffer.
         * B13 is gain selection, 1 = 1x, 0 = 2x.
         * B12 is the shutdown command, which we don't want to use so we leave it at 1.
         */

        v |= 0xf000; // Bitmask B12-B15 to 1
        if (!AB)  v &= ~0x8000; // When zero clear B15 for A.

        SPI.beginTransaction(_settings);
        digitalWrite(_sck_pin, LOW); // Data is clocked in on the rising edge, so set clock low
        SPI.transfer((0xff00 & v) >> 8); // Bitmask the first half of the message and send it (4 control bits plus 4 bits of the 12 bit value)
        SPI.transfer(0x00ff & v); // Bitmask the second half and send it (the remaining 8 bits of the 12 bit value)
        digitalWrite(_sck_pin, HIGH); // Set clock high to clock in data
        SPI.endTransaction;
    }
}