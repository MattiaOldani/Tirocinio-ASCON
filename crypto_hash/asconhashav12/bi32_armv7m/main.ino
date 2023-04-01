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
typedef union
{
    uint64_t x[5];
    uint32_t w[5][2];
    uint8_t b[5][8];
} ascon_state_t;

// FILE bendian.h
#define U64BIG(x)                            \
    (((0x00000000000000FFULL & (x)) << 56) | \
     ((0x000000000000FF00ULL & (x)) << 40) | \
     ((0x0000000000FF0000ULL & (x)) << 24) | \
     ((0x00000000FF000000ULL & (x)) << 8) |  \
     ((0x000000FF00000000ULL & (x)) >> 8) |  \
     ((0x0000FF0000000000ULL & (x)) >> 24) | \
     ((0x00FF000000000000ULL & (x)) >> 40) | \
     ((0xFF00000000000000ULL & (x)) >> 56))
#define U32BIG(x)                                             \
    (((0x000000FF & (x)) << 24) | ((0x0000FF00 & (x)) << 8) | \
     ((0x00FF0000 & (x)) >> 8) | ((0xFF000000 & (x)) >> 24))
#define U16BIG(x) (((0x00FF & (x)) << 8) | ((0xFF00 & (x)) >> 8))

// FILE config.h
#define ASCON_INLINE_MODE 1
#define ASCON_INLINE_PERM 1
#define ASCON_UNROLL_LOOPS 1
#define ASCON_INLINE_BI 1
#define ASCON_EXTERN_BI 0

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

#define RC(i) ((uint64_t)constants[i + 1] << 32 | constants[i])

#define START(n) (24 - 2 * (n))
#define INC 2
#define END 24

const uint8_t constants[] = {0xc, 0xc, 0x9, 0xc, 0xc, 0x9, 0x9, 0x9,
                             0x6, 0xc, 0x3, 0xc, 0x6, 0x9, 0x3, 0x9,
                             0xc, 0x6, 0x9, 0x6, 0xc, 0x3, 0x9, 0x3};

// FILE forceinline.h
#define forceinline inline __attribute__((__always_inline__))

// FILE interleave.h
#define TOBI deinterleave32
#define FROMBI interleave32

extern const uint32_t B[3];

forceinline uint32_t deinterleave16(uint32_t x)
{
    uint32_t t;
    t = (x ^ (x >> 1)) & B[0], x ^= t ^ (t << 1);
    t = (x ^ (x >> 2)) & B[1], x ^= t ^ (t << 2);
    t = (x ^ (x >> 4)) & B[2], x ^= t ^ (t << 4);
    t = (x ^ (x >> 8)) & 0xff00, x ^= t ^ (t << 8);
    return x;
}

forceinline uint32_t interleave16(uint32_t x)
{
    uint32_t t;
    t = (x ^ (x >> 8)) & 0xff00, x ^= t ^ (t << 8);
    t = (x ^ (x >> 4)) & B[2], x ^= t ^ (t << 4);
    t = (x ^ (x >> 2)) & B[1], x ^= t ^ (t << 2);
    t = (x ^ (x >> 1)) & B[0], x ^= t ^ (t << 1);
    return x;
}

forceinline uint64_t deinterleave32(uint64_t in)
{
    in = U64BIG(in);
    uint32_t hi = in >> 32;
    uint32_t lo = in;
    uint32_t t0, t1, e, o;
    t0 = deinterleave16(lo);
    t1 = deinterleave16(hi);
    e = (t1 << 16) | (t0 & 0x0000FFFF);
    o = (t1 & 0xFFFF0000) | (t0 >> 16);
    return (uint64_t)o << 32 | e;
}

forceinline uint64_t interleave32(uint64_t in)
{
    uint32_t e = in;
    uint32_t o = in >> 32;
    uint32_t t0, t1, lo, hi;
    t0 = (o << 16) | (e & 0x0000FFFF);
    t1 = (o & 0xFFFF0000) | (e >> 16);
    lo = interleave16(t0);
    hi = interleave16(t1);
    return U64BIG((uint64_t)hi << 32 | lo);
}

const uint32_t B[3] = {0x22222222, 0x0c0c0c0c, 0x00f000f0};

