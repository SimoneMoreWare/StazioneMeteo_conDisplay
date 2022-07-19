# StazioneMeteo_conDisplay
Arduino: stazione meteo con display tft st7735 e DHT11

Ci sono tantissimi display TFT da 1,8″ nel mercato, quindi il collegamento potrebbe cambiare da display a display. I display possono avere la posizioni di alcuni pin differente ma comunque sono presenti le “stesse sigle” che permettono quindi di effettuare correttamente il collegamento prendendo anche come riferimento altri display con la posizione dei pin diversa. Rispetto a questo display ce ne potrebbero essere altri con pin BLK (blacklight), che in questo caso non è presente, ma niente di preoccuparsi, lo puoi collegare al pin 12

Ecco una schema che può tornare utile:

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2021/09/map.png?w=315&ssl=1)

Ecco il diagramma di collegamento:

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2021/09/Untitled-Sketch-2_bb-11.png?w=824&ssl=1)

CODICE E TEST

Se è la prima volta che utilizzi il display, prima di scrivere il codice ti consiglio vivamente di leggere questo articolo introddutivo sul collegamento e configurazione del display ST7735 TFT 1,8″

[Come collegare display TFT 1,8″ ST7735 ad Arduino
](https://www.moreware.org/wp/blog/2022/01/04/come-collegare-display-tft-18-st7735-ad-arduino/)
Forse ad alcuni occorre installare la libreria DHT.h. Non sai come fare? Tranquillo, leggi questo articolo:

[Arduino IDE: come installare una libreria #10.1
](https://www.moreware.org/wp/blog/2020/03/11/arduino-ide-come-installare-una-libreria-10-1/)

Ecco il [codice](https://github.com/SimoneMoreWare/StazioneMeteo_conDisplay/blob/main/meteo.ino)

Risultato
![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2021/09/e353581f-dbe6-4ee6-92fe-21d428b385cc.jpg?resize=1024%2C461&ssl=1)
