# STM8 Development

```
This is documentation for project developing STM8 using Arduino IDE and stm8flash
```
## Preparation
* Hardware
  * STM8S103F3P6 Mini Dev Board
  <img src="/Pics/STM8 Minimum System Development Board.JPG" width="333" height="250">
  <img src="https://tenbaht.github.io/sduino/hardware/stm8blue-pinout.png" width="300" height="220">
  
  * ST-Link V2
  <img src="/Pics/sta-2.jpg" width="300" height="310">
 
* Software 
  * Arduino IDE for STM8 Board - sduino : https://github.com/tenbaht/sduino
    ```
    This open source project to make Arduino IDE can compile a code for STM8
    ```
  <img src="/Pics/arduino_stm8.png" width="300" height="310">

  * stm8flash : https://github.com/vdudouyt/stm8flash
    ```
    The open source program for uploading hex file into STM8
    ```
## Wiring
```
STM8 --- ST-Link V2
3.3v --- 3.3v
SWMI --- SWIM
GND  --- GND
NRST --- RST
```
<img src="https://robu.in/wp-content/uploads/2018/07/robu-5-2.jpg" width="333" height="250">

## Arduino IDE - sduino
Start the Arduino-IDE. In File->Preferences, Settings tab, enter 
> https://github.com/tenbaht/sduino/raw/master/package_sduino_stm8_index.json

as an Additional Boards Manager URL.

* Open Tools->Board:...->Boards Manager
* Find Sduino by typing 'sd' into the search line
* Click on the list entry
* Click on Install

Now you should find a new entry STM8S Boards in the list at Tools->Board:...

* Choose STM8S103F3 Breakout Board from the list
* open the standard Blink example from File->Examples->01. Basics->Blink
* compile it by hitting Verify


## stm8flash
only for Linux Ubuntu
Download stm8flash and depedencies
> $ git clone https://github.com/vdudouyt/stm8flash.git

> $ sudo apt-get install libusb-1.0-0-dev

Compile and Install stm8flash Tool
> $ cd stm8flash

> $ make

> $ sudo make install

Create 99-stlinkv2.rules
> $ sudo gedit /etc/udev/rules.d/99-stlinkv2.rules

and copy this into the file
```
# stm32 discovery boards, with onboard st/linkv2
# ie, STM32L, STM32F4.
# STM32VL has st/linkv1, which is quite different

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="3748", \
    MODE:="0666", \
    SYMLINK+="stlinkv2_%n"

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="374b", \
    KERNEL!="sd*", KERNEL!="sg*", KERNEL!="tty*", SUBSYSTEM!="bsg", \
    MODE:="0666", \
    SYMLINK+="stlinkv2_%n"

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="374b", \
    KERNEL=="sd*", MODE:="0666", \
    SYMLINK+="stlinkv2_disk"

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="374b", \
    KERNEL=="sg*", MODE:="0666", \
    SYMLINK+="stlinkv2_raw_scsi"

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="374b", \
    SUBSYSTEM=="bsg", MODE:="0666", \
    SYMLINK+="stlinkv2_block_scsi"

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="374b", \
    KERNEL=="tty*", MODE:="0666", \
    SYMLINK+="stlinkv2_console"

# If you share your linux system with other users, or just don't like the
# idea of write permission for everybody, you can replace MODE:="0666" with
# OWNER:="yourusername" to create the device owned by you, or with
# GROUP:="somegroupname" and control access using standard unix groups.
```
The last step is 
> $ echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="3748", MODE="0666"' | sudo tee /etc/udev/rules.d/99-stlinkv2.ruleS > /dev/null

Unlocking a write protected MCU
> $ stm8flash -cstlinkv2 -pstm8s103?3 -u

Command for uploading the hex file into STM8
> $ stm8flash -c stlinkv2 -p stm8s103f3 -s flash -w /tmp/arduino_build_10931/Blink.ino.hex 

where /tmp/arduino_build_10931/Blink.ino.hex is the location of compiled file using Arduino IDE

## Example
List of example

[1. LCD 16x2](https://github.com/2black0/STM8_development/blob/master/Example/stm8_lcd.ino)

[2. Hardware Serial](https://github.com/2black0/STM8_development/blob/master/Example/stm8_serial.ino)
