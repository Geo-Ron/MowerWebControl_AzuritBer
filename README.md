# MowerWebControl_AzuritBer
 
[Link to forum](https://forum.ardumower.de/threads/ardumower-webinterface.23825)
[Link to original forum entry](https://forum.ardumower.de/threads/ardumower-webinterface.23360/)

## Additional componentents
[Set up Arduino IDE to program ESP8266](https://www.instructables.com/id/Setting-Up-the-Arduino-IDE-to-Program-the-ESP8266-/)
[Arduino ESP8266 FS Plugin](https://github.com/esp8266/arduino-esp8266fs-plugin/releases)
[Using ESP8266 SPIFFS](https://www.instructables.com/Using-ESP8266-SPIFFS)

## Configure Wifi settings:

Edit MowerWebControl_ESP8266\MowerWebControl_ESP8266.ino

```C++
#define SET_IP_SETTING  1  //true=IP-Settings aus programm, false=IP-Settings von Mower
IPAddress myIP(xxx, xxx, xxx, xxx);
IPAddress gateway(xxx, xxx, xxx, xxx);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(xxx, xxx, xxx, xxx);
char *ssid = "xxx";
char *password = "xxx";
```

Flash the ESP

## Configure mower to use wifi instead of bluetooth
```C++
// ----- bluetooth -------------------------------------
bluetoothUse = 0; // use Bluetooth module? (WARNING: if enabled, you cannot use ESP8266)

// ----- esp8266 ---------------------------------------
esp8266Use = 1; // use ESP8266 Wifi module? (WARNING: if enabled, you cannot use Bluetooth)
esp8266ConfigString = "123test321";
```

## MowerWebControl baud rate
Verify the baud rate in Mowerwebcontrol.ino to match the setting in mower.h

## ESP8266 SPIFFS
[Link to instructable article](https://www.instructables.com/Using-ESP8266-SPIFFS/)

## Domoticz Calls
```C++
'http://moweresp/set?ra=true' //Auto
'http://moweresp/set?ro=true' //Off
'http://moweresp/set?rh=true' //Home
```


