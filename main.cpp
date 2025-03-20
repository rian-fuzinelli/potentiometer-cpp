byte led1 = 13;
byte led2 = 12;
byte led3 = 11;
byte led4 = 10;

byte button = 3;

int pot = A0;

byte qtde = 0;

bool sit = false; // sit = situation
 
int i = 0; // i = integrator

void setup() {
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(button, INPUT_PULLUP);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop() {
  qtde = map(analogRead(A0), 0, 1023, 0, 4);
  
  Serial.print("Leitura ");
  Serial.print(i);
  Serial.print(": ");
  Serial.println(digitalRead(button));
  Serial.println(sit);
  
  Serial.print("QTDE ");
  Serial.print(": ");
  Serial.println(qtde);
  
  if (digitalRead(button) == 0) {
    // change the LEDs'states
    sit = !sit;
    delay(250);
  }
  // if the LEDs are on, light them up
  if (sit) {
    
    if (qtde == 1) {
      digitalWrite(led1, 1);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    } else if (qtde == 2) {
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    } else if (qtde == 3) {
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, LOW);
    } else if (qtde == 4) {
      digitalWrite(led1, 1);
      digitalWrite(led2, 2);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
    } else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    
  } else { //  if the LEDs are off, fade them out
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  i++;
}
