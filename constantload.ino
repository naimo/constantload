/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fading
*/

int CURRENT = 1000; /* mA */
int RSHUNT = 200; /* mR */

int dacPin = 9;    // LED connected to digital pin 9
int currentPin = A0;
int voltPin = A7;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);

  analogWrite(dacPin, 120);
}

void loop() {
  int current, volt;

  current = map(analogRead(currentPin), 0, 1023, 0, 5500);
  volt = map(analogRead(voltPin), 0, 1023, 0, 4522);
  
  Serial.print(current);
  Serial.print("mA,");
  Serial.print(volt);
  Serial.println("mV");
  delay(1000);
}
