#define MOTOR_L_PWM 10
#define MOTOR_L_C1 8
#define MOTOR_L_C2 9

#define MOTOR_R_PWM 11
#define MOTOR_R_C2 12
#define MOTOR_R_C1 13


void setup() {
  pinMode(MOTOR_L_PWM, OUTPUT);
  pinMode(MOTOR_L_C1, OUTPUT);
  pinMode(MOTOR_L_C2, OUTPUT);

  pinMode(MOTOR_R_PWM, OUTPUT);
  pinMode(MOTOR_R_C1, OUTPUT);
  pinMode(MOTOR_R_C2, OUTPUT);
}

void loop() {
  // Forward
  analogWrite(MOTOR_L_PWM,255);
  analogWrite(MOTOR_R_PWM,255);
  
  digitalWrite(MOTOR_L_C1,HIGH);
  digitalWrite(MOTOR_L_C2,LOW);

  digitalWrite(MOTOR_R_C1,HIGH);
  digitalWrite(MOTOR_R_C2,LOW);

  delay(4000);

  // Left
  analogWrite(MOTOR_L_PWM,128);
  analogWrite(MOTOR_R_PWM,255);
  
  digitalWrite(MOTOR_L_C1,HIGH);
  digitalWrite(MOTOR_L_C2,LOW);

  digitalWrite(MOTOR_R_C1,HIGH);
  digitalWrite(MOTOR_R_C2,LOW);

  delay(4000);

  // Right
  analogWrite(MOTOR_L_PWM,255);
  analogWrite(MOTOR_R_PWM,128);
  
  digitalWrite(MOTOR_L_C1,HIGH);
  digitalWrite(MOTOR_L_C2,LOW);

  digitalWrite(MOTOR_R_C1,HIGH);
  digitalWrite(MOTOR_R_C2,LOW);

  delay(4000);
  
  // Backward
  analogWrite(MOTOR_L_PWM,255);
  analogWrite(MOTOR_R_PWM,255);
  
  digitalWrite(MOTOR_L_C1,LOW);
  digitalWrite(MOTOR_L_C2,HIGH);

  digitalWrite(MOTOR_R_C1,LOW);
  digitalWrite(MOTOR_R_C2,HIGH);

  
  delay(4000);
  
  // Stop
  analogWrite(MOTOR_L_PWM,0);
  analogWrite(MOTOR_R_PWM,0);
  
  delay(4000);
}
