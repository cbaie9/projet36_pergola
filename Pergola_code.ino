// Projet 36h | Pergola bio -> capteur buggé a moitée donc le code est modifié en conséquence 
// -> branchez sur pin exact 
//
// Si reconstruit pour porte ouvert jf
// -> Dernière ver https://github.com/cbaie9/projet36_pergola
// Crédits : clement ( cbaie9 ) : dev, gaspard : dev, iwann + adrien -> onshape
#include <Servo.h>
#include <Wire.h>
#include <rgb_lcd.h>

#define PIN_SERVO_7  7
#define PIN_TEMPERATURE_SENSOR_A14  A14                          
#define PIN_POTENTIOMETER_A2  A4

Servo servomotor_7;
rgb_lcd lcdRgb;

String texte1;
int loop_lrgb;
boolean interrupteur_gen;
boolean interrupteur_lames;
boolean interrupteur_lum;
boolean interrupteur_lum2;
int vitesse_vent;
float temp;
int potentiometre;
boolean pluie;
float limite_vent;
int lum_exterieur;

uint16_t getAnalogMean(uint8_t pin, uint8_t n) { //Stabilitée des capteur  ; moyenne des valeur 
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(pin);
    delay(1);
  }
  return sum / n;
}

float getGroveTemperature(uint8_t pin, uint8_t unit) { // Code constructeur de conversion, source Seeed, modifié par vittascience
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

void serial_setupConnection(int baudrate) {
  Serial.begin(baudrate);
  while (!Serial) {
    Serial.println("En attente de l'ouverture du port série...");
    delay(1000);
  }
  Serial.println("Port série activé. Baudrate: " + String(baudrate));
  delay(50);
}

void lcd() {
  if (interrupteur_lum) {
    texte1 = "Automatique";
  } else {
    if (interrupteur_lum2) {
      texte1 = "Manuel: On";
    } else {
      texte1 = "Manuel: Off";
    }
  }
  lcdRgb.setRGB(51, 51, 255);
  lcdRgb.setCursor(0, 0);
  lcdRgb.print(String((String("Lumiere : ") + String(texte1))));
  loop_lrgb += 1;
  if (loop_lrgb >= 0 && loop_lrgb < 60) {
    lcdRgb.setCursor(0, 1);
    lcdRgb.print(String((String("Lum :  ") + String(lum_exterieur))));
  } else if (loop_lrgb >= 60 && loop_lrgb < 120) {
    lcdRgb.setCursor(0, 1);
    lcdRgb.print(String((String("Temp : ") + String(temp))));
  } else if (loop_lrgb > 120) {
    loop_lrgb = 0;
  }
}

void recup_var() {
  //Mettre "true" de interrupteur gen sur d5 avant prod
  interrupteur_gen = true;
  interrupteur_lames = digitalRead(4);
  //interrupteur_lum | on = auto ; off = interrupteu_lum2
  //Mettre "true" de interrupteur lum sur d10 avant prod
  interrupteur_lum = true;
  //interrupteur_lum2 | off = éteindre , on = éclairage standard
  interrupteur_lum2 = digitalRead(12);
  vitesse_vent = analogRead(A6);
  temp = getGroveTemperature(PIN_TEMPERATURE_SENSOR_A14, 0);
  potentiometre = analogRead(PIN_POTENTIOMETER_A2);
  pluie = digitalRead(6);
  limite_vent = 1023 * 0.7;
  lum_exterieur = analogRead(A2);
  lum_exterieur = map(lum_exterieur, 0, 1023, 0, 100);
  Serial.println((String("Capteur lum : ") + String(lum_exterieur)));
  Serial.println((String("Capteur pluie : ") + String(pluie)));
  Serial.println((String("Capteur temp : ") + String(temp)));
}


void setup() {
  Serial.begin(9600);
  lcdRgb.begin(16, 2);
  servomotor_7.attach(PIN_SERVO_7);  // Attacher le servo une seule fois dans setup
  servomotor_7.write(0);  // Mettre le servo à 0 degrés
  pinMode(PIN_TEMPERATURE_SENSOR_A14, INPUT);
  pinMode(PIN_POTENTIOMETER_A2, INPUT);  // Définir la broche du potentiomètre comme entrée
  pinMode(A4, INPUT);
  pinMode(A2, INPUT);
  pinMode(4, INPUT);
  pinMode(10, OUTPUT); // inter lum 1
  pinMode(12, INPUT); // inter lum 2
  pinMode(6, INPUT); // pluie
  pinMode(13, INPUT); // lum temp
  serial_setupConnection(9600);
  recup_var();
  lcd();
}

void loop() {
  //Mettre if interupteur gen avant prod final
  recup_var();
  lcd();
  if (interrupteur_lum) {
    //Mode lumière auto
    // Si la lumière est en dessous de 20% de la capacité du capteur ( 1023 ) alors la lumière s'allume
    if (lum_exterieur <= 50) {
      Serial.println((String("mater")));
      digitalWrite(10, HIGH);
    } else {
      Serial.println((String("logic")));
      digitalWrite(10, LOW);
    }
  } else if (interrupteur_lum2) {
    //Mode lumière standard
    digitalWrite(10, HIGH);
  } else {
    //Mode lumière éteinte
    digitalWrite(10, LOW);
  }
  if (interrupteur_lames) {
    //interrupteur lames = 1 -> auto sinon manuel
    if (limite_vent < vitesse_vent) {
      //Mode vent extreme
      lcdRgb.begin(16, 2);
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("                ")); //Effacer la ligne haut du lcd
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("Mode Vent Extrm"));
      servomotor_7.write(45);
      
    } else if (temp < 2 && pluie) {
      //Mode neige
      lcdRgb.begin(16, 2);
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("                ")); //Effacer la ligne haut du lcd
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("Mode Neige"));
      servomotor_7.write(90);
    } else if (temp < 2) {
      //Mode Gel
      lcdRgb.begin(16, 2);
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("                ")); //Effacer la ligne haut du lcd
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("Mode gel"));
      servomotor_7.write(90);
    } else if (pluie) {
      //Mode pluie
      lcdRgb.begin(16, 2);
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("                ")); //Effacer la ligne haut du lcd
      lcdRgb.setCursor(0, 0);
      lcdRgb.print(String("Mode Neige"));
      servomotor_7.write(25);
    }
  } else {
    //Mode Manuel
    int potValue = analogRead(PIN_POTENTIOMETER_A2);  // Lire la valeur du potentiomètre
    float angle = (potValue / 1023.0) * 90;  // Convertir la valeur en angle (0 à 180 degrés)
    servomotor_7.write(angle);  // Définir l'angle du servo
    delay(15);  // Ajouter un léger délai pour stabiliser le signal
  }
}
