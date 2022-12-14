//LordEvilFish3DP offical code for the RoboArm
//This is the Serial keyboard input control version for use without the controller
//The computer is meant to directly communicate with the RoboArm through serial communication

//Base motor
const int basePin1 = 10; //All of these pins can be changed to wherever you connect them to
const int basePin2 = 11;
const int pwm1 = 9; //PWM pin, controls the speed of each motor

//First arm(central)
const int arm1pin1 = 12;
const int arm1pin2 = 13;  
const int pwm2 = 6; //These NEED to be pwm pins otherwise they will not work A pwm compatible pin will have "~" next to it

//Pincer Arm Control
const int pincerArmPin1 = A4; //Some analog pins need to be used, there is not enough gpio pins
const int pincerArmPin2 = A3;
const int pwm3 = 3;

//Actual pincers themselves 
const int pincerPin1 = A1;
const int pincerPin2 = A2;
const int pwm4 = 5;

String input;
String userChar;
int length;

void setup() {
  Serial.begin(9600);
  //Base Pins
  pinMode(basePin1, OUTPUT); //Set the state of each pin
  pinMode(basePin2, OUTPUT);
  pinMode(pwm1, OUTPUT);

  //Central arm pins
  pinMode(arm1pin1, OUTPUT);
  pinMode(arm1pin2, OUTPUT);
  pinMode(pwm2, OUTPUT);

  //Pincer Arm Pins
  pinMode(pincerArmPin1, OUTPUT);
  pinMode(pincerArmPin2, OUTPUT);
  pinMode(pwm3, OUTPUT);

  //Pincer pins
  pinMode(pincerPin1, OUTPUT);
  pinMode(pincerPin2, OUTPUT);
  pinMode(pwm4, OUTPUT);
}


void loop() {
  if (Serial.available()) { //This here is used to control the robot using keyboard inputs from the serial monitor 
    input = Serial.readStringUntil('\n');
    length = input.length() - 1;  
    userChar = input.charAt(0);
    //move base
    if (userChar == "q") { //if user inputs q in serial monitor perform action
      Serial.println("moving base anti-clockwise");
      for(int x = 0; x <= length; x++){      
        moveBaseF(); //call function moveBaseF
        Serial.println(x + 1);
      } 
      
    } 
    else if (userChar == "a") {
      Serial.println("moving base clockwise");
      for(int x = 0; x <= length; x++){      //these for loops allow the the function to run(spin motor) to spin a given amount of time through the character length 
        moveBaseB();
        Serial.println(x + 1);
      } 
    }
    //turns arm at base
    else if (userChar == "w") {
      Serial.println("turning base arm clockwise");
      for(int x = 0; x <= length; x++){      
        moveBaseArmF();
        Serial.println(x + 1);
      }          
      
      
    } 
    else if (userChar == "s") {
      Serial.println("turning base arm anti-clockwise");
      for(int x = 0; x <= length; x++){      
        moveBaseArmB();
        Serial.println(x + 1);
      }       
      
      
    }
    //turns pincer arm
    else if (userChar == "e") {
      Serial.println("turning pincer arm clockwise");
      for(int x = 0; x <= length; x++){      
        turnPincerF();
        Serial.println(x + 1);
      }       
      
      
    } 
    else if (userChar == "d") {
      Serial.println("turning pincer arm anti-clockwise");
      for(int x = 0; x <= length; x++){      
        turnPincerB();
        Serial.println(x + 1);
      }       
      
      
    }
    //closes and opens pincer arm
    else if (userChar == "r") {
      Serial.println("closing pincer");
      for(int x = 0; x <= length; x++){      
        openPincer();
        Serial.println(x + 1);
      }       
      
      
    }
    else if (userChar == "f") {
      Serial.println("opening pincer");
      for(int x = 0; x <= length; x++){      
        closePincer();
        Serial.println(x + 1);
      }       
      
      
    }    
  }
}

//---turns entire base---
void moveBaseF() {
  analogWrite(pwm1, 250); //Set motor speed to max
  digitalWrite(basePin1, HIGH);
  digitalWrite(basePin2, LOW);
  delay(150); //Let motor spin for 150ms, the lower the value the less degrees the arm turns
  analogWrite(pwm1, 0); //Set motor speed to 0 so it stops spinning 
}

void moveBaseB() {
  analogWrite(pwm1, 250);
  digitalWrite(basePin1, LOW); //Swapping these lets you reverse motor direction
  digitalWrite(basePin2, HIGH);//
  delay(150);
  analogWrite(pwm1, 0);
}

// ----turn arm mounted to the base---
void moveBaseArmF() {
  analogWrite(pwm2, 250);
  digitalWrite(arm1pin1, HIGH);
  digitalWrite(arm1pin2, LOW);
  delay(50);
  analogWrite(pwm2, 0);
}
void moveBaseArmB() {
  analogWrite(pwm2, 250);
  digitalWrite(arm1pin1, LOW);
  digitalWrite(arm1pin2, HIGH);
  delay(50);
  analogWrite(pwm2, 0);
}
// --- Turn pincer Arm ---
void turnPincerF() {
  analogWrite(pwm3, 250);
  digitalWrite(pincerArmPin1, HIGH);
  digitalWrite(pincerArmPin2, LOW);
  delay(30);
  analogWrite(pwm3, 0);
}
void turnPincerB() {
  analogWrite(pwm3, 250);
  digitalWrite(pincerArmPin1, LOW);
  digitalWrite(pincerArmPin2, HIGH);
  delay(30);
  analogWrite(pwm3, 0);
}
//close and open pincers
void closePincer() {
  analogWrite(pwm4, 250);
  digitalWrite(pincerPin1, HIGH);
  digitalWrite(pincerPin2, LOW);
  delay(50);
  analogWrite(pwm4, 0);
}

void openPincer() {
  analogWrite(pwm4, 250);
  digitalWrite(pincerPin1, LOW);
  digitalWrite(pincerPin2, HIGH);
  delay(50);
  analogWrite(pwm4, 0);
}







