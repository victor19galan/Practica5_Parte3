#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SDA_PIN 20
#define SCL_PIN 21

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_WIDTH 16
#define LOGO_HEIGHT 16

static const unsigned char PROGMEM logo_bmp[] = {
    0b00000000, 0b11000000,
    0b00000001, 0b11000000,
    0b00000001, 0b11000000,
    0b00000011, 0b11100000,
    0b11110011, 0b11100000,
    0b11111110, 0b11111000,
    0b01111110, 0b11111111,
    0b00110011, 0b10011111,
    0b00011111, 0b11111100,
    0b00001101, 0b01110000,
    0b00011011, 0b10100000,
    0b00111111, 0b11100000,
    0b00111111, 0b11110000,
    0b01111100, 0b11110000,
    0b01110000, 0b01110000,
    0b00000000, 0b00110000
};

void testDrawPixel();
void testDrawLine();
void testDrawRect();
void testFillRect();
void testDrawCircle();
void testFillCircle();
void testDrawRoundRect();
void testFillRoundRect();
void testDrawTriangle();
void testFillTriangle();
void testDrawChar();
void testDrawStyles();
void testScrollText();
void testDrawBitmap();
void splashMessage();

// Nuevas animaciones
void animLogoBounce();
void animBoatWaves();
void animSineWave();
void animFourierWave();
void animBarcode();
void animFakeQR();
void animVolumeBar();
void animSmilingBoy();

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Wire.begin(SDA_PIN, SCL_PIN);
    delay(200);

    Serial.println("Inicializando OLED SSD1306 en 0x3C...");

    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println("Error: OLED no encontrada en 0x3C");
        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("OLED detectada correctamente");

    randomSeed(analogRead(0));
    splashMessage();
}

void loop()
{
    testDrawPixel();
    testDrawLine();
    testDrawRect();
    testFillRect();
    testDrawCircle();
    testFillCircle();
    testDrawRoundRect();
    testFillRoundRect();
    testDrawTriangle();
    testFillTriangle();
    testDrawChar();
    testDrawStyles();
    testScrollText();
    testDrawBitmap();

    animLogoBounce();
    animBoatWaves();
    animSineWave();
    animFourierWave();
    animBarcode();
    animFakeQR();
    animVolumeBar();
    animSmilingBoy();
}

void splashMessage()
{
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(2);
    display.setCursor(8, 8);
    display.println("OLED OK");

    display.setTextSize(1);
    display.setCursor(18, 36);
    display.println("Direccion 0x3C");

    display.display();
    delay(2000);
}

void testDrawPixel()
{
    Serial.println("Prueba: pixel");
    display.clearDisplay();
    display.drawPixel(10, 10, SSD1306_WHITE);
    display.drawPixel(20, 20, SSD1306_WHITE);
    display.drawPixel(30, 30, SSD1306_WHITE);
    display.display();
    delay(1500);
}

void testDrawLine()
{
    Serial.println("Prueba: lineas");
    display.clearDisplay();

    for (int16_t i = 0; i < display.width(); i += 4)
    {
        display.drawLine(0, 0, i, display.height() - 1, SSD1306_WHITE);
        display.display();
        delay(10);
    }

    display.clearDisplay();

    for (int16_t i = 0; i < display.height(); i += 4)
    {
        display.drawLine(0, 0, display.width() - 1, i, SSD1306_WHITE);
        display.display();
        delay(10);
    }

    delay(1000);
}

void testDrawRect()
{
    Serial.println("Prueba: rectangulos");
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2; i += 3)
    {
        display.drawRect(i, i, display.width() - 2 * i, display.height() - 2 * i, SSD1306_WHITE);
        display.display();
        delay(20);
    }

    delay(1500);
}

void testFillRect()
{
    Serial.println("Prueba: rectangulos rellenos");
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2; i += 4)
    {
        display.fillRect(i, i, display.width() - 2 * i, display.height() - 2 * i, SSD1306_INVERSE);
        display.display();
        delay(30);
    }

    delay(1500);
}

