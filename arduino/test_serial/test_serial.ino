int funRef;

const char LEFT = 0;
const char BACK = 1;
const char FORWARD = 2;
const char RIGHT = 3;

void setup() {
  Serial.begin(38400);
  Serial.setTimeout(50);
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
    default: 
      // throw err or something
    break;
  }
}

void goLeft() {
  Serial.println("Going Left!");
}

void goBack() {
  Serial.println("Going Back!");
}

void goForward() {
  Serial.println("Going Forward!");
}

void goRight() {
  Serial.println("Going Right!");
}

