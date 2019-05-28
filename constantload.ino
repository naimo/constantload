//int CURRENT = 1000; /* mA */
//int RSHUNT = 200; /* mR */

// pwm duty cycle (50 <> 1A)
char DEFAULT_DUTY = 50;

int CUTOFF = 3000;

int dacPin = 9;    // LED connected to digital pin 9
int currentPin = A0;
int voltPin = A7;

enum stat {
  DISARMED,
  ARMED,
  DISCHARGING
};

stat discharging = DISARMED;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);

  pinMode(9, OUTPUT);

  // configure Timer1 pwm output, high frequency
  TCCR1A = _BV(COM1A1) | _BV(WGM10);
  TCCR1B = _BV(WGM12) | _BV(CS10);
  
  // start with 0% duty cycle
  OCR1AL = 0;
}

void loop() {
  if (Serial.available()){
      switch (Serial.read()) {
        case '0':
        case 'd':
          OCR1AL = 0;
          discharging = DISARMED;
          break;
        case 'a':
          discharging = ARMED; 
          break;
        case '1':
          if (discharging != DISARMED){
            OCR1AL = 50;
            discharging = DISCHARGING;
          }
          break;
        case '2':
          if (discharging != DISARMED){
            OCR1AL = 100;
            discharging = DISCHARGING;
          }
          break;
      } 
    }
    
    int current, volt;
    current = map(analogRead(currentPin), 0, 1023, 0, 5500);
    volt = map(analogRead(voltPin), 0, 1023, 0, 4565);
  
    Serial.print(millis());
    Serial.print(',');    
    Serial.print(current);
    Serial.print("mA,");
    Serial.print(volt);
    Serial.print("mV,");
    Serial.println(discharging);
    delay(100);

    if(volt < CUTOFF){
      OCR1AL = 0;
      discharging = DISARMED;
    }
}
