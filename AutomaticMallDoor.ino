// Inicio do projeto 


// Definindo os servos motores

#include <Servo.h>
Servo myservo; 
Servo myservo2;

// Fim da definição dos servos motores


// Definindo as variáveis


int buzzer = 10; // Variável do buzzer
int ledPin = 13; // Variável do led
int pirPin = 2;  // Variavel do sensor               
int pirStat = 0;  // Variavel do sensor 2                
int pos = 0; // Variavel do servo motor


// Fim da definição das variáveis

// Definindo saidas

void setup() {
  
 pinMode(ledPin, OUTPUT); // Definindo a saida do led  
 pinMode(pirPin, INPUT); // Definindo a saido do sensor
 myservo.attach(5);  // Definindo saida do servo motor
  pinMode(buzzer,OUTPUT); // Definindo saido do buzzer 
  myservo2.attach(7);  // Definindo saida do segundo servo motor
}

// Fim da definição das saidas

// Inicio do projeto

void loop(){
 pirStat = digitalRead(pirPin); // Atribuindo o estado do sensor
  
  // Estrutura de decisão
  
  
 if (pirStat == HIGH) {    
   
   digitalWrite(ledPin, HIGH); // Ligando o led
   tone(buzzer, 700); // Função para ativar o buzzer
   Serial.println("Movimento detectado!"); // Frase digitada ao ativar o sensor
   pos = 90; // Definindo o valor da posição do servo ao sensor ser ativado
   myservo.write(pos);  // Definindo a posição do servo
   myservo2.write(pos);  // Definindo a posição do segundo servo
   delay(15);  // Definindo o atraso das ações   
   digitalWrite(ledPin, LOW); // Desativando o led
 
 } 
  // Estrutura de decisão
  
 else {
    noTone(buzzer); // Função para desativar o buzzer
  	pos = 0; // Definindo o valor da posição dos servos ao sensor ser desativado
  	myservo.write(pos); // Definindo a posição do servo
    myservo2.write(pos);  // Definindo a posição do segundo servo
    delay(15);  // Definindo o atraso das ações                  
 
 }
} 

// Fim do projeto
