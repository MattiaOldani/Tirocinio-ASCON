extern "C"
{
#include <inttypes.h>
#include <string.h>

#include "api.h"
#include "crypto_auth.h"
}

#if defined(AVR_UART)
#include "avr_uart.h"
#endif

#define MAX_DATA_LENGTH 1024

void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
    unsigned long long i;
    for (i = 0; i < numbytes; i++)
        buffer[i] = (unsigned char)i;
}

void test(unsigned long long dlen)
{
    unsigned char key[CRYPTO_KEYBYTES];
    unsigned char msg[MAX_DATA_LENGTH];
    unsigned char tag[CRYPTO_BYTES];

    init_buffer(key, sizeof(key));
    init_buffer(msg, sizeof(msg));

    unsigned long time = micros();
    if (crypto_auth(tag, msg, dlen, key) != 0)
    {
        Serial.println("Errore: crypto_auth");
    }
    Serial.println(micros() - time);

    // for (unsigned long long i = 0; i < CRYPTO_BYTES; i++) Serial.print(tag[i], HEX);
    // Serial.println();

    time = micros();
    if (crypto_auth_verify(tag, msg, dlen, key) != 0)
    {
        Serial.println("Errore: crypto_auth_verify");
    }

    // test failed verification
    tag[0] ^= 1;
    if (crypto_auth_verify(tag, msg, dlen, key) == 0)
    {
        Serial.println("Errore: diverso tag");
    }
    Serial.println(micros() - time);
}

void setup()
{
    Serial.begin(9600);

    // Caso migliore
    test(0);

    // Caso peggiore
    test(16);

    Serial.end();
}

void loop() {}
