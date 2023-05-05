# Prestazioni

Prestazioni della famiglia **crypto_aead** su una board [Adafruit ItsyBitsy M0 Express](https://www.adafruit.com/product/3727)

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
| bi32            | 29168 byte [11%]  | 29260 byte            | 458              | 0.250s                            |
| bi32_armv6m     | 25420 byte [9%]   | 25512 byte            | 399              | 0.226s                            |
| bi32_lowreg     | 23076 byte [8%]   | 23168 byte            | 362              | 0.208s                            |
| bi32_lowsize    | 16700 byte [6%]   | 16792 byte            | 263              | 0.166s                            |
| opt32           | 53160 byte [20%]  | 53252 byte            | 833              | 0.421s                            |
| opt32_lowsize   | 16948 byte [6%]   | 17040 byte            | 267              | 0.182s                            |
| ref             | 53268 byte [20%]  | 53360 byte            | 834              | 0.503s                            |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 27760 byte [10%]  | 27852 byte            | 436              | 0.239s                            |
| bi32_armv6m     | 23116 byte [8%]   | 23208 byte            | 363              | 0.200s                            |
| bi32_lowreg     | 21140 byte [8%]   | 21232 byte            | 332              | 0.189s                            |
| bi32_lowsize    | 16928 byte [6%]   | 17020 byte            | 266              | 0.136s                            |
| ref             | 48352 byte [18%]  | 48444 byte            | 757              | 0.448s                            |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 23108 byte [8%]   | 23200 byte            | 363              | 0.210s                            |
| armv6m_lowsize  | 16888 byte [6%]   | 16980 byte            | 266              | 0.179s                            |
| bi32            | 32132 byte [12%]  | 32224 byte            | 504              | 0.300s                            |
| bi32_armv6m     | 27748 byte [10%]  | 27840 byte            | 435              | 0.271s                            |
| bi32_lowreg     | 24964 byte [9%]   | 25056 byte            | 391              | 0.240s                            |
| bi32_lowsize    | 16600 byte [6%]   | 16692 byte            | 261              | 0.164s                            |
| opt32           | 58872 byte [22%]  | 58964 byte            | 922              | 0.455s                            |
| opt32_lowsize   | 16972 byte [6%]   | 17064 byte            | 267              | 0.170s                            |
| ref             | 56412 byte [21%]  | 56504 byte            | 883              | 0.526s                            |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 25824 byte [9%]   | 25916 byte            | 405              | 0.201s                            |
| bi32_armv6m     | 21916 byte [8%]   | 22008 byte            | 344              | 0.198s                            |
| bi32_lowreg     | 20232 byte [7%]   | 20324 byte            | 318              | 0.155s                            |
| bi32_lowsize    | 16864 byte [6%]   | 16956 byte            | 265              | 0.185s                            |
| ref             | 39628 byte [15%]  | 39720 byte            | 621              | 0.370s                            |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv6m          | 21864 byte [8%]   | 21956 byte            | 344              | 0.227s                            |
| armv6m_lowsize  | 16824 byte [6%]   | 16916 byte            | 265              | 0.183s                            |
| bi32            | 28736 byte [10%]  | 28828 byte            | 451              | 0.369s                            |
| bi32_armv6m     | 25076 byte [9%]   | 25168 byte            | 394              | 0.249s                            |
| bi32_lowreg     | 22880 byte [8%]   | 22972 byte            | 359              | 0.192s                            |
| bi32_lowsize    | 16560 byte [6%]   | 16652 byte            | 261              | 0.159s                            |
| opt32           | 52768 byte [20%]  | 52860 byte            | 826              | 0.425s                            |
| opt32_lowsize   | 16908 byte [6%]   | 17000 byte            | 266              | 0.170s                            |
| ref             | 53044 byte [20%]  | 53136 byte            | 831              | 0.484s                            |
