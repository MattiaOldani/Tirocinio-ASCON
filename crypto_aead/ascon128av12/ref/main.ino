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
#define CRYPTO_KEYBYTES 16
#define CRYPTO_NSECBYTES 0
#define CRYPTO_NPUBBYTES 16
#define CRYPTO_ABYTES 16
#define CRYPTO_NOOVERLAP 1
#define ASCON_AEAD_RATE 16

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

// FILE aead.c
int crypto_aead_encrypt(unsigned char *c, unsigned long long *clen,
                        const unsigned char *m, unsigned long long mlen,
                        const unsigned char *ad, unsigned long long adlen,
                        const unsigned char *nsec, const unsigned char *npub,
                        const unsigned char *k)
{
    (void)nsec;

    /* set ciphertext size */
    *clen = mlen + CRYPTO_ABYTES;

    /* load key and nonce */
    const uint64_t K0 = LOADBYTES(k, 8);
    const uint64_t K1 = LOADBYTES(k + 8, 8);
    const uint64_t N0 = LOADBYTES(npub, 8);
    const uint64_t N1 = LOADBYTES(npub + 8, 8);

    /* initialize */
    ascon_state_t s;
    s.x[0] = ASCON_128A_IV;
    s.x[1] = K0;
    s.x[2] = K1;
    s.x[3] = N0;
    s.x[4] = N1;
    P12(&s);
    s.x[3] ^= K0;
    s.x[4] ^= K1;

    if (adlen)
    {
        /* full associated data blocks */
        while (adlen >= ASCON_128A_RATE)
        {
            s.x[0] ^= LOADBYTES(ad, 8);
            s.x[1] ^= LOADBYTES(ad + 8, 8);
            P8(&s);
            ad += ASCON_128A_RATE;
            adlen -= ASCON_128A_RATE;
        }
        /* final associated data block */
        if (adlen >= 8)
        {
            s.x[0] ^= LOADBYTES(ad, 8);
            s.x[1] ^= LOADBYTES(ad + 8, adlen - 8);
            s.x[1] ^= PAD(adlen - 8);
        }
        else
        {
            s.x[0] ^= LOADBYTES(ad, adlen);
            s.x[0] ^= PAD(adlen);
        }
        P8(&s);
    }
    /* domain separation */
    s.x[4] ^= 1;

    /* full plaintext blocks */
    while (mlen >= ASCON_128A_RATE)
    {
        s.x[0] ^= LOADBYTES(m, 8);
        s.x[1] ^= LOADBYTES(m + 8, 8);
        STOREBYTES(c, s.x[0], 8);
        STOREBYTES(c + 8, s.x[1], 8);
        P8(&s);
        m += ASCON_128A_RATE;
        c += ASCON_128A_RATE;
        mlen -= ASCON_128A_RATE;
    }
    /* final plaintext block */
    if (mlen >= 8)
    {
        s.x[0] ^= LOADBYTES(m, 8);
        s.x[1] ^= LOADBYTES(m + 8, mlen - 8);
        STOREBYTES(c, s.x[0], 8);
        STOREBYTES(c + 8, s.x[1], mlen - 8);
        s.x[1] ^= PAD(mlen - 8);
    }
    else
    {
        s.x[0] ^= LOADBYTES(m, mlen);
        STOREBYTES(c, s.x[0], mlen);
        s.x[0] ^= PAD(mlen);
    }
    c += mlen;

    /* finalize */
    s.x[2] ^= K0;
    s.x[3] ^= K1;
    P12(&s);
    s.x[3] ^= K0;
    s.x[4] ^= K1;

    /* set tag */
    STOREBYTES(c, s.x[3], 8);
    STOREBYTES(c + 8, s.x[4], 8);

    return 0;
}

