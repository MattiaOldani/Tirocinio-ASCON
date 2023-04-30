# Prestazioni

Prestazioni della famiglia **crypto_auth** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `bi32_armv6m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di creazione del tag
* il secondo valore rappresenta il tempo di esecuzione della fase di verifica del tag

Gli algoritmi utilizzano  byte [%] dello spazio complessivo per allocare le variabili globali, lasciando  byte per le variabili locali

## Asconmacav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconmacv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconprfav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          |  byte [%]   |  byte            |               | s                            |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]  |  byte            |               | s                            |
