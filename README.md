# Mbed CE BasicSerial library
This project implements software serial communication without the use of interrupts or threads. Originally, the intention was to convert SoftSerial, but I encountered difficulties in getting it to work.

Regarding the Arduino library, it is important to note that independent sending and receiving is not possible. The scheduling of threads is set at 1ms, which means that the high-speed responsiveness required for Serial communications cannot be achieved through multithreading.

Since this library relies on the implementation of wait_ns for each microcontroller within MBED-OS CE, its performance will heavily depend on the specific implementation of wait_ns for each microcontroller.

While this project may work well for low-speed and high-clock MCUs, it may encounter issues with other low CPU clock configurations. Currently, the project is based on the NUCLEO-F207ZG board, but you will need to modify the settings to make it work with other CPUs.

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
