#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "WM8978.h"
#include "clarinet.h"

clarinet fClarinet(22000, 4);

void setup()
{
    /*
    WM8978 wm8978;
    wm8978.init();
    wm8978.addaCfg(1, 1);
    wm8978.inputCfg(1, 0, 0);
    wm8978.outputCfg(1, 0);
    wm8978.micGain(30);
    wm8978.auxGain(0);
    wm8978.lineinGain(0);
    wm8978.spkVolSet(0);
    wm8978.hpVolSet(40, 40);
    wm8978.i2sCfg(2, 0);
*/
    fClarinet.start();
}

void loop()
{
    fClarinet.setParamValue("freq", rand() % (2000 - 50 + 1) + 50);
    delay(1000);
}