#include <SoftwareSerial.h>       //Software Serial library
SoftwareSerialespSerial(2, 3);   //Pin 2 and 3 act as RX and TX. Connect them to TX and RX of ESP8266      
#define DEBUG true
String mySSID = "SwastikDas";       // WiFi SSID
String myPWD = "swastikdas"; // WiFi Password
String myAPI = "Y30OKFT2Y42Z69N6";   // API Key
String myHOST = "api.thingspeak.com";
String myPORT = "80";
String myFIELD1 = "field1";
String myFIELD2 = "field2"; 
String myFIELD3 = "field3"; 
int sendVal1;
int sendVal2;
int sendVal3;
int sensorpin1=A0;
int sensorpin2=A1;
int sensorpin3=A3;
void setup()
{
pinMode(sensorpin1,INPUT);
pinMode(sensorpin2,INPUT);
pinMode(sensorpin3,INPUT);
Serial.begin(9600);
espSerial.begin(115200);

espData("AT+RST", 1000, DEBUG);                      //Reset the ESP8266 module
espData("AT+CWMODE=1", 1000, DEBUG);                 //Set the ESP mode as station mode
espData("AT+CWJAP=\""+ mySSID +"\",\""+ myPWD +"\"", 1000, DEBUG);   //Connect to WiFi network
espData("AT+RST", 1000, DEBUG);
espData("AT+CWMODE=1", 1000, DEBUG); 
espData("AT+CWJAP=\""+ mySSID +"\",\""+ myPWD +"\"", 1000, DEBUG);
  /*while(!esp.find("OK")) 
  {          
      //Wait for connection
  }*/
delay(600);

}

void loop()
  {
    /* Here, I'm using the function random(range) to send a random value to the 
ThingSpeak API. You can change this value to any sensor data
so that the API will show the sensor data  
    */
delay(500);
    sendVal1 = analogRead(sensorpin1);// Send a random number between 1 and 10
    String sendData1 = "GET /update?api_key="+ myAPI +"&"+ myFIELD1 +"="+String(sendVal1);
espData("AT+CIPMUX=1", 1000, DEBUG);       //Allow multiple connections
espData("AT+CIPSTART=0,\"TCP\",\""+ myHOST +"\","+ myPORT, 1000, DEBUG);
espData("AT+CIPSEND=0," +String(sendData1.length()+4),1000,DEBUG); 
espSerial.find(">"); 
espSerial.println(sendData1);
Serial.print("Value to be sent1: ");
Serial.println(sendVal1);
espData("AT+CIPCLOSE=0",1000,DEBUG);
delay(500);

 sendVal2 = analogRead(sensorpin2);// Send a random number between 1 and 10
    String sendData2 = "GET /update?api_key="+ myAPI +"&"+myFIELD2 +"="+String(sendVal2);
espData("AT+CIPMUX=1", 1000, DEBUG);       //Allow multiple connections
espData("AT+CIPSTART=0,\"TCP\",\""+ myHOST +"\","+ myPORT, 1000, DEBUG);
espData("AT+CIPSEND=0," +String(sendData2.length()+4),1000,DEBUG); 
espSerial.find(">"); 
espSerial.println(sendData2);
Serial.print("Value to be sent2: ");
Serial.println(sendVal2);
espData("AT+CIPCLOSE=0",1000,DEBUG);
delay(500);
sendVal3 = analogRead(sensorpin3);// Send a random number between 1 and 10
    String sendData3 = "GET /update?api_key="+ myAPI +"&"+myFIELD3 +"="+String(sendVal3);
espData("AT+CIPMUX=1", 1000, DEBUG);       //Allow multiple connections
espData("AT+CIPSTART=0,\"TCP\",\""+ myHOST +"\","+ myPORT, 1000, DEBUG);
espData("AT+CIPSEND=0," +String(sendData3.length()+4),1000,DEBUG); 
espSerial.find(">"); 
espSerial.println(sendData3);
Serial.print("Value to be sent3: ");
Serial.println(sendVal3);
espData("AT+CIPCLOSE=0",1000,DEBUG);
delay(500);


  }

  String espData(String command, constint timeout, boolean debug)
{
Serial.print("AT Command ==> ");
Serial.print(command);
Serial.println("     ");

  String response = "";
espSerial.println(command);
longint time = millis();
while ( (time + timeout) >millis())
  {
while (espSerial.available())
    {
char c = espSerial.read();
response += c;
    }
  }
if (debug)
  {
    //Serial.print(response);
  }
return response;
}
