#ifndef VOLTLORA_H
#define VOLTLORA_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class VoltLora {
public:
    VoltLora(uint8_t rxPin, uint8_t txPin);
    void begin(long baudRate);
    void setAddress(uint8_t address);
    void setNetworkID(uint8_t networkID);
    void setBand(long frequency);
    void send(uint8_t receiverAddress, String message);
    String readMessage();
    void printWiring();
    
private:
    SoftwareSerial LoRa;
    String sendCommand(String command); // FIXED: Function now returns String
    String checkError(String response);
};

#endif
