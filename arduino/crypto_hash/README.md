# Prestazioni

Prestazioni della famiglia **crypto_hash** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_lowsize`
* `armv7m_small`
* `bi32_armv7m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi

## Asconhashabi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv7m     | 19140 byte [3%]   | 20320 byte            | 80               | 3.921s                            |
| ref             | 12380 byte [2%]   | 13560 byte            | 53               | 2.603s                            |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 18812 byte [3%]   | 19992 byte            | 79               | 3.871s                            |
| armv7m_lowsize  | 12260 byte [2%]   | 13440 byte            | 53               | 2.593s                            |
| armv7m_small    | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| bi32_armv7m     | 19788 byte [3%]   | 20968 byte            | 82               | 4.028s                            |
| ref             | 12412 byte [2%]   | 13592 byte            | 54               | 2.643s                            |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv7m     | 21156 byte [4%]   | 22336 byte            | 88               | 4.311s                            |
| ref             | 12292 byte [2%]   | 13472 byte            | 53               | 2.604s                            |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 15980 byte [3%]   | 17160 byte            | 68               | 3.330s                            |
| armv7m_lowsize  | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| armv7m_small    | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| bi32_armv7m     | 21756 byte [4%]   | 22936 byte            | 90               | 4.424s                            |
| ref             | 12340 byte [2%]   | 13520 byte            | 53               | 2.606s                            |

## Asconxofav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          |  byte [%]   |  byte            |                | s                            |
| armv7m_lowsize  |  byte [%]   |  byte            |                | s                            |
| armv7m_small    |  byte [%]   |  byte            |                | s                            |
| bi32_armv7m     |  byte [%]   |  byte            |                | s                            |
| ref             |  byte [%]   |  byte            |                | s                            |

## Asconxofv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          |  byte [%]   |  byte            |                | s                            |
| armv7m_lowsize  |  byte [%]   |  byte            |                | s                            |
| armv7m_small    |  byte [%]   |  byte            |                | s                            |
| bi32_armv7m     |  byte [%]   |  byte            |                | s                            |
| ref             |  byte [%]   |  byte            |                | s                            |
