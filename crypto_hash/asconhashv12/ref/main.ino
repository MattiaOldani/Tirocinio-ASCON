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
#define CRYPTO_VERSION "1.2.7"
#define CRYPTO_BYTES 32
#define ASCON_HASH_BYTES 32 /* HASH */
#define ASCON_HASH_ROUNDS 12

// FILE ascon.h
typedef struct
{
    uint64_t x[5];
} ascon_state_t;

// FILE constants.h
#include <stdint.h>

#define ASCON_128_KEYBYTES 16
#define ASCON_128A_KEYBYTES 16
#define ASCON_80PQ_KEYBYTES 20

#define ASCON_128_RATE 8
#define ASCON_128A_RATE 16
#define ASCON_HASH_RATE 8
#define ASCON_PRF_IN_RATE 32
#define ASCON_PRFA_IN_RATE 40
#define ASCON_PRF_OUT_RATE 16

#define ASCON_128_PA_ROUNDS 12
#define ASCON_128_PB_ROUNDS 6
#define ASCON_128A_PA_ROUNDS 12
#define ASCON_128A_PB_ROUNDS 8

#define ASCON_HASH_PA_ROUNDS 12
#define ASCON_HASH_PB_ROUNDS 12
#define ASCON_HASHA_PA_ROUNDS 12
#define ASCON_HASHA_PB_ROUNDS 8

#define ASCON_PRF_PA_ROUNDS 12
#define ASCON_PRF_PB_ROUNDS 12
#define ASCON_PRFA_PA_ROUNDS 12
#define ASCON_PRFA_PB_ROUNDS 8

#define ASCON_128_IV                              \
    (((uint64_t)(ASCON_128_KEYBYTES * 8) << 56) | \
     ((uint64_t)(ASCON_128_RATE * 8) << 48) |     \
     ((uint64_t)(ASCON_128_PA_ROUNDS) << 40) |    \
     ((uint64_t)(ASCON_128_PB_ROUNDS) << 32))

#define ASCON_128A_IV                              \
    (((uint64_t)(ASCON_128A_KEYBYTES * 8) << 56) | \
     ((uint64_t)(ASCON_128A_RATE * 8) << 48) |     \
     ((uint64_t)(ASCON_128A_PA_ROUNDS) << 40) |    \
     ((uint64_t)(ASCON_128A_PB_ROUNDS) << 32))

#define ASCON_80PQ_IV                              \
    (((uint64_t)(ASCON_80PQ_KEYBYTES * 8) << 56) | \
     ((uint64_t)(ASCON_128_RATE * 8) << 48) |      \
     ((uint64_t)(ASCON_128_PA_ROUNDS) << 40) |     \
     ((uint64_t)(ASCON_128_PB_ROUNDS) << 32))

#define ASCON_HASH_IV                                                  \
    (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |                         \
     ((uint64_t)(ASCON_HASH_PA_ROUNDS) << 40) |                        \
     ((uint64_t)(ASCON_HASH_PA_ROUNDS - ASCON_HASH_PB_ROUNDS) << 32) | \
     ((uint64_t)(ASCON_HASH_BYTES * 8) << 0))

#define ASCON_HASHA_IV                                                   \
    (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |                           \
     ((uint64_t)(ASCON_HASHA_PA_ROUNDS) << 40) |                         \
     ((uint64_t)(ASCON_HASHA_PA_ROUNDS - ASCON_HASHA_PB_ROUNDS) << 32) | \
     ((uint64_t)(ASCON_HASH_BYTES * 8) << 0))

#define ASCON_XOF_IV                            \
    (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |  \
     ((uint64_t)(ASCON_HASH_PA_ROUNDS) << 40) | \
     ((uint64_t)(ASCON_HASH_PA_ROUNDS - ASCON_HASH_PB_ROUNDS) << 32))

#define ASCON_XOFA_IV                            \
    (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |   \
     ((uint64_t)(ASCON_HASHA_PA_ROUNDS) << 40) | \
     ((uint64_t)(ASCON_HASHA_PA_ROUNDS - ASCON_HASHA_PB_ROUNDS) << 32))

