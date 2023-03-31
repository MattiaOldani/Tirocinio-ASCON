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
#define ASCON_AEAD_RATE 8

// FILE ascon.h
typedef union
{
  uint64_t x[5];
  uint32_t w[5][2];
  uint8_t b[5][8];
} ascon_state_t;

#define ASCON_KEYWORDS (CRYPTO_KEYBYTES + 7) / 8

typedef union
{
  uint64_t x[ASCON_KEYWORDS];
  uint32_t w[ASCON_KEYWORDS][2];
  uint8_t b[ASCON_KEYWORDS][8];
} ascon_key_t;

void ascon_adata(ascon_state_t *s, const uint8_t *ad, uint64_t adlen);
void ascon_encrypt(ascon_state_t *s, uint8_t *c, const uint8_t *m,
                   uint64_t mlen);
void ascon_decrypt(ascon_state_t *s, uint8_t *m, const uint8_t *c,
                   uint64_t clen);
void ascon_final(ascon_state_t *s, const ascon_key_t *k);

// FILE bendian.h
#define U64BIG(x)                          \
  (((0x00000000000000FFULL & (x)) << 56) | \
   ((0x000000000000FF00ULL & (x)) << 40) | \
   ((0x0000000000FF0000ULL & (x)) << 24) | \
   ((0x00000000FF000000ULL & (x)) << 8) |  \
   ((0x000000FF00000000ULL & (x)) >> 8) |  \
   ((0x0000FF0000000000ULL & (x)) >> 24) | \
   ((0x00FF000000000000ULL & (x)) >> 40) | \
   ((0xFF00000000000000ULL & (x)) >> 56))
#define U32BIG(x)                                           \
  (((0x000000FF & (x)) << 24) | ((0x0000FF00 & (x)) << 8) | \
   ((0x00FF0000 & (x)) >> 8) | ((0xFF000000 & (x)) >> 24))
#define U16BIG(x) (((0x00FF & (x)) << 8) | ((0xFF00 & (x)) >> 8))

// FILE config.h
#define ASCON_INLINE_MODE 0
#define ASCON_INLINE_PERM 0
#define ASCON_UNROLL_LOOPS 1

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

#define ASCON_128_IV 0x80400c0600000000ull
#define ASCON_128A_IV 0x80800c0800000000ull
#define ASCON_80PQ_IV 0xa0400c0600000000ull

#define ASCON_HASH_IV 0x00400c0000000100ull
#define ASCON_HASHA_IV 0x00400c0400000100ull
#define ASCON_XOF_IV 0x00400c0000000000ull
#define ASCON_XOFA_IV 0x00400c0400000000ull

#define ASCON_HASH_IV0 0xee9398aadb67f03dull
#define ASCON_HASH_IV1 0x8bb21831c60f1002ull
#define ASCON_HASH_IV2 0xb48a92db98d5da62ull
#define ASCON_HASH_IV3 0x43189921b8f8e3e8ull
#define ASCON_HASH_IV4 0x348fa5c9d525e140ull

#define ASCON_HASHA_IV0 0x01470194fc6528a6ull
#define ASCON_HASHA_IV1 0x738ec38ac0adffa7ull
#define ASCON_HASHA_IV2 0x2ec8e3296c76384cull
#define ASCON_HASHA_IV3 0xd6f6a54d7f52377dull
#define ASCON_HASHA_IV4 0xa13c42a223be8d87ull

#define ASCON_XOF_IV0 0xb57e273b814cd416ull
#define ASCON_XOF_IV1 0x2b51042562ae2420ull
#define ASCON_XOF_IV2 0x66a3a7768ddf2218ull
#define ASCON_XOF_IV3 0x5aad0a7a8153650cull
#define ASCON_XOF_IV4 0x4f3e0e32539493b6ull

