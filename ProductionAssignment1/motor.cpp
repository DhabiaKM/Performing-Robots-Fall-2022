


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  // pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT); 
  pinMode(6,OUTPUT); 
  pinMode(7,OUTPUT); 
  Serial.print("i worked");
}

int number = 0; 

int leftMotor= 0;   //(2 and three)

int rightMotor= 0; //(6 and seven)

unsigned long previousMillis=0; 

//intervals for the panic attacks

// int stopInterval= 400;

//Jittering
const long jittering= 300; 
int jitterCount=25; 
int jitterCounter=0;
bool stopJitter=false; 

//Spinning 
const long Spin= 9000; 
int spinCount=10; 
int spinCounter=0; 
bool stopSpin=false; 

//Resolved
const long resolved= 11000; 
int resolvedCounter=0; 
bool resetAll=false; 


// // the loop function runs over and over again forever
void loop() {
  unsigned long currentMillis = millis();
  //Jittering  
  if(jitterCounter<=jitterCount&& currentMillis - previousMillis >= jittering &&stopJitter==false){
    previousMillis = currentMillis;
    Serial.print("hiii");
    
    if(leftMotor==0 && rightMotor==0){ 
      leftMotor= 200;
      rightMotor= 200;
    }
    else{ 
      leftMotor= 0;
      rightMotor= 0;
    }

    analogWrite(3,leftMotor); 
    analogWrite(6,rightMotor); 

    jitterCounter=jitterCounter+1;

}
  if (jitterCounter==jitterCount){ 
    stopJitter=true; 
    Serial.print("im here");
  }  

  // Spinning 
  if(currentMillis-previousMillis>=Spin && spinCounter<=spinCount && stopJitter==true) {
      previousMillis = currentMillis;
      if(leftMotor==0 && rightMotor==0){ 
        leftMotor= 0;
        rightMotor= 200;
        }
      else{ 
        leftMotor= 0;
        rightMotor= 0;        
      }
       
      analogWrite(3,leftMotor); 
      analogWrite(6,rightMotor);  
        
      spinCounter=spinCounter+1;
  } 
  if (spinCount==spinCounter){ 
    stopSpin=true; 
  }

  //Resolved 
  if (stopSpin==true &&  resolvedCounter<=3 && currentMillis-previousMillis>=resolved ){ 
      previousMillis = currentMillis;
    if(leftMotor==0 && rightMotor==0){ 
        leftMotor= 200;
        rightMotor= 200;
        }
      else{ 
        leftMotor=0; 
        rightMotor=0;
      }
      analogWrite(3,leftMotor); 
      analogWrite(6,rightMotor);  
      resolvedCounter= resolvedCounter+1; 
       

  }

  if (resolvedCounter==3){ 
    jitterCounter=0; 
    spinCounter=0; 
    stopJitter=false; 
    stopSpin=false;
    resolvedCounter=0;

  }



} 






