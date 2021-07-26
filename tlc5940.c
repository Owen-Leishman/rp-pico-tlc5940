#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "serial.pio.h"
#include "coast.pio.h"
#include "encode.h"
#include <stdio.h>



// pin connections
// 1 - SIN
// 2 - SCLK
// 3 - BLANK
// 4 - XLAT
// 5 - GSCLK



int main(){
    
    // example data to output, must be 12 bit, FFF is max pulse width
    int16_t test[16] ={0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0};

    // transmits data after encoding it, as well as setting up the state machines to run the tlc5940 without any cpu oversight
    encode(test);
}