// FILE permutations.h
#define LOADSTATE(s, a, b, c, d, e) \
    do                              \
    {                               \
        a.x = s->x[0];              \
        b.x = s->x[1];              \
        c.x = s->x[2];              \
        d.x = s->x[3];              \
        e.x = s->x[4];              \
    } while (0)

#define STORESTATE(s, a, b, c, d, e) \
    do                               \
    {                                \
        s->x[0] = a.x;               \
        s->x[1] = b.x;               \
        s->x[2] = c.x;               \
        s->x[3] = d.x;               \
        s->x[4] = e.x;               \
    } while (0)

typedef union
{
    uint64_t x;
    uint32_t w[2];
    uint8_t b[8];
} word_t;

#define ROUND5(x0, x1, x2, x3, x4, C)                                           \
    do                                                                          \
    {                                                                           \
        uint32_t tmp0, tmp1, tmp2;                                              \
        /* Based on the round description of Ascon given in the Bachelor's */   \
        /* thesis: "Optimizing Ascon on RISC-V" of Lars Jellema */              \
        /* see https://github.com/Lucus16/ascon-riscv/ */                       \
        __asm__ __volatile__(                                                   \
            "eor %[x2_l], %[x2_l], %[C_e]\n\t"                                  \
            "eor %[tmp0], %[x1_l], %[x2_l]\n\t"                                 \
            "eor %[tmp1], %[x0_l], %[x4_l]\n\t"                                 \
            "eor %[tmp2], %[x3_l], %[x4_l]\n\t"                                 \
            "orn %[x4_l], %[x3_l], %[x4_l]\n\t"                                 \
            "eor %[x4_l], %[x4_l], %[tmp0]\n\t"                                 \
            "eor %[x3_l], %[x3_l], %[x1_l]\n\t"                                 \
            "orr %[x3_l], %[x3_l], %[tmp0]\n\t"                                 \
            "eor %[x3_l], %[x3_l], %[tmp1]\n\t"                                 \
            "eor %[x2_l], %[x2_l], %[tmp1]\n\t"                                 \
            "orr %[x2_l], %[x2_l], %[x1_l]\n\t"                                 \
            "eor %[x2_l], %[x2_l], %[tmp2]\n\t"                                 \
            "bic %[x1_l], %[x1_l], %[tmp1]\n\t"                                 \
            "eor %[x1_l], %[x1_l], %[tmp2]\n\t"                                 \
            "orr %[x0_l], %[x0_l], %[tmp2]\n\t"                                 \
            "eor %[x0_l], %[x0_l], %[tmp0]\n\t"                                 \
            "eor %[x2_h], %[x2_h], %[C_o]\n\t"                                  \
            "eor %[tmp0], %[x1_h], %[x2_h]\n\t"                                 \
            "eor %[tmp1], %[x0_h], %[x4_h]\n\t"                                 \
            "eor %[tmp2], %[x3_h], %[x4_h]\n\t"                                 \
            "orn %[x4_h], %[x3_h], %[x4_h]\n\t"                                 \
            "eor %[x4_h], %[x4_h], %[tmp0]\n\t"                                 \
            "eor %[x3_h], %[x3_h], %[x1_h]\n\t"                                 \
            "orr %[x3_h], %[x3_h], %[tmp0]\n\t"                                 \
            "eor %[x3_h], %[x3_h], %[tmp1]\n\t"                                 \
            "eor %[x2_h], %[x2_h], %[tmp1]\n\t"                                 \
            "orr %[x2_h], %[x2_h], %[x1_h]\n\t"                                 \
            "eor %[x2_h], %[x2_h], %[tmp2]\n\t"                                 \
            "bic %[x1_h], %[x1_h], %[tmp1]\n\t"                                 \
            "eor %[x1_h], %[x1_h], %[tmp2]\n\t"                                 \
            "orr %[x0_h], %[x0_h], %[tmp2]\n\t"                                 \
            "eor %[x0_h], %[x0_h], %[tmp0]\n\t"                                 \
            "eor %[tmp0], %[x2_l], %[x2_h], ror #4\n\t"                         \
            "eor %[tmp1], %[x2_h], %[x2_l], ror #5\n\t"                         \
            "eor %[x2_h], %[x2_h], %[tmp0], ror #10\n\t"                        \
            "eor %[x2_l], %[x2_l], %[tmp1], ror #9\n\t"                         \
            "eor %[tmp0], %[x3_l], %[x3_l], ror #11\n\t"                        \
            "eor %[tmp1], %[x3_h], %[x3_h], ror #11\n\t"                        \
            "eor %[x3_h], %[x3_h], %[tmp0], ror #20\n\t"                        \
            "eor %[x3_l], %[x3_l], %[tmp1], ror #19\n\t"                        \
            "eor %[tmp0], %[x4_l], %[x4_h], ror #2\n\t"                         \
            "eor %[tmp1], %[x4_h], %[x4_l], ror #3\n\t"                         \
            "eor %[x4_h], %[x4_h], %[tmp0], ror #1\n\t"                         \
            "eor %[x4_l], %[x4_l], %[tmp1]\n\t"                                 \
            "eor %[tmp0], %[x0_l], %[x0_h], ror #3\n\t"                         \
            "eor %[tmp1], %[x0_h], %[x0_l], ror #4\n\t"                         \
            "eor %[x0_l], %[x0_l], %[tmp0], ror #5\n\t"                         \
            "eor %[x0_h], %[x0_h], %[tmp1], ror #5\n\t"                         \
            "eor %[tmp0], %[x1_l], %[x1_l], ror #17\n\t"                        \
            "eor %[tmp1], %[x1_h], %[x1_h], ror #17\n\t"                        \
            "eor %[x1_h], %[x1_h], %[tmp0], ror #4\n\t"                         \
            "eor %[x1_l], %[x1_l], %[tmp1], ror #3\n\t"                         \
            : [x0_l] "+r"(x0.w[0]), [x0_h] "+r"(x0.w[1]), [x1_l] "+r"(x1.w[0]), \
              [x1_h] "+r"(x1.w[1]), [x2_l] "+r"(x2.w[0]), [x2_h] "+r"(x2.w[1]), \
              [x3_l] "+r"(x3.w[0]), [x3_h] "+r"(x3.w[1]), [x4_l] "+r"(x4.w[0]), \
              [x4_h] "+r"(x4.w[1]), [tmp0] "=r"(tmp0), [tmp1] "=r"(tmp1),       \
              [tmp2] "=r"(tmp2)                                                 \
            : [C_e] "i"((uint32_t)C), [C_o] "i"((uint32_t)(C >> 32))            \
            :);                                                                 \
    } while (0)

