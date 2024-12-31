// 1 = Adelante, 2 = Atras, 3 = Izquierda, 4 = Derecha, 9 = GO
int vecProg [20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int vecProgPoint = 0; 
int stateMemory;
#define   stateMemoryError  1
#define   stateMemoryEmpty  2
#define   stateMemoryReady  3
#define   stateMemoryFull   4

#define   orderForward      1
#define   orderBackward     2
#define   orderLeft         3
#define   orderRight        4

const int nroUpDown = 800;
const int nroLeftRight = 800;
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
// Buttons
const int pinBackward = A3;  // the number of the pushbutton pin
const int pinLeft     = A4;  // the number of the pushbutton pin
const int pinOk       = A2;  // the number of the pushbutton pin
const int pinForward  = A0;  // the number of the pushbutton pin
const int pinRight    = A1;  // the number of the pushbutton pin
bool statePinBackward;
bool statePinLeft;
bool statePinOk;
bool statePinForward;
bool statePinRight;

bool stateButBackward;
bool stateButLeft;
bool stateButOk;
bool stateButForward;
bool stateButRight;

void deleteMemory(){
  for(int i=0;i<10;i++){
    vecProg[i]=0;
  }
  stateMemory = stateMemoryEmpty;
}

void readMemory(){
  int vecReadPoint=0;
  while (vecProg[vecReadPoint]!=0){
    switch (vecProg[vecReadPoint]){
      case orderForward:   // Adelante
        Serial.println("Mov. Adelante");
        adelante();
        delay(200);
      break;
      case orderBackward:  // Atras
        Serial.println("Mov. Atras");
        atras();
        delay(200);
      break;
      case orderLeft:      // Izquierda
        Serial.println("Mov. Izquierda");
        izquierda();
        delay(200);
      break;
      case orderRight:     // Derecha
        Serial.println("Mov. Derecha");
        derecha();
        delay(200);
      break;
    }
    vecReadPoint++;
  }
  deleteMemory();
}

void saveMemory(int data){
  vecProg[vecProgPoint] = data;
  if (vecProgPoint >= 19){
    vecProgPoint = 19;
    stateMemory = stateMemoryFull;
  }
  else{
    vecProgPoint++;
    stateMemory = stateMemoryReady;
  }  
}

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
  for (int i=0;i<=nroUpDown;i++){
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
  for (int i=0;i<=nroUpDown;i++){
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

void izquierda(){
  stepMot1=0;
  stepMot2=4;
  for (int i=0;i<=nroLeftRight;i++){
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

void derecha(){
  stepMot1=4;
  stepMot2=0;
  for (int i=0;i<=nroLeftRight;i++){
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
  Serial.begin(115200);
  pinMode(pinMot11, OUTPUT);
  pinMode(pinMot12, OUTPUT);
  pinMode(pinMot13, OUTPUT);
  pinMode(pinMot14, OUTPUT);
  pinMode(pinMot21, OUTPUT);
  pinMode(pinMot22, OUTPUT);
  pinMode(pinMot23, OUTPUT);
  pinMode(pinMot24, OUTPUT);
  pinMode(pinBackward,INPUT);
  pinMode(pinLeft,    INPUT);
  pinMode(pinOk,      INPUT);
  pinMode(pinForward, INPUT);
  pinMode(pinRight,   INPUT);
  statePinBackward = digitalRead(pinBackward);
  statePinLeft = digitalRead(pinLeft);
  statePinOk = digitalRead(pinOk);
  statePinForward = digitalRead(pinForward);
  statePinRight = digitalRead(pinRight);
  stateButBackward = 0;
  stateButLeft = 0;
  stateButOk = 0;
  stateButForward = 0;
  stateButRight = 0;
  vecProgPoint = 0;
  deleteMemory();
}
void loop() {
  // Boton Atras
  if (statePinBackward != digitalRead(pinBackward)){
    statePinBackward = digitalRead(pinBackward);
    delay(100);
    if (statePinBackward){
      // Presiono
      stateButBackward = 1;
    }
    else{
      // Solto
    }
  }
  // Boton Adelante
  if (statePinForward != digitalRead(pinForward)){
    statePinForward = digitalRead(pinForward);
    delay(100);
    if (statePinForward){
      // Presiono
      stateButForward = 1;
    }
    else{
      // Solto
    }
  }
  // Boton Izquierda
  if (statePinLeft != digitalRead(pinLeft)){
    statePinLeft = digitalRead(pinLeft);
    delay(100);
    if (statePinLeft){
      // Presiono
      stateButLeft = 1;
    }
    else{
      // Solto
    }
  }
  // Boton Derecha
  if (statePinRight != digitalRead(pinRight)){
    statePinRight = digitalRead(pinRight);
    delay(100);
    if (statePinRight){
      // Presiono
      stateButRight = 1;
    }
    else{
      // Solto
    }
  }
  // Boton OK
  if (statePinOk != digitalRead(pinOk)){
    statePinOk = digitalRead(pinOk);
    delay(100);
    if (statePinOk){
      // Presiono
      stateButOk = 1;
    }
    else{
      // Solto
    }
  }
  if (stateButBackward){
    stateButBackward = 0;
    saveMemory(orderBackward);
    Serial.println("Atras");
  }
  if (stateButForward){
    stateButForward = 0;
    saveMemory(orderForward);
    Serial.println("Adelante");
  }
  if (stateButRight){
    stateButRight = 0;
    saveMemory(orderRight);
    Serial.println("Derecha");
  }
  if (stateButLeft){
    stateButLeft = 0;
    saveMemory(orderLeft);
    Serial.println("Izquierda");
  }
  if (stateButOk){
    stateButOk = 0;
    delay(300);
    readMemory();
    Serial.println("Go");
  }
}
