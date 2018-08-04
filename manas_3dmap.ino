#include <Servo.h> ;        //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle_y = 0;   
int angle_x = 0;
int angle = 0;
const int trigPin = 11;
const int echoPin = 12; 
long duration;
int distance;

void setup() 
{ 
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
} 
  
void loop() 
{ 
  for(angle_y = 0; angle_y < 180; angle_y += 1)    // command to move from 0 degrees to 180 degrees 
  {  
    for(angle_x = 0; angle_x<180; angle_x+=1)     // command to move from 180 degrees to 0 degrees 
    {                                
      servo_test.write(angle_x);
      delay(15);  
      //command to rotate the servo to the specified angle
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance= duration*0.034/2;
      if (distance>101){
        distance = 100 ;
      }
      // Prints the distance on the Serial Monitor
      Serial.print(angle_x);   
      Serial.print(',');
      Serial.print(angle_y);
      Serial.print(',');     
      Serial.println(distance);
      delay(400);                                                 
    }
    for(angle_x = 180; angle_x>=1; angle_x-=5)     // command to move from 180 degrees to 0 degrees 
     {                                
      servo_test.write(angle_x);              //command to rotate the servo to the specified angle
      delay(5);                       
     } 
    servo_test.write(angle_y);                 //command to rotate the servo to the specified angle
    delay(5);                        
  }
   
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 
  
  
  
}


