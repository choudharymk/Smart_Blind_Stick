const int trigPin = 2;
const int echoPin = 3;

const int trigPin1 = 4;
const int echoPin1 = 5;
//
//const int trigPin2 = 6;
//const int echoPin2 = 7;
//
//const int trigPin3 = 8;
//const int echoPin3 = 9;

const int bzPin = 10;

long duration;
long duration1;
//long duration2;
//long duration3;

int distance;
int distance1;
//int distance2;
//int distance3;

void setup() {
  
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
//
//pinMode(trigPin2, OUTPUT);
//pinMode(echoPin2, INPUT);
//
//pinMode(trigPin3, OUTPUT);
//pinMode(echoPin3, INPUT);

pinMode(bzPin, OUTPUT);

Serial.begin(9600);
}
void loop() {

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);

digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);


//digitalWrite(trigPin2, HIGH);
//delayMicroseconds(10);
//digitalWrite(trigPin2, LOW);
//duration2 = pulseIn(echoPin2, HIGH);
//
//
//digitalWrite(trigPin3, HIGH);
//delayMicroseconds(10);
//digitalWrite(trigPin3, LOW);
//duration3 = pulseIn(echoPin3, HIGH);

distance= duration*0.034/2;
distance1= duration1*0.034/2;
//distance2= duration2*0.034/2;
//distance3= duration3*0.034/2;
Serial.println(distance);
Serial.println(distance1);
Serial.println();
Serial.println();
digitalWrite(bzPin, LOW);
if (distance < 250){
  if(distance1 < 100) {
    if ( abs(distance-distance1) < 70 && abs(distance-distance1) > 40) {
      digitalWrite(bzPin, HIGH);
      delay(500);
      Serial.println("blink1 ");
      digitalWrite(bzPin, LOW);
      delay(2000);
    } else if (distance < 70)  {
      if (distance < 70) {
        digitalWrite(bzPin, HIGH);
        delay(2000);
        Serial.println("blink2 " );
        digitalWrite(bzPin, LOW);
        delay(2000);
      }
    }
  } else {
    if (distance < 70) {
      digitalWrite(bzPin, HIGH);
      delay(1000);
      Serial.println("blink3 ");
      digitalWrite(bzPin, LOW);
      delay(2000);
    }
  }
}
}
