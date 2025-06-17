#define BLYNK_TEMPLATE_ID "TMPL3es2-xAmn"
#define BLYNK_TEMPLATE_NAME "Wireless project"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Define motor pins (only two motors)
#define ENA D1
#define IN1 D2
#define IN2 D3
#define ENB D4
#define IN3 D5
#define IN4 D6

// Variables for the Blynk widget values
int x = 50;
int y = 50;
int Speed = 150;

char auth[] = "MHbVzeq_EP0Ocl5TJVDcT3Mhivm7BD2u";
char ssid[] = "realme 9";
char pass[] = "21012005";

void setup() {
  Serial.begin(9600);
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

BLYNK_WRITE(V0) {
  x = param[0].asInt();
}

BLYNK_WRITE(V1) {
  y = param[0].asInt();
}

BLYNK_WRITE(V2) {
  Speed = param.asInt();
}

void smartcar() {
  if (y > 70) {
    carForward();
    Serial.println("Moving Forward");
  } else if (y < 30) {
    carBackward();
    Serial.println("Moving Backward");
  } else if (x < 30) {
    carLeft();
    Serial.println("Turning Left");
  } else if (x > 70) {
    carRight();
    Serial.println("Turning Right");
  } else {
    carStop();
    Serial.println("Stop");
  }
}

void loop() {
  Blynk.run();
  smartcar();
}

void carForward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carBackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void carRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}