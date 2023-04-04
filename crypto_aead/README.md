# Prestazioni

Prestazioni della famiglia **crypto_aead** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_lowsize`
* `armv7m_small`
* `bi32_armv7m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di cifratura
* il secondo valore rappresenta il tempo di esecuzione della fase di decifratura, suddivisa a sua volta in due parti:
  * una decifratura per risalire al plain text
  * una cifratura per verificare la validità del tag

Sempre per quanto riguarda i tempi di esecuzione:
* il **caso migliore** è calcolato usando `mlen = 0` e `adlen = 0`, parametri usati nelle funzioni `crypto_aead_encrypt` e `crypto_aead_decrypt` che diminuiscono il numero di iterazioni necessarie alla terminazione dell'algoritmo
* il **caso peggiore** è calcolato usando `mlen = MAX_MESSAGE_LENGTH` e `adlen = MAX_ASSOCIATED_DATA_LENGTH`, parametri usati nelle funzioni `crypto_aead_encrypt` e `crypto_aead_decrypt` che aumentano il numero di iterazioni necessarie alla terminazione dell'algoritmo

## Ascon80pqv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          |  byte [%]   |  byte            | 83               | 4.066s                            | 46 e 92                        | 146 e 295                      |
| armv7m_lowsize  | 13180 byte [2%]   | 14360 byte            | 57               | 2.788s                            | 43 e 89                        | 129 e 264                      |
| armv7m_small    | 14140 byte [2%]   | 15320 byte            | 60               | 2.947s                            | 39 e 79                        | 123 e 248                      |
| bi32_armv7m     | 39908 byte [7%]   | 41088 byte            | 161              | 7.904s                            | 41 e 83                        | 128 e 257                      |
| ref             | 13852 byte [2%]   | 15032 byte            | 59               | 2.899s                            | 146 e 301                      | 451 e 916                      |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 38636 byte [7%]   | 39816 byte            | 156              | 7.680s                            | 35 e 71                        | 88 e 177                       |
| ref             | 14284 byte [2%]   | 15464 byte            | 61               | 2.984s                            | 294 e 592                      | 786 e 1578                     |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 20756 byte [3%]   | 21936 byte            | 86               | 4.228s                            | 45 e 90                        | 118 e 239                      |
| armv7m_lowsize  | 13108 byte [2%]   | 14288 byte            | 56               | 2.750s                            | 44 e 86                        | 111 e 220                      |
| armv7m_small    | 14332 byte [2%]   | 15512 byte            | 61               | 2.998s                            | 38 e 77                        | 98 e 198                       |
| bi32_armv7m     | 44708 byte [8%]   | 45888 byte            | 180              | 8.833s                            | 39 e 81                        | 105 e 211                      |
| ref             | 14332 byte [2%]   | 15512 byte            | 61               | 2.997s                            | 144 e 294                      | 384 e 781                      |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 35396 byte [6%]   | 36576 byte            | 143              | 7.027s                            | 35 e 70                        | 108 e 209                      |
| ref             | 13692 byte [2%]   | 14872 byte            | 59               | 2.890s                            | 294 e 592                      | 942 e 1893                     |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 19572 byte [3%]   | 20752 byte            | 82               | 4.017s                            | 46 e 93                        | 148 e 296                      |
| armv7m_lowsize  | 13084 byte [2%]   | 14264 byte            | 56               | 2.751s                            | 44 e 85                        | 131 e 259                      |
| armv7m_small    | 13948 byte [2%]   | 15128 byte            | 60               | 2.940s                            | 38 e 78                        | 124 e 248                      |
| bi32_armv7m     | 39340 byte [7%]   | 40520 byte            | 159              | 7.801s                            | 39 e 80                        | 129 e 260                      |
| ref             | 13748 byte [2%]   | 14928 byte            | 59               | 2.891s                            | 147 e 302                      | 462 e 935                      |
