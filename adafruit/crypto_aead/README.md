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

Gli algoritmi utilizzano 2404 byte [7%] dello spazio complessivo per la memoria dinamica, lasciando 30364 byte per le variabili locali

## Ascon80pqv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 22048 byte [8%]   | 22140 byte            | 346              | 0.192s                            |
| armv6m_lowsize  | 16864 byte [6%]   | 16956 byte            | 265              | 0.162s                            |
| bi32_armv6m     | 25420 byte [9%]   | 25512 byte            | 399              | 0.226s                            |
| ref             | 53268 byte [20%]  | 53360 byte            | 834              | 0.503s                            |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     | 23116 byte [8%]   | 23208 byte            | 363              | 0.200s                            |
| ref             | 48352 byte [18%]  | 48444 byte            | 757              | 0.448s                            |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 23108 byte [8%]   | 23200 byte            | 363              | 0.210s                            |
| armv6m_lowsize  | 16888 byte [6%]   | 16980 byte            | 266              | 0.179s                            |
| bi32_armv6m     | 27748 byte [10%]  | 27840 byte            | 435              | 0.271s                            |
| ref             | 56412 byte [21%]  | 56504 byte            | 883              | 0.526s                            |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv6m     | 21916 byte [8%]   | 22008 byte            | 344              | 0.198s                            |
| ref             | 39628 byte [15%]  | 39720 byte            | 621              | 0.370s                            |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 21864 byte [8%]   | 21956 byte            | 344              | 0.227s                            |
| armv6m_lowsize  | 16824 byte [6%]   | 16916 byte            | 265              | 0.183s                            |
| bi32_armv6m     | 25076 byte [9%]   | 25168 byte            | 394              | 0.249s                            |
| ref             | 53044 byte [20%]  | 53136 byte            | 831              | 0.484s                            |
