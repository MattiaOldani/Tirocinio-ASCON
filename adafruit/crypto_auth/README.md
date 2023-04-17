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
| armv6m          | 17116 byte [6%]   | 17208 byte            | 269              | 0.164s                            | 2404 byte [7%]           | 30364 byte              | 115 e 239                      | 1323 e 2660                    |
| bi32_armv6m     | 17884 byte [6%]   | 17976 byte            | 281              | 0.155s                            | 2404 byte [7%]           | 30364 byte              | 121 e 249                      | 1533 e 3077                    |
| ref             | 32304 byte [12%]  | 32396 byte            | 507              | 0.266s                            | 2404 byte [7%]           | 30364 byte              | 167 e 350                      | 2101 e 4210                    |

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 15924 byte [6%]   | 16016 byte            | 251              | 0.136s                            | 2404 byte [7%]           | 30364 byte              | 62 e 132                       | 64 e 135                       |
| bi32_armv6m     | 17060 byte [6%]   | 17152 byte            | 268              | 0.162s                            | 2404 byte [7%]           | 30364 byte              | 69 e 146                       | 74 e 155                       |
| ref             | 20236 byte [7%]   | 20328 byte            | 318              | 0.188s                            | 2404 byte [7%]           | 30364 byte              | 92 e 193                       | 101 e 208                      |

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Spazio variabili globali | Spazio variabili locali | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------ | ----------------------- | ------------------------------ | ------------------------------ |
| armv6m          | 17116 byte [6%]   | 17208 byte            | 269              | 0.163s                            | 2404 byte [7%]           | 30364 byte              | 115 e 238                      | 2116 e 4238                    |
| bi32_armv6m     | 17884 byte [6%]   | 17976 byte            | 281              | 0.158s                            | 2404 byte [7%]           | 30364 byte              | 121 e 249                      | 2301 e 4598                    |
| ref             | 35816 byte [13%]  | 35908 byte            | 562              | 0.310s                            | 2404 byte [7%]           | 30364 byte              | 168 e 352                      | 3222 e 6454                    |
