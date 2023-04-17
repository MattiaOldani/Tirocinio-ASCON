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
* il **caso migliore** è calcolato usando `dlen = 0`, parametro usato nelle funzioni `crypto_auth` e `crypto_auth_verify` che diminuisce il numero di iterazioni necessarie alla terminazione dell'algoritmo
* il **caso peggiore** è calcolato usando:
  * `dlen = 16` nella famiglia **asconprfs**, parametro usato nelle funzioni `crypto_auth` e `crypto_auth_verify` che aumenta il numero di iterazioni necessarie alla terminazione dell'algoritmo
  * `dlen = MAX_DATA_LENGTH` nelle restanti famiglie, parametro usato nelle funzioni `crypto_auth` e `crypto_auth_verify` che aumenta il numero di iterazioni necessarie alla terminazione dell'algoritmo

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
| armv7m          | 18916 byte [3%]   | 20096 byte            | 79               | 3.868s                            | 44 e 91                        | 459 e 921                      |
| armv7m_small    | 12436 byte [2%]   | 13616 byte            | 54               | 2.641s                            | 38 e 80                        | 393 e 789                      |
| bi32_armv7m     | 23252 byte [4%]   | 24432 byte            | 96               | 4.704s                            | 36 e 76                        | 471 e 946                      |
| ref             | 12620 byte [2%]   | 13800 byte            | 54               | 2.652s                            | 132 e 272                      | 1767 e 3540                    |

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 16196 byte [3%]   | 17376 byte            | 68               | 3.338s                            | 25 e 54                        | 25 e 55                        |
| armv7m_small    | 12548 byte [2%]   | 13728 byte            | 54               | 2.653s                            | 21 e 45                        | 21 e 47                        |
| bi32_armv7m     | 16460 byte [3%]   | 17640 byte            | 69               | 3.389s                            | 24 e 51                        | 26 e 54                        |
| ref             | 12460 byte [2%]   | 13640 byte            | 54               | 2.640s                            | 79 e 162                       | 89 e 185                       |

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 16092 byte [3%]   | 17272 byte            | 68               | 3.330s                            | 44 e 91                        | 725 e 1453                     |
| armv7m_small    | 12444 byte [2%]   | 13624 byte            | 54               | 2.640s                            | 39 e 79                        | 626 e 1255                     |
| bi32_armv7m     | 25404 byte [4%]   | 26584 byte            | 104              | 5.109s                            | 37 e 80                        | 727 e 1462                     |
| ref             | 12556 byte [2%]   | 13736 byte            | 54               | 2.652s                            | 134 e 270                      | 2558 e 5120                    |
