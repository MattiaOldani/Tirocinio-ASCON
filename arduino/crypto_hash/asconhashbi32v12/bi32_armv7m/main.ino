extern "C"
{
#include <string.h>

#include "api.h"
#include "crypto_hash.h"
#include "constants.h"
}

#if defined(AVR_UART)
#include "avr_uart.h"
#endif

#define MAX_MESSAGE_LENGTH 1024

void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
    unsigned long long i;
    for (i = 0; i < numbytes; i++)
        buffer[i] = (unsigned char)i;
}

void test(unsigned long long mlen)
{
    unsigned char msg[MAX_MESSAGE_LENGTH];
    unsigned char digest[CRYPTO_BYTES];

    init_buffer(msg, sizeof(msg));

    unsigned long time = micros();
    if (crypto_hash(digest, msg, mlen) != 0)
    {
        Serial.println("Errore: crypto_hash");
    }
    Serial.print(micros() - time);
}

void setup()
{
    Serial.begin(9600);

    // Tip by Matteo Yon per permettere la stampa
    while (!Serial);

    for (int i = 0; i < 1000; i++)
    {
        test(0);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH / 128);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH / 64);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH / 32);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH / 16);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH / 8);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH / 4);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH / 2);
        Serial.print(";");
        test(MAX_MESSAGE_LENGTH);
        Serial.println();
    }

    Serial.end();
}

void loop() {}
