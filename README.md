# Mbed CE BasicSerial library
This project implements software serial communication without the use of interrupts or threads. Initially, the goal was to convert the SoftSerial library, but I encountered difficulties in achieving functionality.

It is important to note that the Arduino library does not support independent sending and receiving. The thread scheduling is set at 1 ms, which means that the high-speed responsiveness required for serial communications cannot be achieved through multithreading.

Since this library relies on the implementation of `wait_ns` for each microcontroller within MBED-OS CE, its performance will heavily depend on how `wait_ns` is implemented for each specific microcontroller.

While this project may work well for low-speed and high-clock MCUs, it may face challenges with other configurations that have lower CPU clock speeds. Currently, the project is based on the NUCLEO-F207ZG board, but you will need to modify the settings to make it compatible with other CPUs.

# WARNING!!
 Use it at your own risk. I don't guarantee the performance of this library.

## How to set up this project:

1. Clone it to your machine.  Don't forget to use `--recursive` to clone the submodules: `git clone --recursive https://github.com/MariwanJ/BasicSerial `
2. You may want to update the mbed-os submodule to the latest version, with `cd mbed-os && git pull origin master`
3. Set up the GNU ARM toolchain (and other programs) on your machine using [the toolchain setup guide](https://github.com/mbed-ce/mbed-os/wiki/Toolchain-Setup-Guide).
4. Set up the CMake project for editing.  We have three ways to do this:
    - On the [command line](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-Command-Line)
    - Using the [CLion IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-CLion)
    - Using the [VS Code IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-VS-Code)
5. See more at MBED OS CE how you can flash or simply send the bin file to your virtual drive of your Nucleo

## Notes:
- Inside your cpp file under /src do not use #include <balbla.h> , you should write the include with quotation marks .i.e. #include "balbla.h".
- Run the batch or bash file to compile. 
