/*
   EXPLORE ENGINEERING - UNIVERSITY OF SYDNEY
   Max Schultz - 2017
   For use in the Biomedical Engineering module

   This file is the top level file used to call all other Arduino files used in this project.
   This file reads and displays data from the pulse oximeter.

*/
#include <Filters.h>

#define PULSE_OX_PIN A0
#define LED_PIN 13

// VARIABLES FOR YOU TO CHANGE:
///////////////////////////////////////////////////////////////////////////////////////////////
float filterFrequency = 15.0; //What value works best?
const int QR_range = 50; //What value works best?
int sample_rate = 10; //Units in Hz, what value works best?
///////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // pin definitions
  pinMode(PULSE_OX_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  float sensor_value = filter_function(); //samples and filters analog input
  delay(sample_rate * 10);
}

float filter_function() {

  FilterOnePole lowpassFilter (LOWPASS, filterFrequency);
  float sensor_value = lowpassFilter.input( analogRead (PULSE_OX_PIN));
  Serial.println(sensor_value);
  return sensor_value;

}

void led_function() {
  //what should we put here?
}

void button_function() {
  //what should we put here?
}

