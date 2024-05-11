#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pil A1

// 338 max - 1.65 V
// 246 min - 1.2 V

int min_deger = 246;
float yuzde = 0;
float deger = 0;

int gerilim = 0;

void setup()
{
  lcd.init();
  //LCD Başlat
  lcd.backlight();
  //LCD Zemin Işığı aç
  lcd.setCursor(0,0);
  lcd.print("PIL OLCER");
}

void loop()
{
  gerilim = analogRead(pil);

  if(gerilim >= 338)
  {
    gerilim = 338; 
  }
  
  if(gerilim <= 246)
  {
    gerilim = 246;
  }

   yuzde = gerilim - min_deger;
   deger = (100.00/92.00) * yuzde;

   lcd.setCursor(0,1);
   lcd.print("Doluluk: %");
   lcd.print(deger);
   delay(500);
}
