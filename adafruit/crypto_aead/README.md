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
| armv6m          | 21924 byte [8%]   | 22016 byte            | 344              | 0.184s                            | 2404 byte [7%]           | 30364 byte              | 126 e 255                      | 399 e 801                      |
| armv6m_lowsize  | 16740 byte [6%]   | 16832 byte            | 263              | 0.144s                            | 2404 byte [7%]           | 30364 byte              | 135 e 275                      | 412 e 846                      |
| bi32_armv6m     | 25296 byte [9%]   | 25388 byte            | 397              | 0.207s                            | 2404 byte [7%]           | 30364 byte              | 135 e 273                      | 418 e 852                      |
| ref             | 53144 byte [20%]  | 53236 byte            | 832              | 0.406s                            | 2404 byte [7%]           | 30364 byte              | 184 e 364                      | 575 e 1166                     |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| bi32_armv6m     | 23000 byte [8%]   | 23092 byte            | 361              | 0.190s                            | 2404 byte [7%]           | 30364 byte              | 119 e 238                      | 317 e 627                      |
| ref             | 48236 byte [18%]  | 48328 byte            | 756              | 0.378s                            | 2404 byte [7%]           | 30364 byte              | 169 e 388                      | 452 e 963                      |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
| ref             |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
| ref             |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
| ref             |  byte [%]   |  byte            |               | s                            |  byte [%]           |  byte              |  e                       |  e                       |
