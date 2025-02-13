#include <VoltLora.h>

#define RX_PIN 2
#define TX_PIN 3

VoltLora lora(RX_PIN, TX_PIN);

void setup() {
    Serial.begin(115200);
    delay(1000); // Give Serial some time to initialize

    Serial.println("\n--- LoRa Wiring Diagram ---");
    lora.printWiring();
}

void loop() {
    // Nothing in loop, just printing wiring in setup()
}
