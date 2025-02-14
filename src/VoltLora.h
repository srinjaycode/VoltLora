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
    
    bool available();
    char read();
    void write(char c);

    void printWiring();

private:
    SoftwareSerial* _serial;  // Pointer to SoftwareSerial to avoid conflicts
    String sendCommand(String command);
    String checkError(String response);
};

#endif