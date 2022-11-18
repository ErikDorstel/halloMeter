boolean debug=true;

const char* appName="halloMeter";
const char* appDesc="PV Powermeter";

#include "WLAN.h"
#include "DNS.h"
#include "ADS1115.h"
#include "HTTP.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initWLAN();
  initDNS();
  initHTTP();
  initADS1115(); }

void loop() { wlanWorker(); httpWorker(); dnsWorker(); ads1115Worker(); }
