#include <Servo.h>

#define PIN_SERVO_7  7
#define PIN_SWITCH_BUTTON_5  5
#define PIN_SWITCH_BUTTON_4  4
#define PIN_SWITCH_BUTTON_10  10
#define PIN_SWITCH_BUTTON_12  12
#define PIN_POTENTIOMETER_A0  A0
#define PIN_TEMPERATURE_SENSOR_A1  A1
#define PIN_RAIN_GAUGE_8  8
#define PIN_LIGHT_SENSOR_A5  A5

Servo servomotor_7;

boolean interrupteur_gen;
boolean interrupteur_lames;
boolean interrupteur_lum;
boolean interrupteur_lum2;
int vitesse_vent;
float temp;
int potentiometre;
boolean pluie;
int limite_vent;
int lum_exterieur;

uint16_t getAnalogMean(uint8_t pin, uint8_t n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(pin);
    delay(1);
  }
  return sum / n;
}

float getGroveTemperature(uint8_t pin, uint8_t unit) {
  float R = 1023.0/getAnalogMean(pin, 5) - 1;
  float t = 1/(log(R)/4275+1/298.15) - 273.15; // celsius
  switch (unit) {
    case 1: // fahrenheit
      t = t * 9/5 + 32;
      break;
    case 2: // kelvin
      t += 273.15;
      break;
  }
  return t;
}

void recup_var() {
  interrupteur_gen = digitalRead(PIN_SWITCH_BUTTON_5);
  interrupteur_lames = digitalRead(PIN_SWITCH_BUTTON_4);
  //interrupteur_lum | on = auto ; off = interrupteu_lum2
  interrupteur_lum = digitalRead(PIN_SWITCH_BUTTON_10);
  //interrupteur_lum2 | off = éteindre , on = éclairage standard
  interrupteur_lum2 = digitalRead(PIN_SWITCH_BUTTON_12);
  // Temporaire
  vitesse_vent = analogRead(PIN_POTENTIOMETER_A0);
  temp = getGroveTemperature(PIN_TEMPERATURE_SENSOR_A1, 0);
  potentiometre = analogRead(PIN_POTENTIOMETER_A0);
  pluie = digitalRead(PIN_RAIN_GAUGE_8);
  limite_vent = 90;
  lum_exterieur = getAnalogMean(PIN_LIGHT_SENSOR_A5, 5);
}


void setup() {
  pinMode(0, OUTPUT);
  servomotor_7.attach(PIN_SERVO_7);
  pinMode(PIN_SWITCH_BUTTON_5, INPUT);
  pinMode(PIN_SWITCH_BUTTON_4, INPUT);
  pinMode(PIN_SWITCH_BUTTON_10, INPUT);
  pinMode(PIN_SWITCH_BUTTON_12, INPUT);
  pinMode(PIN_POTENTIOMETER_A0, INPUT);
  pinMode(PIN_TEMPERATURE_SENSOR_A1, INPUT);
  pinMode(PIN_RAIN_GAUGE_8, INPUT);
  pinMode(PIN_LIGHT_SENSOR_A5, INPUT);
  recup_var();
}

void loop() {
  recup_var();
  if (interrupteur_lum) {
    //Mode lumière auto
    // Si la lumière est en dessous de 20% de la capacité du capteur ( 1023 ) alors la lumière s'allume
    if (lum_exterieur <= 1023 * 0.2) {
      digitalWrite(0, HIGH);
    } else {
      digitalWrite(0, LOW);
    }
  } else if (interrupteur_lum2) {
    //Mode lumière standard
    digitalWrite(0, HIGH);
  } else {
    //Mode lumière éteinte
    digitalWrite(0, LOW);
  }
  if (interrupteur_gen) {
    if (interrupteur_lames) {
      //interrupteur lames = 1 -> auto sinon manuel
      if (limite_vent < vitesse_vent) {
        //Mode vent extreme
        servomotor_7.write(45);
      } else if (temp < 2 && pluie) {
        //Mode neige
        servomotor_7.write(90);
      } else if (temp < 2) {
        //Mode Gel
        servomotor_7.write(90);
      } else if (pluie) {
        //Mode pluie
        servomotor_7.write(25);
      }
    } else {
      //Mode Manuel
      servomotor_7.write(potentiometre);
    }
  }
}
