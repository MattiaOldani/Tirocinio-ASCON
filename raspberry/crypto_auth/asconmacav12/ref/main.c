#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <time.h>

#include "api.h"
#include "crypto_auth.h"

#if defined(AVR_UART)
#include "avr_uart.h"
#endif

#define MAX_DATA_LENGTH 1024

void init_buffer(unsigned char *buffer, unsigned long long numbytes);
void test(unsigned long long dlen, FILE* fptr);
int get_time(struct timeval tv1, struct timeval tv2);

void main(int argc, char* argv[]) {
  FILE *fptr;
  fptr = fopen(argv[1], "a");

  for (int i = 0; i < 1000; i++)
  {
    test(0, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH / 128, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH / 64, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH / 32, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH / 16, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH / 8, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH / 4, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH / 2, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_DATA_LENGTH, fptr);
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

void test(unsigned long long dlen, FILE* fptr)
{
  unsigned char key[CRYPTO_KEYBYTES];
  unsigned char msg[MAX_DATA_LENGTH];
  unsigned char tag[CRYPTO_BYTES];

  init_buffer(key, sizeof(key));
  init_buffer(msg, sizeof(msg));

  struct timeval tv1, tv2;

  gettimeofday(&tv1, NULL);
  if (crypto_auth(tag, msg, dlen, key) != 0)
  {
    printf("Errore: crypto_auth\n");
  }
  gettimeofday(&tv2, NULL);
  fprintf(fptr, "%d;", get_time(tv1, tv2));

  gettimeofday(&tv1, NULL);
  if (crypto_auth_verify(tag, msg, dlen, key) != 0)
  {
    printf("Errore: crypto_auth_verify\n");
  }

  // test failed verification
  tag[0] ^= 1;
  if (crypto_auth_verify(tag, msg, dlen, key) == 0)
  {
      printf("Errore: diverso tag\n");
  }
  gettimeofday(&tv2, NULL);
  fprintf(fptr, "%d", get_time(tv1, tv2));
}

int get_time(struct timeval tv1, struct timeval tv2) {
  return (int) ((double) (tv2.tv_usec - tv1.tv_usec) + (double) ((tv2.tv_sec - tv1.tv_sec) * 1000000));
}
