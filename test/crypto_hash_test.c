#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <time.h>

#include "api.h"
#include "crypto_hash.h"
#include "constants.h"

#if defined(AVR_UART)
#include "avr_uart.h"
#endif

#define MAX_MESSAGE_LENGTH 1024

void init_buffer(unsigned char *buffer, unsigned long long numbytes);
void test(unsigned long long mlen, FILE* fptr);
int get_time(struct timeval tv1, struct timeval tv2);

void main(int argc, char* argv[]) {
  FILE *fptr;
  fptr = fopen(argv[1], "a");

  for (int i = 0; i < 1000; i++)
  {
    test(0, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH / 128, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH / 64, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH / 32, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH / 16, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH / 8, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH / 4, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH / 2, fptr);
    fprintf(fptr, "%s", ";");
    test(MAX_MESSAGE_LENGTH, fptr);
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

void test(unsigned long long mlen, FILE* fptr)
{
  unsigned char msg[MAX_MESSAGE_LENGTH];
  unsigned char digest[CRYPTO_BYTES];

  init_buffer(msg, sizeof(msg));

  struct timeval tv1, tv2;

  gettimeofday(&tv1, NULL);
  if (crypto_hash(digest, msg, mlen) != 0)
  {
    printf("Errore: crypto_hash\n");
  }
  gettimeofday(&tv2, NULL);
  fprintf(fptr, "%d", get_time(tv1, tv2));
}

int get_time(struct timeval tv1, struct timeval tv2) {
  return (int) ((double) (tv2.tv_usec - tv1.tv_usec) + (double) ((tv2.tv_sec - tv1.tv_sec) * 1000000));
}
