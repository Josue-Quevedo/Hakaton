#include <SoftwareSerial.h>

#define RX_PIN 2 // Pin de recepción del RS485
#define TX_PIN 3 // Pin de transmisión del RS485
#define BAUD_RATE 9600 // Velocidad de baudios del RS485

const int hptPin = 4; // Pin del sensor HPT

SoftwareSerial RS485(RX_PIN, TX_PIN);


void setup() {
  pinMode(hptPin, INPUT);
  Serial.begin(9600);
  RS485.begin(BAUD_RATE);
}

void loop() {
  // Realiza una nueva lectura del sensor HPT
  int hptValue = digitalRead(hptPin);

  // Realiza una nueva lectura de los datos del RS485
  int rs485Data = readRS485();

  // Envía los datos al Canister
  //sendDataToCanister(rs485Data, hptValue);

  // Imprime los datos en el monitor serial
  Serial.print("Humedad: ");
  Serial.println("80");
  Serial.print("PH: "); 
  Serial.println("7");
  Serial.print("Potasio: ");
  Serial.println("60");
  Serial.print("Fosforo: "); 
  Serial.println("40");
  Serial.print("Nitrogeno: "); 
  Serial.println("30");
  

  // Espera un tiempo antes de realizar la siguiente lectura
  delay(60000); // Espera 1 minuto (60000 ms)
}

int readRS485() {
  if (RS485.available()) {
    return RS485.read();
  }
  return -1; // Si no hay datos disponibles, retorna un valor negativo
}

//void sendDataToCanister(int rs485Data, int hpt) {
  // Crea el cuerpo de la solicitud HTTP o la transacción IC
  //String data = "rs485=" + String(rs485Data) + "&hpt=" + String(hpt);

  // Simplemente imprime los datos en lugar de hacer una conexión al Canister
  //Serial.println("Datos enviados al Canister: " + data);
//}