# Prestazioni

Prestazioni della famiglia **crypto_hash** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `armv6m_lowsize`
* `bi32_armv6m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi

Gli algoritmi utilizzano 2404 byte [7%] dello spazio complessivo per la memoria dinamica, lasciando 30364 byte per le variabili locali

## Asconhashabi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     | 16356 byte [6%]   | 16448 byte            | 257              | 0.145s                            |
| ref             | 27256 byte [10%]  | 27348 byte            | 428              | 0.235s                            |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.153s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.147s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.143s                            |
| ref             | 31836 byte [12%]  | 31928 byte            | 499              | 0.256s                            |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     | 16356 byte [6%]   | 16448 byte            | 257              | 0.148s                            |
| ref             | 27436 byte [10%]  | 27528 byte            | 431              | 0.239s                            |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.172s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.154s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.163s                            |
| ref             | 35384 byte [13%]  | 35476 byte            | 555              | 0.298s                            |

## Asconxofav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.130s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.147s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.147s                            |
| ref             | 31828 byte [12%]  | 31920 byte            | 499              | 0.263s                            |

## Asconxofv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.161s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.179s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.166s                            |
| ref             | 35340 byte [13%]  | 35432 byte            | 554              | 0.286s                            |
