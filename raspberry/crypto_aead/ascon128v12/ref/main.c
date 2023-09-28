#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <time.h>

#include "api.h"
#include "crypto_aead.h"

#if defined(AVR_UART)
#include "avr_uart.h"
#endif

#define MAX_MESSAGE_LENGTH 4 * ASCON_AEAD_RATE
#define MAX_ASSOCIATED_DATA_LENGTH 4 * ASCON_AEAD_RATE

void init_buffer(unsigned char *buffer, unsigned long long numbytes);
void test(unsigned long long mlen, unsigned long long adlen, FILE* fptr);
int get_time(struct timeval tv1, struct timeval tv2);

void main(int argc, char* argv[]) {
  FILE *fptr;
  fptr = fopen(argv[1], "a");

  for (int i = 0; i < 1000; i++)
  {
    test(0, 0, fptr);
    fprintf(fptr, "%s", ";");
    test(1, 1, fptr);
    fprintf(fptr, "%s", ";");
    test(ASCON_AEAD_RATE, ASCON_AEAD_RATE, fptr);
    fprintf(fptr, "%s", ";");
    test(2 * ASCON_AEAD_RATE, 2 * ASCON_AEAD_RATE, fptr);
    fprintf(fptr, "%s", ";");
    test(3 * ASCON_AEAD_RATE, 3 * ASCON_AEAD_RATE, fptr);
    fprintf(fptr, "%s", ";");
    test(4 * ASCON_AEAD_RATE, 4 * ASCON_AEAD_RATE, fptr);
    fprintf(fptr, "\n");
  }

  fclose(fptr);
}

void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
  unsigned long long i;
  for (i = 0; i < numbytes; i++)
    buffer[i] = (unsigned char)i;
}

void test(unsigned long long mlen, unsigned long long adlen, FILE* fptr)
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

  struct timeval tv1, tv2;

	gettimeofday(&tv1, NULL);
  if (crypto_aead_encrypt(ct, &clen, msg, mlen, ad, adlen, NULL, nonce, key) != 0)
  {
    printf("ERRORE: crypto_aead_encrypt\n");
  }
  gettimeofday(&tv2, NULL);
  fprintf(fptr, "%d;", get_time(tv1, tv2));

  gettimeofday(&tv1, NULL);
  if (crypto_aead_decrypt(msg2, &mlen2, NULL, ct, clen, ad, adlen, nonce, key) != 0)
  {
    printf("ERRORE: prima crypto_aead_decrypt\n");
  }
  if (mlen != mlen2)
  {
    printf("ERRORE: diversa lunghezza\n");
  }
  if (memcmp(msg, msg2, mlen))
  {
    printf("ERRORE: impossibile recuperare il PT\n");
  }

  // test failed verification
  ct[0] ^= 1;
  if (crypto_aead_decrypt(msg2, &mlen2, NULL, ct, clen, ad, adlen, nonce, key) == 0)
  {
    printf("ERRORE: diverso tag\n");
  }
  gettimeofday(&tv2, NULL);
  fprintf(fptr, "%d", get_time(tv1, tv2));
}

int get_time(struct timeval tv1, struct timeval tv2) {
  return (int) ((double) (tv2.tv_usec - tv1.tv_usec) + (double) ((tv2.tv_sec - tv1.tv_sec) * 1000000));
}
