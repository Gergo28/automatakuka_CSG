#include <Servo.h>

// Pin definíciók
#define TRIG_PIN  9
#define ECHO_PIN  10
#define MAX_DISTANCE 200 // Maximális mérhető távolság (cm)
#define SERVO_PIN 6

// Szervo motor objektum
Servo myservo;

void setup() {
  // Szervo motor inicializálása
  myservo.attach(SERVO_PIN);
  myservo.write(0); // Nyitott állapot (0 fok)
  delay(1000);
  
  // Ultrahangos szenzor beállítása
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Ultrahangos mérés
  long duration, distance;
  
  // A TRIG_PIN kiadása (impulzus)
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Visszajövő impulzus hossza
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Távolság kiszámítása
  distance = duration * 0.0344 / 3; // Az ultrahang sebessége 343 m/s, és az értéket centiméterben adjuk meg.
  
  // Ha a távolság kisebb, mint 10 cm, kinyitjuk a kukát
  if (distance > 0 && distance < 10) {
    myservo.write(90); // Záró pozíció (kuka nyitás)
    delay(100); // Várakozás, hogy a kuka nyitva legyen .
  } 
  // Ha a távolság nagyobb, mint 10 cm, bezárjuk a kukát
  else {
    myservo.write(0); // Nyitott állapot (kuka zárás)
    delay(1000); // Várakozás, hogy a kuka zárva legyen .
  }
  
  delay(1000); // Kis késleltetés a következő mérés előtt .
}