forceinline void P12ROUNDS(ascon_state_t *s)
{
    word_t x0, x1, x2, x3, x4;
    LOADSTATE(s, x0, x1, x2, x3, x4);
    ROUND5(x0, x1, x2, x3, x4, RC0);
    ROUND5(x2, x3, x4, x0, x1, RC1);
    ROUND5(x4, x0, x1, x2, x3, RC2);
    ROUND5(x1, x2, x3, x4, x0, RC3);
    ROUND5(x3, x4, x0, x1, x2, RC4);
    ROUND5(x0, x1, x2, x3, x4, RC5);
    ROUND5(x2, x3, x4, x0, x1, RC6);
    ROUND5(x4, x0, x1, x2, x3, RC7);
    ROUND5(x1, x2, x3, x4, x0, RC8);
    ROUND5(x3, x4, x0, x1, x2, RC9);
    STORESTATE(s, x0, x1, x2, x3, x4);
    ROUND(s, RCa);
    ROUND(s, RCb);
}

forceinline void P8ROUNDS(ascon_state_t *s)
{
    word_t x0, x1, x2, x3, x4;
    LOADSTATE(s, x0, x1, x2, x3, x4);
    ROUND5(x0, x1, x2, x3, x4, RC4);
    ROUND5(x2, x3, x4, x0, x1, RC5);
    ROUND5(x4, x0, x1, x2, x3, RC6);
    ROUND5(x1, x2, x3, x4, x0, RC7);
    ROUND5(x3, x4, x0, x1, x2, RC8);
    STORESTATE(s, x0, x1, x2, x3, x4);
    ROUND(s, RC9);
    ROUND(s, RCa);
    ROUND(s, RCb);
}

