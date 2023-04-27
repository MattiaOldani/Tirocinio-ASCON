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

## Ascon80pqv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 19780 byte [3%]   | 20960 byte            | 82               | 4.022s                            |
| armv7m_lowsize  | 13292 byte [2%]   | 14472 byte            | 57               | 2.801s                            |
| armv7m_small    | 14244 byte [2%]   | 15424 byte            | 61               | 2.996s                            |
| bi32_armv7m     | 39948 byte [7%]   | 41128 byte            | 161              | 7.915s                            |
| ref             | 14020 byte [2%]   | 15200 byte            | 60               | 2.936s                            |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv7m     | 38756 byte [7%]   | 39936 byte            | 156              | 7.666s                            |
| ref             | 14436 byte [2%]   | 15616 byte            | 61               | 2.996s                            |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 20692 byte [3%]   | 21872 byte            | 86               | 4.212s                            |
| armv7m_lowsize  | 13220 byte [2%]   | 14400 byte            | 57               | 2.785s                            |
| armv7m_small    | 14444 byte [2%]   | 15624 byte            | 62               | 3.032s                            |
| bi32_armv7m     | 44964 byte [8%]   | 46144 byte            | 181              | 8.889s                            |
| ref             | 14484 byte [2%]   | 15664 byte            | 62               | 3.041s                            |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv7m     | 35508 byte [6%]   | 36688 byte            | 144              | 7.067s                            |
| ref             | 13812 byte [2%]   | 14992 byte            | 59               | 2.900s                            |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 19668 byte [3%]   | 20848 byte            | 82               | 4.017s                            |
| armv7m_lowsize  | 13188 byte [2%]   | 14368 byte            | 57               | 2.750s                            |
| armv7m_small    | 14052 byte [2%]   | 15232 byte            | 60               | 2.939s                            |
| bi32_armv7m     | 39444 byte [7%]   | 40624 byte            | 159              | 7.815s                            |
| ref             | 13852 byte [2%]   | 15032 byte            | 59               | 2.899s                            |
