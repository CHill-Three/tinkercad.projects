#include <Wire.h>

long x = 0;
int slaveAddress = 4;
int buttonPin = 7; // the number of the pushbutton pin
int buttonState = 0; // variable for reading the pushbutton status

void setup()
{
pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input
Wire.begin(); // join i2c bus (address optional for master)
Serial.begin(9600); // start serial for output
}
void loop()
{
// read the state of the pushbutton value:
buttonState = digitalRead(buttonPin);
// check if the pushbutton is pressed. If it is, the buttonState is HIGH:
if (buttonState == HIGH)
{
  x = random(256);
  Serial.print("Random number : ");
  Serial.println(x);
} else 
{
} 
Wire.beginTransmission(slaveAddress); // transmit to device #4
Wire.write(x); // sends x
Wire.endTransmission(); // stop transmitting
delay(200);
}
