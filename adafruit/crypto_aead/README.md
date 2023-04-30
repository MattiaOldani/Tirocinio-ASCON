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

Gli algoritmi utilizzano  byte [%] dello spazio complessivo per allocare le variabili globali, lasciando  byte per le variabili locali

## Ascon80pqv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| armv6m_lowsize  |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |
