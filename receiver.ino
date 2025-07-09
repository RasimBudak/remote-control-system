#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

struct DataPayload {
  bool button1;
  bool button2;
  bool button3;
};

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

  Serial.println("Alıcı hazır.");
}

void loop() {
  if (radio.available()) {
    DataPayload data;
    radio.read(&data, sizeof(DataPayload));
    
    Serial.print("Buton durumları: ");
    Serial.print(data.button1);
    Serial.print(" ");
    Serial.print(data.button2);
    Serial.print(" ");
    Serial.println(data.button3);

    // Burada istenirse buton durumlarına göre başka işlemler yapılabilir
  }
}