#define ASCON_XOFA_IV0 0x44906568b77b9832ull
#define ASCON_XOFA_IV1 0xcd8d6cae53455532ull
#define ASCON_XOFA_IV2 0xf7b5212756422129ull
#define ASCON_XOFA_IV3 0x246885e1de0d225bull
#define ASCON_XOFA_IV4 0xa8cb5ce33449973full

#define ASCON_MAC_IV 0x80808c0000000080ull
#define ASCON_MACA_IV 0x80808c0400000080ull
#define ASCON_PRF_IV 0x80808c0000000000ull
#define ASCON_PRFA_IV 0x80808c0400000000ull
#define ASCON_PRFS_IV 0x80004c8000000000ull

#define RC0 0xf0
#define RC1 0xe1
#define RC2 0xd2
#define RC3 0xc3
#define RC4 0xb4
#define RC5 0xa5
#define RC6 0x96
#define RC7 0x87
#define RC8 0x78
#define RC9 0x69
#define RCa 0x5a
#define RCb 0x4b

#define RC(i) (i)

#define START(n) ((3 + (n)) << 4 | (12 - (n)))
#define INC -0x0f
#define END 0x3c

// FILE forceinline.h
#define forceinline inline __attribute__((__always_inline__))

// FILE permutations.h
#define LOADSTATE(s, a, b, c, d, e) \
  do                                \
  {                                 \
    a.x = s->x[0];                  \
    b.x = s->x[1];                  \
    c.x = s->x[2];                  \
    d.x = s->x[3];                  \
    e.x = s->x[4];                  \
  } while (0)

#define STORESTATE(s, a, b, c, d, e) \
  do                                 \
  {                                  \
    s->x[0] = a.x;                   \
    s->x[1] = b.x;                   \
    s->x[2] = c.x;                   \
    s->x[3] = d.x;                   \
    s->x[4] = e.x;                   \
  } while (0)

typedef union
{
  uint64_t x;
  uint32_t w[2];
  uint8_t b[8];
} word_t;