forceinline void P6ROUNDS(ascon_state_t *s)
{
    word_t x0, x1, x2, x3, x4;
    LOADSTATE(s, x0, x1, x2, x3, x4);
    ROUND5(x0, x1, x2, x3, x4, RC6);
    ROUND5(x2, x3, x4, x0, x1, RC7);
    ROUND5(x4, x0, x1, x2, x3, RC8);
    ROUND5(x1, x2, x3, x4, x0, RC9);
    ROUND5(x3, x4, x0, x1, x2, RCa);
    STORESTATE(s, x0, x1, x2, x3, x4);
    ROUND(s, RCb);
}

forceinline void P(ascon_state_t *s, int nr)
{
    if (nr == 12)
        P12ROUNDS(s);
    if (nr == 8)
        P8ROUNDS(s);
    if (nr == 6)
        P6ROUNDS(s);
}

// FILE word.h
#include <string.h>

#define U64TOWORD(x) TOBI(x)
#define WORDTOU64(x) FROMBI(x)

forceinline uint32_t ROR32(uint32_t x, int n)
{
    return x >> n | x << (-n & 31);
}

forceinline uint64_t ROR(uint64_t x, int n)
{
    word_t b, a = {.x = x};
    b.w[0] = (n % 2) ? ROR32(a.w[1], (n - 1) / 2) : ROR32(a.w[0], n / 2);
    b.w[1] = (n % 2) ? ROR32(a.w[0], (n + 1) / 2) : ROR32(a.w[1], n / 2);
    return b.x;
}

forceinline uint64_t KEYROT(uint64_t a, uint64_t b)
{
    word_t w, lo2hi = {.x = a}, hi2lo = {.x = b};
    w.w[0] = lo2hi.w[0] << 16 | hi2lo.w[0] >> 16;
    w.w[1] = lo2hi.w[1] << 16 | hi2lo.w[1] >> 16;
    return w.x;
}

forceinline int NOTZERO(uint64_t a, uint64_t b)
{
    uint64_t result = a | b;
    result |= result >> 32;
    result |= result >> 16;
    result |= result >> 8;
    return ((((int)(result & 0xff) - 1) >> 8) & 1) - 1;
}

forceinline uint64_t PAD(int i)
{
    return ((uint64_t)((uint32_t)0x08 << (28 - 4 * i)) << 32);
}

forceinline uint64_t PRFS_MLEN(uint64_t len)
{
    return ((len & 0x01) << 57) | /* 0000x */
           ((len & 0x02) << 25) | /* 000x0 */
           ((len & 0x04) << 56) | /* 00x00 */
           ((len & 0x08) << 24) | /* 0x000 */
           ((len & 0x10) << 55);  /* x0000 */
}

forceinline uint64_t CLEAR(uint64_t w, int n)
{
    /* undefined for n == 0 */
    uint32_t mask = 0xffffffffull >> (4 * n);
    return w & ((uint64_t)mask << 32 | mask);
}

forceinline uint64_t MASK(int n)
{
    /* undefined for n == 0 */
    return ~0ull >> (64 - 8 * n);
}

forceinline uint64_t LOAD(const uint8_t *bytes, int n)
{
    uint64_t x = *(uint64_t *)bytes & MASK(n);
    return U64TOWORD(x);
}

forceinline void STORE(uint8_t *bytes, uint64_t w, int n)
{
    *(uint64_t *)bytes &= ~MASK(n);
    *(uint64_t *)bytes |= WORDTOU64(w);
}

forceinline uint64_t LOADBYTES(const uint8_t *bytes, int n)
{
    uint64_t x = 0;
    memcpy(&x, bytes, n);
    return U64TOWORD(x);
}

forceinline void STOREBYTES(uint8_t *bytes, uint64_t w, int n)
{
    uint64_t x = WORDTOU64(w);
    memcpy(bytes, &x, n);
}

