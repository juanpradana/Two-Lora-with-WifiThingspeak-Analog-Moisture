# Two-Lora-with-WifiThingspeak-Analog-Moisture
This repository for one ESP32 as gateway where it will send all data to Thingspeak and two ESP32 as sender/station using Lora e32-433t30d.

![Lora e32-433t30d](https://www.ebyte.com/Uploadfiles/Picture/2021-5-25/20215251730359457.jpg)

![Analog Waterproof Capacitive Soil Moisture Sensor dfrobot sen0308](https://img.dfrobot.com.cn/wiki/none/8cab8d259187bb1bd867f5c3f0b48a8f)

# Requirement
You need install library:
- Wifi.h
- ThingSpeak.h
- time.h

# Wiring
## LoRa
ESP32 >>  Lora e32-433t30d

GND   >> GND

GND   >> M0

GND   >> M1

D16   >> Tx

D17   >> Rx

3.3V  >> VCC

## dfrobot sen0308
ESP32 >> dfrobot sen0308

3.3V  >> Red

GND   >> Black

34    >> Yellow

# Explanation
slave0 is identified as User#1 and slave1 i identified as User#2, data sended to gateway every 5 Second.

CountOut is used for counting failed queue data from station, when countOut is 3 so queue will change to other station (station 1 to station 0). CountOut 0 for slave0 and countOut 1 for slave1.

Time delay set to 20 seconds cause free ThingSpeak just can received new data for every 15 seconds.

# ThingSpeak Channel
![image](https://user-images.githubusercontent.com/30497994/156391795-4cfbc924-5850-4f2c-b821-9f0dda21f55b.png)

https://thingspeak.com/channels/1663500
