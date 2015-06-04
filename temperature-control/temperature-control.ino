// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to
#define DHTTYPE DHT22 // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

#define INCUBATOR_LIGHT_PIN A1
#define UV_PIN A2
#define CENTRIFUGE_PIN A3
#define TENT_LIGHT_PIN 2

void setup() 
{    
    // pin setup
    pinMode(INCUBATOR_LIGHT_PIN, OUTPUT);
    pinMode(UV_PIN, OUTPUT);
    pinMode(CENTRIFUGE_PIN, OUTPUT);
    pinMode(TENT_LIGHT_PIN, OUTPUT);
 
    //start with the incubator light on. LOW/HIGH are inverted
    digitalWrite(INCUBATOR_LIGHT_PIN, LOW);
        
    // starts with tent light on. LOW/HIGH are inverted
    digitalWrite(TENT_LIGHT_PIN, LOW);
    
    // start with the uv light off
    digitalWrite(UV_PIN, LOW);

    // start with the centrifuge off  
    digitalWrite(CENTRIFUGE_PIN, LOW);
    
    // serial handshake
    Serial.begin(9600);

    // starts the temperature sensor
    dht.begin();
}

int UV_ON = 0;
char buffer[64];
size_t len = 0;

void loop() 
{  
    // clean the serial buffer
    memset(buffer,0,sizeof(buffer));
   
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    // implement serial read bytes and read command
    if (Serial.available()) {
      len = Serial.readBytes(buffer, 1);
      if (len > 0) {
        if (buffer[0] == '0') {
          UV_ON = 0;
          //turn incubator light on
          digitalWrite(INCUBATOR_LIGHT_PIN, LOW);
          // turn tent light on
          digitalWrite(TENT_LIGHT_PIN, LOW);
          // turn the UV light off
          digitalWrite(UV_PIN, LOW);
          Serial.println("0");
        }
        if (buffer[0] == '1') {
          UV_ON = 1;
          //turn incubator light off
          digitalWrite(INCUBATOR_LIGHT_PIN, HIGH);
          // turn tent light off.
          digitalWrite(TENT_LIGHT_PIN, HIGH);
          // turn the UV light ON
          digitalWrite(UV_PIN, HIGH);
          Serial.println("1");
        }
        if (buffer[0] == '2') {
          // check if returns are valid, if they are NaN (not a number) then something went wrong!
          if (isnan(t) || isnan(h)) 
          {
            Serial.println("Failed to read from DHT");
          } else {
            Serial.print("Humidity: "); 
            Serial.print(h);
            Serial.print("% ");
            Serial.print("Temperature: "); 
            Serial.print(t);
            Serial.println("C");
          }      
        }
        if (buffer[0] == '3') {
          UV_ON = 1;
          //turn incubator light off
          digitalWrite(INCUBATOR_LIGHT_PIN, HIGH);
          // turn tent light off.
          digitalWrite(TENT_LIGHT_PIN, HIGH);
          Serial.println("3");
        }
        if (buffer[0] == '4') {
          UV_ON = 0;
          //turn incubator light on
          digitalWrite(INCUBATOR_LIGHT_PIN, LOW);
          // turn tent light on
          digitalWrite(TENT_LIGHT_PIN, LOW);
          Serial.println("4");
        }
        if (buffer[0] == '5') {
          // turn the centrifuge on
          digitalWrite(CENTRIFUGE_PIN, HIGH);
          Serial.println("5");
        }
        if (buffer[0] == '6') {
          // turn the centrifuge off
          digitalWrite(CENTRIFUGE_PIN, LOW);
          Serial.println("6");
        }
      }
    }
  
    if (t < 37 && UV_ON == 0) {
      //turn incubator light on
      digitalWrite(INCUBATOR_LIGHT_PIN, LOW);
    } 
    else {
      //turn incubator light off
      digitalWrite(INCUBATOR_LIGHT_PIN, HIGH);
    }
}
