// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Tushar Rathore
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 April 2022
// ---------------------------------------------------------------- //

// Connections are as follows:
//attach pin 10 of ARduino to Trig pin of Sensor
// attach pin 11 of ARduino to Echo pin of Sensor
// Give Vcc and Gnd to Sensor from Arduino or any other source 
// Connect LED's +ve to pin 3 4 & 5 and -ve to GND
// ----------------------------------------------------------------


#define TrigPin 10 
#define EchoPin 11 

//variables
long time_taken; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(TrigPin, OUTPUT);  // Sets the trigPin as an OUTPUT 
  pinMode(EchoPin, INPUT);   // Sets the echoPin as an INPUT
  
  Serial.begin(9600);        // Serial Communication is starting with 9600 of baudrate speed
  
  Serial.println("Ultrasonic Sensor HC-SR04 Test begins"); // Printing in Serial Monitor
  
  pinMode(3,OUTPUT);         // Setting the output pins 
  pinMode(4,OUTPUT);         // Setting the output pins  
  pinMode(5,OUTPUT);         // Setting the output pins    
}
void loop() {
  pinMode(3,0);         // Setting the output pins at 0 first 
  pinMode(4,0);         // Setting the output pins at 0 first  
  pinMode(5,0);         // Setting the output pins at 0 first
  
  digitalWrite(TrigPin, 0);   // Setting trig pin to 0/Low
  delayMicroseconds(2);       // Sets the trigPin LOW for 2 microseconds
  
  digitalWrite(TrigPin, 1);   // Setting trig pin to 1/High
  delayMicroseconds(10);      // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  
  digitalWrite(TrigPin, 0); // Reads the echoPin, and returns the time taken by sound wave in travelling (in microseconds)
  
  time_taken = pulseIn(EchoPin, HIGH); // pulseIn calculates the time for which echoPin is high 
  
  // Calculating the distance
  distance = time_taken * 0.034 / 2;
  // Duration is in microseconds , multiplying it with speed of light
  // Dividing it by 2 as the time is for going and coming back for wave
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

        if(distance<5)
  {
    digitalWrite(3,1);      // Turning on 1st LED at 3
    digitalWrite(4,1);      // Turning on 2nd LED at 4   
    digitalWrite(5,1);      // Turning on 3rd LED at 5
    }
        if(distance<10)
  {
    digitalWrite(3,1);      // Turning on 1st LED at 3
    digitalWrite(4,1);      // Turning on 2nd LED at 4    
    }  
        if(distance<15)
  {
    digitalWrite(3,1);      // Turning on only 1st LED at 3
    }


  delay(10);     // 10 miliseconds delay, after that repeat the whole loop.
}
