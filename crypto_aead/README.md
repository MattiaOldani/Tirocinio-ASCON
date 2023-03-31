# Prestazioni

Prestazioni della famiglia **crypto_aead** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_lowsize`
* `armv7m_small`
* `bi32_armv7m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di cifratura
* il secondo valore rappresenta il tempo di esecuzione della fase di decifratura, suddivisa a sua volta in due parti:
  * una decifratura per risalire al plain text
  * una cifratura per verificare la validità del tag

Sempre per quanto riguarda i tempi di esecuzione:
* il **caso migliore** è calcolato usando `mlen = 0` e `adlen = 0`, parametri usati nelle funzioni `crypto_aead_encrypt` e `crypto_aead_decrypt` che diminuiscono il numero di iterazioni necessarie alla terminazione dell'algoritmo
* il **caso peggiore** è calcolato usando `mlen = MAX_MESSAGE_LENGTH` e `adlen = MAX_ASSOCIATED_DATA_LENGTH`, parametri usati nelle funzioni `crypto_aead_encrypt` e `crypto_aead_decrypt` che aumentano il numero di iterazioni necessarie alla terminazione dell'algoritmo

## Ascon80pqv12

## Ascon128abi32v12

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 20756 byte [3%]   | 21936 byte            | 86               | 4.228s                            | 45 e 90                        | 118 e 239                      |
| armv7m_lowsize  | 13108 byte [2%]   | 14288 byte            | 56               | 2.750s                            | 44 e 86                        | 111 e 220                      |
| armv7m_small    | 14332 byte [2%]   | 15512 byte            | 61               | 2.998s                            | 38 e 77                        | 98 e 198                       |
| bi32_armv7m     | 44708 byte [8%]   | 45888 byte            | 180              | 8.833s                            | 39 e 81                        | 105 e 211                      |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| bi32_armv7m     | 35396 byte [6%]   | 36576 byte            | 143              | 7.027s                            | 35 e 70                        | 108 e 209                      |
| ref             | 13692 byte [2%]   | 14872 byte            | 59               | 2.890s                            | 294 e 592                      | 942 e 1893                     |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
| armv7m          | 19668 byte [3%]   | 20848 byte            | 82               | 4.016s                            | 45 e 90                        | 146 e 294                      |
| armv7m_lowsize  | 13076 byte [2%]   | 14256 byte            | 56               | 2.751s                            | 44 e 85                        | 131 e 259                      |
| armv7m_small    | 13948 byte [2%]   | 15128 byte            | 60               | 2.935s                            | 38 e 77                        | 122 e 245                      |
| bi32_armv7m     | 38980 byte [7%]   | 40160 byte            | 157              | 7.719s                            | 38 e 77                        | 123 e 246                      |
| ref             | 13732 byte [2%]   | 14912 byte            | 59               | 2.891s                            | 143 e 293                      | 448 e 906                      |
