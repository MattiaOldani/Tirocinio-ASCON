# Prestazioni

Prestazioni della famiglia **crypto_hash** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_lowsize`
* `armv7m_small`
* `bi32_armv7m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi

Sempre per quanto riguarda i tempi di esecuzione:
* il **caso migliore** è calcolato usando `mlen = 0`, parametro usato nella funzione `crypto_hash` che diminuisce il numero di iterazioni necessarie alla terminazione dell'algoritmo
* il **caso peggiore** è calcolato usando `mlen = MAX_MESSAGE_LENGTH`, parametro usato nella funzione `crypto_hash`  che aumenta il numero di iterazioni necessarie alla terminazione dell'algoritmo

## Asconhashabi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 18980 byte [3%]   | 20160 byte            | 79               | 3.881s                            | 52                             | 1309                           |
| ref             | 12244 byte [2%]   | 13424 byte            | 53               | 2.592s                            | 513                            | 11707                          |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 18604 byte [3%]   | 19784 byte            | 78               | 3.820s                            | 66                             | 1878                           |
| armv7m_lowsize  | 12124 byte [2%]   | 13304 byte            | 52               | 2.555s                            | 56                             | 1529                           |
| armv7m_small    | 12124 byte [2%]   | 13304 byte            | 52               | 2.555s                            | 55                             | 1529                           |
| bi32_armv7m     | 19620 byte [3%]   | 20800 byte            | 82               | 4.022s                            | 55                             | 1457                           |
| ref             | 12268 byte [2%]   | 13448 byte            | 53               | 2.607s                            | 244                            | 5701                           |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 21004 byte [4%]   | 22184 byte            | 87               | 4.274s                            | 66                             | 1867                           |
| ref             | 12148 byte [2%]   | 13328 byte            | 53               | 2.591s                            | 637                            | 17072                          |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 15772 byte [3%]   | 16952 byte            | 67               | 3.279s                            | 83                             | 2603                           |
| armv7m_lowsize  | 12124 byte [2%]   | 13304 byte            | 52               | 2.553s                            | 69                             | 2161                           |
| armv7m_small    | 12124 byte [2%]   | 13304 byte            | 52               | 2.554s                            | 69                             | 2161                           |
| bi32_armv7m     | 21580 byte [4%]   | 22760 byte            | 89               | 4.370s                            | 70                             | 1970                           |
