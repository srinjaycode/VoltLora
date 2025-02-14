#include "VoltLora.h"

VoltLora::VoltLora(uint8_t rxPin, uint8_t txPin) {
    _serial = new SoftwareSerial(rxPin, txPin);
}

void VoltLora::begin(long baudRate) {
    Serial.begin(baudRate);
    _serial->begin(baudRate);
    delay(5000);
}

void VoltLora::setAddress(uint8_t address) {
    String command = "AT+ADDRESS=" + String(address);
    String response = sendCommand(command);
    Serial.println(checkError(response));
}

void VoltLora::setNetworkID(uint8_t networkID) {
    String command = "AT+NETWORKID=" + String(networkID);
    String response = sendCommand(command);
    Serial.println(checkError(response));
}

void VoltLora::setBand(long frequency) {
    String command = "AT+BAND=" + String(frequency);
    String response = sendCommand(command);
    Serial.println(checkError(response));
}

void VoltLora::send(uint8_t receiverAddress, String message) {
    String command = "AT+SEND=" + String(receiverAddress) + "," + String(message.length()) + "," + message;
    String response = sendCommand(command);
    Serial.println(checkError(response));
}

String VoltLora::readMessage() {
    String receivedMessage = "";
    while (_serial->available()) {
        receivedMessage += (char)_serial->read();
    }
    return receivedMessage;
}

String VoltLora::sendCommand(String command) {
    _serial->println(command);
    delay(200); // Give LoRa some time to respond

    String response = "";
    while (_serial->available()) {
        response += (char)_serial->read();
    }
    return response;
}

String VoltLora::checkError(String response) {
    if (response.indexOf("ERROR") != -1) {
        return "Error: Invalid Command or Parameter";
    } else if (response.indexOf("+OK") != -1) {
        return "Command executed successfully.";
    }
    return "Unknown response: " + response;
}

bool VoltLora::available() {
    return _serial->available();
}

char VoltLora::read() {
    return _serial->read();
}

void VoltLora::write(char c) {
    _serial->write(c);
}

void VoltLora::printWiring() {
    Serial.println("\nLoRa Wiring for Arduino Uno:");
    Serial.println("┌──────────────┐");
    Serial.println("│ LoRa RYLR998 │");
    Serial.println("├──────────────┤");
    Serial.println("│ VCC  → 3.3V  │");
    Serial.println("│ GND  → GND   │");
    Serial.println("│ TX   → D2    │");
    Serial.println("│ RX   → D3    │");
    Serial.println("└──────────────┘");
    Serial.println("Use a voltage divider (4.7KΩ and 10KΩ) for RX to step down 5V to 3.3V.");
}
