# Tinyduck
<p align="center"><img alt="Marauder logo" src="https://github.com/justcallmekoko/Tinyduck/blob/master/images/tinyduck_front.jpg?raw=true" width="400"><img alt="Marauder logo" src="https://github.com/justcallmekoko/Tinyduck/blob/master/images/tinyduck_back.jpg?raw=true" width="400"></p>
<p align="center">
  <b>The super tiny USB Rubber Ducky</b>
  <br><br>
  <a href="https://github.com/justcallmekoko/Tinyduck/blob/master/LICENSE"><img alt="License" src="https://img.shields.io/github/license/mashape/apistatus.svg"></a>
  <br>
  <a href="https://twitter.com/intent/follow?screen_name=jcmkyoutube"><img src="https://img.shields.io/twitter/follow/jcmkyoutube?style=social&logo=twitter" alt="Twitter"></a>
  <a href="https://www.instagram.com/just.call.me.koko"><img src="https://img.shields.io/badge/Follow%20Me-Instagram-orange" alt="Instagram"/></a>
  <br><br>
  <a href="https://www.tindie.com/products/justcallmekoko/tinyduck-usb-rubber-ducky/"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-larges.png" alt="I sell on Tindie" width="200" height="104"></a>
</p>

# Table of Condemnation
- [About](#about)
- [Setup](#setup)
  - [Creating Your Own Script](#creating-your-own-script)
  - [Flashing Firmware](#flashing-firmware)
  - [Issues](#issues)
- [Usage](#usage)

# About
If you don't already know about the USB Rubber Ducky, check it out [here](https://shop.hak5.org/products/usb-rubber-ducky-deluxe). Escentially is a keystroke injection tool that comes in the form factor of a USB thumb drive. It will execute a prewritten script of keystrokes on a target computer as though it were a keyboard. If you can do it with a keyboard, you can do it with a USB Rubber Ducky but faster. There are a lot of projects online [here](https://www.youtube.com/watch?v=fGmGBa-4cYQ), [here](https://www.youtube.com/watch?v=wwFhMG8D7Lc), and [here](https://www.youtube.com/watch?v=A3cB9BDE6XM) showing how to create your own USB Rubber ducky using the digispark development board. The whole reason I created the project was to see just how small I could make the device itself. While the firmware and the concept isn't ground breaking, I am proud to have been the one to create a USB Rubber Ducky with a footprint the size of an overgrown fingernail.

# Setup
The Tinyduck functions the same way as the digispark attiny85 board right down to the bootloader. If you have already setup your Arduino IDE to work with the digispark and know how to use it, you can skip [Flashing Firmware](#flashing-firmware).

## Creating Your Own Script
[Ducky Script](https://docs.hak5.org/hc/en-us/articles/360010555153-Ducky-Script-the-USB-Rubber-Ducky-language#:~:text=Ducky%20Script%20is%20the%20language,%2C%20kedit%2C%20TextEdit%2C%20etc.) is a very straight forward scripting language used to create keystroke injection binaries to be run on the original USB Rubber Ducky. While this language does not work natively in the Arduino IDE, there are [tools](https://d4n5h.github.io/Duckuino/) that have been created to translate Ducky Script into Arduino code and further translated to work with digispark specific libraries.

1. Write your ducky script in any text editor
2. Copy the contents of your ducky script in the the first text box of [digiQuack](https://cedarctic.github.io/digiQuack/)
3. Click `convert`
4. Copy the Arduino code from the bottom window into your Arduino IDE

## Flashing Firmware
If you have used the Arduino IDE before but have not used the digispark or any other ATtiny variants that use the micronucleus bootloader, you will find out about some nuances that tend to confuse newcomers.

Prior to attempting to flash any firmware, you need to follow [these instructions](https://digistump.com/wiki/digispark/tutorials/connecting) to install the digispark boards in your Arduino IDE.

Here is the typical order of operations when booting a microcontroller loaded with micronucleus.  
1. Microcontroller receives power
2. Bootloader executes and waits 5 seconds for USB connection (This is when new firmware is uploaded)
3. Main firmware is executed

To upload your new ducky script firmware to Tinyduck, follow the steps below (Assuming you already have digispark compatible ducky code in your Arduino IDE)
1. Under `Tools`>`Boards`, select `Digispark (Default - 16.5Mhz)`
2. <b>with Tinyduck unplugged</b> click the upload button
3. Wait for the IDE to instruct you to plug in your device then insert Tinyduck
    - The firmware should promptly start uploading to Tinyduck
4. Unplug Tinyduck as soon as the upload completes to avoid firmware execution

## Issues
While the tools used to translate ducky script can be very useful, they have their shortcomings which keep them from being the perfect translator. You may find that some of your translated scripts do not allow the Arduino IDE to compile your firmware and you will need to make some manual adjustments in order to proceed.

For example:
```Java
DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT,KEY_R); // This will not compile because of too many arguments

DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // This WILL compile and accomplish the intended action
```

# Usage
Tinyduck is intended to be a fire and forget device. Once inserted into a computer, Tinyduck will execute its preprogrammed functions without any needed user intervention. Because of the required USB support, Tinyduck will take 5 seconds to run through the micronucleus bootloader before proceeding to its main code execution.
