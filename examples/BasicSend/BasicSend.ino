#include <VoltLora.h>

#define RX_PIN 2
#define TX_PIN 3

VoltLora lora(RX_PIN, TX_PIN);

void setup() {
    Serial.begin(115200);
    lora.begin(115200);
    lora.setAddress(1);
    lora.setNetworkID(5);
    lora.setBand(868500000);

    Serial.println("Sending LoRa message...");
    lora.send(2, "Hello from VoltLora!");
}

void loop() {
    // Nothing here, just sending once in setup()
}
