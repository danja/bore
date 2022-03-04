**2022-03-04**

There is a Faust syntax highlighter extension for VSCode.

Ok, so trying the clarinetdsp example :

`faust2esp32 clarinet.dsp -lib -o clarinet`

put the generated files in src/, added a main.cpp to call it, got :

...
/home/danny/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld: .pio/build/esp32doit-devkit-v1/firmware.elf section `.dram0.bss' will not fit in region`dram0_0_seg'
/home/danny/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld: DRAM segment data does not fit.
/home/danny/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld: region `dram0_0_seg' overflowed by 151184 bytes
collect2: error: ld returned 1 exit status
\*\*\* [.pio/build/esp32doit-devkit-v1/firmware.elf] Error 1

**2022-02-27**

Set up repo. Copied across barebones DAC bits from Chatterbox. Got it generating white noise.

Downloaded Faust : https://faust.grame.fr/downloads/