#define ASCON_MAC_IV                                                 \
    (((uint64_t)(CRYPTO_KEYBYTES * 8) << 56) |                       \
     ((uint64_t)(ASCON_PRF_OUT_RATE * 8) << 48) |                    \
     ((uint64_t)(0x80 | ASCON_PRF_PA_ROUNDS) << 40) |                \
     ((uint64_t)(ASCON_PRF_PA_ROUNDS - ASCON_PRF_PB_ROUNDS) << 32) | \
     ((uint64_t)(ASCON_PRF_BYTES * 8) << 0))

#define ASCON_MACA_IV                                                  \
    (((uint64_t)(CRYPTO_KEYBYTES * 8) << 56) |                         \
     ((uint64_t)(ASCON_PRF_OUT_RATE * 8) << 48) |                      \
     ((uint64_t)(0x80 | ASCON_PRFA_PA_ROUNDS) << 40) |                 \
     ((uint64_t)(ASCON_PRFA_PA_ROUNDS - ASCON_PRFA_PB_ROUNDS) << 32) | \
     ((uint64_t)(ASCON_PRF_BYTES * 8) << 0))

#define ASCON_PRF_IV                                  \
    (((uint64_t)(CRYPTO_KEYBYTES * 8) << 56) |        \
     ((uint64_t)(ASCON_PRF_OUT_RATE * 8) << 48) |     \
     ((uint64_t)(0x80 | ASCON_PRF_PA_ROUNDS) << 40) | \
     ((uint64_t)(ASCON_PRF_PA_ROUNDS - ASCON_PRF_PB_ROUNDS) << 32))

#define ASCON_PRFA_IV                                  \
    (((uint64_t)(CRYPTO_KEYBYTES * 8) << 56) |         \
     ((uint64_t)(ASCON_PRF_OUT_RATE * 8) << 48) |      \
     ((uint64_t)(0x80 | ASCON_PRFA_PA_ROUNDS) << 40) | \
     ((uint64_t)(ASCON_PRFA_PA_ROUNDS - ASCON_PRFA_PB_ROUNDS) << 32))

#define ASCON_PRFS_IV                                 \
    (((uint64_t)(CRYPTO_KEYBYTES * 8) << 56) |        \
     ((uint64_t)(0x40 | ASCON_PRF_PA_ROUNDS) << 40) | \
     ((uint64_t)(ASCON_PRF_BYTES * 8) << 32))

// FILE permutations.h
static inline void P12(ascon_state_t *s)
{
    ROUND(s, 0xf0);
    ROUND(s, 0xe1);
    ROUND(s, 0xd2);
    ROUND(s, 0xc3);
    ROUND(s, 0xb4);
    ROUND(s, 0xa5);
    ROUND(s, 0x96);
    ROUND(s, 0x87);
    ROUND(s, 0x78);
    ROUND(s, 0x69);
    ROUND(s, 0x5a);
    ROUND(s, 0x4b);
}

static inline void P8(ascon_state_t *s)
{
    ROUND(s, 0xb4);
    ROUND(s, 0xa5);
    ROUND(s, 0x96);
    ROUND(s, 0x87);
    ROUND(s, 0x78);
    ROUND(s, 0x69);
    ROUND(s, 0x5a);
    ROUND(s, 0x4b);
}

static inline void P6(ascon_state_t *s)
{
    ROUND(s, 0x96);
    ROUND(s, 0x87);
    ROUND(s, 0x78);
    ROUND(s, 0x69);
    ROUND(s, 0x5a);
    ROUND(s, 0x4b);
}

// FILE word.h
#include <string.h>

typedef uint64_t uint64_t;

/* get byte from 64-bit Ascon word */
#define GETBYTE(x, i) ((uint8_t)((uint64_t)(x) >> (56 - 8 * (i))))

