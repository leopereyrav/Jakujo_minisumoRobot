int m1Ava = 6;
int m1Ret = 5;
int m2Ava = 11;
int m2Ret = 10;
int velocidad = 80;

void ataque(){
  digitalWrite(m1Ava,HIGH);
  digitalWrite(m1Ret,LOW);
  digitalWrite(m2Ava,HIGH);
  digitalWrite(m2Ret,LOW);
}
void busqueda(){
  digitalWrite(m1Ava,LOW);
  analogWrite(m1Ret,150);
  analogWrite(m2Ava,150);
  digitalWrite(m2Ret,LOW);
}
void avanzar(){
  analogWrite(m1Ava,velocidad);
  digitalWrite(m1Ret,LOW);
  analogWrite(m2Ava,velocidad);
  digitalWrite(m2Ret,LOW);
}
void derecha(){
  analogWrite(m1Ava,velocidad);
  digitalWrite(m1Ret,LOW);
  digitalWrite(m2Ava,HIGH);
  digitalWrite(m2Ret,LOW);
}
void izquierda(){
  digitalWrite(m1Ava,HIGH);
  digitalWrite(m1Ret,LOW);
  analogWrite(m2Ava,velocidad);
  digitalWrite(m2Ret,LOW);
}
void retroceder(){
  digitalWrite(m1Ava,LOW);
  analogWrite(m1Ret,velocidad);
  digitalWrite(m2Ava,LOW);
  analogWrite(m2Ret,velocidad);
}
void retroderecha(){
  digitalWrite(m1Ava,LOW);
  analogWrite(m1Ret,velocidad);
  digitalWrite(m2Ava,LOW);
  digitalWrite(m2Ret,HIGH);
}
void retroizquierda(){
  digitalWrite(m1Ava,LOW);
  digitalWrite(m1Ret,HIGH);
  digitalWrite(m2Ava,LOW);
  analogWrite(m2Ret,velocidad);
}
void parar(){
  digitalWrite(m1Ava,LOW);
  digitalWrite(m1Ret,LOW);
  digitalWrite(m2Ava,LOW);
  digitalWrite(m2Ret,LOW);
}

int detCo1;
int detCo2;
int detCo3;
int detCo4;

long distT;
long distF;

long ultrasonidoF(){
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  delayMicroseconds(2);
  digitalWrite(2,HIGH);
  delayMicroseconds(5);
  digitalWrite(2,LOW);
  pinMode(3,INPUT);
  long distancia, cm;
  distancia = pulseIn(3,HIGH);
  cm = distancia/29/2;
  return cm;
}
long ultrasonidoT(){
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  delayMicroseconds(2);
  digitalWrite(12,HIGH);
  delayMicroseconds(5);
  digitalWrite(12,LOW);
  pinMode(13,INPUT);
  long distancia, cm;
  distancia = pulseIn(13,HIGH);
  cm = distancia/29/2;
  return cm;
}

void setup() { 
  pinMode(m1Ava,OUTPUT);
  pinMode(m1Ret,OUTPUT);
  pinMode(m2Ava,OUTPUT);
  pinMode(m2Ret,OUTPUT);
  delay(5000);
}

void loop() {  

  detCo1 = digitalRead(A1);
  detCo2 = digitalRead(A2);
  detCo3 = digitalRead(A3);
  detCo4 = digitalRead(A4);

  distF = ultrasonidoF();
  distT = ultrasonidoT();
  
  if(detCo1 == 0 && detCo2 == 0 && detCo3 == 0 && detCo4 == 0){
    
    if(0 < distF && distF < 100 && 100 <= distT){
      ataque();
    } 
  
    if(100 <= distF && 100 <= distT){
      busqueda();
    } 

    if(100 <= distF && 7 < distT && distT < 100){
      busqueda();
    } 

    if(100 <= distF && 0 < distT && distT <= 7){
      derecha();
      delay(1500);
    }

  }
  
  if(detCo1 == 1 && detCo2 == 0 && detCo3 == 0 && detCo4 == 0){
    parar();
    delay(1000);
    izquierda();
    delay(1500);
    parar();
    delay(1000);
  }

  if(detCo1 == 0 && detCo2 == 1 && detCo3 == 0 && detCo4 == 0){
    parar();
    delay(1000);
    derecha();
    delay(1500);
    parar();
    delay(1000);
  }

  if(detCo1 == 0 && detCo2 == 0 && detCo3 == 1 && detCo4 == 0){
    parar();
    delay(1000);
    retroizquierda();
    delay(1500);
    parar();
    delay(1000);
  }

  if(detCo1 == 0 && detCo2 == 0 && detCo3 == 0 && detCo4 == 1){
    parar();
    delay(1000);
    retroderecha();
    delay(1500);
    parar();
    delay(1000);
  }
  
  if(detCo1 == 1 && detCo2 == 1 && detCo3 == 0 && detCo4 == 0){
    parar();
    delay(1000);
    avanzar();
    delay(1500);
    parar();
    delay(1000);
  }
  
  if(detCo1 == 1 && detCo2 == 0 && detCo3 == 1 && detCo4 == 0){
    parar();
    delay(1000);
    izquierda();
    delay(1500);
    parar();
    delay(1000);
  }
  
  if(detCo1 == 0 && detCo2 == 1 && detCo3 == 0 && detCo4 == 1){
    parar();
    delay(1000);
    derecha();
    delay(1500);
    parar();
    delay(1000);
  } 

  if(detCo1 == 0 && detCo2 == 0 && detCo3 == 1 && detCo4 == 1){
    parar();
    delay(1000);
    retroceder();
    delay(1500);
    parar();
    delay(1000);
  }

  if(detCo1 == 1 && detCo2 == 1 && detCo3 == 1 && detCo4 == 1){
    parar();
  } 
 
}
