const int anemometerPin = A0;
volatile int rotationCount = 1;
unsigned long lastMillis = 0;
const int sampleTime = 1000; // Temps d'échantillonnage en millisecondes

void setup() {
  Serial.begin(9600); // Initialiser la communication série
  pinMode(anemometerPin, INPUT_PULLUP); // Config broche comme entrée avc pull-up
  attachInterrupt(digitalPinToInterrupt(anemometerPin), countRotation, FALLING); // Interruption sur front descendant
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= sampleTime) {
    detachInterrupt(digitalPinToInterrupt(anemometerPin)); // Désactiver l'interruption pour calculer en toute sécurité

    float windSpeed = calculateWindSpeed(rotationCount);
    Serial.print("Vitesse du vent: ");
    Serial.print(windspeed_kmh);
    Serial.println(" km/h");

    rotationCount = 0; // Réinitialiser le compteur
    lastMillis = currentMillis;
    
    attachInterrupt(digitalPinToInterrupt(anemometerPin), countRotation, FALLING); // Réactiver l'interruption
  }
}

void countRotation() {
  rotationCount++;
}

float calculateWindSpeed(int rotations) {
  // Calibrer en fonction du capteur spécifique. Par exemple :
  float circumference = 0.3; // Circonférence du capteur en mètres (à ajuster selon le modèle)
  float rotationsPerSecond = rotations / (sampleTime / 1000.0);
  float windSpeed = rotationsPerSecond * circumference; // Vitesse en m/s
  float windspeed_kmh = windSpeed*3.6:

  return windspeed_kmh;
}
