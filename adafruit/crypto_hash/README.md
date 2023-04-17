# Prestazioni

Prestazioni della famiglia **crypto_hash** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `armv6m_lowsize`
* `bi32_armv6m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi

Sempre per quanto riguarda i tempi di esecuzione:
* il **caso migliore** è calcolato usando `mlen = 0`, parametro usato nella funzione `crypto_hash` che diminuisce il numero di iterazioni necessarie alla terminazione dell'algoritmo
* il **caso peggiore** è calcolato usando `mlen = MAX_MESSAGE_LENGTH`, parametro usato nella funzione `crypto_hash`  che aumenta il numero di iterazioni necessarie alla terminazione dell'algoritmo

## Asconhashabi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| bi32_armv6m     | 16216 byte [6%]   | 16308 byte            | 255              | 0.134s                            | 2404 byte [7%]           | 30364 byte              | 182                            | 4892                           |
| ref             | 27116 byte [10%]  | 27208 byte            | 426              | 0.244s                            | 2404 byte [7%]           | 30364 byte              | 312                            | 6846                           |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 16192 byte [6%]   | 16284 byte            | 255              | 0.143s                            | 2404 byte [7%]           | 30364 byte              | 185                            | 4980                           |
| armv6m_lowsize  | 15400 byte [5%]   | 15492 byte            | 243              | 0.121s                            | 2404 byte [7%]           | 30364 byte              | 187                            | 5090                           |
| bi32_armv6m     | 16692 byte [6%]   | 16784 byte            | 263              | 0.152s                            | 2404 byte [7%]           | 30364 byte              | 192                            | 5128                           |
| ref             | 31696 byte [12%]  | 31788 byte            | 497              | 0.282s                            | 2404 byte [7%]           | 30364 byte              | 316                            | 7165                           |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| bi32_armv6m     | 16216 byte [6%]   | 16308 byte            | 255              | 0.134s                            | 2404 byte [7%]           | 30364 byte              | 232                            | 7007                           |
| ref             | 27296 byte [10%]  | 27388 byte            | 428              | 0.250s                            | 2404 byte [7%]           | 30364 byte              | 392                            | 10035                          |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| ref             |  byte [%]  |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                         |

## Asconxofav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| ref             |  byte [%]  |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                         |

## Asconxofv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                          |
| ref             |  byte [%]  |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |                          |                         |
