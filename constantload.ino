int CURRENT = 1000; /* mA */
int RSHUNT = 200; /* mR */

int dacPin = 9;    // LED connected to digital pin 9
int currentPin = A0;
int voltPin = A7;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);

  pinMode(9, OUTPUT);
  
  TCCR1A = _BV(COM1A1) | _BV(WGM10);
  TCCR1B = _BV(WGM12) | _BV(CS10);

  OCR1AL = 118;
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