int crypto_aead_decrypt(unsigned char *m, unsigned long long *mlen,
                        unsigned char *nsec, const unsigned char *c,
                        unsigned long long clen, const unsigned char *ad,
                        unsigned long long adlen, const unsigned char *npub,
                        const unsigned char *k)
{
    (void)nsec;

    if (clen < CRYPTO_ABYTES)
        return -1;

    /* set plaintext size */
    *mlen = clen - CRYPTO_ABYTES;

    /* load key and nonce */
    const uint64_t K0 = LOADBYTES(k, 8);
    const uint64_t K1 = LOADBYTES(k + 8, 8);
    const uint64_t N0 = LOADBYTES(npub, 8);
    const uint64_t N1 = LOADBYTES(npub + 8, 8);

    /* initialize */
    ascon_state_t s;
    s.x[0] = ASCON_128A_IV;
    s.x[1] = K0;
    s.x[2] = K1;
    s.x[3] = N0;
    s.x[4] = N1;
    P12(&s);
    s.x[3] ^= K0;
    s.x[4] ^= K1;

    if (adlen)
    {
        /* full associated data blocks */
        while (adlen >= ASCON_128A_RATE)
        {
            s.x[0] ^= LOADBYTES(ad, 8);
            s.x[1] ^= LOADBYTES(ad + 8, 8);
            P8(&s);
            ad += ASCON_128A_RATE;
            adlen -= ASCON_128A_RATE;
        }
        /* final associated data block */
        if (adlen >= 8)
        {
            s.x[0] ^= LOADBYTES(ad, 8);
            s.x[1] ^= LOADBYTES(ad + 8, adlen - 8);
            s.x[1] ^= PAD(adlen - 8);
        }
        else
        {
            s.x[0] ^= LOADBYTES(ad, adlen);
            s.x[0] ^= PAD(adlen);
        }
        P8(&s);
    }
    /* domain separation */
    s.x[4] ^= 1;

    /* full ciphertext blocks */
    clen -= CRYPTO_ABYTES;
    while (clen >= ASCON_128A_RATE)
    {
        uint64_t c0 = LOADBYTES(c, 8);
        uint64_t c1 = LOADBYTES(c + 8, 8);
        STOREBYTES(m, s.x[0] ^ c0, 8);
        STOREBYTES(m + 8, s.x[1] ^ c1, 8);
        s.x[0] = c0;
        s.x[1] = c1;
        P8(&s);
        m += ASCON_128A_RATE;
        c += ASCON_128A_RATE;
        clen -= ASCON_128A_RATE;
    }
    /* final ciphertext block */
    if (clen >= 8)
    {
        uint64_t c0 = LOADBYTES(c, 8);
        uint64_t c1 = LOADBYTES(c + 8, clen - 8);
        STOREBYTES(m, s.x[0] ^ c0, 8);
        STOREBYTES(m + 8, s.x[1] ^ c1, clen - 8);
        s.x[0] = c0;
        s.x[1] = CLEARBYTES(s.x[1], clen - 8);
        s.x[1] |= c1;
        s.x[1] ^= PAD(clen - 8);
    }
    else
    {
        uint64_t c0 = LOADBYTES(c, clen);
        STOREBYTES(m, s.x[0] ^ c0, clen);
        s.x[0] = CLEARBYTES(s.x[0], clen);
        s.x[0] |= c0;
        s.x[0] ^= PAD(clen);
    }
    c += clen;

    /* finalize */
    s.x[2] ^= K0;
    s.x[3] ^= K1;
    P12(&s);
    s.x[3] ^= K0;
    s.x[4] ^= K1;

    /* set tag */
    uint8_t t[16];
    STOREBYTES(t, s.x[3], 8);
    STOREBYTES(t + 8, s.x[4], 8);

    /* verify tag (should be constant time, check compiler output) */
    int i;
    int result = 0;
    for (i = 0; i < CRYPTO_ABYTES; ++i)
        result |= c[i] ^ t[i];
    result = (((result - 1) >> 8) & 1) - 1;

    return result;
}

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
