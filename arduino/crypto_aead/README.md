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
| armv7m          |  byte [%]   |  byte            |                | s                            |
| armv7m_lowsize  |  byte [%]   |  byte            |                | s                            |
| armv7m_small    |  byte [%]   |  byte            |                | s                            |
| bi32_armv7m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]   |  byte            |                | s                            |

## Ascon128abi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv7m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]   |  byte            |                | s                            |

## Ascon128av12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          |  byte [%]   |  byte            |                | s                            |
| armv7m_lowsize  |  byte [%]   |  byte            |                | s                            |
| armv7m_small    |  byte [%]   |  byte            |                | s                            |
| bi32_armv7m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]   |  byte            |                | s                            |

## Ascon128bi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32_armv7m     |  byte [%]   |  byte            |               | s                            |
| ref             |  byte [%]   |  byte            |                | s                            |

## Ascon128v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 19668 byte [3%]   | 20848 byte            | 82               | 4.017s                            |
| armv7m_lowsize  | 13188 byte [2%]   | 14368 byte            | 57               | 2.750s                            |
| armv7m_small    | 14052 byte [2%]   | 15232 byte            | 60               | 2.939s                            |
| bi32_armv7m     | 39444 byte [7%]   | 40624 byte            | 159              | 7.815s                            |
| ref             | 13852 byte [2%]   | 15032 byte            | 59               | 2.899s                            |
