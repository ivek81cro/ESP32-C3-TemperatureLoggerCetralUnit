#ifndef MAIN_H
#define MAIN_H

#include <esp_now.h>
#include <esp_wifi.h>
#include <WiFi.h>

// Variable to store if sending data was successful
String success;

// Structure example to send data
// Must match the receiver structure
typedef struct EspNowMessage {
    char dateAndTime[25];
    float temperature;    
} EspNowMessage;

// Create a struct_message to hold incoming sensor readings
EspNowMessage incomingReadings;

esp_now_peer_info_t peerInfo;

// Callback when data is sent
void onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

// Callback when data is received
void onDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);

int32_t getWiFiChannel(const char *ssid);

void initializeESPNOW();;

void setup();
void loop();

#endif // MAIN_H
