#include <ESP8266HTTPClient.h>

#include <ESP8266WiFi.h>


// WiFi config
const char ssid[] = "Connectify-me";
const char password[] = "qwert12345";

const int pin = 8;
 
// WiFiClient object
WiFiClient client;
 
void setup() {

 pinMode(pin,OUTPUT);
  // Initialize Serial
  Serial.begin(9600);
  delay(100);
 
  // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
 
  // Show that we are connected
  Serial.println("Connected!");
}
 
void loop() {
 
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://dry-brook-43259.herokuapp.com/bulbs/status");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);
      if(payload == "ON"){                     //Print the response payload
        digitalWrite(pin,HIGH);
         Serial.println("Should Glow the Blub");
    }else{
      digitalWrite(pin,LOW);
      
         Serial.println("Should not Glow the Blub");
    }
 
    http.end();   //Close connection
 
  }
 
  delay(5000);    //Send a request every 10 seconds
  }
}