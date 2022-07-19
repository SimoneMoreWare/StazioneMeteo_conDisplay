#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_ST7735.h>   // include Adafruit ST7735 TFT library
#include <SPI.h>
#include <EEPROM.h>

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

 
#define TFT_RST   8      // TFT RST pin is connected to arduino pin 8
#define TFT_CS    10      // TFT CS  pin is connected to arduino pin 10
#define TFT_DC    9     // TFT DC  pin is connected to arduino pin 9
// initialize ST7735 TFT library
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
 
// define device I2C address: 0x76 or 0x77 (0x77 is library default address)
 
void setup(void)
{
   dht.begin();

  tft.initR(INITR_BLACKTAB);     // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);  // fill screen with black color
  tft.drawFastHLine(0, 30,  tft.width(), ST7735_WHITE);   // draw horizontal white line at position (0, 30)
 
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);  // set text color to white and black background
  tft.setTextSize(1);                 // text size = 1
  tft.setCursor(4, 0);               // move cursor to position (4, 0) pixel
  tft.print("ARDUINO + ST7735 TFT");
  tft.setCursor(19, 15);              // move cursor to position (19, 15) pixel
  tft.print("WEATHER STATION");
 

  
 
  tft.drawFastHLine(0, 76,  tft.width(), ST7735_WHITE);  // draw horizontal white line at position (0, 76)
  tft.drawFastHLine(0, 122,  tft.width(), ST7735_WHITE);  // draw horizontal white line at position (0, 122)
  tft.setTextColor(ST7735_RED, ST7735_BLACK);     // set text color to red and black background
  tft.setCursor(25, 39);              // move cursor to position (25, 39) pixel
  tft.print("TEMPERATURE =");
  tft.setTextColor(ST7735_CYAN, ST7735_BLACK);  // set text color to cyan and black background
  tft.setCursor(34, 85);              // move cursor to position (34, 85) pixel
  tft.print("HUMIDITY =");
  tft.setTextSize(2);                 // text size = 2
 
}
 
// main loop
void loop()
{
  char _buffer[8];
  // read temperature, humidity and pressure from the BME280 sensor
   int humi = dht.readHumidity();
   int temp = dht.readTemperature();
 
  // print temperature (in °C)
  if(temp < 0)    // if temperature < 0
    sprintf( _buffer, "-%02u.%02u", (int)abs(temp), (int)(abs(temp) * 100) % 100 );
  else            // temperature >= 0
    sprintf( _buffer, " %02u.%02u", (int)temp, (int)(temp * 100) % 100 );
  tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);  // set text color to yellow and black background
  tft.setCursor(11, 54);
  tft.print(_buffer);
  tft.drawCircle(89, 56, 2, ST7735_YELLOW);  // print degree symbol ( ° )
  tft.setCursor(95, 54);
  tft.print("C");
 
  // 2: print humidity
  sprintf( _buffer, "%02u.%02u %%", (int)humi, (int)(humi * 100) % 100 );
  tft.setTextColor(ST7735_MAGENTA, ST7735_BLACK);  // set text color to magenta and black background
  tft.setCursor(23, 100);
  tft.print(_buffer);
 
  
 
  delay(1000);    // wait a second
 
}
 
// end of code.