void testDrawCircle()
{
    Serial.println("Prueba: circulos");
    display.clearDisplay();

    for (int16_t i = 2; i < max(display.width(), display.height()) / 2; i += 4)
    {
        display.drawCircle(display.width() / 2, display.height() / 2, i, SSD1306_WHITE);
        display.display();
        delay(20);
    }

    delay(1500);
}

void testFillCircle()
{
    Serial.println("Prueba: circulos rellenos");
    display.clearDisplay();

    for (int16_t i = max(display.width(), display.height()) / 2; i > 0; i -= 4)
    {
        display.fillCircle(display.width() / 2, display.height() / 2, i, SSD1306_INVERSE);
        display.display();
        delay(30);
    }

    delay(1500);
}

void testDrawRoundRect()
{
    Serial.println("Prueba: rectangulos redondeados");
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2 - 2; i += 3)
    {
        display.drawRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i, 8, SSD1306_WHITE);
        display.display();
        delay(20);
    }

    delay(1500);
}

void testFillRoundRect()
{
    Serial.println("Prueba: rectangulos redondeados rellenos");
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2 - 2; i += 3)
    {
        display.fillRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i, 8, SSD1306_INVERSE);
        display.display();
        delay(30);
    }

    delay(1500);
}

void testDrawTriangle()
{
    Serial.println("Prueba: triangulos");
    display.clearDisplay();

    for (int16_t i = 0; i < max(display.width(), display.height()) / 2; i += 5)
    {
        display.drawTriangle(
            display.width() / 2, display.height() / 2 - i,
            display.width() / 2 - i, display.height() / 2 + i,
            display.width() / 2 + i, display.height() / 2 + i,
            SSD1306_WHITE);
        display.display();
        delay(25);
    }

    delay(1500);
}

void testFillTriangle()
{
    Serial.println("Prueba: triangulos rellenos");
    display.clearDisplay();

    for (int16_t i = max(display.width(), display.height()) / 2; i > 0; i -= 5)
    {
        display.fillTriangle(
            display.width() / 2, display.height() / 2 - i,
            display.width() / 2 - i, display.height() / 2 + i,
            display.width() / 2 + i, display.height() / 2 + i,
            SSD1306_INVERSE);
        display.display();
        delay(30);
    }

    delay(1500);
}

void testDrawChar()
{
    Serial.println("Prueba: caracteres");
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.cp437(true);

    for (int16_t i = 33; i < 128; i++)
    {
        display.write(i);
    }

    display.display();
    delay(2500);
}

void testDrawStyles()
{
    Serial.println("Prueba: estilos de texto");
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Hello, world!");

    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.println(3.141592);

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.print("0x");
    display.println(0xDEADBEEF, HEX);

    display.display();
    delay(2500);
}

void testScrollText()
{
    Serial.println("Prueba: scroll");
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 20);
    display.println("scroll");
    display.display();
    delay(300);

    display.startscrollright(0x00, 0x0F);
    delay(2000);
    display.stopscroll();
    delay(500);

    display.startscrollleft(0x00, 0x0F);
    delay(2000);
    display.stopscroll();
    delay(500);

    display.startscrolldiagright(0x00, 0x07);
    delay(2000);
    display.stopscroll();
    delay(500);

    display.startscrolldiagleft(0x00, 0x07);
    delay(2000);
    display.stopscroll();
    delay(1000);
}

void testDrawBitmap()
{
    Serial.println("Prueba: bitmap");
    display.clearDisplay();

    display.drawBitmap(
        (display.width() - LOGO_WIDTH) / 2,
        (display.height() - LOGO_HEIGHT) / 2,
        logo_bmp,
        LOGO_WIDTH,
        LOGO_HEIGHT,
        SSD1306_WHITE);

    display.display();
    delay(2500);
}

// ==================== NUEVAS ANIMACIONES ====================

void animLogoBounce()
{
    Serial.println("Animacion: logo rebotando");

    int x = 10;
    int y = 10;
    int dx = 2;
    int dy = 2;

    for (int i = 0; i < 120; i++)
    {
        display.clearDisplay();
        display.drawBitmap(x, y, logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE);
        display.display();
        delay(25);

        x += dx;
        y += dy;

        if (x <= 0 || x >= SCREEN_WIDTH - LOGO_WIDTH) dx = -dx;
        if (y <= 0 || y >= SCREEN_HEIGHT - LOGO_HEIGHT) dy = -dy;
    }
}

