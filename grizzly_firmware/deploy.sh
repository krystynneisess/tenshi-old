#!/bin/sh

echo "Connect Grizzly to test jig and AVR programmer."
echo "Choose yes if prompted."
echo

sudo avrdude -c usbtiny -p atmega32u4 -U lfuse:w:0xff:m -U hfuse:w:0xD9:m -U efuse:w:0xFB:m
sudo avrdude -c usbtiny -p atmega32u4 -U flash:w:../build/artifacts/grizzly_firmware/opt/grizzly_firmware.hex:i

