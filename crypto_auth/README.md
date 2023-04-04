# Prestazioni

Prestazioni della famiglia **crypto_auth** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_small`
* `bi32_armv7m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di creazione del tag
* il secondo valore rappresenta il tempo di esecuzione della fase di verifica del tag, suddivisa a sua volta in due parti:
  * una "decifratura" per risalire al plain text
  * una "decifratura" per verificare la validità del tag

Sempre per quanto riguarda i tempi di esecuzione:
* il **caso migliore** è calcolato usando `dlen = 0`, parametri usati nelle funzioni `crypto_auth` e `crypto_auth_verify` che diminuiscono il numero di iterazioni necessarie alla terminazione dell'algoritmo
* il **caso peggiore** è calcolato usando `dlen = MAX_DATA_LENGTH`, parametri usati nelle funzioni `crypto_auth` e `crypto_auth_verify` che aumentano il numero di iterazioni necessarie alla terminazione dell'algoritmo

## Asconmacav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 18916 byte [3%]   | 20096 byte            | 79               | 3.868s                            | 44 e 91                        | 459 e 921                      |
| armv7m_small    | 12436 byte [2%]   | 13616 byte            | 54               | 2.640s                            | 38 e 80                        | 393 e 789                      |
| bi32_armv7m     | 23276 byte [4%]   | 24456 byte            | 96               | 4.717s                            | 37 e 78                        | 484 e 972                      |
| ref             | 12620 byte [2%]   | 13800 byte            | 54               | 2.653s                            | 133 e 271                      | 1768 e 3540                    |

## Asconmacv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 16092 byte [3%]   | 17272 byte            | 68               | 3.328s                            | 45 e 91                        | 724 e 1453                     |
| armv7m_small    | 12444 byte [2%]   | 13624 byte            | 54               | 2.635s                            | 38 e 79                        | 626 e 1255                     |
| bi32_armv7m     | 25428 byte [4%]   | 26608 byte            | 105              | 5.110s                            | 37 e 76                        | 710 e 1425                     |
| ref             | 12556 byte [2%]   | 13736 byte            | 54               | 2.653s                            | 133 e 270                      | 2559 e 5120                    |

## Asconprfav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
