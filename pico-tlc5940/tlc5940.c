#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "serial.pio.h"
#include "coast.pio.h"
#include <stdio.h>

// pin connections
// 0 - GSCLK
// 1 - SIN
// 2 - SCLK
// 3 - BLANK
// 4 - XLAT
// 5 - GSCLK



// this function sends data to the tlc5940, and then turns on the coast program which runs GSCLK and BLANK
void disp(uint32_t output[6]){
        pio_clear_instruction_memory(pio0);
        serial_program_init();
        pio_sm_put_blocking(pio0, 0, output[0]);
        pio_sm_put_blocking(pio0, 0, output[1]);
        pio_sm_put_blocking(pio0, 0, output[2]);
        pio_sm_put_blocking(pio0, 0, output[3]);
        pio_sm_put_blocking(pio0, 0, output[4]);
        pio_sm_put_blocking(pio0, 0, output[5]);
        sleep_ms(1);
        pio_clear_instruction_memory(pio0);
        coast_program_init();
}


int main(){
    // the output data needs to be encoded, as there are 16 outputs and only 6 inputs
    // encoding has not been implemented in the c file yet, as it is easier to do in other langauges
    uint32_t test[6] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}; 
    disp(test);
}






