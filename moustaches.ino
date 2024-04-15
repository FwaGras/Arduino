int moteurA = 12;
int pwmA = 3;
int freinA = 9;
int capteurA = 4;

int moteurB = 13;
int pwmB = 11;
int freinB  = 8;
int capteurB = 5;

//test bool

void setup() {  
  //define pins of channel A
  pinMode(moteurA, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(freinA, OUTPUT);
  pinMode(capteurA, INPUT);

  //channel B
  pinMode(moteurB, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(freinB, OUTPUT);
  pinMode(capteurB, INPUT);
}

void loop() {
  bool etatCapteurA;
  bool etatCapteurB;
  etatCapteurA = digitalRead(capteurA);
  etatCapteurB = digitalRead(capteurB);

  //le moteur A avance
  digitalWrite(moteurA, LOW);
  digitalWrite(freinA, LOW);
  analogWrite(pwmA, 255);

  //de même pour B
  digitalWrite(moteurB, LOW);
  digitalWrite(freinB, LOW);
  analogWrite(pwmB, 255);

  if (etatCapteurA == HIGH){
    //le moteur A recule
    digitalWrite(moteurA, HIGH);
    digitalWrite(freinA, LOW);
    analogWrite(pwmA, 255);

    //de même pour B
    digitalWrite(moteurB, HIGH);
    digitalWrite(freinB, LOW);
    analogWrite(pwmB, 255);

    //le robot recule pendant une seconde
    delay(1000);

    //engage les freins
    digitalWrite(freinA, HIGH);
    digitalWrite(freinB, HIGH);

    //le robot tourne droite
    digitalWrite(moteurA, HIGH);
    digitalWrite(freinA, LOW);
    analogWrite(pwmA, 255);
    //pendant une seconde
    delay(1000);
  }

  else if (etatCapteurB == HIGH){
    //le moteur A recule
    digitalWrite(moteurA, HIGH);
    digitalWrite(freinA, LOW);
    analogWrite(pwmA, 255);

    //de même pour B
    digitalWrite(moteurB, HIGH);
    digitalWrite(freinB, LOW);
    analogWrite(pwmB, 255);

    //le robot recule pendant une seconde
    delay(1000);

    //engage les freins
    digitalWrite(freinA, HIGH);
    digitalWrite(freinB, HIGH);

    //tourne à gauche
    digitalWrite(moteurB, HIGH);
    digitalWrite(freinB, LOW);
    analogWrite(pwmB, 255);
    //pendant une seconde
    delay(1000);

  }


}