const int pinMot11 = 5;  // the number of the pushbutton pin
const int pinMot12 = 4;  // the number of the pushbutton pin
const int pinMot13 = 3;  // the number of the pushbutton pin
const int pinMot14 = 2;  // the number of the pushbutton pin
int stepMot1 = 0;  // variable for reading the pushbutton status
const int pinMot21 = 6;  // the number of the pushbutton pin
const int pinMot22 = 7;  // the number of the pushbutton pin
const int pinMot23 = 8;  // the number of the pushbutton pin
const int pinMot24 = 9;  // the number of the pushbutton pin
int stepMot2 = 0;  // variable for reading the pushbutton status

void motores(int stepMot1,int stepMot2){
  switch(stepMot1){
    case 0:
      digitalWrite(pinMot11,1);
      digitalWrite(pinMot12,1);
      digitalWrite(pinMot13,1);
      digitalWrite(pinMot14,1);
    break;
    case 1:
      digitalWrite(pinMot11,1);
      digitalWrite(pinMot12,0);
      digitalWrite(pinMot13,0);
      digitalWrite(pinMot14,0);
    break;
    case 2:
      digitalWrite(pinMot11,0);
      digitalWrite(pinMot12,1);
      digitalWrite(pinMot13,0);
      digitalWrite(pinMot14,0);
    break;
    case 3:
      digitalWrite(pinMot11,0);
      digitalWrite(pinMot12,0);
      digitalWrite(pinMot13,1);
      digitalWrite(pinMot14,0);
    break;
    case 4:
      digitalWrite(pinMot11,0);
      digitalWrite(pinMot12,0);
      digitalWrite(pinMot13,0);
      digitalWrite(pinMot14,1);
    break;
  }
    switch(stepMot2){
    case 0:
      digitalWrite(pinMot21,1);
      digitalWrite(pinMot22,1);
      digitalWrite(pinMot23,1);
      digitalWrite(pinMot24,1);
    break;
    case 1:
      digitalWrite(pinMot21,1);
      digitalWrite(pinMot22,0);
      digitalWrite(pinMot23,0);
      digitalWrite(pinMot24,0);
    break;
    case 2:
      digitalWrite(pinMot21,0);
      digitalWrite(pinMot22,1);
      digitalWrite(pinMot23,0);
      digitalWrite(pinMot24,0);
    break;
    case 3:
      digitalWrite(pinMot21,0);
      digitalWrite(pinMot22,0);
      digitalWrite(pinMot23,1);
      digitalWrite(pinMot24,0);
    break;
    case 4:
      digitalWrite(pinMot21,0);
      digitalWrite(pinMot22,0);
      digitalWrite(pinMot23,0);
      digitalWrite(pinMot24,1);
    break;
  }
}
void adelante(){
  stepMot1=0;
  stepMot2=0;
  for (int i=0;i<=400;i++){
    motores(stepMot1,stepMot2);
    stepMot1++;
    if (stepMot1>=5){
      stepMot1=1;
    }
    stepMot2++;
    if (stepMot2>=5){
      stepMot2=1;
    }
    delay(4);
  }
  stepMot1=0;
  stepMot2=0;
  motores(stepMot1,stepMot2);
}

void atras(){
  stepMot1=4;
  stepMot2=4;
  for (int i=0;i<=400;i++){
    motores(stepMot1,stepMot2);
    stepMot1--;
    if (stepMot1<=0){
      stepMot1=4;
    }
    stepMot2--;
    if (stepMot2<=0){
      stepMot2=4;
    }
    delay(4);
  }
  stepMot1=0;
  stepMot2=0;
  motores(stepMot1,stepMot2);
}

void derecha(){
  stepMot1=0;
  stepMot2=4;
  for (int i=0;i<=800;i++){
    motores(stepMot1,stepMot2);
    stepMot1++;
    if (stepMot1>=5){
      stepMot1=1;
    }
    stepMot2--;
    if (stepMot2<=0){
      stepMot2=4;
    }
    delay(4);
  }
  stepMot1=0;
  stepMot2=0;
  motores(stepMot1,stepMot2);
}

void izquierda(){
  stepMot1=4;
  stepMot2=0;
  for (int i=0;i<=800;i++){
    motores(stepMot1,stepMot2);
    stepMot1--;
    if (stepMot1<=0){
      stepMot1=4;
    }
    stepMot2++;
    if (stepMot2>=5){
      stepMot2=1;
    }
    delay(4);
  }
  stepMot1=0;
  stepMot2=0;
  motores(stepMot1,stepMot2);
}

void setup() {
  pinMode(pinMot11, OUTPUT);
  pinMode(pinMot12, OUTPUT);
  pinMode(pinMot13, OUTPUT);
  pinMode(pinMot14, OUTPUT);
  pinMode(pinMot21, OUTPUT);
  pinMode(pinMot22, OUTPUT);
  pinMode(pinMot23, OUTPUT);
  pinMode(pinMot24, OUTPUT);
}
void loop() {
  adelante();
  delay(200);
  izquierda();
  delay(200);
  derecha();
  delay(200);
  atras();
  delay(200);
}