#define ROUND5(x0, x1, x2, x3, x4, C)                                       \
  do                                                                        \
  {                                                                         \
    uint32_t tmp0, tmp1, tmp2;                                              \
    /* Based on the round description of Ascon given in the Bachelor's */   \
    /* thesis: "Optimizing Ascon on RISC-V" of Lars Jellema */              \
    /* see https://github_com/Lucus16/ascon-riscv/ */                       \
    __asm__ __volatile__(                                                   \
        "eor %[x2_l], %[x2_l], %[C_l]\n\t"                                  \
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
        "eor %[tmp0], %[x2_l], %[x2_l], lsr #19\n\t"                        \
        "eor %[tmp1], %[x2_h], %[x2_h], lsr #19\n\t"                        \
        "eor %[tmp0], %[tmp0], %[x2_h], lsl #(32-19)\n\t"                   \
        "eor %[tmp1], %[tmp1], %[x2_l], lsl #(32-19)\n\t"                   \
        "eor %[tmp0], %[tmp0], %[x2_h], lsl #(32-28)\n\t"                   \
        "eor %[tmp1], %[tmp1], %[x2_l], lsl #(32-28)\n\t"                   \
        "eor %[x2_l], %[tmp0], %[x2_l], lsr #28\n\t"                        \
        "eor %[x2_h], %[tmp1], %[x2_h], lsr #28\n\t"                        \
        "eor %[tmp0], %[x3_l], %[x3_l], lsl #(64-61)\n\t"                   \
        "eor %[tmp1], %[x3_h], %[x3_h], lsl #(64-61)\n\t"                   \
        "eor %[tmp0], %[tmp0], %[x3_h], lsr #(61-32)\n\t"                   \
        "eor %[tmp1], %[tmp1], %[x3_l], lsr #(61-32)\n\t"                   \
        "eor %[tmp0], %[tmp0], %[x3_h], lsr #(39-32)\n\t"                   \
        "eor %[tmp1], %[tmp1], %[x3_l], lsr #(39-32)\n\t"                   \
        "eor %[x3_l], %[tmp0], %[x3_l], lsl #(64-39)\n\t"                   \
        "eor %[x3_h], %[tmp1], %[x3_h], lsl #(64-39)\n\t"                   \
        "eor %[tmp0], %[x4_l], %[x4_l], lsr #1\n\t"                         \
        "eor %[tmp1], %[x4_h], %[x4_h], lsr #1\n\t"                         \
        "eor %[tmp0], %[tmp0], %[x4_h], lsl #(32-1)\n\t"                    \
        "eor %[tmp1], %[tmp1], %[x4_l], lsl #(32-1)\n\t"                    \
        "eor %[tmp0], %[tmp0], %[x4_h], lsl #(32-6)\n\t"                    \
        "eor %[tmp1], %[tmp1], %[x4_l], lsl #(32-6)\n\t"                    \
        "eor %[x4_l], %[tmp0], %[x4_l], lsr #6\n\t"                         \
        "eor %[x4_h], %[tmp1], %[x4_h], lsr #6\n\t"                         \
        "eor %[tmp0], %[x0_l], %[x0_l], lsr #10\n\t"                        \
        "eor %[tmp1], %[x0_h], %[x0_h], lsr #10\n\t"                        \
        "eor %[tmp0], %[tmp0], %[x0_h], lsl #(32-10)\n\t"                   \
        "eor %[tmp1], %[tmp1], %[x0_l], lsl #(32-10)\n\t"                   \
        "eor %[tmp0], %[tmp0], %[x0_h], lsl #(32-17)\n\t"                   \
        "eor %[tmp1], %[tmp1], %[x0_l], lsl #(32-17)\n\t"                   \
        "eor %[x0_l], %[tmp0], %[x0_l], lsr #17\n\t"                        \
        "eor %[x0_h], %[tmp1], %[x0_h], lsr #17\n\t"                        \
        "eor %[tmp0], %[x1_l], %[x1_l], lsr #7\n\t"                         \
        "eor %[tmp1], %[x1_h], %[x1_h], lsr #7\n\t"                         \
        "eor %[tmp0], %[tmp0], %[x1_h], lsl #(32-7)\n\t"                    \
        "eor %[tmp1], %[tmp1], %[x1_l], lsl #(32-7)\n\t"                    \
        "eor %[tmp0], %[tmp0], %[x1_h], lsr #(41-32)\n\t"                   \
        "eor %[tmp1], %[tmp1], %[x1_l], lsr #(41-32)\n\t"                   \
        "eor %[x1_l], %[tmp0], %[x1_l], lsl #(64-41)\n\t"                   \
        "eor %[x1_h], %[tmp1], %[x1_h], lsl #(64-41)\n\t"                   \
        : [x0_l] "+r"(x0.w[0]), [x0_h] "+r"(x0.w[1]), [x1_l] "+r"(x1.w[0]), \
          [x1_h] "+r"(x1.w[1]), [x2_l] "+r"(x2.w[0]), [x2_h] "+r"(x2.w[1]), \
          [x3_l] "+r"(x3.w[0]), [x3_h] "+r"(x3.w[1]), [x4_l] "+r"(x4.w[0]), \
          [x4_h] "+r"(x4.w[1]), [tmp0] "=r"(tmp0), [tmp1] "=r"(tmp1),       \
          [tmp2] "=r"(tmp2)                                                 \
        : [C_l] "i"((uint32_t)C)                                            \
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
  ROUND5(x0, x1, x2, x3, x4, RCa);
  ROUND5(x2, x3, x4, x0, x1, RCb);
  STORESTATE(s, x4, x0, x1, x2, x3);
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
  ROUND5(x0, x1, x2, x3, x4, RC9);
  ROUND5(x2, x3, x4, x0, x1, RCa);
  ROUND5(x4, x0, x1, x2, x3, RCb);
  STORESTATE(s, x1, x2, x3, x4, x0);
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
  ROUND5(x0, x1, x2, x3, x4, RCb);
  STORESTATE(s, x2, x3, x4, x0, x1);
}

void P12(ascon_state_t *s);
void P8(ascon_state_t *s);
void P6(ascon_state_t *s);

forceinline void P(ascon_state_t *s, int nr)
{
  if (nr == 12)
    P12(s);
  if (nr == 8)
    P8(s);
  if (nr == 6)
    P6(s);
}

void P12(ascon_state_t *s) { P12ROUNDS(s); }
void P6(ascon_state_t *s) { P6ROUNDS(s); }

// FILE word.h
#include <string.h>

#define U64TOWORD(x) U64BIG(x)
#define WORDTOU64(x) U64BIG(x)

forceinline uint64_t ROR(uint64_t x, int n)
{
  return x >> n | x << (-n & 63);
}

forceinline uint64_t KEYROT(uint64_t lo2hi, uint64_t hi2lo)
{
  return lo2hi << 32 | hi2lo >> 32;
}

forceinline int NOTZERO(uint64_t a, uint64_t b)
{
  uint64_t result = a | b;
  result |= result >> 32;
  result |= result >> 16;
  result |= result >> 8;
  return ((((int)(result & 0xff) - 1) >> 8) & 1) - 1;
}

forceinline uint64_t PAD(int i) { return 0x80ull << (56 - 8 * i); }

forceinline uint64_t PRFS_MLEN(uint64_t len) { return len << 51; }

forceinline uint64_t CLEAR(uint64_t w, int n)
{
  /* undefined for n == 0 */
  uint64_t mask = ~0ull >> (8 * n);
  return w & mask;
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
forceinline void ROUND_LOOP(ascon_state_t *s, uint32_t C)
{
  uint32_t tmp0, tmp1;
  __asm__ __volatile__(
      "rbegin_%=:;\n\t"
      "eor %[x2_l], %[x2_l], %[C]\n\t"
      "eor %[x0_l], %[x0_l], %[x4_l]\n\t"
      "eor %[x4_l], %[x4_l], %[x3_l]\n\t"
      "eor %[x2_l], %[x2_l], %[x1_l]\n\t"
      "orn %[tmp0], %[x4_l], %[x0_l]\n\t"
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
      "eor %[tmp0], %[x0_l], %[x0_l], lsr #19\n\t"
      "eor %[tmp1], %[x0_h], %[x0_h], lsr #19\n\t"
      "eor %[tmp0], %[tmp0], %[x0_h], lsl #(32-19)\n\t"
      "eor %[tmp1], %[tmp1], %[x0_l], lsl #(32-19)\n\t"
      "eor %[tmp0], %[tmp0], %[x0_h], lsl #(32-28)\n\t"
      "eor %[tmp1], %[tmp1], %[x0_l], lsl #(32-28)\n\t"
      "eor %[x0_l], %[tmp0], %[x0_l], lsr #28\n\t"
      "eor %[x0_h], %[tmp1], %[x0_h], lsr #28\n\t"
      "eor %[tmp0], %[x1_l], %[x1_l], lsl #(64-61)\n\t"
      "eor %[tmp1], %[x1_h], %[x1_h], lsl #(64-61)\n\t"
      "eor %[tmp0], %[tmp0], %[x1_h], lsr #(61-32)\n\t"
      "eor %[tmp1], %[tmp1], %[x1_l], lsr #(61-32)\n\t"
      "eor %[tmp0], %[tmp0], %[x1_h], lsr #(39-32)\n\t"
      "eor %[tmp1], %[tmp1], %[x1_l], lsr #(39-32)\n\t"
      "eor %[x1_l], %[tmp0], %[x1_l], lsl #(64-39)\n\t"
      "eor %[x1_h], %[tmp1], %[x1_h], lsl #(64-39)\n\t"
      "eor %[tmp0], %[x2_l], %[x2_l], lsr #1\n\t"
      "eor %[tmp1], %[x2_h], %[x2_h], lsr #1\n\t"
      "eor %[tmp0], %[tmp0], %[x2_h], lsl #(32-1)\n\t"
      "eor %[tmp1], %[tmp1], %[x2_l], lsl #(32-1)\n\t"
      "eor %[tmp0], %[tmp0], %[x2_h], lsl #(32-6)\n\t"
      "eor %[tmp1], %[tmp1], %[x2_l], lsl #(32-6)\n\t"
      "eor %[x2_l], %[tmp0], %[x2_l], lsr #6\n\t"
      "eor %[x2_h], %[tmp1], %[x2_h], lsr #6\n\t"
      "eor %[tmp0], %[x3_l], %[x3_l], lsr #10\n\t"
      "eor %[tmp1], %[x3_h], %[x3_h], lsr #10\n\t"
      "eor %[tmp0], %[tmp0], %[x3_h], lsl #(32-10)\n\t"
      "eor %[tmp1], %[tmp1], %[x3_l], lsl #(32-10)\n\t"
      "eor %[tmp0], %[tmp0], %[x3_h], lsl #(32-17)\n\t"
      "eor %[tmp1], %[tmp1], %[x3_l], lsl #(32-17)\n\t"
      "eor %[x3_l], %[tmp0], %[x3_l], lsr #17\n\t"
      "eor %[x3_h], %[tmp1], %[x3_h], lsr #17\n\t"
      "eor %[tmp0], %[x4_l], %[x4_l], lsr #7\n\t"
      "eor %[tmp1], %[x4_h], %[x4_h], lsr #7\n\t"
      "eor %[tmp0], %[tmp0], %[x4_h], lsl #(32-7)\n\t"
      "eor %[tmp1], %[tmp1], %[x4_l], lsl #(32-7)\n\t"
      "eor %[tmp0], %[tmp0], %[x4_h], lsr #(41-32)\n\t"
      "eor %[tmp1], %[tmp1], %[x4_l], lsr #(41-32)\n\t"
      "eor %[x4_l], %[tmp0], %[x4_l], lsl #(64-41)\n\t"
      "eor %[x4_h], %[tmp1], %[x4_h], lsl #(64-41)\n\t"
      "sub %[C], #15\n\t"
      "cmp %[C], #60\n\t"
      "bne rbegin_%=\n\t"
      :
      [x0_l] "+r"(s->w[0][0]), [x0_h] "+r"(s->w[0][1]), [x1_l] "+r"(s->w[1][0]),
      [x1_h] "+r"(s->w[1][1]), [x2_l] "+r"(s->w[2][0]), [x2_h] "+r"(s->w[2][1]),
      [x3_l] "+r"(s->w[3][0]), [x3_h] "+r"(s->w[3][1]), [x4_l] "+r"(s->w[4][0]),
      [x4_h] "+r"(s->w[4][1]), [C] "+r"(C), [tmp0] "=r"(tmp0), [tmp1] "=r"(tmp1)
      :
      :);
}

forceinline void ROUND(ascon_state_t *s, uint32_t C)
{
  uint32_t tmp0, tmp1;
  __asm__ __volatile__(
      "eor %[x0_l], %[x0_l], %[x4_l]\n\t"
      "eor %[x4_l], %[x4_l], %[x3_l]\n\t"
      "eor %[x2_l], %[x2_l], %[x1_l]\n\t"
      "orn %[tmp0], %[x4_l], %[x0_l]\n\t"
      "eor %[x2_l], %[x2_l], %[C_l]\n\t"
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
      "eor %[tmp0], %[x0_l], %[x0_l], lsr #19\n\t"
      "eor %[tmp1], %[x0_h], %[x0_h], lsr #19\n\t"
      "eor %[tmp0], %[tmp0], %[x0_h], lsl #(32-19)\n\t"
      "eor %[tmp1], %[tmp1], %[x0_l], lsl #(32-19)\n\t"
      "eor %[tmp0], %[tmp0], %[x0_h], lsl #(32-28)\n\t"
      "eor %[tmp1], %[tmp1], %[x0_l], lsl #(32-28)\n\t"
      "eor %[x0_l], %[tmp0], %[x0_l], lsr #28\n\t"
      "eor %[x0_h], %[tmp1], %[x0_h], lsr #28\n\t"
      "eor %[tmp0], %[x1_l], %[x1_l], lsl #(64-61)\n\t"
      "eor %[tmp1], %[x1_h], %[x1_h], lsl #(64-61)\n\t"
      "eor %[tmp0], %[tmp0], %[x1_h], lsr #(61-32)\n\t"
      "eor %[tmp1], %[tmp1], %[x1_l], lsr #(61-32)\n\t"
      "eor %[tmp0], %[tmp0], %[x1_h], lsr #(39-32)\n\t"
      "eor %[tmp1], %[tmp1], %[x1_l], lsr #(39-32)\n\t"
      "eor %[x1_l], %[tmp0], %[x1_l], lsl #(64-39)\n\t"
      "eor %[x1_h], %[tmp1], %[x1_h], lsl #(64-39)\n\t"
      "eor %[tmp0], %[x2_l], %[x2_l], lsr #1\n\t"
      "eor %[tmp1], %[x2_h], %[x2_h], lsr #1\n\t"
      "eor %[tmp0], %[tmp0], %[x2_h], lsl #(32-1)\n\t"
      "eor %[tmp1], %[tmp1], %[x2_l], lsl #(32-1)\n\t"
      "eor %[tmp0], %[tmp0], %[x2_h], lsl #(32-6)\n\t"
      "eor %[tmp1], %[tmp1], %[x2_l], lsl #(32-6)\n\t"
      "eor %[x2_l], %[tmp0], %[x2_l], lsr #6\n\t"
      "eor %[x2_h], %[tmp1], %[x2_h], lsr #6\n\t"
      "eor %[tmp0], %[x3_l], %[x3_l], lsr #10\n\t"
      "eor %[tmp1], %[x3_h], %[x3_h], lsr #10\n\t"
      "eor %[tmp0], %[tmp0], %[x3_h], lsl #(32-10)\n\t"
      "eor %[tmp1], %[tmp1], %[x3_l], lsl #(32-10)\n\t"
      "eor %[tmp0], %[tmp0], %[x3_h], lsl #(32-17)\n\t"
      "eor %[tmp1], %[tmp1], %[x3_l], lsl #(32-17)\n\t"
      "eor %[x3_l], %[tmp0], %[x3_l], lsr #17\n\t"
      "eor %[x3_h], %[tmp1], %[x3_h], lsr #17\n\t"
      "eor %[tmp0], %[x4_l], %[x4_l], lsr #7\n\t"
      "eor %[tmp1], %[x4_h], %[x4_h], lsr #7\n\t"
      "eor %[tmp0], %[tmp0], %[x4_h], lsl #(32-7)\n\t"
      "eor %[tmp1], %[tmp1], %[x4_l], lsl #(32-7)\n\t"
      "eor %[tmp0], %[tmp0], %[x4_h], lsr #(41-32)\n\t"
      "eor %[tmp1], %[tmp1], %[x4_l], lsr #(41-32)\n\t"
      "eor %[x4_l], %[tmp0], %[x4_l], lsl #(64-41)\n\t"
      "eor %[x4_h], %[tmp1], %[x4_h], lsl #(64-41)\n\t"
      :
      [x0_l] "+r"(s->w[0][0]), [x0_h] "+r"(s->w[0][1]), [x1_l] "+r"(s->w[1][0]),
      [x1_h] "+r"(s->w[1][1]), [x2_l] "+r"(s->w[2][0]), [x2_h] "+r"(s->w[2][1]),
      [x3_l] "+r"(s->w[3][0]), [x3_h] "+r"(s->w[3][1]), [x4_l] "+r"(s->w[4][0]),
      [x4_h] "+r"(s->w[4][1]), [tmp0] "=r"(tmp0), [tmp1] "=r"(tmp1)
      : [C_l] "i"(C)
      :);
}

forceinline void PROUNDS(ascon_state_t *s, int nr)
{
  ROUND_LOOP(s, START(nr));
}

// FILE aead.c
forceinline void ascon_loadkey(ascon_key_t *key, const uint8_t *k)
{
  key->x[0] = LOAD(k, 8);
  key->x[1] = LOAD(k + 8, 8);
}

forceinline void ascon_initaead(ascon_state_t *s, const ascon_key_t *key,
                                const uint8_t *npub)
{
  if (ASCON_AEAD_RATE == 8)
    s->x[0] = ASCON_128_IV;
  if (ASCON_AEAD_RATE == 16)
    s->x[0] = ASCON_128A_IV;
  s->x[1] = key->x[0];
  s->x[2] = key->x[1];
  s->x[3] = LOAD(npub, 8);
  s->x[4] = LOAD(npub + 8, 8);
  P(s, 12);
  s->x[3] ^= key->x[0];
  s->x[4] ^= key->x[1];
}

forceinline void ascon_adata(ascon_state_t *s, const uint8_t *ad,
                             uint64_t adlen)
{
  const int nr = (ASCON_AEAD_RATE == 8) ? 6 : 8;
  if (adlen)
  {
    /* full associated data blocks */
    while (adlen >= ASCON_AEAD_RATE)
    {
      s->x[0] ^= LOAD(ad, 8);
      if (ASCON_AEAD_RATE == 16)
        s->x[1] ^= LOAD(ad + 8, 8);
      P(s, nr);
      ad += ASCON_AEAD_RATE;
      adlen -= ASCON_AEAD_RATE;
    }
    /* final associated data block */
    uint64_t *px = &s->x[0];
    if (ASCON_AEAD_RATE == 16 && adlen >= 8)
    {
      s->x[0] ^= LOAD(ad, 8);
      px = &s->x[1];
      ad += 8;
      adlen -= 8;
    }
    *px ^= PAD(adlen);
    if (adlen)
      *px ^= LOAD(ad, adlen);
    P(s, nr);
  }
  /* domain separation */
  s->x[4] ^= 1;
}

forceinline void ascon_encrypt(ascon_state_t *s, uint8_t *c, const uint8_t *m,
                               uint64_t mlen)
{
  const int nr = (ASCON_AEAD_RATE == 8) ? 6 : 8;
  /* full plaintext blocks */
  while (mlen >= ASCON_AEAD_RATE)
  {
    s->x[0] ^= LOAD(m, 8);
    STORE(c, s->x[0], 8);
    if (ASCON_AEAD_RATE == 16)
    {
      s->x[1] ^= LOAD(m + 8, 8);
      STORE(c + 8, s->x[1], 8);
    }
    P(s, nr);
    m += ASCON_AEAD_RATE;
    c += ASCON_AEAD_RATE;
    mlen -= ASCON_AEAD_RATE;
  }
  /* final plaintext block */
  uint64_t *px = &s->x[0];
  if (ASCON_AEAD_RATE == 16 && mlen >= 8)
  {
    s->x[0] ^= LOAD(m, 8);
    STORE(c, s->x[0], 8);
    px = &s->x[1];
    m += 8;
    c += 8;
    mlen -= 8;
  }
  *px ^= PAD(mlen);
  if (mlen)
  {
    *px ^= LOAD(m, mlen);
    STORE(c, *px, mlen);
  }
}

forceinline void ascon_decrypt(ascon_state_t *s, uint8_t *m, const uint8_t *c,
                               uint64_t clen)
{
  const int nr = (ASCON_AEAD_RATE == 8) ? 6 : 8;
  /* full ciphertext blocks */
  while (clen >= ASCON_AEAD_RATE)
  {
    uint64_t cx = LOAD(c, 8);
    s->x[0] ^= cx;
    STORE(m, s->x[0], 8);
    s->x[0] = cx;
    if (ASCON_AEAD_RATE == 16)
    {
      cx = LOAD(c + 8, 8);
      s->x[1] ^= cx;
      STORE(m + 8, s->x[1], 8);
      s->x[1] = cx;
    }
    P(s, nr);
    m += ASCON_AEAD_RATE;
    c += ASCON_AEAD_RATE;
    clen -= ASCON_AEAD_RATE;
  }
  /* final ciphertext block */
  uint64_t *px = &s->x[0];
  if (ASCON_AEAD_RATE == 16 && clen >= 8)
  {
    uint64_t cx = LOAD(c, 8);
    s->x[0] ^= cx;
    STORE(m, s->x[0], 8);
    s->x[0] = cx;
    px = &s->x[1];
    m += 8;
    c += 8;
    clen -= 8;
  }
  *px ^= PAD(clen);
  if (clen)
  {
    uint64_t cx = LOAD(c, clen);
    *px ^= cx;
    STORE(m, *px, clen);
    *px = CLEAR(*px, clen);
    *px ^= cx;
  }
}

forceinline void ascon_final(ascon_state_t *s, const ascon_key_t *key)
{
  if (ASCON_AEAD_RATE == 8)
  {
    s->x[1] ^= key->x[0];
    s->x[2] ^= key->x[1];
  }
  else
  {
    s->x[2] ^= key->x[0];
    s->x[3] ^= key->x[1];
  }
  P(s, 12);
  s->x[3] ^= key->x[0];
  s->x[4] ^= key->x[1];
}

int crypto_aead_encrypt(unsigned char *c, unsigned long long *clen,
                        const unsigned char *m, unsigned long long mlen,
                        const unsigned char *ad, unsigned long long adlen,
                        const unsigned char *nsec, const unsigned char *npub,
                        const unsigned char *k)
{
  ascon_state_t s;
  (void)nsec;
  *clen = mlen + CRYPTO_ABYTES;
  /* perform ascon computation */
  ascon_key_t key;
  ascon_loadkey(&key, k);
  ascon_initaead(&s, &key, npub);
  ascon_adata(&s, ad, adlen);
  ascon_encrypt(&s, c, m, mlen);
  ascon_final(&s, &key);
  /* set tag */
  STOREBYTES(c + mlen, s.x[3], 8);
  STOREBYTES(c + mlen + 8, s.x[4], 8);
  return 0;
}

int crypto_aead_decrypt(unsigned char *m, unsigned long long *mlen,
                        unsigned char *nsec, const unsigned char *c,
                        unsigned long long clen, const unsigned char *ad,
                        unsigned long long adlen, const unsigned char *npub,
                        const unsigned char *k)
{
  ascon_state_t s;
  (void)nsec;
  if (clen < CRYPTO_ABYTES)
    return -1;
  *mlen = clen = clen - CRYPTO_ABYTES;
  /* perform ascon computation */
  ascon_key_t key;
  ascon_loadkey(&key, k);
  ascon_initaead(&s, &key, npub);
  ascon_adata(&s, ad, adlen);
  ascon_decrypt(&s, m, c, clen);
  ascon_final(&s, &key);
  /* verify tag (should be constant time, check compiler output) */
  s.x[3] ^= LOADBYTES(c + clen, 8);
  s.x[4] ^= LOADBYTES(c + clen + 8, 8);
  return NOTZERO(s.x[3], s.x[4]);
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
