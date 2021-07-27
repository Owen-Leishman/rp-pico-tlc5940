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
    int16_t test[16] ={0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0};
    int16_t test_2[16] = {0, 0, 0xFFF, 0, 0, 0xFFF, 0, 0, 0xFFF, 0, 0, 0xFFF, 0, 0, 0xFFF, 0};
    int32_t output[6] = { 0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0, 0x12354125, 0x0};
    // transmits data after encoding it, as well as setting up the state machines to run the tlc5940 without any cpu oversight
    encode(test);


    while(1){
        encode(test);
        sleep_ms(100);
    }

}