// FILE round.h
forceinline void ROUND_LOOP(ascon_state_t *s, const uint8_t *C,
                            const uint8_t *E)
{
    uint32_t tmp0, tmp1;
    __asm__ __volatile__(
        "rbegin_%=:;\n\t"
        "ldrb %[tmp1], [%[C]], #1\n\t"
        "eor %[x0_l], %[x0_l], %[x4_l]\n\t"
        "eor %[x4_l], %[x4_l], %[x3_l]\n\t"
        "eor %[x2_l], %[x2_l], %[x1_l]\n\t"
        "orn %[tmp0], %[x4_l], %[x0_l]\n\t"
        "eor %[x2_l], %[x2_l], %[tmp1]\n\t"
        "bic %[tmp1], %[x2_l], %[x1_l]\n\t"
        "eor %[x0_l], %[x0_l], %[tmp1]\n\t"
        "orn %[tmp1], %[x3_l], %[x4_l]\n\t"
        "eor %[x2_l], %[x2_l], %[tmp1]\n\t"
        "bic %[tmp1], %[x1_l], %[x0_l]\n\t"
        "eor %[x4_l], %[x4_l], %[tmp1]\n\t"
        "and %[tmp1], %[x3_l], %[x2_l]\n\t"
        "eor %[x1_l], %[x1_l], %[tmp1]\n\t"
        "eor %[x3_l], %[x3_l], %[tmp0]\n\t"
        "ldrb %[tmp1], [%[C]], #1\n\t"
        "eor %[x1_l], %[x1_l], %[x0_l]\n\t"
        "eor %[x3_l], %[x3_l], %[x2_l]\n\t"
        "eor %[x0_l], %[x0_l], %[x4_l]\n\t"
        "eor %[x0_h], %[x0_h], %[x4_h]\n\t"
        "eor %[x4_h], %[x4_h], %[x3_h]\n\t"
        "eor %[x2_h], %[x2_h], %[tmp1]\n\t"
        "eor %[x2_h], %[x2_h], %[x1_h]\n\t"
        "orn %[tmp0], %[x4_h], %[x0_h]\n\t"
        "bic %[tmp1], %[x2_h], %[x1_h]\n\t"
        "eor %[x0_h], %[x0_h], %[tmp1]\n\t"
        "orn %[tmp1], %[x3_h], %[x4_h]\n\t"
        "eor %[x2_h], %[x2_h], %[tmp1]\n\t"
        "bic %[tmp1], %[x1_h], %[x0_h]\n\t"
        "eor %[x4_h], %[x4_h], %[tmp1]\n\t"
        "and %[tmp1], %[x3_h], %[x2_h]\n\t"
        "eor %[x1_h], %[x1_h], %[tmp1]\n\t"
        "eor %[x3_h], %[x3_h], %[tmp0]\n\t"
        "eor %[x1_h], %[x1_h], %[x0_h]\n\t"
        "eor %[x3_h], %[x3_h], %[x2_h]\n\t"
        "eor %[x0_h], %[x0_h], %[x4_h]\n\t"
        "eor %[tmp0], %[x0_l], %[x0_h], ror #4\n\t"
        "eor %[tmp1], %[x0_h], %[x0_l], ror #5\n\t"
        "eor %[x0_h], %[x0_h], %[tmp0], ror #10\n\t"
        "eor %[x0_l], %[x0_l], %[tmp1], ror #9\n\t"
        "eor %[tmp0], %[x1_l], %[x1_l], ror #11\n\t"
        "eor %[tmp1], %[x1_h], %[x1_h], ror #11\n\t"
        "eor %[x1_h], %[x1_h], %[tmp0], ror #20\n\t"
        "eor %[x1_l], %[x1_l], %[tmp1], ror #19\n\t"
        "eor %[tmp0], %[x2_l], %[x2_h], ror #2\n\t"
        "eor %[tmp1], %[x2_h], %[x2_l], ror #3\n\t"
        "eor %[x2_h], %[x2_h], %[tmp0], ror #1\n\t"
        "eor %[x2_l], %[x2_l], %[tmp1]\n\t"
        "eor %[tmp0], %[x3_l], %[x3_h], ror #3\n\t"
        "eor %[tmp1], %[x3_h], %[x3_l], ror #4\n\t"
        "eor %[x3_l], %[x3_l], %[tmp0], ror #5\n\t"
        "eor %[x3_h], %[x3_h], %[tmp1], ror #5\n\t"
        "eor %[tmp0], %[x4_l], %[x4_l], ror #17\n\t"
        "eor %[tmp1], %[x4_h], %[x4_h], ror #17\n\t"
        "eor %[x4_h], %[x4_h], %[tmp0], ror #4\n\t"
        "eor %[x4_l], %[x4_l], %[tmp1], ror #3\n\t"
        "cmp %[C], %[E]\n\t"
        "bne rbegin_%=\n\t"
        :
        [x0_l] "+r"(s->w[0][0]), [x0_h] "+r"(s->w[0][1]), [x1_l] "+r"(s->w[1][0]),
        [x1_h] "+r"(s->w[1][1]), [x2_l] "+r"(s->w[2][0]), [x2_h] "+r"(s->w[2][1]),
        [x3_l] "+r"(s->w[3][0]), [x3_h] "+r"(s->w[3][1]), [x4_l] "+r"(s->w[4][0]),
        [x4_h] "+r"(s->w[4][1]), [C] "+r"(C), [E] "+r"(E), [tmp0] "=r"(tmp0),
        [tmp1] "=r"(tmp1)
        :
        : "cc");
}

