#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "serial.pio.h"
#include "coast.pio.h"
#include <stdio.h>

#define frequency = 100000  //GSCLK frequency

// 0 - GSCLK
// 1 - SIN
// 2 - SCLK
// 3 - BLANK
// 4 - XLAT
// 5 - GSCLK




void disp(int output[16]){
        pio_clear_instruction_memory(pio0);
        serial_program_init();

        pio_sm_put_blocking(pio0, 0, output[15]);
        pio_sm_put_blocking(pio0, 0, output[14]);
        pio_sm_put_blocking(pio0, 0, output[13]);
        pio_sm_put_blocking(pio0, 0, output[12]);
        pio_sm_put_blocking(pio0, 0, output[11]);
        pio_sm_put_blocking(pio0, 0, output[10]);
        pio_sm_put_blocking(pio0, 0, output[9]);
        pio_sm_put_blocking(pio0, 0, output[8]);
        pio_sm_put_blocking(pio0, 0, output[7]);
        pio_sm_put_blocking(pio0, 0, output[6]);
        pio_sm_put_blocking(pio0, 0, output[5]);
        pio_sm_put_blocking(pio0, 0, output[4]);
        pio_sm_put_blocking(pio0, 0, output[3]);
        pio_sm_put_blocking(pio0, 0, output[2]);
        pio_sm_put_blocking(pio0, 0, output[1]);
        pio_sm_put_blocking(pio0, 0, output[0]);


        pio_clear_instruction_memory(pio0);
        coast_program_init();
        
     

}



void disp_2(uint32_t output[6]){
        pio_clear_instruction_memory(pio0);
        serial_program_init();
        sleep_us(3);
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    gpio_init(8);
    gpio_set_dir(8, 1);
    gpio_put(8, 1);



    int zero[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int full[16] = {4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094};
    int temp[16] = {0x0, 0x0, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0xFFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

    uint32_t test[6] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};




    disp_2(test);


/**
    pio_clear_instruction_memory(pio0);
    serial_program_init();

    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    pio_sm_put_blocking(pio0, 0, 0);
    sleep_ms(1);
    pio_clear_instruction_memory(pio0);
    coast_program_init();
**/

    //disp(zero);
    //disp(zero);
    //disp(zero);
    //disp(temp);


/**
    while(1){
        disp(full);

        sleep_ms(500);

        disp(zero);

        sleep_ms(500);

    }
**/


}







