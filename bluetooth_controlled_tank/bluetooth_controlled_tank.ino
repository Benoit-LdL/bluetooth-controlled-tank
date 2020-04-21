char t;

#define MOTOR1_ENABLE A1
#define MOTOR1_A 3
#define MOTOR1_B 4

#define MOTOR2_ENABLE A2
#define MOTOR2_A 6
#define MOTOR2_B 7 
void setup() {
//----Bluetooth/Serial interface
Serial.begin(9600);
//----MOTORS
  pinMode(MOTOR1_ENABLE,OUTPUT);
  pinMode(MOTOR1_A,OUTPUT);
  pinMode(MOTOR1_B,OUTPUT);
  analogWrite(MOTOR1_ENABLE,255);

  pinMode(MOTOR2_ENABLE,OUTPUT);
  pinMode(MOTOR2_A,OUTPUT);
  pinMode(MOTOR2_B,OUTPUT);
  analogWrite(MOTOR2_ENABLE,200);
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
Forwards(100);
t='S';
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
Backwards(100);
t='S';
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
Left(100);
t='S';
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
Right(100);
t='S';
}
 
else if(t == 'S'){      //STOP (all motors stop)
Reset();
}
delay(10);
}

void Forwards(int duration)
{
  //Left Track
  digitalWrite(MOTOR1_A, HIGH); 
  digitalWrite(MOTOR1_B, LOW);
  //Right Track
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, HIGH);
  delay(duration);
  Reset();
}

void Backwards(int duration)
{
  //Left Track
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, HIGH);
  //Right Track
  digitalWrite(MOTOR2_A, HIGH); 
  digitalWrite(MOTOR2_B, LOW);
  delay(duration);
  Reset();
}

void Left(int duration)
{
  //Left Track
  digitalWrite(MOTOR1_A, HIGH); 
  digitalWrite(MOTOR1_B, LOW);
  //Right Track
  digitalWrite(MOTOR2_A, HIGH); 
  digitalWrite(MOTOR2_B, LOW);
  delay(duration);
  Reset();
}

void Right(int duration)
{
  //Left Track
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, HIGH);
  //Right Track
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, HIGH);
  delay(duration);
  Reset();
}

void Reset()
{
  //Left Track
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, LOW);
  //Right Track
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, LOW);
  delay(100);
}
