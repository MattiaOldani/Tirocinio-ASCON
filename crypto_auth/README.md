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

## Asconmacv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |

## Asconprfav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine | Tempo di esecuzione (migliore) | Tempo di esecuzione (peggiore) |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | ------------------------------ | ------------------------------ |
