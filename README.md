# Mbed CE BasicSerial library
This project implements the software serial. No interrupt or threads are used. The origional idea was to convert the SoftSerial but I could not get it working. 
Now as for Arduino library, you will not be able to send and recieve independetly. Scheduling of threads is 1ms. Which means that the high speed reaction which Serial communications needs cannot be achieved.
Since this library uses wait_ns. It will be very much dependent on the implementation of the wait_ns per each microcontroller inside MBED-OS CE. 
This might work well for low hastighet and high clock MCU:s. But might fail on some other low cpu clocks.
This project is based on NUCLEO-F207ZG. Change the setting to get it work for other CPU.

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
- The PDF shows you how to configure Eclipse for debugging and for compiling. Please notice that the pictures inside the pdf is for a project based on NUCLEO-F207ZG. 
  Try to change the names, script files..etc. to your HW. OpeOCD scritp could be either written or found on the net if you cannot find it. 
  I made the script for F2X. Boards by myself. OpenOCD doesn’t provide that by default.
- Run the batch or bash file to compile. 