void animBoatWaves()
{
    Serial.println("Animacion: barco y olas");

    for (int t = 0; t < 180; t++)
    {
        display.clearDisplay();

        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            int y = 46 + (int)(3.0 * sin((x + t) * 0.18));
            display.drawPixel(x, y, SSD1306_WHITE);
        }

        int boatX = (t % (SCREEN_WIDTH + 20)) - 20;
        int boatY = 38 + (int)(2.0 * sin(t * 0.18));

        display.drawLine(boatX, boatY, boatX + 14, boatY, SSD1306_WHITE);
        display.drawLine(boatX, boatY, boatX + 4, boatY + 5, SSD1306_WHITE);
        display.drawLine(boatX + 14, boatY, boatX + 10, boatY + 5, SSD1306_WHITE);
        display.drawLine(boatX + 4, boatY + 5, boatX + 10, boatY + 5, SSD1306_WHITE);

        display.drawLine(boatX + 7, boatY, boatX + 7, boatY - 10, SSD1306_WHITE);
        display.drawLine(boatX + 7, boatY - 10, boatX + 12, boatY - 5, SSD1306_WHITE);
        display.drawLine(boatX + 7, boatY - 10, boatX + 7, boatY - 5, SSD1306_WHITE);

        display.display();
        delay(30);
    }
}

void animSineWave()
{
    Serial.println("Animacion: seno");

    for (int t = 0; t < 160; t++)
    {
        display.clearDisplay();

        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            int y = 32 + (int)(12.0 * sin((x + t) * 0.16));
            display.drawPixel(x, y, SSD1306_WHITE);
        }

        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.println("Seno");

        display.display();
        delay(20);
    }
}

void animFourierWave()
{
    Serial.println("Animacion: fourier");

    for (int t = 0; t < 160; t++)
    {
        display.clearDisplay();

        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            float y =
                32.0
                + 10.0 * sin((x + t) * 0.10)
                + 5.0 * sin((x + t) * 0.24)
                + 3.0 * sin((x + t) * 0.43);

            display.drawPixel(x, (int)y, SSD1306_WHITE);
        }

        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.println("Fourier");

        display.display();
        delay(20);
    }
}

void animBarcode()
{
    Serial.println("Animacion: codigo de barras");

    for (int t = 0; t < 90; t++)
    {
        display.clearDisplay();

        int offset = t % 8;

        for (int x = -offset; x < SCREEN_WIDTH; x += 6)
        {
            int w = (x / 6) % 2 == 0 ? 2 : 4;
            if (x >= 0)
            {
                display.fillRect(x, 8, w, 48, SSD1306_WHITE);
            }
        }

        display.setTextSize(1);
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
        display.setCursor(30, 0);
        display.println("BARCODE");

        display.display();
        delay(45);
    }
}

void animFakeQR()
{
    Serial.println("Animacion: QR simulado");

    for (int frame = 0; frame < 25; frame++)
    {
        display.clearDisplay();

        int startX = 32;
        int startY = 0;
        int cell = 4;

        for (int y = 0; y < 16; y++)
        {
            for (int x = 0; x < 16; x++)
            {
                bool on = ((x * 7 + y * 11 + frame * 3) % 5) < 2;
                if (on)
                {
                    display.fillRect(startX + x * cell, startY + y * cell, 3, 3, SSD1306_WHITE);
                }
            }
        }

        display.drawRect(startX, startY, 7 * cell, 7 * cell, SSD1306_WHITE);
        display.drawRect(startX + 1, startY + 1, 5 * cell, 5 * cell, SSD1306_WHITE);
        display.fillRect(startX + 2 * cell, startY + 2 * cell, 3 * cell, 3 * cell, SSD1306_WHITE);

        display.drawRect(startX + 9 * cell, startY, 7 * cell, 7 * cell, SSD1306_WHITE);
        display.drawRect(startX + 9 * cell + 1, startY + 1, 5 * cell, 5 * cell, SSD1306_WHITE);
        display.fillRect(startX + 11 * cell, startY + 2 * cell, 3 * cell, 3 * cell, SSD1306_WHITE);

        display.drawRect(startX, startY + 9 * cell, 7 * cell, 7 * cell, SSD1306_WHITE);
        display.drawRect(startX + 1, startY + 9 * cell + 1, 5 * cell, 5 * cell, SSD1306_WHITE);
        display.fillRect(startX + 2 * cell, startY + 11 * cell, 3 * cell, 3 * cell, SSD1306_WHITE);

        display.display();
        delay(180);
    }
}

