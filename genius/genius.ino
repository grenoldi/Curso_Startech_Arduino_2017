#include <node.h>
#include <lista.h>
//definicao de constantes para os pinos de saida

#define LED_VERMELHO  4
#define LED_AMARELO   5
#define LED_VERDE     6
#define LED_AZUL      7
#define BUZZER       12

//definicao de constantes para os pinos de entrada

#define BOTAO_VERMELHO  8
#define BOTAO_AMARELO   9
#define BOTAO_VERDE    10
#define BOTAO_AZUL     11

//definicao das constantes sonoras

#define SOL 396
#define REH 297
#define LAH 440
#define MIH 330

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERDE,    OUTPUT);
  pinMode(LED_AZUL,     OUTPUT);
  pinMode(BUZZER,       OUTPUT);
  
  pinMode(BOTAO_VERMELHO,INPUT);
  pinMode(BOTAO_AMARELO, INPUT);
  pinMode(BOTAO_VERDE,   INPUT);
  pinMode(BOTAO_AZUL,    INPUT);

  randomSeed(analogRead(0));
}

void inicio(){ 
  tone(BUZZER, SOL, 500);
  tone(BUZZER, REH, 500);
  tone(BUZZER, LAH, 500);
  delay(1000);
}

void errrou(){
  tone(BUZZER, 138, 1000);
  for(int i = 0; i < 5; i++){
    tone(BUZZER, 138, 500);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO,  HIGH);
    digitalWrite(LED_VERDE,    HIGH);
    digitalWrite(LED_AZUL,     HIGH);
    delay(500);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO,  LOW);
    digitalWrite(LED_VERDE,    LOW);
    digitalWrite(LED_AZUL,     LOW);
    delay(200);
  }
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Lista l;
  int correto = 1;
  while(correto == 1){
    inicio();
    int randNum = random(1,5);
    l.inserirFim(randNum);
    Node* pisca = l.ini;
    Node* compara = l.ini;
    while(pisca!=NULL){
      digitalWrite(pisca->getValue()+3, HIGH);
      delay(800);
      digitalWrite(pisca->getValue()+3, LOW);
      delay(200);
      pisca = pisca->getProx();
    }
    while(compara!=NULL && correto == 1){
      if(digitalRead(BOTAO_VERMELHO) == HIGH){
        if(compara->getValue() == 1){
          digitalWrite(compara->getValue()+3, HIGH);
          delay(800);
          digitalWrite(compara->getValue()+3, LOW);
          delay(200);
          compara = compara->getProx();
        }
        else{
          while(!l.vazia()){
            l.remover();
          }
          errrou();
          correto = 0;
        }
      }
      if(digitalRead(BOTAO_AMARELO) == HIGH){
        if(compara->getValue() == 2){
          digitalWrite(compara->getValue()+3, HIGH);
          delay(800);
          digitalWrite(compara->getValue()+3, LOW);
          delay(200);
          compara = compara->getProx();
        }
        else{
          while(!l.vazia()){
            l.remover();
          }
          errrou();
          correto = 0;
        }
      }
      if(digitalRead(BOTAO_VERDE) == HIGH){
        if(compara->getValue() == 3){
          digitalWrite(compara->getValue()+3, HIGH);
          delay(800);
          digitalWrite(compara->getValue()+3, LOW);
          delay(200);
          compara = compara->getProx();
        }
        else{
          while(!l.vazia()){
            l.remover();
          }
          errrou();
          correto = 0;
        }
      }
      if(digitalRead(BOTAO_AZUL) == HIGH){
        if(compara->getValue() == 4){
          digitalWrite(compara->getValue()+3, HIGH);
          delay(800);
          digitalWrite(compara->getValue()+3, LOW);
          delay(200);
          compara = compara->getProx();
        }
        else{
          while(!l.vazia()){
            l.remover();
          }
          errrou();
          correto = 0;
        }
      }
    }
  }
}
