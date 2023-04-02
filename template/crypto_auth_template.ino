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
#define ASCON_INLINE_MODE
#define ASCON_INLINE_PERM
#define ASCON_UNROLL_LOOPS
#define ASCON_INLINE_BI
#define ASCON_EXTERN_BI

// FILE constants.h
#include <stdint.h>



// FILE forceinline.h


// FILE interleave.h


// FILE permutations.h


// FILE word.h
#include <string.h>



// FILE round.h


// FILE prf.c


// FILE prfs.c


////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX_DATA_LENGTH 1024

void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
    for (unsigned long long i = 0; i < numbytes; i++)
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
    ct[0] ^= 1;
    if (crypto_auth_verify(tag, msg, dlen, key) == 0)
    {
        Serial.println("Errore: diverso tag");
    }
    Serial.println(micros() - time);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
    Serial.begin(9600);

    // Caso migliore
    test(0);

    // Caso peggiore
    test(MAX_DATA_LENGTH);

    Serial.end();
}

void loop() {}
