#include <Wire.h>
#include <SPI.h>
#include "time.h"
#include <ESP_Google_Sheet_Client.h>
#include "BluetoothSerial.h"
#include <esp_wifi.h>
#define DEBUG_ESP_WIFI

BluetoothSerial SerialBT;

#define WIFI_SSID "PERRO"
#define WIFI_PASSWORD "Jr123456789"

// Google Project ID
#define PROJECT_ID "esp32datalogger-442320"

// Service Account's client email
#define CLIENT_EMAIL "esp32data@esp32datalogger-442320.iam.gserviceaccount.com"


// Service Account's private key
const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\nMIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQCpPeUk1VZSgyFM\nTnDKYEvIf1LRvZqYxkJUlQN3dTFrJT5frPkFv1Nc3Vu7GNtS/Bt9SsQ3uzgs2SNq\nMit0rY0+ch1VVVPg30HT5TEe4xIPGAzyhvt8TAKCuadGwFpkhwR1E1i99O2tvhYM\nd87Zo185MFHFVCMlDO9bVwVfl6fEI9lJNS+XhbPgXY/bY5Ix+9ozVSrdYvz3FR9k\n6zfeQYzhkWtJ0IcFmUXEjAfMcCaE7rj65UGqW6FVO9OP/IQhb50olgrrWW+p4KGa\nsLWamW4rTdyKyVMT2cRuPQaitr4pFIpJ4aI7ingjNUD7yTcBmZPckc0sseFgwyvX\ntSwOj+xNAgMBAAECgf8ws0mST9GHQjSoFepe/KwnWybPNBWd4MSK56vCXvbZiN4U\nqgb+oGUHVAC8K2rxdkUdc2ZYozHcYJ9675+Rnl9b7iUtaQsPVS9Gyleti6n8A0UL\n2naDo1vAQlbgWnmoc9x/KWdf7MXNjpAfBlrU8IN2RsaWV0pwXvMsVYjg+RhNrYtj\nRFJyNY4WIgeI2CknIbOF9GyoczNGPF2uW20kX8Sv9WRzrGXUGLbnx6t4/rvAmwvP\n9NNihhUySUFfkWyeEOtFSM3MMTGVt+XAjxyNvp6xOLv+9EnsBOx6XnwOZN+BTYRf\nZwvuDCsvNsBgfV2JOKs6Ys/AP1ZX9ZW6m08tYUECgYEA0E0tfZ9ioo0FcuzinCrb\nn+J7tn32PUEcF2PF1CVl3je02KGznXnEHHN6gf1PbryVetSNIj7lbDOe9RPYEZ7h\ncOMylV/Xl9NDQ840CT4i/ASTktWO9aTLRzljhnZxGTNBRCedYjydcoK6ImnnxgCz\njMXjLJb/ba0tt3hOyeGLJ1ECgYEAz/8AmFL14x8kvfFCTztlFCFkpA2d5JQF3W7+\nyj2bH/hr7w76rwqxroXLLg2vo89HaLchx1swPQ3L81xSU79nPaKCeeS3KIp3x+Ri\ngRwYA78GaotzS1SAi7IYLsRwv/QORhpv+C4XigiQMV4S/RO10o72TwXasDMh3bWc\nsbInLj0CgYBtwx1jgudQzIrAgn7u186fM5MJGNr2cCbDVHncTlCdhjEvrhWdt5pV\ne6xkbvy6V3lVHke4cfgmyhTLA8fpkRUujSoMeFJ82IArbK8S58E7l5XD2/DXFB1h\nzKXbJvJ12wJbTZyrNVGqE6TNmYzeU2RJm8UXrAGw436hnS23R7gx4QKBgQCWuFA0\nERnA5RZ41VSZmY6bUb9d6cgalPDTDtVus8mvFxMPfilFolgzARzEWIKID3HNfbbq\ngTepZk/+H05BBZfIX/RwY74dkIlPvj1rFXKJdGkv17FKSweDMyC28v5I+o9FWW79\nxlikW6QxQdw8q4W7+ICfrrxTphnKUQok8dXWeQKBgQDG58tZ8LyNu1/8bxier+y5\nYW1WiVjTsYQ1ZKataB5qO+jz/UwzYq1asry19282D7RFP9Pbo2m5coKLUdBK2KFt\nWhL0bNY2qWPozP0GxZiIsxlWWyV7I2rYGsrGLPJI1M69Qf4K9/PHLWaAkCE7nsq8\nd9OqJ9mZwGerZUi5nw6xWQ==\n-----END PRIVATE KEY-----\n";

