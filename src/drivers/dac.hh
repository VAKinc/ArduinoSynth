#ifndef SYNTH_DAC_H_
#define SYNTH_DAC_H_

#include "Arduino.h"
#include "SPI.h"

namespace synth {

    /**
     * @brief Class that controls the MCP4922 12-bit DAC
     */
    class DAC {
        public:
            DAC (){
                _cipo_pin = 11;
                _sck_pin = 13;
                _cs_and_ldac_pin = 10;
                _settings = SPISettings(16000000, MSBFIRST, SPI_MODE0);
            }
            ~DAC (){}

            void init();
            void write(byte AB, uint16_t v);
        
        private:
            uint8_t _cipo_pin;
            uint8_t _sck_pin;
            uint8_t _cs_and_ldac_pin;

            SPISettings _settings;
    };

}

#endif