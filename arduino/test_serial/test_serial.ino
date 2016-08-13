long i = 0;
int j = 0;
int inFunc;

void setup() {
  Serial.begin(38400);
  Serial.setTimeout(50);
}

void loop() {

//  if (i > 5000) {
//    Serial.print("Blip ");
//    Serial.println(j);
//    i = 0;
//    j++;
//  }
  
  if (Serial.available() > 0) {
    inFunc = Serial.read();
    chooseFun(inFunc);
  }

  delay(50);
  //i++;
}

void chooseFun(int funNr) {
  switch (funNr) {
    case 0:
      doLeft();
      break;
    case 1:
      doDown();
      break;
    case 2:
      doUp();
      break;
    case 3:
      doRight();  
    default: 
      // throw err or something
    break;
  }
}

void doLeft() {
  Serial.println("Go Left!");
}

void doDown() {
  Serial.println("Go Down!");
}

void doUp() {
  Serial.println("Go Up!");
}

void doRight() {
  Serial.println("Go Right!");
}