forceinline void ROUND(ascon_state_t *s, uint64_t C)
{
    uint32_t tmp0, tmp1;
    __asm__ __volatile__(
        "eor %[x0_l], %[x0_l], %[x4_l]\n\t"
        "eor %[x4_l], %[x4_l], %[x3_l]\n\t"
        "eor %[x2_l], %[x2_l], %[x1_l]\n\t"
        "orn %[tmp0], %[x4_l], %[x0_l]\n\t"
        "eor %[x2_l], %[x2_l], %[C_e]\n\t"
        "bic %[tmp1], %[x2_l], %[x1_l]\n\t"
        "eor %[x0_l], %[x0_l], %[tmp1]\n\t"
        "orn %[tmp1], %[x3_l], %[x4_l]\n\t"
        "eor %[x2_l], %[x2_l], %[tmp1]\n\t"
        "bic %[tmp1], %[x1_l], %[x0_l]\n\t"
        "eor %[x4_l], %[x4_l], %[tmp1]\n\t"
        "and %[tmp1], %[x3_l], %[x2_l]\n\t"
        "eor %[x1_l], %[x1_l], %[tmp1]\n\t"
        "eor %[x3_l], %[x3_l], %[tmp0]\n\t"
        "eor %[x1_l], %[x1_l], %[x0_l]\n\t"
        "eor %[x3_l], %[x3_l], %[x2_l]\n\t"
        "eor %[x0_l], %[x0_l], %[x4_l]\n\t"
        "eor %[x0_h], %[x0_h], %[x4_h]\n\t"
        "eor %[x4_h], %[x4_h], %[x3_h]\n\t"
        "eor %[x2_h], %[x2_h], %[C_o]\n\t"
        "eor %[x2_h], %[x2_h], %[x1_h]\n\t"
        "orn %[tmp0], %[x4_h], %[x0_h]\n\t"
        "bic %[tmp1], %[x2_h], %[x1_h]\n\t"
        "eor %[x0_h], %[x0_h], %[tmp1]\n\t"
        "orn %[tmp1], %[x3_h], %[x4_h]\n\t"
        "eor %[x2_h], %[x2_h], %[tmp1]\n\t"
        "bic %[tmp1], %[x1_h], %[x0_h]\n\t"
        "eor %[x4_h], %[x4_h], %[tmp1]\n\t"
        "and %[tmp1], %[x3_h], %[x2_h]\n\t"
        "eor %[x1_h], %[x1_h], %[tmp1]\n\t"
        "eor %[x3_h], %[x3_h], %[tmp0]\n\t"
        "eor %[x1_h], %[x1_h], %[x0_h]\n\t"
        "eor %[x3_h], %[x3_h], %[x2_h]\n\t"
        "eor %[x0_h], %[x0_h], %[x4_h]\n\t"
        "eor %[tmp0], %[x0_l], %[x0_h], ror #4\n\t"
        "eor %[tmp1], %[x0_h], %[x0_l], ror #5\n\t"
        "eor %[x0_h], %[x0_h], %[tmp0], ror #10\n\t"
        "eor %[x0_l], %[x0_l], %[tmp1], ror #9\n\t"
        "eor %[tmp0], %[x1_l], %[x1_l], ror #11\n\t"
        "eor %[tmp1], %[x1_h], %[x1_h], ror #11\n\t"
        "eor %[x1_h], %[x1_h], %[tmp0], ror #20\n\t"
        "eor %[x1_l], %[x1_l], %[tmp1], ror #19\n\t"
        "eor %[tmp0], %[x2_l], %[x2_h], ror #2\n\t"
        "eor %[tmp1], %[x2_h], %[x2_l], ror #3\n\t"
        "eor %[x2_h], %[x2_h], %[tmp0], ror #1\n\t"
        "eor %[x2_l], %[x2_l], %[tmp1]\n\t"
        "eor %[tmp0], %[x3_l], %[x3_h], ror #3\n\t"
        "eor %[tmp1], %[x3_h], %[x3_l], ror #4\n\t"
        "eor %[x3_l], %[x3_l], %[tmp0], ror #5\n\t"
        "eor %[x3_h], %[x3_h], %[tmp1], ror #5\n\t"
        "eor %[tmp0], %[x4_l], %[x4_l], ror #17\n\t"
        "eor %[tmp1], %[x4_h], %[x4_h], ror #17\n\t"
        "eor %[x4_h], %[x4_h], %[tmp0], ror #4\n\t"
        "eor %[x4_l], %[x4_l], %[tmp1], ror #3\n\t"
        :
        [x0_l] "+r"(s->w[0][0]), [x0_h] "+r"(s->w[0][1]), [x1_l] "+r"(s->w[1][0]),
        [x1_h] "+r"(s->w[1][1]), [x2_l] "+r"(s->w[2][0]), [x2_h] "+r"(s->w[2][1]),
        [x3_l] "+r"(s->w[3][0]), [x3_h] "+r"(s->w[3][1]), [x4_l] "+r"(s->w[4][0]),
        [x4_h] "+r"(s->w[4][1]), [tmp0] "=r"(tmp0), [tmp1] "=r"(tmp1)
        : [C_e] "i"((uint32_t)C), [C_o] "i"((uint32_t)(C >> 32))
        :);
}

