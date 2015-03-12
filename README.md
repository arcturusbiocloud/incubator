arcturus-incubator
============

Arduino project to keep the temperature inside a incubator at 37 degrees using temperature sensor, a lamp, and a controlled power source. It requires this [library](https://github.com/Seeed-Studio/Grove_Temperature_And_Humidity_Sensor).

How to send and receive commands in an Arduino UNO connected on the USB port from BBB:

    python incubator-driver.py UV_ON # turn the UV light ON, turning off the incubator and tent lights
    python incubator-driver.py UV_OFF # turn the UV light OFF, turning on the incubator and tent lights
    python incubator_driver.py MONITOR # get the humidity and temperature through the sensor from the Arduino using a DHT sensor
    
Caveats:

* The Arduino is reseting when the serial port is being connected.

Some references:

* <http://biodesign.cc/2013/12/25/diy-incubator/>
* <https://www.manylabs.org/docs/project/freezerIncubator>
* <http://biohackacademy.github.io/biofactory/class/1-incubator>