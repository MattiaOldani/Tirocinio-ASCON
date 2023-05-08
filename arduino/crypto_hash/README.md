# Prestazioni

Prestazioni della famiglia **crypto_hash** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

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

I **tempi di esecuzione** sono espressi in microsecondi

## Asconhashabi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 19852 byte [3%]   | 21032 byte            | 83               | 4.066s                            |
| bi32_armv7m     | 19140 byte [3%]   | 20320 byte            | 80               | 3.921s                            |
| bi32_lowreg     | 13508 byte [2%]   | 14688 byte            | 58               | 2.843s                            |
| bi32_lowsize    | 12380 byte [2%]   | 13560 byte            | 53               | 2.605s                            |
| ref             | 12380 byte [2%]   | 13560 byte            | 53               | 2.603s                            |

## Asconhashav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 18812 byte [3%]   | 19992 byte            | 79               | 3.871s                            |
| armv7m_lowsize  | 12260 byte [2%]   | 13440 byte            | 53               | 2.593s                            |
| armv7m_small    | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| bi32            | 20444 byte [3%]   | 21624 byte            | 85               | 4.164s                            |
| bi32_armv7m     | 19788 byte [3%]   | 20968 byte            | 82               | 4.028s                            |
| bi32_lowreg     | 14036 byte [2%]   | 15216 byte            | 60               | 2.945s                            |
| bi32_lowsize    | 12668 byte [2%]   | 13848 byte            | 55               | 2.689s                            |
| opt32           | 27084 byte [5%]   | 28264 byte            | 111              | 5.442s                            |
| opt32_lowsize   | 12508 byte [2%]   | 13688 byte            | 54               | 2.640s                            |
| ref             | 12412 byte [2%]   | 13592 byte            | 54               | 2.643s                            |

## Asconhashbi32v12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| bi32            | 16644 byte [3%]   | 17824 byte            | 70               | 3.443s                            |
| bi32_armv7m     | 21156 byte [4%]   | 22336 byte            | 88               | 4.311s                            |
| bi32_lowreg     | 13508 byte [2%]   | 14688 byte            | 58               | 2.837s                            |
| bi32_lowsize    | 12380 byte [2%]   | 12380 byte            | 53               | 2.603s                            |
| ref             | 12292 byte [2%]   | 13472 byte            | 53               | 2.604s                            |

## Asconhashv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 15980 byte [3%]   | 17160 byte            | 68               | 3.330s                            |
| armv7m_lowsize  | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| armv7m_small    | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| bi32            | 17228 byte [3%]   | 18408 byte            | 72               | 3.546s                            |
| bi32_armv7m     | 21756 byte [4%]   | 22936 byte            | 90               | 4.424s                            |
| bi32_lowreg     | 14044 byte [2%]   | 15224 byte            | 60               | 2.935s                            |
| bi32_lowsize    | 12668 byte [2%]   | 13848 byte            | 55               | 2.688s                            |
| opt32           | 32412 byte [6%]   | 33592 byte            | 132              | 6.474s                            |
| opt32_lowsize   | 12508 byte [2%]   | 13688 byte            | 54               | 2.648s                            |
| ref             | 12340 byte [2%]   | 13520 byte            | 53               | 2.606s                            |

## Asconxofav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 18812 byte [3%]   | 19992 byte            | 79               | 3.877s                            |
| armv7m_lowsize  | 12260 byte [2%]   | 13440 byte            | 53               | 2.600s                            |
| armv7m_small    | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| bi32            | 20444 byte [3%]   | 21624 byte            | 85               | 4.172s                            |
| bi32_armv7m     | 19788 byte [3%]   | 20968 byte            | 82               | 4.038s                            |
| bi32_lowreg     | 14036 byte [2%]   | 15216 byte            | 60               | 2.936s                            |
| bi32_lowsize    | 12668 byte [2%]   | 13848 byte            | 55               | 2.689s                            |
| opt32           | 27084 byte [5%]   | 28264 byte            | 111              | 5.442s                            |
| opt32_lowsize   | 12508 byte [2%]   | 13688 byte            | 54               | 2.641s                            |
| ref             | 12404 byte [2%]   | 13584 byte            | 54               | 2.640s                            |

## Asconxofv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- |
| armv7m          | 15980 byte [3%]   | 17160 byte            | 68               | 3.337s                            |
| armv7m_lowsize  | 12260 byte [2%]   | 13440 byte            | 53               | 2.594s                            |
| armv7m_small    | 12260 byte [2%]   | 13440 byte            | 53               | 2.591s                            |
| bi32            | 17228 byte [3%]   | 18408 byte            | 72               | 3.538s                            |
| bi32_armv7m     | 21756 byte [4%]   | 22936 byte            | 90               | 4.429s                            |
| bi32_lowreg     | 14044 byte [2%]   | 15224 byte            | 60               | 2.937s                            |
| bi32_lowsize    | 12668 byte [2%]   | 13848 byte            | 55               | 2.689s                            |
| opt32           | 32412 byte [6%]   | 33592 byte            | 132              | 6.481s                            |
| opt32_lowsize   | 12508 byte [2%]   | 13688 byte            | 54               | 2.648s                            |
| ref             | 12332 byte [2%]   | 13512 byte            | 53               | 2.619s                            |
