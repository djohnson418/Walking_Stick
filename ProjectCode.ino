#define trigPin 8
#define echoPin 9
#define vibe 4
#define trigPin2 10
#define echoPin2 11
#define vibe2 2
#define trigPin3 12
#define echoPin3 13
#define vibe3 A5
#define vibe4 5
#define vibe5 3
#define vibe6 7
#define motor 6
//#define button 1


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(vibe, OUTPUT);
  pinMode(vibe2, OUTPUT);
  pinMode(vibe3, OUTPUT);
  pinMode(vibe4, OUTPUT);
  pinMode(vibe5, OUTPUT);
  pinMode(vibe6, OUTPUT);
  pinMode(motor, OUTPUT);
}

int counter = 0;

void loop() {
  long duration, distance, duration2, distance2, duration3, distance3;

  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin2, HIGH);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);

if (counter == 0) {
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
    if (distance < 100) {
      digitalWrite(vibe,HIGH);
      digitalWrite(vibe4,HIGH);
      analogWrite(motor,255);
  }
    else if (distance < 150) {
      digitalWrite(vibe,HIGH);
      digitalWrite(vibe4,LOW);
      analogWrite(motor,0);
    }
    else {
      digitalWrite(vibe,LOW);
      digitalWrite(vibe4,LOW);
      analogWrite(motor,0);
  }
 // Serial.print(distance);
 // Serial.println(" cm for Sensor 1");
}  

if (counter == 1) {
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2.0) / 29.1;
    if (distance2 < 100) {
      digitalWrite(vibe2,HIGH);
      digitalWrite(vibe5,HIGH);
      analogWrite(motor,255);
  }
  else if (distance2 < 150) {
      digitalWrite(vibe2,HIGH);
      digitalWrite(vibe5,LOW);
      analogWrite(motor,0);
  }
    else {
      digitalWrite(vibe2,LOW);
      digitalWrite(vibe5,LOW);
      analogWrite(motor,0);
  }
 // Serial.print(distance2);
 // Serial.println(" cm for Sensor 2");
}

if (counter == 2) {
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (long)(duration3/2.0) / 29.1;
    if (distance3 < 100) {
      digitalWrite(vibe3,HIGH);
      digitalWrite(vibe6,HIGH);
      analogWrite(motor,255);
  }
    else if (distance3 < 150) {
      digitalWrite(vibe3,HIGH);
      digitalWrite(vibe6,LOW);
      analogWrite(motor,0);
    }
    else {
      digitalWrite(vibe3,LOW);
      digitalWrite(vibe6,LOW);
      analogWrite(motor,0);
  }
  // Serial.print(distance3);
  // Serial.println(" cm for Sensor 3");
  counter = -1;
}
  counter = counter + 1;
 //GRAPHING
  Serial.print("Sensor1:");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Sensor2:");
  Serial.print(distance2);
  Serial.println(" cm");
  
  Serial.print("Sensor3:");
  Serial.print(distance3);
  Serial.println(" cm\n");

  Serial.print("Sensor1_inches:");//Sensor 1 in inches
  Serial.print(distance / 2.54);
  Serial.println(" in");

  Serial.print("Sensor2_inches:");//Sensor 2 in inches
  Serial.print(distance2 / 2.54);
  Serial.println(" in");

  Serial.print("Sensor3_inches:");//Sensor 3 in inches
  Serial.print(distance3 / 2.54);
  Serial.println(" in\n");

}