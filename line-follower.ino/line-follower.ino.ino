const int LeftSensor = A2;
const int RightSensor = A0;

#define leftMa 2
#define leftMb 3
#define rightMa 4
#define rightMb 5

#define leftLed 12
#define rightLed 11


int lSensor = 0;
int rSensor = 0;
int left = 0;
int right = 0;
//const int trigger = 300;

void setup(){
  delay(500);
  Serial.begin(9600);
pinMode(leftMa ,OUTPUT);
pinMode(leftMb,OUTPUT);
pinMode(rightMa,OUTPUT);
pinMode(rightMb,OUTPUT);
pinMode(leftLed,OUTPUT);
pinMode(rightLed,OUTPUT);
digitalWrite(leftMa,LOW);
digitalWrite(leftMb,LOW);
digitalWrite(rightMa,LOW);
digitalWrite(rightMb,LOW);
digitalWrite(leftLed,LOW);
digitalWrite(rightLed,LOW);
for (int i = 0; i < 10; i++){
  digitalWrite(leftLed,HIGH);
  digitalWrite(rightLed,HIGH);
  delay(100);
  digitalWrite(rightLed,LOW);
  digitalWrite(leftLed,LOW); 
  delay(100);
}

  }


void loop() {

  lSensor = analogRead(A0);
  delay(5);
  rSensor = analogRead(A1);
  delay(5);
  
  if (lSensor < 500 && rSensor < 500){
    
    Serial.println("forward");
    digitalWrite(leftMa,HIGH);
    digitalWrite(leftMb,LOW);
    digitalWrite(rightMa,HIGH);
    digitalWrite(rightMb,LOW);
  }
  else if (lSensor < 500 && rSensor > 500){//turn right
    Serial.println("right");
    digitalWrite(leftMa,HIGH);
    digitalWrite(leftMb,LOW);
    digitalWrite(rightMa,LOW);
    digitalWrite(rightMb,HIGH);
    
  }
  else if(lSensor > 500 && rSensor < 500){//turn left
    Serial.println("left");
    digitalWrite(leftMa,LOW);
    digitalWrite(leftMb,HIGH);
    digitalWrite(rightMa,HIGH);
    digitalWrite(rightMb,LOW);
    
  }

  else if(lSensor > 500 && rSensor > 500){
    Serial.println("stop");
    digitalWrite(leftMa,LOW);
    digitalWrite(leftMb,LOW);
    digitalWrite(rightMa,LOW);
    digitalWrite(rightMb,LOW);
    
  }
    
  
} 