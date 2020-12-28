// Includes the Servo library
#include <Servo.h>
#include<SoftwareSerial.h>

char s;

SoftwareSerial BTSerial(2,3);

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int pingPin = 11;
const int echoPin = 10;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(pingPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  BTSerial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  if(BTSerial.available())
  {
    s=BTSerial.read();
  }
  if(s!='a')
  {
  for(int i=0;i<=360;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  BTSerial.print(i); // Sends the current degree into the Serial Port
  BTSerial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  BTSerial.print(distance); // Sends the distance value into the Serial Port
  BTSerial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=0;i>360;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  BTSerial.print(i);
  BTSerial.print(",");
  BTSerial.print(distance);
  BTSerial.print(".");
  }
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   //inches = microsecondsToInches(duration);
   distance = microsecondsToCentimeters(duration);
   //Serial.print(inches);
  // Serial.print("in, ");
   //Serial.print(cm);
   //Serial.print("cm");
   //Serial.println();
   return distance;
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
  
//  digitalWrite(trigPin, LOW); 
  //delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  //digitalWrite(trigPin, HIGH); 
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);
  //duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  //distance= duration*0.034/2;
  //return distance;
//}