forceinline void PROUNDS(ascon_state_t *s, int nr)
{
    ROUND_LOOP(s, constants + START(nr), constants + 24);
}

// FILE hash.c
forceinline void ascon_inithash(ascon_state_t *s)
{
    int i;
    /* initialize */
    const uint64_t iv[5] = {ASCON_HASHA_IV0, ASCON_HASHA_IV1, ASCON_HASHA_IV2,
                            ASCON_HASHA_IV3, ASCON_HASHA_IV4};
    for (i = 0; i < 5; ++i)
        s->x[i] = (iv[i]);
}

forceinline void ascon_absorb(ascon_state_t *s, const uint8_t *in,
                              uint64_t inlen)
{
    /* absorb full plaintext blocks */
    while (inlen >= ASCON_HASH_RATE)
    {
        s->x[0] ^= LOAD(in, 8);
        P(s, ASCON_HASH_ROUNDS);
        in += ASCON_HASH_RATE;
        inlen -= ASCON_HASH_RATE;
    }
    /* absorb final plaintext block */
    s->x[0] ^= LOADBYTES(in, inlen);
    s->x[0] ^= PAD(inlen);
}

forceinline void ascon_squeeze(ascon_state_t *s, uint8_t *out,
                               uint64_t outlen)
{
    /* squeeze full output blocks */
    P(s, 12);
    while (outlen > ASCON_HASH_RATE)
    {
        STORE(out, s->x[0], 8);
        P(s, ASCON_HASH_ROUNDS);
        out += ASCON_HASH_RATE;
        outlen -= ASCON_HASH_RATE;
    }
    /* squeeze final output block */
    STOREBYTES(out, s->x[0], outlen);
}

int crypto_hash(unsigned char *out, const unsigned char *in,
                unsigned long long inlen)
{
    ascon_state_t s;
    ascon_inithash(&s);
    ascon_absorb(&s, in, inlen);
    ascon_squeeze(&s, out, CRYPTO_BYTES);
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