void animVolumeBar()
{
    Serial.println("Animacion: barra de volumen");

    for (int t = 0; t < 100; t++)
    {
        display.clearDisplay();

        int level = (int)(60 + 50 * sin(t * 0.18));
        if (level < 0) level = 0;
        if (level > 100) level = 100;

        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.print("Volumen: ");
        display.print(level);
        display.println("%");

        display.drawRect(10, 24, 108, 16, SSD1306_WHITE);
        display.fillRect(12, 26, level, 12, SSD1306_WHITE);

        for (int i = 0; i < 8; i++)
        {
            int h = (int)(8 + 10 * fabs(sin((t + i * 4) * 0.25)));
            display.fillRect(10 + i * 14, 50 - h, 8, h, SSD1306_WHITE);
        }

        display.display();
        delay(50);
    }
}

void animSmilingBoy()
{
    Serial.println("Animacion: chico con gafas sonriendo");

    for (int t = 0; t < 100; t++)
    {
        display.clearDisplay();

        int faceX = 64;
        int faceY = 30;
        int blink = (t % 30 == 0) ? 0 : 1;
        int smileOffset = (int)(2.0 * sin(t * 0.25));

        // Cabeza
        display.drawCircle(faceX, faceY, 20, SSD1306_WHITE);

        // Pelo
        display.drawLine(faceX - 12, faceY - 14, faceX + 12, faceY - 14, SSD1306_WHITE);
        display.drawLine(faceX - 10, faceY - 16, faceX + 8, faceY - 18, SSD1306_WHITE);

        // Gafas
        display.drawCircle(faceX - 7, faceY - 3, 5, SSD1306_WHITE);
        display.drawCircle(faceX + 7, faceY - 3, 5, SSD1306_WHITE);
        display.drawLine(faceX - 2, faceY - 3, faceX + 2, faceY - 3, SSD1306_WHITE);

        // Ojos/parpadeo
        if (blink)
        {
            display.drawPixel(faceX - 7, faceY - 3, SSD1306_WHITE);
            display.drawPixel(faceX + 7, faceY - 3, SSD1306_WHITE);
        }
        else
        {
            display.drawLine(faceX - 9, faceY - 3, faceX - 5, faceY - 3, SSD1306_WHITE);
            display.drawLine(faceX + 5, faceY - 3, faceX + 9, faceY - 3, SSD1306_WHITE);
        }

        // Nariz
        display.drawLine(faceX, faceY - 1, faceX - 1, faceY + 5, SSD1306_WHITE);

        // Sonrisa
        display.drawLine(faceX - 6, faceY + 10, faceX + 6, faceY + 10, SSD1306_WHITE);
        display.drawPixel(faceX - 5, faceY + 11 + smileOffset, SSD1306_WHITE);
        display.drawPixel(faceX - 4, faceY + 12 + smileOffset, SSD1306_WHITE);
        display.drawPixel(faceX + 4, faceY + 12 + smileOffset, SSD1306_WHITE);
        display.drawPixel(faceX + 5, faceY + 11 + smileOffset, SSD1306_WHITE);

        // Cuello y hombros
        display.drawLine(faceX - 4, faceY + 20, faceX - 4, faceY + 25, SSD1306_WHITE);
        display.drawLine(faceX + 4, faceY + 20, faceX + 4, faceY + 25, SSD1306_WHITE);
        display.drawLine(faceX - 14, faceY + 30, faceX + 14, faceY + 30, SSD1306_WHITE);

        display.display();
        delay(60);
    }
}