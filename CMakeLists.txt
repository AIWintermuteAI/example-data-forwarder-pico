cmake_minimum_required(VERSION 3.13.1)

include(pico_sdk_import.cmake)

project(data_forwarder C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

pico_sdk_init()

add_executable(data_forwarder
        sources/data_forwarder.c
        )

target_link_libraries(data_forwarder pico_stdlib hardware_adc)

# enable usb output, disable uart output
pico_enable_stdio_usb(data_forwarder 1)
pico_enable_stdio_uart(data_forwarder 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(data_forwarder)
