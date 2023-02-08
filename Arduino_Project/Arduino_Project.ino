#define trigPin 2
#define echoPin 3

#include <SD.h>
#define SD_ChipSelectPin 10
#include <TMRpcm.h>
#include <SPI.h>

// Define variables:
long duration;
int distance;

TMRpcm tmrpcm;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);

tmrpcm.speakerPin= 9;
if(!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return; }
  
tmrpcm.setVolume(5);

}
void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance= duration*0.034/2;
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  if(distance >= 380)  {
  Serial.println("Out of range");
  }
  else {
  Serial.print(distance);
  Serial.println(" cm");
   }
    if (distance <=330 && distance >180) {
      tmrpcm.play("Tri.wav");    
    }
    if (distance <=180 && distance > 80) {
      tmrpcm.play("Dva.wav");
    }

    if (distance <=80 )  {
    tmrpcm.play ("Stani.wav");
    delay(4500); 
   } 
   
    delay(1000);
   }
