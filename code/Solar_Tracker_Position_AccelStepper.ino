#include <AccelStepper.h>

// Definição dos pinos do driver do motor bipolar
#define motorPin1 8 // IN1 no driver do motor
#define motorPin2 9 // IN2 no driver do motor
#define motorPin3 10 // IN3 no driver do motor
#define motorPin4 11 // IN4 no driver do motor

// Configuração do motor de passo usando a biblioteca AccelStepper
AccelStepper motor(AccelStepper::FULL4WIRE, motorPin1, motorPin3, motorPin2, motorPin4);

// Posições predefinidas (em passos) para o motor bipolar
int positions[6] = {0, 200, 400, 600, 800, 1000}; // Ajuste os valores de acordo com o número de passos necessários para cada ângulo
int currentPosition = 0; // índice da posição atual

// Função de setup, definindo as configurações iniciais
void setup() {
  motor.setMaxSpeed(200.0); // Define a velocidade máxima do motor (ajuste conforme necessário)
  motor.setAcceleration(100.0); // Define a aceleração do motor (ajuste conforme necessário)
  motor.moveTo(positions[currentPosition]); // Move o motor para a posição inicial
  motor.runToPosition(); // Aguarda até que o motor atinja a posição inicial
  delay(1000); // 1 segundo de delay para que o programa comece a funcionar
}

// Função que mantém o programa em loop para movimentar o motor ao longo de 12 horas
void loop() {
  // Move o motor para a próxima posição predefinida
  motor.moveTo(positions[currentPosition]);
  motor.runToPosition(); // Aguarda até que o motor atinja a nova posição
  
  // Incrementa a posição atual
  currentPosition++;
  
  // Verifica se todas as posições foram percorridas, se sim, reseta para o início
  if(currentPosition >= 6) {
    currentPosition = 0;
  }
  
  // Espera 2 horas (em milissegundos) antes de mover para a próxima posição
  delay(7200000); // 2 horas = 2 * 60 * 60 * 1000 milissegundos
}