/* set byte in 64-bit Ascon word */
#define SETBYTE(b, i) ((uint64_t)(b) << (56 - 8 * (i)))

/* set padding byte in 64-bit Ascon word */
#define PAD(i) SETBYTE(0x80, i)

/* load bytes into 64-bit Ascon word */
static inline uint64_t LOADBYTES(const uint8_t *bytes, int n)
{
    int i;
    uint64_t x = 0;
    for (i = 0; i < n; ++i)
        x |= SETBYTE(bytes[i], i);
    return x;
}

/* store bytes from 64-bit Ascon word */
static inline void STOREBYTES(uint8_t *bytes, uint64_t x, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        bytes[i] = GETBYTE(x, i);
}

/* clear bytes in 64-bit Ascon word */
static inline uint64_t CLEARBYTES(uint64_t x, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        x &= ~SETBYTE(0xff, i);
    return x;
}

// FILE round.h
static inline uint64_t ROR(uint64_t x, int n)
{
    return x >> n | x << (-n & 63);
}

static inline void ROUND(ascon_state_t *s, uint8_t C)
{
    ascon_state_t t;
    /* addition of round constant */
    s->x[2] ^= C;
    /* printstate(" round constant", s); */
    /* substitution layer */
    s->x[0] ^= s->x[4];
    s->x[4] ^= s->x[3];
    s->x[2] ^= s->x[1];
    /* start of keccak s-box */
    t.x[0] = s->x[0] ^ (~s->x[1] & s->x[2]);
    t.x[1] = s->x[1] ^ (~s->x[2] & s->x[3]);
    t.x[2] = s->x[2] ^ (~s->x[3] & s->x[4]);
    t.x[3] = s->x[3] ^ (~s->x[4] & s->x[0]);
    t.x[4] = s->x[4] ^ (~s->x[0] & s->x[1]);
    /* end of keccak s-box */
    t.x[1] ^= t.x[0];
    t.x[0] ^= t.x[4];
    t.x[3] ^= t.x[2];
    t.x[2] = ~t.x[2];
    /* printstate(" substitution layer", &t); */
    /* linear diffusion layer */
    s->x[0] = t.x[0] ^ ROR(t.x[0], 19) ^ ROR(t.x[0], 28);
    s->x[1] = t.x[1] ^ ROR(t.x[1], 61) ^ ROR(t.x[1], 39);
    s->x[2] = t.x[2] ^ ROR(t.x[2], 1) ^ ROR(t.x[2], 6);
    s->x[3] = t.x[3] ^ ROR(t.x[3], 10) ^ ROR(t.x[3], 17);
    s->x[4] = t.x[4] ^ ROR(t.x[4], 7) ^ ROR(t.x[4], 41);
}

// FILE hash.c
int crypto_hash(unsigned char *out, const unsigned char *in,
                unsigned long long len)
{
    /* initialize */
    ascon_state_t s;
    s.x[0] = ASCON_HASH_IV;
    s.x[1] = 0;
    s.x[2] = 0;
    s.x[3] = 0;
    s.x[4] = 0;
    P12(&s);

    /* absorb full plaintext blocks */
    while (len >= ASCON_HASH_RATE)
    {
        s.x[0] ^= LOADBYTES(in, 8);
        P12(&s);
        in += ASCON_HASH_RATE;
        len -= ASCON_HASH_RATE;
    }
    /* absorb final plaintext block */
    s.x[0] ^= LOADBYTES(in, len);
    s.x[0] ^= PAD(len);
    P12(&s);

    /* squeeze full output blocks */
    len = CRYPTO_BYTES;
    while (len > ASCON_HASH_RATE)
    {
        STOREBYTES(out, s.x[0], 8);
        P12(&s);
        out += ASCON_HASH_RATE;
        len -= ASCON_HASH_RATE;
    }
    /* squeeze final output block */
    STOREBYTES(out, s.x[0], len);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

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

    // for (unsigned long long i = 0; i < CRYPTO_BYTES; i++) Serial.print(digest[i], HEX);
    // Serial.println();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

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
