/*
    Nella prima parte di ogni file sono presenti i file della libreria ASCON per permettere
    la compilazione dello sketch e il suo successivo avvio sulla board

    Nella seconda parte è presente la definizione della funzione di test, che va ad eseguire
    effettivamente il cifrario e a calcolare il tempo di esecuzione

    Nell'ultima parte sono presenti le funzioni di setup, che chiama appunto la funzione di
    test, e loop, che è vuota poichè non va eseguito niente in loop
*/

////////////////////////////////////////////////////////////////////////////////////////////////////

// FILE api.h


// FILE ascon.h


// FILE bendian.h


// FILE config.h


// FILE constants.h
#include <stdint.h>



// FILE forceinline.h


// FILE interleave.h


// FILE permutations.h


// FILE word.h
#include <string.h>



// FILE round.h


// FILE hash.c


////////////////////////////////////////////////////////////////////////////////////////////////////

// Test
#define MAX_MESSAGE_LENGTH 1024

void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
    for (unsigned long long i = 0; i < numbytes; i++)
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

    // for (unsigned long long i = 0; i < clen; i++) Serial.print(digest[i], HEX);
    // Serial.println();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
    erial.begin(9600);

    // Caso migliore
    test(0);

    // Caso peggiore
    test(MAX_MESSAGE_LENGTH);

    Serial.end();
}

void loop() {}
