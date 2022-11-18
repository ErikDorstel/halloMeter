# halloMeter
ESP32 and WCS1800 based photovoltaic powermeter
#### Features
* uses WCS1800 as current sensor
* uses ADS1115 as 16 bit analog to digital converter at 5 volt operating voltage
* uses YF08E as 3.3 volt to 5 volt level shifter to convert the i2c signals
* works as WLAN client and AP (AP chooser included)
* WebUI with IP address 192.168.4.1
* mDNS hostname hallometer.local
* DNS hostname hallometer.local (WLAN AP mode only)
* manual zero point adjustment of the hall voltage
* measures up to +/- 35 amps dc
* measures up to 20 volts dc
* measures voltage, current, power, charge and energy
* charge, energy and running time are stored every 6 hours automatically or manually via web ui
#### I2C bus
* SDA - GPIO 21
* SCL - GPIO 22
* address - 0x48
#### Development Hardware
![IMAGE ALT TEXT HERE](https://www.dorstel.de/github/halloMeter_a_v1.0.png)
#### Web UI Screenshot
![IMAGE ALT TEXT HERE](https://www.dorstel.de/github/halloMeter_b_v1.0.png)
