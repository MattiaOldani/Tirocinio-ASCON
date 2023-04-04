extern "C"
{
#include <string.h>

#include "api.h"
#include "crypto_hash.h"
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
    Serial.println(micros() - time);

    // for (unsigned long long i = 0; i < CRYPTO_BYTES; i++) Serial.print(digest[i], HEX);
    // Serial.println();
}

void setup()
{
    Serial.begin(9600);

    // Caso migliore
    test(0);

    // Caso peggiore
    test(MAX_MESSAGE_LENGTH);

    Serial.end();
}

void loop() {}