const char spreadsheetId[] = "1F2T8mP9cg6gK78FS5aYiJ8-lO9WqkThGUL-bg_A0nQY";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 100;

const char* ntpServer = "pool.ntp.org"; // NTP server for time sync
unsigned long epochTime; // Store current epoch time

#define LDR_PIN 33  // Cambia este valor según tu conexión

// Parámetros de calibración
#define R_FIXED 10000   // Resistencia fija de 100 kΩ
#define VCC 3.3    // Máximo valor que puede leer el ADC



void setup() {
    Serial.begin(115200);
    Serial.println("Initializing...");

    // Configure time
    configTime(0, 0, ntpServer);
    // Wi-Fi connection
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
}
Serial.println("\nWi-Fi conectado. Dirección IP: " + WiFi.localIP().toString());

    // Initialize Google Sheets API
    GSheet.printf("ESP Google Sheet Client v%s\n\n", ESP_GOOGLE_SHEET_CLIENT_VERSION);
    GSheet.setTokenCallback(tokenStatusCallback);
    GSheet.setPrerefreshSeconds(10 * 60);
    GSheet.begin(CLIENT_EMAIL, PROJECT_ID, PRIVATE_KEY);

    // Initialize Bluetooth
    SerialBT.begin("ESP32_SENSOR");

    pinMode(33,INPUT);
}

bool reconnectWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.disconnect();
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        for (int i = 0; i < 10; i++) {
            if (WiFi.status() == WL_CONNECTED) {
                Serial.println("Reconectado a WiFi.");
                return true;
            }
            delay(1000);
        }
        Serial.println("Error: No se pudo reconectar a WiFi.");
        return false;
    }
    return true;
}


void loop() {
if (WiFi.status() != WL_CONNECTED) {
        reconnectWiFi();  // Intentar reconectar si se pierde conexión
    }

    bool ready = GSheet.ready();

    if (ready && millis() - lastTime > timerDelay) {
        lastTime = millis();

        FirebaseJson valueRange;

        // Leer el valor analógico del pin conectado al LDR
        int ldrValue = analogRead(LDR_PIN);

        // Calcular la resistencia del LDR
        float ldrResistance = R_FIXED * (4095.0 / ldrValue - 1.0);

        // Aproximar los luxes según resistencia
        float lux = 500 / (ldrResistance / 1000.0);

        // Add data to valueRange
        valueRange.add("majorDimension", "COLUMNS");
        valueRange.set("values/[0]/[0]", millis()); // Usar millis() como timestamp
        valueRange.set("values/[1]/[0]", lux);

        // Send data to Bluetooth and Telegram
        SerialBT.println("La luminocidad es de: " + String(lux));
        delay(1000);

        // Append data to Google Sheets
        FirebaseJson response;
        bool success = GSheet.values.append(&response, spreadsheetId, "DATOS", &valueRange);
        if (success) {
            response.toString(Serial, true);
            valueRange.clear(); // Limpiar datos
        } else {
            Serial.println("Error al enviar datos a Google Sheets: " + GSheet.errorReason());
        }
        Serial.println("Heap disponible: " + String(ESP.getFreeHeap()));
    }
}

void tokenStatusCallback(TokenInfo info) {
    if (info.status == token_status_error) {
        GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
        GSheet.printf("Token error: %s\n", GSheet.getTokenError(info).c_str());
    } else {
        GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
    }
}
