# MowerWebControl_AzuritBer
 
[Link to forum](https://forum.ardumower.de/threads/ardumower-webinterface.23825)
[Link to original forum entry](https://forum.ardumower.de/threads/ardumower-webinterface.23360/)

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


## Domoticz Calls
```C++
'http://moweresp/set?ra=true' //Auto
'http://moweresp/set?ro=true' //Off
'http://moweresp/set?rh=true' //Home
```


