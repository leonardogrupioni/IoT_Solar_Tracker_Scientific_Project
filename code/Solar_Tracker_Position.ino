#include <Servo.h> // biblioteca do servo motor

Servo myservo; // declaração do servo motor

// Posições predefinidas (em graus) para o servo motor
int positions[6] = {30, 55, 80, 105, 130, 160};
int currentPosition = 0; // índice da posição atual

// Função de setup, definindo os pins do Arduino
void setup() {
  myservo.attach(A2); // setando o pin A2 como pin que controla o movimento do servo motor
  myservo.write(positions[currentPosition]); // coloca o servo motor na posição inicial
  delay(1000); // 1 segundo de delay para que o programa comece a funcionar
}

// Função que mantém o programa em loop para movimentar o servo motor ao longo de 12 horas
void loop() {
  // Move o servo motor para a próxima posição predefinida
  myservo.write(positions[currentPosition]);

  // Incrementa a posição atual
  currentPosition++;
  
  // Verifica se todas as posições foram percorridas, se sim, reseta para o início
  if(currentPosition >= 6) {
    currentPosition = 0;
  }
  
  // Espera 2 horas (em milissegundos) antes de mover para a próxima posição
  delay(7200000); // 2 horas = 2 * 60 * 60 * 1000 milissegundos
}
