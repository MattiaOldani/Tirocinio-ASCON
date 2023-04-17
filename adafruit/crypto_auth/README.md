# Prestazioni

Prestazioni della famiglia **crypto_auth** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

Vengono testate le seguenti **implementazioni**:
* `armv6m`
* `bi32_armv6m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di creazione del tag
* il secondo valore rappresenta il tempo di esecuzione della fase di verifica del tag, suddivisa a sua volta in due parti:
  * una "decifratura" per risalire al plain text
  * una "decifratura" per verificare la validità del tag

Sempre per quanto riguarda i tempi di esecuzione:
* il **caso migliore** è calcolato usando `dlen = 0`, parametro usato nelle funzioni `crypto_auth` e `crypto_auth_verify` che diminuisce il numero di iterazioni necessarie alla terminazione dell'algoritmo
* il **caso peggiore** è calcolato usando:
  * `dlen = 16` nella famiglia **asconprfs**, parametro usato nelle funzioni `crypto_auth` e `crypto_auth_verify` che aumenta il numero di iterazioni necessarie alla terminazione dell'algoritmo
  * `dlen = MAX_DATA_LENGTH` nelle restanti famiglie, parametro usato nelle funzioni `crypto_auth` e `crypto_auth_verify` che aumenta il numero di iterazioni necessarie alla terminazione dell'algoritmo

## Asconmacav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 17116 byte [6%]   | 17208 byte            | 269              | 0.168s                            | 2404 byte [7%]           | 30364 byte              | 116 e 239                      | 1323 e 2659                    |
| bi32_armv6m     | 17884 byte [6%]   | 17976 byte            | 281              | 0.174s                            | 2404 byte [7%]           | 30364 byte              | 120 e 256                      | 1540 e 3077                    |
| ref             | 32344 byte [12%]  | 32436 byte            | 507              | 0.257s                            | 2404 byte [7%]           | 30364 byte              | 167 e 351                      | 2102 e 4219                    |

## Asconmacv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 17116 byte [6%]   | 17208 byte            | 269              | 0.148s                            | 2404 byte [7%]           | 30364 byte              | 116 e 238                      | 2116 e 4240                    |
| bi32_armv6m     | 17884 byte [6%]   | 17976 byte            | 281              | 0.180s                            | 2404 byte [7%]           | 30364 byte              | 120 e 249                      | 2303 e 4598                    |
| ref             | 35856 byte [13%]  | 35948 byte            | 562              | 0.299s                            | 2404 byte [7%]           | 30364 byte              | 169 e 345                      | 3227 e 6461                    |

## Asconprfav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                       |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                       |
| ref             |  byte [%]  |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                      |

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                       |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                       |
| ref             |  byte [%]  |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                      |

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                       |
| bi32_armv6m     |  byte [%]   |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                       |
| ref             |  byte [%]  |  byte            |               | s                            | 2404 byte [7%]           | 30364 byte              |  e                       |  e                      |
