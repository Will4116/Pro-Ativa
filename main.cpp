#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define LED_PIN_1 13  // Pino do primeiro LED (GPIO 13)
#define LED_PIN_2 14  // Pino do segundo LED (GPIO 14)
#define LED_PIN_3 26  // Pino do terceiro LED (GPIO 26)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);

    // Configura os pinos dos LEDs como saídas
    pinMode(LED_PIN_1, OUTPUT);
    pinMode(LED_PIN_2, OUTPUT);
    pinMode(LED_PIN_3, OUTPUT);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Endereço I2C do OLED
        Serial.println(F("Falha ao inicializar o display"));
        for (;;);
    }

    display.clearDisplay();
    display.setTextSize(3);       // Define o tamanho do texto (4 = tamanho grande)
    display.setTextColor(WHITE);  // Cor do texto
    display.setCursor(10, 10);    // Define a posição do texto (ajustado para centralizar)
    display.println("ALERTACRITICO");   // Exibe a palavra "PERIGO!"
    display.display();            // Atualiza o display
}

void loop() {
    // Acende os LEDs
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    delay(500);  // Aguarda 500ms

    // Apaga os LEDs
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    delay(500);  // Aguarda 500ms
}
