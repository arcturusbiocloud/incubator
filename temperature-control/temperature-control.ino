// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to
#define DHTTYPE DHT22 // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

#define INCUBATOR_LIGHT_PIN A1
#define UV_PIN A2
#define TENT_LIGHT_PIN 2

void setup() 
{
    Serial.begin(9600); 
    Serial.println("Arcturus Incubator and lights controller connected");
    Serial.setTimeout(25);
    
    // pin setup
    pinMode(INCUBATOR_LIGHT_PIN, OUTPUT);
    pinMode(UV_PIN, OUTPUT);
    pinMode(TENT_LIGHT_PIN, OUTPUT);
 
    //start with the incubator light on. LOW/HIGH are inverted
    digitalWrite(INCUBATOR_LIGHT_PIN, LOW);
        
    // starts with tent light on. LOW/HIGH are inverted
    digitalWrite(TENT_LIGHT_PIN, LOW);
    
    // start with the uv light off
    digitalWrite(UV_PIN, LOW);
    
    // starts the temperature sensor
    dht.begin();
}

void loop() 
{
    char buffer[64];
    size_t length = 64;
   
    // clean the serial buffer
    memset(buffer,0,sizeof(buffer));
    
    // implement serial read bytes and read command
  
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (t < 37) {
      //turn incubator light on
      digitalWrite(INCUBATOR_LIGHT_PIN, LOW);
    } 
    else {
      //turn incubator light off
      digitalWrite(INCUBATOR_LIGHT_PIN, HIGH);
    }

    // check if returns are valid, if they are NaN (not a number) then something went wrong!
    if (isnan(t) || isnan(h)) 
    {
        Serial.println("Failed to read from DHT");
    } 
    else 
    {
        Serial.print("Humidity: "); 
        Serial.print(h);
        Serial.print(" %\t");
        Serial.print("Temperature: "); 
        Serial.print(t);
        Serial.print(" *C");
    }
}
