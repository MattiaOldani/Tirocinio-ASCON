# Prestazioni

Prestazioni della famiglia **crypto_aead** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `armv6m_lowsize`
* `bi32_armv6m`
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

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 21932 byte [8%]   | 22024 byte            | 345              | 0.184s                            | 2404 byte [7%]           | 30364 byte              | 126 e 255                      | 399 e 801                      |
| armv6m_lowsize  | 16748 byte [6%]   | 16840 byte            | 264              | 0.144s                            | 2404 byte [7%]           | 30364 byte              | 135 e 275                      | 412 e 846                      |
| bi32_armv6m     | 25304 byte [9%]   | 25396 byte            | 397              | 0.207s                            | 2404 byte [7%]           | 30364 byte              | 135 e 273                      | 418 e 852                      |
| ref             | 53152 byte [20%]  | 53244 byte            | 832              | 0.406s                            | 2404 byte [7%]           | 30364 byte              | 184 e 364                      | 575 e 1166                     |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| bi32_armv6m     | 23000 byte [8%]   | 23092 byte            | 361              | 0.190s                            | 2404 byte [7%]           | 30364 byte              | 119 e 238                      | 317 e 627                      |
| ref             | 48236 byte [18%]  | 48328 byte            | 756              | 0.378s                            | 2404 byte [7%]           | 30364 byte              | 169 e 388                      | 452 e 963                      |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 22992 byte [8%]   | 23084 byte            | 361              | 0.187s                            | 2404 byte [7%]           | 30364 byte              | 129 e 245                      | 317 e 648                      |
| armv6m_lowsize  | 16772 byte [6%]   | 16864 byte            | 264              | 0.134s                            | 2404 byte [7%]           | 30364 byte              | 136 e 264                      | 343 e 705                      |
| bi32_armv6m     | 27632 byte [10%]  | 27724 byte            | 434              | 0.233s                            | 2404 byte [7%]           | 30364 byte              | 129 e 260                      | 339 e 698                      |
| ref             | 53152 byte [20%]  | 53244 byte            | 832              | 0.459s                            | 2404 byte [7%]           | 30364 byte              | 177 e 365                      | 574 e 1165                     |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| bi32_armv6m     | 21800 byte [8%]   | 21892 byte            | 343              | 0.194s                            | 2404 byte [7%]           | 30364 byte              | 125 e 236                      | 379 e 774                      |
| ref             | 48236 byte [18%]  | 48328 byte            | 756              | 0.390s                            | 2404 byte [7%]           | 30364 byte              | 170 e 388                      | 452 e 963                      |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 21748 byte [8%]   | 21840 byte            | 342              | 0.212s                            | 2404 byte [7%]           | 30364 byte              | 120 e 241                      | 384 e 788                      |
| armv6m_lowsize  | 16708 byte [6%]   | 16800 byte            | 263              | 0.140s                            | 2404 byte [7%]           | 30364 byte              | 136 e 263                      | 407 e 834                      |
| bi32_armv6m     | 24960 byte [9%]   | 25052 byte            | 392              | 0.211s                            | 2404 byte [7%]           | 30364 byte              | 127 e 257                      | 409 e 837                      |
| ref             | 53152 byte [20%]  | 53244 byte            | 832              | 0.428s                            | 2404 byte [7%]           | 30364 byte              | 177 e 373                      | 567 e 1172                     |
