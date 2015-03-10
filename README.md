arcturus-incubator
============

Arduino project to keep the temperature inside a incubator at 37 degrees using temperature sensor, a lamp, and a controlled power source. It requires this [library](https://github.com/Seeed-Studio/Grove_Temperature_And_Humidity_Sensor).

Some references:

* <http://biodesign.cc/2013/12/25/diy-incubator/>
* <https://www.manylabs.org/docs/project/freezerIncubator>
* <http://biohackacademy.github.io/biofactory/class/1-incubator>

How to send and receive commands in an Arduino UNO connected on the USB port from BBB:

    cat /dev/ttyACM0 # read Arduino serial buffer connected on BBB
    echo "test" > /dev/ttyACM0 # write to the Arduino serial buffer connected on BBB
