#include <HTTPClient.h>

#include <WiFi.h>

char in;

void setup(){
  
  Serial.begin(9600);
  Serial.println("\n... Starting ESP32 ...");

  WiFi.begin("TP-Link_FD7A", "32373561");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
  Serial.println("connected");
}


void loop() {

 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;   
 
   http.begin("http://jsonplaceholder.typicode.com/posts");  //Specify destination for HTTP request

//   http.addHeader("Content-Type", "text/plain");             //Specify content-type header
//   int httpResponseCode = http.POST("request body in text formate");   //Send the actual POST request
   
   http.addHeader("Content-Type", "application/json");             //Specify content-type header
   int httpResponseCode = http.POST("{ \"id\" : \"101\", \"name\": \"inzamam\", \"description\": \"request body in json form\"}");   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{ 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode); 
   }
 
   http.end();  //Free resources
 
 }else{ 
    Serial.println("Error in WiFi connection");    
 }
 
  delay(10000);  //Send a request every 10 seconds
 
}

