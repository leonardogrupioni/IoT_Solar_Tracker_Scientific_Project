//Rastreador Solar

#include <Servo.h> // biblioteca do servo motor

Servo myservo; //declaração do servo motor

#define ldr1 A0 //  define ldr1 para leste
#define ldr2 A1 //  define ldr2 para oeste

//declaração de variaveis que alteram a angulação do servo motor
int pos = 120; // posição inicial no movimento vertical do servo motor
int limite = 20; // limite de intensidade da luz para os testes presentes no "void loop()"


//função de setup, definindo os pins do arduino 
void setup(){
  myservo.attach(A2); // setando o pin A2 como pin que controla o movimento do servo motor
  pinMode(ldr1, INPUT); // seta o pin A0, para o ldr1 a leste 
  pinMode(ldr2, INPUT); // seta o pin A1, para o ldr2 a oeste 
  myservo.write(pos); // coloca o servo motor em posição inicial
      
  delay(1000); // 1 segundo de delay para que o programa comece a funcionar e o servo motor comece a seguir a intensidade da luz
}

//função que mantem o programa em loop para que o rastreador se mantenha nos conformes enquanto o sistema estiver ligado 
void loop(){

  //definição das variaveis que recebem o valor enviado pelos LDRs 1 e 2
  int retorno1 = analogRead(ldr1); //  lê o valor do ldr1 e envia para o retorno 1
  int retorno2 = analogRead(ldr2); //  lê o valor do ldr2 e envia para o retorno 2

  //testes que definem o posicionamento do servo motor:
  if((abs(retorno1 - retorno2) <= limite) || (abs(retorno2 - retorno1) <= limite)) { //funcao abs retorna o valor absoluto de uma expressão 
    //matem o servo motor estatico por a intensidade da luz se manter menor que o limite de intensidade
  }else {
      if(retorno1 > retorno2) {// se o ldr1 possuir mais luminosidade que o ldr2
        pos = pos+1; // Movimenta o painel na direção oeste 
      } 
      if(retorno1 < retorno2) {// se o ldr2 possuir mais luminosidade que o ldr1
        pos = pos-1; // Movimenta o painel na direção leste
      }
  }
  //testes de limite de movimento do servo motor, não o deixa ultrapassar os angulos definidos   
  if(pos > 120) {pos = 120;} //  reseta a posição vertical do motor se ele tentar ultrapassar de 120 graus
  if(pos < 20) {pos = 20;} //    reseta a posição vertical do motor se ele tentar ultrapassar de 20 graus
  
  myservo.write(pos); // seta a nova posição do motor e garante o movimento do servo
  
  delay(50);//repete de 50 em 50 milissegundos
}