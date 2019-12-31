float a;
float b;
floatanalogpin=A0;
floatdb; 
float d;                           
void setup()
{
pinMode(A0,INPUT);
Serial.begin(9600);
}
void loop()
{
  a=float (analogRead(A0));
db=float((a-10)/12);
b=float(db+60);
d=float(100+db);
if(db>23)
 {
Serial.print(db,2);
Serial.print("decible");
 }
if(db<23&&db>10)
 {
Serial.print(b,2);
Serial.print("deceible");
 }  
if(db<10)
{
Serial.print(d,2);
Serial.print("deceible");  
  }  
Serial.print("\n");
delay(1000);
}
