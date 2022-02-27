/************************************************************************************/
/*    Bore                                                                   */
/*                                                                                  */
/*    sound generator                                                  */
/*                                                                                  */
/*    see http://github.com/danja/bore                                        */
/*                                                                                  */
/*    unless otherwise stated: MIT license, attribution appreciated                 */
/*                                                                                  */
/*    Danny Ayers 2022 | danny.ayers@gmail.com | @danja | https://hyperdata.it */
/************************************************************************************/

#define CHECK_STACK false // will make noisy
#define INPUT_TASK_STACK_SIZE 72000
#define OUTPUT_TASK_STACK_SIZE 3072

#define SAMPLERATE 22000 // 16000 // want at least 22000

#include <Arduino.h>
// #include <driver/adc.h> // depends on Espressif ESP32 libs
#include <I2SDAC.h> // see src/lib - based on https://github.com/wjslager/esp32-dac

// I2C DAC interface
#define GPIO_DAC_DATAPORT 0
#define GPIO_DAC_BCLK 26
#define GPIO_DAC_WSEL 25
#define GPIO_DAC_DOUT 27

// #define ADC_TOP 4096
// #define ADC_SAMPLES 32 // pot reading takes mean over this number of values

float samplerate = (float)SAMPLERATE;

I2sDAC dac;

TaskHandle_t controlInputHandle = NULL;
TaskHandle_t outputDACHandle = NULL;

class BoreOutput
{
public:
  BoreOutput();
  static void OutputDAC(void *pvParameter);
};

BoreOutput::BoreOutput()
{
  xTaskCreatePinnedToCore(
      OutputDAC,
      "audio",
      OUTPUT_TASK_STACK_SIZE, // was 2048, 4096
      NULL,
      10,               // 1 | portPRIVILEGE_BIT,
      &outputDACHandle, // was &AudioTask,
      0);
}

class BoreInput
{
public:
  BoreInput();
  static void ControlInput(void *pvParameter);
};

BoreInput::BoreInput()
{
  xTaskCreatePinnedToCore(
      ControlInput,
      "ControlInput",
      INPUT_TASK_STACK_SIZE, // stack size, was 4096, 64000 // high 97004
      NULL,
      2, // priority
      &controlInputHandle,
      1); // core
}

//// FORWARD DECLARATIONS ////////////////////
void ControlInput(void *pvParameter);

void setup();

/*********************/
/*** INPUT RELATED ***/
/*********************/

void loop()
{
  delay(1000);
};

/* *** START SETUP() *** */
void setup()
{
  Serial.begin(115200);

  delay(1000); // let it connect

  Serial.println("\n*** Starting Bore ***\n");

  // Serial.println("portTICK_RATE_MS = " + portTICK_RATE_MS);

  if (dac.begin(SAMPLERATE, GPIO_DAC_DATAPORT, GPIO_DAC_BCLK, GPIO_DAC_WSEL, GPIO_DAC_DOUT))
  {
    Serial.println("DAC init success");
  }
  else
  {
    Serial.println("DAC init fail");
  }

  static BoreOutput BoreOutput;
  static BoreInput BoreInput;

  if (CHECK_STACK)
  {
    Serial.print("esp_get_free_heap_size() = ");
    Serial.println(esp_get_free_heap_size(), DEC);

    Serial.print("esp_get_minimum_free_heap_size() = ");
    Serial.println(esp_get_minimum_free_heap_size(), DEC);

    Serial.print("uxTaskGetStackHighWaterMark(controlInputHandle) = ");
    Serial.println(uxTaskGetStackHighWaterMark(controlInputHandle), DEC);

    Serial.print("uxTaskGetStackHighWaterMark(outputDACHandle) = ");
    Serial.println(uxTaskGetStackHighWaterMark(outputDACHandle), DEC);

    Serial.print("uxTaskGetNumberOfTasks() = ");
    Serial.println(uxTaskGetNumberOfTasks(), DEC);
  }
}
/*** END SETUP() ***/

/************************/
/* *** INPUT THREAD *** */
/************************/
void BoreInput::ControlInput(void *pvParameter)
{
  while (1)
  {

    vTaskDelay(1000);
  }
}
/* END INPUT THREAD */

/*****************/
/* OUTPUT THREAD */
/*****************/
void BoreOutput::OutputDAC(void *pvParameter)
{
  // Serial.print("Audio thread started at core: ");
  // Serial.println(xPortGetCoreID());
  // static SineWavetable sinWavetable;
  // static SawtoothWavetable sawWavetable;

  while (1)
  {

    // ************************************************
    // ****************** THE WIRING ******************
    // ************************************************
    float left = random(-32768, 32767) / 32768.0f;
    float right = random(-32768, 32767) / 32768.0f;
    // Outputs A, B
    dac.writeSample(left, right);

    // ****************** END WIRING ******************
    vTaskDelay(1);
  }
}

// END OUTPUT THREAD