#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads1115;

#define currentMul 15.1515 // 1/0.066=15.1515
#define voltageMul 4.125   // 1/3.2*(3.2+10)=4.125
uint32_t ads1115Timer=0;

struct wcs1800Struct {
  float current=0;
  float voltage=0;
  float power=0;
  double charge=0;
  double energy=0;
  uint32_t runtime; } wcs1800Data;

void loadValues() {
  preferences.begin("halloMeter",false);
  wcs1800Data.charge=preferences.getDouble("charge",0); wcs1800Data.energy=preferences.getDouble("energy",0); wcs1800Data.runtime=preferences.getULong("runtime",0);
  preferences.end(); }

void saveValues() {
  preferences.begin("halloMeter",false);
  preferences.putDouble("charge",wcs1800Data.charge); preferences.putDouble("energy",wcs1800Data.energy); preferences.putULong("runtime",wcs1800Data.runtime);
  preferences.end(); }

void initADS1115() {
  ads1115.setGain(GAIN_TWOTHIRDS); ads1115.setDataRate(RATE_ADS1115_128SPS);
  if (!ads1115.begin()) { Serial.println("Failed to initialize ADS1115."); }
  loadValues(); }

void ads1115Worker() {
  if (millis()>=ads1115Timer) { ads1115Timer=millis()+1000;
    wcs1800Data.current=ads1115.computeVolts(ads1115.readADC_Differential_0_3())*currentMul;
    wcs1800Data.voltage=ads1115.computeVolts(ads1115.readADC_SingleEnded(2))*voltageMul;
    wcs1800Data.power=wcs1800Data.voltage*wcs1800Data.current;
    wcs1800Data.charge+=wcs1800Data.current/3600;
    wcs1800Data.energy+=wcs1800Data.power/3600;
    wcs1800Data.runtime++;
    if (wcs1800Data.runtime % 21600 == 0) { saveValues(); } } }
