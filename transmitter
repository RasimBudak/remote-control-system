#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// NRF24L01 pinleri (Arduino Uno için)
#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;

struct DataPayload {
  bool button1;
  bool button2;
  bool button3;
};

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  Serial.println("Verici hazır.");
}

void loop() {
  DataPayload data;
  data.button1 = (digitalRead(buttonPin1) == LOW); // Butona basıldıysa LOW olur
  data.button2 = (digitalRead(buttonPin2) == LOW);
  data.button3 = (digitalRead(buttonPin3) == LOW);

  bool success = radio.write(&data, sizeof(DataPayload));
  
  if (success) {
    Serial.print("Veri gönderildi: ");
    Serial.print(data.button1);
    Serial.print(" ");
    Serial.print(data.button2);
    Serial.print(" ");
    Serial.println(data.button3);
  } else {
    Serial.println("Gönderme başarısız!");
  }

  delay(100);
}
