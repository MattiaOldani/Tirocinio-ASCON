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
| armv7m          | 19676 byte [3%]   | 20856 byte            | 82               | 4.025s                            | 47 e 96                        | 149 e 298                      |
| armv7m_lowsize  | 13188 byte [2%]   | 14368 byte            | 57               | 2.784s                            | 44 e 90                        | 131 e 267                      |
| armv7m_small    | 14140 byte [2%]   | 15320 byte            | 60               | 2.949s                            | 40 e 81                        | 125 e 250                      |
| bi32_armv7m     | 39844 byte [7%]   | 41024 byte            | 161              | 7.900s                            | 41 e 83                        | 128 e 261                      |
| ref             | 13916 byte [2%]   | 15096 byte            | 59               | 2.906s                            | 149 e 305                      | 465 e 934                      |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 38644 byte [7%]   | 39824 byte            | 156              | 7.668s                            | 35 e 71                        | 88 e 178                       |
| ref             | 14324 byte [2%]   | 15504 byte            | 61               | 2.996s                            | 295 e 595                      | 791 e 1588                     |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 20580 byte [3%]   | 21760 byte            | 85               | 4.176s                            | 47 e 95                        | 120 e 243                      |
| armv7m_lowsize  | 13116 byte [2%]   | 14296 byte            | 56               | 2.751s                            | 44 e 86                        | 111 e 219                      |
| armv7m_small    | 14332 byte [2%]   | 15512 byte            | 61               | 2.997s                            | 38 e 79                        | 101 e 203                      |
| bi32_armv7m     | 44860 byte [8%]   | 46040 byte            | 180              | 8.846s                            | 41 e 83                        | 108 e 216                      |
| ref             | 14372 byte [2%]   | 15552 byte            | 61               | 2.996s                            | 147 e 299                      | 395 e 799                      |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 35404 byte [6%]   | 36584 byte            | 143              | 7.027s                            | 34 e 70                        | 108 e 218                      |
| ref             | 13708 byte [2%]   | 14888 byte            | 59               | 2.885s                            | 294 e 594                      | 942 e 1891                     |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 19572 byte [3%]   | 20752 byte            | 82               | 4.017s                            | 46 e 93                        | 148 e 296                      |
| armv7m_lowsize  | 13084 byte [2%]   | 14264 byte            | 56               | 2.751s                            | 44 e 85                        | 131 e 259                      |
| armv7m_small    | 13948 byte [2%]   | 15128 byte            | 60               | 2.940s                            | 38 e 78                        | 124 e 248                      |
| bi32_armv7m     | 39340 byte [7%]   | 40520 byte            | 159              | 7.801s                            | 39 e 80                        | 129 e 260                      |
| ref             | 13748 byte [2%]   | 14928 byte            | 59               | 2.891s                            | 147 e 302                      | 462 e 935                      |
