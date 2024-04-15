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

  if (etatCapteurA == HIGH){
    recularret();
    tournegauche();
  }
  else if (etatCapteurB == HIGH){
    recularret();
    tournedroite();
  }
  else {
    avance();
  }
}

//définition des fonctions donnant des instructions au robot
void avance(){
  //le moteur A va en avant
  digitalWrite(moteurA, LOW);
  digitalWrite(freinA, LOW);
  analogWrite(pwmA, 255);
  //de même pour B
  digitalWrite(moteurB, LOW);
  digitalWrite(freinB, LOW);
  analogWrite(pwmB, 255);
  delay(5000);
}

void recularret(){
  //le robot recule
  digitalWrite(moteurA, HIGH);
  digitalWrite(freinA, LOW);
  analogWrite(pwmA, 255);
  digitalWrite(moteurB, HIGH);
  digitalWrite(freinB, LOW);
  analogWrite(pwmB, 255);
  delay(200); 
  //le robot s'arrête
  digitalWrite(freinA, HIGH); //engage les freins
  digitalWrite(freinB, HIGH);
  analogWrite(pwmA, 0); //stop les moteurs
  analogWrite(pwmB, 0);
  delay(1000);
}

void tournegauche(){
  digitalWrite(moteurA, LOW); //le moteur A va en avant
  digitalWrite(freinA, LOW); 
  analogWrite(pwmA, 255);
  digitalWrite(moteurB, HIGH); //le moteur B va en arrière
  digitalWrite(freinB, LOW); 
  analogWrite(pwmB, 255);
  delay(600);
}

void tournedroite(){
  digitalWrite(moteurA, HIGH); //le moteur A va en arrière
  digitalWrite(freinA, LOW);
  analogWrite(pwmA, 255);
  digitalWrite(moteurB, LOW); //le moteur B va en avant
  digitalWrite(freinA, LOW); 
  analogWrite(pwmA, 255);
  delay(600);
}
