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

// FILE constants.h
#include <stdint.h>



// FILE forceinline.h


// FILE interleave.h


// FILE permutations.h


// FILE word.h
#include <string.h>



// FILE round.h


// FILE aead.c


////////////////////////////////////////////////////////////////////////////////////////////////////

#define KAT_SUCCESS 0
#define KAT_FILE_OPEN_ERROR -1
#define KAT_DATA_ERROR -3
#define KAT_CRYPTO_FAILURE -4
#define MAX_FILE_NAME 256
#define MAX_MESSAGE_LENGTH 32
#define MAX_ASSOCIATED_DATA_LENGTH 32

void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
  unsigned long long i;
  for (i = 0; i < numbytes; i++)
    buffer[i] = (unsigned char)i;
}

void test(unsigned long long p1, unsigned long long p2)
{
  unsigned char key[CRYPTO_KEYBYTES];
  unsigned char nonce[CRYPTO_NPUBBYTES];
  unsigned char msg[MAX_MESSAGE_LENGTH];
  unsigned char msg2[MAX_MESSAGE_LENGTH];
  unsigned char ad[MAX_ASSOCIATED_DATA_LENGTH];
  unsigned char ct[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES];
  unsigned long long mlen = p1, adlen = p2;
  unsigned long long clen, mlen2;

  init_buffer(key, sizeof(key));
  init_buffer(nonce, sizeof(nonce));
  init_buffer(msg, sizeof(msg));
  init_buffer(ad, sizeof(ad));

  unsigned long time = micros();
  if (crypto_aead_encrypt(ct, &clen, msg, mlen, ad, adlen, NULL, nonce, key) != 0)
  {
    Serial.println("Errore: crypto_aead_encrypt");
  }
  Serial.println(micros() - time);

  // for (unsigned long long i = 0; i < clen; i++) Serial.print(ct[i], HEX);
  // Serial.println();

  time = micros();
  if (crypto_aead_decrypt(msg2, &mlen2, NULL, ct, clen, ad, adlen, nonce, key) != 0)
  {
    Serial.println("Errore: crypto_aead_decrypt");
  }
  if (mlen != mlen2)
  {
    Serial.println("Errore: diversa lunghezza");
  }
  if (memcmp(msg, msg2, mlen))
  {
    Serial.println("Errore: impossibile recuperare il PT");
  }

  // test failed verification
  ct[0] ^= 1;
  if (crypto_aead_decrypt(msg2, &mlen2, NULL, ct, clen, ad,
                          adlen, nonce, key) == 0)
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
  test(0, 0);

  // Caso peggiore
  test(MAX_MESSAGE_LENGTH, MAX_ASSOCIATED_DATA_LENGTH);

  Serial.end();
}

void loop() {}
