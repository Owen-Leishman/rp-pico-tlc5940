cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
project(pico-tlc5940)
pico_sdk_init()

add_executable(tlc5940
    encode.c
)

#creates the binary from the assembly for the state machine
pico_generate_pio_header(tlc5940 ${CMAKE_CURRENT_LIST_DIR}/serial.pio)
pico_generate_pio_header(tlc5940 ${CMAKE_CURRENT_LIST_DIR}/coast.pio)

target_sources(tlc5940 PRIVATE tlc5940.c)

target_link_libraries(tlc5940 PRIVATE
    pico_stdlib
    hardware_pio
)

pico_add_extra_outputs(tlc5940)