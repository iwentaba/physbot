long i = 0;
int j = 0;
int inFunc;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (i > 500000) {
    Serial.print("Blip ");
    Serial.println(j);
    i = 0;
    j++;
  }
  
  if (Serial.available() > 0) {
    inFunc = Serial.read();
    chooseFun(inFunc);
  }
  
  i++;
}

void chooseFun(int funNr) {
  switch (funNr) {
    case 0:
      doZero();
      break;
    case 1:
      doOne();
      break;
    case 2:
      doTwo();
      break;
    default: 
      // throw err or something
    break;
  }
}

void doZero() {
  Serial.println("Zero!");
}

void doOne() {
  Serial.println("One!");
}

void doTwo() {
  Serial.println("Two!");
}

