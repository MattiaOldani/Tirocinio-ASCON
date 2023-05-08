# Prestazioni

Prestazioni della famiglia **crypto_auth** su una board [Arduino Due](https://docs.arduino.cc/hardware/due)

Vengono testate le seguenti **implementazioni**:
* `armv7m`
* `armv7m_small`
* `bi32`
* `bi32_armv7m`
* `bi32_lowreg`
* `opt32`
* `ref`

I **tempi di esecuzione** sono espressi in microsecondi e sono formati da due valori:
* il primo valore rappresenta il tempo di esecuzione della fase di creazione del tag
* il secondo valore rappresenta il tempo di esecuzione della fase di verifica del tag

## Asconmacav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 19060 byte [3%]   | 20240 byte            | 80               | 3.950s                            | 
| armv7m_small    | 12580 byte [2%]   | 13760 byte            | 54               | 2.652s                            | 
| bi32            | 21276 byte [4%]   | 22456 byte            | 88               | 4.330s                            | 
| bi32_armv7m     | 23420 byte [4%]   | 24600 byte            | 97               | 4.762s                            | 
| bi32_lowreg     | 15348 byte [2%]   | 16528 byte            | 65               | 3.193s                            | 
| opt32           | 32212 byte [6%]   | 33392 byte            | 131              | 6.431s                            | 
| ref             | 12764 byte [2%]   | 13944 byte            | 55               | 2.689s                            | 

## Asconmacv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 16236 byte [3%]   | 17416 byte            | 69               | 3.378s                            | 
| armv7m_small    | 12588 byte [2%]   | 13768 byte            | 54               | 2.652s                            | 
| bi32            | 18068 byte [3%]   | 19248 byte            | 76               | 3.722s                            | 
| bi32_armv7m     | 25572 byte [4%]   | 26752 byte            | 105              | 5.147s                            | 
| bi32_lowreg     | 15340 byte [2%]   | 16520 byte            | 65               | 3.193s                            | 
| opt32           | 37556 byte [7%]   | 38736 byte            | 152              | 7.464s                            | 
| ref             | 12700 byte [2%]   | 13880 byte            | 55               | 2.690s                            | 

## Asconprfav12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 19060 byte [3%]   | 20240 byte            | 80               | 3.927s                            | 
| armv7m_small    | 12580 byte [2%]   | 13760 byte            | 54               | 2.653s                            | 
| bi32            | 21268 byte [4%]   | 22448 byte            | 88               | 4.329s                            | 
| bi32_armv7m     | 23396 byte [4%]   | 24576 byte            | 96               | 4.716s                            | 
| bi32_lowreg     | 15324 byte [2%]   | 16504 byte            | 65               | 3.191s                            | 
| opt32           | 32212 byte [6%]   | 33392 byte            | 131              | 6.431s                            | 
| ref             | 12764 byte [2%]   | 13944 byte            | 55               | 2.689s                            | 

## Asconprfsv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 16244 byte [3%]   | 17424 byte            | 69               | 3.405s                            | 
| armv7m_small    | 12588 byte [2%]   | 13768 byte            | 54               | 2.655s                            | 
| bi32            | 18180 byte [3%]   | 19360 byte            | 76               | 3.734s                            |  
| bi32_armv7m     | 16500 byte [3%]   | 17680 byte            | 70               | 3.434s                            | 
| bi32_lowreg     | 13868 byte [2%]   | 15048 byte            | 59               | 2.899s                            | 
| opt32           | 16836 byte [3%]   | 18016 byte            | 71               | 3.476s                            | 
| ref             | 12508 byte [2%]   | 13688 byte            | 54               | 2.640s                            | 

## Asconprfv12

| Implementazione | Dimensione sketch | Dimensione eseguibile | Numero di pagine | Tempo di caricamento delle pagine |
| --------------- | ----------------- | --------------------- | ---------------- | --------------------------------- | 
| armv7m          | 16236 byte [3%]   | 17416 byte            | 69               | 3.383s                            | 
| armv7m_small    | 12588 byte [2%]   | 13768 byte            | 54               | 2.652s                            | 
| bi32            | 18052 byte [3%]   | 19232 byte            | 76               | 3.722s                            |  
| bi32_armv7m     | 25548 byte [4%]   | 26728 byte            | 105              | 5.155s                            | 
| bi32_lowreg     | 15324 byte [2%]   | 16504 byte            | 65               | 3.181s                            | 
| opt32           | 37556 byte [7%]   | 38736 byte            | 152              | 7.458s                            | 
| ref             | 12700 byte [2%]   | 13880 byte            | 55               | 2.696s                            | 
