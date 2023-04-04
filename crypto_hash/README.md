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
| bi32_armv7m     | 19004 byte [3%]   | 20184 byte            | 79               | 3.889s                            | 51                             | 1309                           |
| ref             | 12252 byte [2%]   | 13432 byte            | 53               | 2.599s                            | 513                            | 11723                          |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 18676 byte [3%]   | 19856 byte            | 78               | 3.831s                            | 69                             | 1883                           |
| armv7m_lowsize  | 12124 byte [2%]   | 13304 byte            | 52               | 2.554s                            | 56                             | 1561                           |
| armv7m_small    | 12124 byte [2%]   | 13304 byte            | 52               | 2.554s                            | 56                             | 1560                           |
| bi32_armv7m     | 19660 byte [3%]   | 20840 byte            | 82               | 4.016s                            | 56                             | 1494                           |
| ref             | 12276 byte [2%]   | 13456 byte            | 53               | 2.599s                            | 244                            | 5692                           |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 21020 byte [4%]   | 22200 byte            | 87               | 4.269s                            | 66                             | 1897                           |
| ref             | 12156 byte [2%]   | 13336 byte            | 53               | 2.591s                            | 638                            | 17145                          |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 15844 byte [3%]   | 17024 byte            | 67               | 3.283s                            | 85                             | 2615                           |
| armv7m_lowsize  | 12124 byte [2%]   | 13304 byte            | 52               | 2.554s                            | 71                             | 2207                           |
| armv7m_small    | 12124 byte [2%]   | 13304 byte            | 52               | 2.554s                            | 71                             | 2207                           |
| bi32_armv7m     | 21628 byte [4%]   | 22808 byte            | 90               | 4.415s                            | 71                             | 2028                           |
| ref             | 12204 byte [2%]   | 13384 byte            | 53               | 2.590s                            | 300                            | 8148                           |

## Asconxofav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 18676 byte [3%]   | 19856 byte            | 78               | 3.832s                            | 69                             | 1882                           |
| armv7m_lowsize  | 12124 byte [2%]   | 13304 byte            | 52               | 2.554s                            | 56                             | 1561                           |
| armv7m_small    | 12124 byte [2%]   | 13304 byte            | 52               | 2.555s                            | 56                             | 1560                           |
| bi32_armv7m     | 19660 byte [3%]   | 20840 byte            | 82               | 4.016s                            | 56                             | 1494                           |
| ref             | 12276 byte [2%]   | 13456 byte            | 53               | 2.603s                            | 243                            | 5725                           |

## Asconxofv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 15772 byte [3%]   | 16952 byte            | 67               | 3.279s                            | 83                             | 2603                           |
| armv7m_lowsize  | 12124 byte [2%]   | 13304 byte            | 52               | 2.554s                            | 70                             | 2161                           |
| armv7m_small    | 12124 byte [2%]   | 13304 byte            | 52               | 2.555s                            | 69                             | 2161                           |
| bi32_armv7m     | 21580 byte [4%]   | 22760 byte            | 89               | 4.374s                            | 69                             | 1970                           |
| ref             | 12188 byte [2%]   | 13368 byte            | 53               | 2.591s                            | 300                            | 8199                           |
