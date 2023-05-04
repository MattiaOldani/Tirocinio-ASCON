# Prestazioni

Prestazioni della famiglia **crypto_auth** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `bi32_armv6m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di creazione del tag
* il secondo valore rappresenta il tempo di esecuzione della fase di verifica del tag

Gli algoritmi utilizzano 2404 byte [7%] dello spazio complessivo per la memoria dinamica, lasciando 30364 byte per le variabili locali

## Asconmacav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 17268 byte [6%]   | 17360 byte            | 272              | 0.136s                            |
| bi32_armv6m     | 18036 byte [6%]   | 18128 byte            | 284              | 0.152s                            |
| ref             | 32496 byte [12%]  | 32588 byte            | 510              | 0.256s                            |

## Asconmacv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 17268 byte [6%]   | 17360 byte            | 272              | 0.146s                            |
| bi32_armv6m     | 18036 byte [6%]   | 18128 byte            | 284              | 0.142s                            |
| ref             | 36008 byte [13%]  | 36100 byte            | 565              | 0.284s                            |

## Asconprfav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 17268 byte [6%]   | 17360 byte            | 272              | 0.140s                            |
| bi32_armv6m     | 18036 byte [6%]   | 18128 byte            | 284              | 0.170s                            |
| ref             | 32456 byte [12%]  | 32548 byte            | 509              | 0.255s                            |

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 15972 byte [6%]   | 16064 byte            | 251              | 0.136s                            |
| bi32_armv6m     | 17108 byte [6%]   | 17200 byte            | 269              | 0.170s                            |
| ref             | 20284 byte [7%]   | 20376 byte            | 319              | 0.199s                            |

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 17268 byte [6%]   | 17360 byte            | 272              | 0.156s                            |
| bi32_armv6m     | 18036 byte [6%]   | 18128 byte            | 284              | 0.168s                            |
| ref             | 35968 byte [13%]  | 36060 byte            | 564              | 0.285s                            |
