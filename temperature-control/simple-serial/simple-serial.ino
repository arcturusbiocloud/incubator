void setup() {
  // put your setup code here, to run once:
      // serial handshake
    Serial.begin(9600);
}

char buffer[64];
size_t length = 1;
float h = 35.0;
float t = 37.0;

void loop() {   
    // clean the serial buffer
    memset(buffer,0,sizeof(buffer));
  
    // put your main code here, to run repeatedly:
    // implement serial read bytes and read command
    if (Serial.available()) {
      length = Serial.readBytes(buffer, length);
      if (length > 0) {
        if (buffer[0] == '0') {
          Serial.println("0");
        }
        
        if (buffer[0] == '1') {
          Serial.println("1");
        }
        
        if (buffer[0] == '2') {
          // check if returns are valid, if they are NaN (not a number) then something went wrong!
          if (isnan(t) || isnan(h)) {
            Serial.println("Failed to read from DHT");
          } else {
            Serial.print("Humidity: "); 
            Serial.print(h);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(t);
            Serial.println(" *C");
          }      
        }
      }
   }
}
