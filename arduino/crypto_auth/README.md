# Prestazioni

Prestazioni della famiglia **crypto_auth** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_small`
* `bi32_armv7m`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di creazione del tag
* il secondo valore rappresenta il tempo di esecuzione della fase di verifica del tag

## Asconmacav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 19060 byte [3%]   | 20240 byte            | 80               | 3.950s                            | 
| armv7m_small    | 12580 byte [2%]   | 13760 byte            | 54               | 2.652s                            | 
| bi32_armv7m     | 23420 byte [4%]   | 24600 byte            | 97               | 4.762s                            | 
| ref             | 12764 byte [2%]   | 13944 byte            | 55               | 2.689s                            | 

## Asconmacv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 16236 byte [3%]   | 17416 byte            | 69               | 3.378s                            | 
| armv7m_small    | 12588 byte [2%]   | 13768 byte            | 54               | 2.652s                            | 
| bi32_armv7m     | 25572 byte [4%]   | 26752 byte            | 105              | 5.147s                            | 
| ref             | 12700 byte [2%]   | 13880 byte            | 55               | 2.690s                            | 

## Asconprfav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 19060 byte [3%]   | 20240 byte            | 80               | 3.927s                            | 
| armv7m_small    | 12580 byte [2%]   | 13760 byte            | 54               | 2.653s                            | 
| bi32_armv7m     | 23396 byte [4%]   | 24576 byte            | 96               | 4.716s                            | 
| ref             | 12764 byte [2%]   | 13944 byte            | 55               | 2.689s                            | 

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          |  byte [%]   |  byte            |                | s                            | 
| armv7m_small    |  byte [%]   |  byte            |                | s                            | 
| bi32_armv7m     |  byte [%]   |  byte            |                | s                            | 
| ref             |  byte [%]   |  byte            |                | s                            | 

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 16236 byte [3%]   | 17416 byte            | 69               | 3.383s                            | 
| armv7m_small    | 12588 byte [2%]   | 13768 byte            | 54               | 2.652s                            | 
| bi32_armv7m     | 25548 byte [4%]   | 26728 byte            | 105              | 5.155s                            | 
| ref             | 12700 byte [2%]   | 13880 byte            | 55               | 2.696s                            | 
