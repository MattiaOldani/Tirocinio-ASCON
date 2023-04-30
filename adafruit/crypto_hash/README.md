# Prestazioni

Prestazioni della famiglia **crypto_hash** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `armv6m_lowsize`
* `bi32_armv6m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi

Gli algoritmi utilizzano  byte [%] dello spazio complessivo per allocare le variabili globali, lasciando  byte per le variabili locali

## Asconhashabi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconxofav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconxofv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |
