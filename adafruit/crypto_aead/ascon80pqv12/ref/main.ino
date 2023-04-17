extern "C"
{
#include <inttypes.h>
#include <string.h>

#include "api.h"
#include "crypto_aead.h"
}

#if defined(AVR_UART)
#include "avr_uart.h"
#endif

#define MAX_MESSAGE_LENGTH 32
#define MAX_ASSOCIATED_DATA_LENGTH 32

void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
  unsigned long long i;
  for (i = 0; i < numbytes; i++)
    buffer[i] = (unsigned char)i;
}

void test(unsigned long long mlen, unsigned long long adlen)
{
  unsigned char key[CRYPTO_KEYBYTES];
  unsigned char nonce[CRYPTO_NPUBBYTES];
  unsigned char msg[MAX_MESSAGE_LENGTH];
  unsigned char msg2[MAX_MESSAGE_LENGTH];
  unsigned char ad[MAX_ASSOCIATED_DATA_LENGTH];
  unsigned char ct[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES];
  unsigned long long clen, mlen2;

  init_buffer(key, sizeof(key));
  init_buffer(nonce, sizeof(nonce));
  init_buffer(msg, sizeof(msg));
  init_buffer(ad, sizeof(ad));

  unsigned long time = micros();
  if (crypto_aead_encrypt(ct, &clen, msg, mlen, ad, adlen, NULL, nonce, key) != 0)
  {
    Serial.println("ERRORE: crypto_aead_encrypt");
  }
  Serial.println(micros() - time);

  // for (unsigned long long i = 0; i < clen; i++) Serial.print(ct[i], HEX);
  // Serial.println();

  time = micros();
  if (crypto_aead_decrypt(msg2, &mlen2, NULL, ct, clen, ad, adlen, nonce, key) != 0)
  {
    Serial.println("ERRORE: prima crypto_aead_decrypt");
  }
  if (mlen != mlen2)
  {
    Serial.println("ERRORE: diversa lunghezza");
  }
  if (memcmp(msg, msg2, mlen))
  {
    Serial.println("ERRORE: impossibile recuperare il PT");
  }

  // test failed verification
  ct[0] ^= 1;
  if (crypto_aead_decrypt(msg2, &mlen2, NULL, ct, clen, ad, adlen, nonce, key) == 0)
  {
    Serial.println("ERRORE: diverso tag");
  }
  Serial.println(micros() - time);
}

void setup()
{
  Serial.begin(9600);

  // Tip by Matteo Yon per permettere la stampa
  delay(3000);

  // Caso migliore
  test(0, 0);

  // Caso peggiore
  test(MAX_MESSAGE_LENGTH, MAX_ASSOCIATED_DATA_LENGTH);
}

void loop() {}
