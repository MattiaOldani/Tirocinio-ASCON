# Prestazioni

Prestazioni della famiglia **crypto_aead** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_lowsize`
* `armv7m_small`
* `bi32`
* `bi32_armv7m`
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

## Ascon80pqv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 19780 byte [3%]   | 20960 byte            | 82               | 4.022s                            |
| armv7m_lowsize  | 13292 byte [2%]   | 14472 byte            | 57               | 2.801s                            |
| armv7m_small    | 14244 byte [2%]   | 15424 byte            | 61               | 2.996s                            |
| bi32            | 24844 byte [4%]   | 26024 byte            | 102              | 5.021s                            |
| bi32_armv7m     | 39948 byte [7%]   | 41128 byte            | 161              | 7.915s                            |
| bi32_lowreg     | 19268 byte [3%]   | 20448 byte            | 80               | 3.931s                            |
| bi32_lowsize    | 13748 byte [2%]   | 14928 byte            | 59               | 2.885s                            |
| opt32           | 52964 byte [10%]  | 54144 byte            | 212              | 10.414s                           |
| opt32_lowsize   | 13532 byte [2%]   | 14712 byte            | 58               | 2.847s                            |
| ref             | 14020 byte [2%]   | 15200 byte            | 60               | 2.936s                            |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 21972 byte [4%]   | 23152 byte            | 91               | 4.467s                            |
| bi32_armv7m     | 38756 byte [7%]   | 39936 byte            | 156              | 7.666s                            |
| bi32_lowreg     | 17036 byte [3%]   | 18216 byte            | 72               | 3.533s                            |
| bi32_lowsize    | 13332 byte [2%]   | 14512 byte            | 57               | 2.809s                            |
| ref             | 14436 byte [2%]   | 15616 byte            | 61               | 2.996s                            |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 20692 byte [3%]   | 21872 byte            | 86               | 4.212s                            |
| armv7m_lowsize  | 13220 byte [2%]   | 14400 byte            | 57               | 2.785s                            |
| armv7m_small    | 14444 byte [2%]   | 15624 byte            | 62               | 3.032s                            |
| bi32            | 27252 byte [5%]   | 28432 byte            | 112              | 5.499s                            |
| bi32_armv7m     | 44964 byte [8%]   | 46144 byte            | 181              | 8.889s                            |
| bi32_lowreg     | 20844 byte [3%]   | 22024 byte            | 87               | 4.270s                            |
| bi32_lowsize    | 13644 byte [2%]   | 14824 byte            | 58               | 2.857s                            |
| opt32           | 60812 byte [11%]  | 61992 byte            | 243              | 11.938s                           |
| opt32_lowsize   | 13468 byte [2%]   | 14648 byte            | 58               | 2.842s                            |
| ref             | 14484 byte [2%]   | 15664 byte            | 62               | 3.041s                            |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 20764 byte [3%]   | 21944 byte            | 86               | 4.234s                            |
| bi32_armv7m     | 35508 byte [6%]   | 36688 byte            | 144              | 7.067s                            |
| bi32_lowreg     | 16444 byte [3%]   | 17624 byte            | 69               | 3.389s                            |
| bi32_lowsize    | 13300 byte [2%]   | 14480 byte            | 57               | 2.801s                            |
| ref             | 13812 byte [2%]   | 14992 byte            | 59               | 2.900s                            |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 19668 byte [3%]   | 20848 byte            | 82               | 4.017s                            |
| armv7m_lowsize  | 13188 byte [2%]   | 14368 byte            | 57               | 2.750s                            |
| armv7m_small    | 14052 byte [2%]   | 15232 byte            | 60               | 2.939s                            |
| bi32            | 24300 byte [4%]   | 25480 byte            | 100              | 4.914s                            |
| bi32_armv7m     | 39444 byte [7%]   | 40624 byte            | 159              | 7.815s                            |
| bi32_lowreg     | 18924 byte [3%]   | 20104 byte            | 79               | 3.891s                            |
| bi32_lowsize    | 13604 byte [2%]   | 14784 byte            | 58               | 2.849s                            |
| opt32           | 52620 byte [10%]  | 53800 byte            | 211              | 10.365s                           |
| opt32_lowsize   | 13428 byte [2%]   | 14608 byte            | 58               | 2.845s                            |
| ref             | 13852 byte [2%]   | 15032 byte            | 59               | 2.899s                            |
