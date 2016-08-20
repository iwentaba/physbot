#define MOTOR_L_PWM 10
#define MOTOR_L_C2 8
#define MOTOR_L_C1 9

#define MOTOR_R_PWM 11
#define MOTOR_R_C1 12
#define MOTOR_R_C2 13

const char LEFT = 0;
const char BACK = 1;
const char FORWARD = 2;
const char RIGHT = 3;
const char STOP = 4;
const char VEL_DOWN = 5;
const char VEL_UP = 6;

int funRef;
int velocity = 255;

void setup() {
  Serial.begin(38400);
  Serial.setTimeout(50);

  // Motor setup
  pinMode(MOTOR_L_PWM, OUTPUT);
  pinMode(MOTOR_L_C1, OUTPUT);
  pinMode(MOTOR_L_C2, OUTPUT);

  pinMode(MOTOR_R_PWM, OUTPUT);
  pinMode(MOTOR_R_C1, OUTPUT);
  pinMode(MOTOR_R_C2, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    funRef = Serial.read();
    chooseFun(funRef);
  }

  delay(50);
}

void chooseFun(int funNr) {
  switch (funNr) {
    case LEFT:
      goLeft();
      break;
    case BACK:
      goBack();
      break;
    case FORWARD:
      goForward();
      break;
    case RIGHT:
      goRight();  
      break;
    case STOP:
      goStop();
      break;
    case VEL_UP:
      velUp();
      break;
    case VEL_DOWN:
      velDown();
      break;
    default: 
      // throw err or something
    break;
  }
}

void goLeft() {
  Serial.println("Going Left!");
  analogWrite(MOTOR_L_PWM,velocity);
  analogWrite(MOTOR_R_PWM,velocity/3);
  
  digitalWrite(MOTOR_L_C1,HIGH);
  digitalWrite(MOTOR_L_C2,LOW);

  digitalWrite(MOTOR_R_C1,HIGH);
  digitalWrite(MOTOR_R_C2,LOW);
}

void goBack() {
  Serial.println("Going Back!");
  analogWrite(MOTOR_L_PWM,velocity);
  analogWrite(MOTOR_R_PWM,velocity);
  
  digitalWrite(MOTOR_L_C1,LOW);
  digitalWrite(MOTOR_L_C2,HIGH);

  digitalWrite(MOTOR_R_C1,LOW);
  digitalWrite(MOTOR_R_C2,HIGH);
}

void goStop() {
  Serial.println("Going Back!");
  analogWrite(MOTOR_L_PWM,0);
  analogWrite(MOTOR_R_PWM,0);
  
  digitalWrite(MOTOR_L_C1,HIGH);
  digitalWrite(MOTOR_L_C2,LOW);

  digitalWrite(MOTOR_R_C1,HIGH);
  digitalWrite(MOTOR_R_C2,LOW);
}

void goForward() {
  Serial.println("Going Forward!");
  analogWrite(MOTOR_L_PWM,velocity);
  analogWrite(MOTOR_R_PWM,velocity);
  
  digitalWrite(MOTOR_L_C1,HIGH);
  digitalWrite(MOTOR_L_C2,LOW);

  digitalWrite(MOTOR_R_C1,HIGH);
  digitalWrite(MOTOR_R_C2,LOW);
}

void goRight() {
  Serial.println("Going Right!");
  analogWrite(MOTOR_L_PWM,velocity/3);
  analogWrite(MOTOR_R_PWM,velocity);
  
  digitalWrite(MOTOR_L_C1,HIGH);
  digitalWrite(MOTOR_L_C2,LOW);

  digitalWrite(MOTOR_R_C1,HIGH);
  digitalWrite(MOTOR_R_C2,LOW); 
}

void velUp() {
  setVelocity(velocity + 20)
}

void velDown() {
  setVelocity(velocity - 20)
}

void setVelocity(int vel) {
  if (vel < 0) {
    velocity = 0
  }
  if (vel > 255) {
    velocity = 255
  }
}

