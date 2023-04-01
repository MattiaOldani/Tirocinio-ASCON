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
#define ASCON_HASH_ROUNDS 8

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

#define ASCON_128_IV 0x8021000008220000ull
#define ASCON_128A_IV 0x8822000000200000ull
#define ASCON_80PQ_IV 0xc021000008220000ull

#define ASCON_HASH_IV 0x0020000008200010ull
#define ASCON_HASHA_IV 0x0020000008220010ull
#define ASCON_XOF_IV 0x0020000008200000ull
#define ASCON_XOFA_IV 0x0020000008220000ull

#define ASCON_HASH_IV0 0xf9afb5c6a540dbc7ull
#define ASCON_HASH_IV1 0xbd2493011445a340ull
#define ASCON_HASH_IV2 0xcb9ba8b5604d4fc8ull
#define ASCON_HASH_IV3 0x12a4eede94514c98ull
#define ASCON_HASH_IV4 0x4bca84c06339f398ull

#define ASCON_HASHA_IV0 0x0108e46d1b16eb02ull
#define ASCON_HASHA_IV1 0x5b9b8efdd29083f3ull
#define ASCON_HASHA_IV2 0x7ad665622891ae4aull
#define ASCON_HASHA_IV3 0x9dc27156ee3bfc7full
#define ASCON_HASHA_IV4 0xc61d5fa916801633ull

#define ASCON_XOF_IV0 0xc75782817e351ae6ull
#define ASCON_XOF_IV1 0x70045f441d238220ull
#define ASCON_XOF_IV2 0x5dd5ab52a13e3f04ull
#define ASCON_XOF_IV3 0x3e378142c30c1db2ull
#define ASCON_XOF_IV4 0x3735189db624d656ull

#define ASCON_XOFA_IV0 0x0846d7a5a4b87d44ull
#define ASCON_XOFA_IV1 0xaa6f1005b3a2dbf4ull
#define ASCON_XOFA_IV2 0xdc451146f713e811ull
#define ASCON_XOFA_IV3 0x468cb2532839e30dull
#define ASCON_XOFA_IV4 0xeb2d429709e96977ull

#define ASCON_MAC_IV 0x88a0000800200000ull
#define ASCON_MACA_IV 0x88a0000800220000ull
#define ASCON_PRF_IV 0x88a0000000200000ull
#define ASCON_PRFA_IV 0x88a0000000220000ull
#define ASCON_PRFS_IV 0x8028000000a00000ull

#define RC0 0x0000000c0000000cull
#define RC1 0x0000000c00000009ull
#define RC2 0x000000090000000cull
#define RC3 0x0000000900000009ull
#define RC4 0x0000000c00000006ull
#define RC5 0x0000000c00000003ull
#define RC6 0x0000000900000006ull
#define RC7 0x0000000900000003ull
#define RC8 0x000000060000000cull
#define RC9 0x0000000600000009ull
#define RCa 0x000000030000000cull
#define RCb 0x0000000300000009ull

// FILE permutations.h
static inline void P12(ascon_state_t *s)
{
    ROUND(s, RC0);
    ROUND(s, RC1);
    ROUND(s, RC2);
    ROUND(s, RC3);
    ROUND(s, RC4);
    ROUND(s, RC5);
    ROUND(s, RC6);
    ROUND(s, RC7);
    ROUND(s, RC8);
    ROUND(s, RC9);
    ROUND(s, RCa);
    ROUND(s, RCb);
}

static inline void P8(ascon_state_t *s)
{
    ROUND(s, RC4);
    ROUND(s, RC5);
    ROUND(s, RC6);
    ROUND(s, RC7);
    ROUND(s, RC8);
    ROUND(s, RC9);
    ROUND(s, RCa);
    ROUND(s, RCb);
}

static inline void P6(ascon_state_t *s)
{
    ROUND(s, RC6);
    ROUND(s, RC7);
    ROUND(s, RC8);
    ROUND(s, RC9);
    ROUND(s, RCa);
    ROUND(s, RCb);
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
static inline uint32_t ROR32(uint32_t x, int n)
{
    return x >> n | x << (-n & 31);
}

static inline uint64_t ROR(uint64_t x, int n)
{
    uint32_t al = (uint32_t)x;
    uint32_t ah = x >> 32;
    uint32_t bl, bh;
    bl = (n % 2) ? ROR32(ah, (n - 1) / 2) : ROR32(al, n / 2);
    bh = (n % 2) ? ROR32(al, (n + 1) / 2) : ROR32(ah, n / 2);
    return (uint64_t)bh << 32 | bl;
}

static inline void ROUND(ascon_state_t *s, uint64_t C)
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
    s.x[0] = ASCON_HASHA_IV;
    s.x[1] = 0;
    s.x[2] = 0;
    s.x[3] = 0;
    s.x[4] = 0;
    P12(&s);

    /* absorb full plaintext blocks */
    while (len >= ASCON_HASH_RATE)
    {
        s.x[0] ^= LOADBYTES(in, 8);
        P8(&s);
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
        P8(&s);
        out += ASCON_HASH_RATE;
        len -= ASCON_HASH_RATE;
    }
    /* squeeze final output block */
    STOREBYTES(out, s.x[0], len);

    return 0;
}

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
