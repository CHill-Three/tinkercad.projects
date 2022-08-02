#include <Wire.h>

// The pins to which we've wired each of the LEDs
int ledPins[] = {5,6,7,8,9,10,11,12};

// The number we're going to display.
byte count;

long randNumber;
int x;

void setup()
{
// Start the I2C Bus as Slave on address 4
Wire.begin(4);
// Attach a function to trigger when something is received.
Wire.onReceive(receiveEvent);
Serial.begin(9600);           // start serial for output
}

void receiveEvent(int bytes)
{
x = Wire.read(); // read one character from the I2C
count = x;
}

/*
 *  Show a single number.
 */
void dispBinary(byte n)
{
  for (byte i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], n & 1);
    n /= 2;
  }
}

void loop()
{
Serial.print("The user has entered the number: ");
Serial.println(x);
dispBinary(count);
delay(500);
Wire.endTransmission(); // stop transmitting
delay(500);
}
