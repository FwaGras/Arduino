//programme utilisant millis à la place de delay (idée proposé par ChatGPT)
unsigned long previousTime = 0;
const long rotationDuration = 600;
const long reverseDuration = 200;

int moteurA = 12;
int pwmA = 3;
int freinA = 9;
int capteurA = 6;

int moteurB = 13;
int pwmB = 11;
int freinB  = 8;
int capteurB = 7;

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
    avancer();
  }
}

//définition des fonctions donnant des instructions au robot
void avancer(){
  //le moteur A va en avant
  digitalWrite(moteurA, LOW);
  digitalWrite(freinA, LOW);
  analogWrite(pwmA, 255);
  //de même pour B
  digitalWrite(moteurB, LOW);
  digitalWrite(freinB, LOW);
  analogWrite(pwmB, 255);
}

void recularret(){
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= reverseDuration){
  //le robot recule pendant 200 millisecondes 
  digitalWrite(moteurA, HIGH);
  digitalWrite(freinA, LOW);
  analogWrite(pwmA, 255);
  digitalWrite(moteurB, HIGH);
  digitalWrite(freinB, LOW);
  analogWrite(pwmB, 255);
  
  //le robot s'arrête après le délai de recule
  delay(reverseDuration);
  digitalWrite(freinA, HIGH); //engage les freins
  digitalWrite(freinB, HIGH);
  analogWrite(pwmA, 0); //stop les moteurs
  analogWrite(pwmB, 0);

  previousTime = currentTime;
  }
}

void tournegauche(){
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= rotationDuration){
  digitalWrite(moteurA, LOW); //le moteur A va en avant
  digitalWrite(freinA, LOW); 
  analogWrite(pwmA, 255);
  digitalWrite(moteurB, HIGH); //le moteur B va en arrière
  digitalWrite(freinB, LOW); 
  analogWrite(pwmB, 255);

  previousTime = currentTime;
  }
}

void tournedroite(){
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= rotationDuration){
  digitalWrite(moteurA, HIGH); //le moteur A va en arrière
  digitalWrite(freinA, LOW);
  analogWrite(pwmA, 255);
  digitalWrite(moteurB, LOW); //le moteur B va en avant
  digitalWrite(freinA, LOW); 
  analogWrite(pwmA, 255);

  previousTime = currentTime;
  }
}
