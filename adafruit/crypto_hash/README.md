# Prestazioni

Prestazioni della famiglia **crypto_hash** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `armv6m_lowsize`
* `bi32`
* `bi32_armv6m`
* `bi32_lowreg`
* `bi32_lowsize`
* `opt32`
* `opt32_lowsize`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi

Gli algoritmi utilizzano 2404 byte [7%] dello spazio complessivo per la memoria dinamica, lasciando 30364 byte per le variabili locali

## Asconhashabi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 23516 byte [8%]   | 23608 byte            | 369              | 0.186s                            |
| bi32_armv6m     | 16356 byte [6%]   | 16448 byte            | 257              | 0.145s                            |
| bi32_lowreg     | 16412 byte [6%]   | 16504 byte            | 258              | 0.141s                            |
| bi32_lowsize    | 15572 byte [5%]   | 15664 byte            | 245              | 0.141s                            |
| ref             | 27256 byte [10%]  | 27348 byte            | 428              | 0.235s                            |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.153s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.147s                            |
| bi32            | 24016 byte [9%]   | 24108 byte            | 377              | 0.195s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.143s                            |
| bi32_lowreg     | 16896 byte [6%]   | 16988 byte            | 266              | 0.152s                            |
| bi32_lowsize    | 15644 byte [5%]   | 15736 byte            | 246              | 0.124s                            |
| opt32           | 27028 byte [10%]  | 27120 byte            | 424              | 0.218s                            |
| opt32_lowsize   | 15628 byte [5%]   | 15720 byte            | 246              | 0.126s                            |
| ref             | 31836 byte [12%]  | 31928 byte            | 499              | 0.256s                            |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 20188 byte [7%]   | 20280 byte            | 317              | 0.181s                            |
| bi32_armv6m     | 16356 byte [6%]   | 16448 byte            | 257              | 0.148s                            |
| bi32_lowreg     | 16412 byte [6%]   | 16504 byte            | 258              | 0.148s                            |
| bi32_lowsize    | 15572 byte [5%]   | 15664 byte            | 245              | 0.129s                            |
| ref             | 27436 byte [10%]  | 27528 byte            | 431              | 0.239s                            |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.172s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.154s                            |
| bi32            | 20688 byte [7%]   | 20780 byte            | 325              | 0.182s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.163s                            |
| bi32_lowreg     | 16896 byte [6%]   | 16988 byte            | 266              | 0.144s                            |
| bi32_lowsize    | 15644 byte [5%]   | 15736 byte            | 246              | 0.137s                            |
| opt32           | 30500 byte [11%]  | 30592 byte            | 478              | 0.261s                            |
| opt32_lowsize   | 15628 byte [5%]   | 15720 byte            | 246              | 0.128s                            |
| ref             | 35384 byte [13%]  | 35476 byte            | 555              | 0.298s                            |

## Asconxofav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.130s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.147s                            |
| bi32            | 24016 byte [9%]   | 24108 byte            | 377              | 0.212s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.147s                            |
| bi32_lowreg     | 16896 byte [6%]   | 16988 byte            | 266              | 0.137s                            |
| bi32_lowsize    | 15644 byte [5%]   | 15736 byte            | 246              | 0.131s                            |
| opt32           | 27028 byte [10%]  | 27120 byte            | 424              | 0.230s                            |
| opt32_lowsize   | 15628 byte [5%]   | 15720 byte            | 246              | 0.138s                            |
| ref             | 31828 byte [12%]  | 31920 byte            | 499              | 0.263s                            |

## Asconxofv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 16332 byte [6%]   | 16424 byte            | 257              | 0.161s                            |
| armv6m_lowsize  | 15540 byte [5%]   | 15632 byte            | 245              | 0.179s                            |
| bi32            | 20688 byte [7%]   | 20780 byte            | 325              | 0.179s                            |
| bi32_armv6m     | 16832 byte [6%]   | 16924 byte            | 265              | 0.166s                            |
| bi32_lowreg     | 16896 byte [6%]   | 16988 byte            | 266              | 0.144s                            |
| bi32_lowsize    | 15644 byte [5%]   | 15736 byte            | 246              | 0.141s                            |
| opt32           | 30500 byte [11%]  | 30592 byte            | 478              | 0.246s                            |
| opt32_lowsize   | 15628 byte [5%]   | 15720 byte            | 246              | 0.137s                            |
| ref             | 35340 byte [13%]  | 35432 byte            | 554              | 0.286s                            |
