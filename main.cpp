#include <ESP8266HTTPClient.h>

#include <ESP8266WiFi.h>


// WiFi config
const char ssid[] = "Connectify-me";
const char password[] = "qwert12345";
 
// Server, file, and port
const char hostname[] = "adafruit.com";
const String uri = "/testwifi/index.html";
const int port = 80;
 
// WiFiClient object
WiFiClient client;
 
void setup() {
 
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
 
    http.begin("http://difpedia.a2hosted.com/api/makes/2");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
 
    }
 
    http.end();   //Close connection
 
  }
 
  delay(10000);    //Send a request every 10 seconds
  
}