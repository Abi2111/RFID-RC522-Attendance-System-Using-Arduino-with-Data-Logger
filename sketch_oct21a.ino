#include<SPI.h>
#include<RFID.h>
#include<LiquidCrystal.h>
#include<DS3231.h>
DS3231 rtc(SDA,SCL);
LiquidCrystal lcd(1,2,4,5,6,7);
RFID rfid(10,9);
int a=0;
String rfidread;
void setup(){ 

  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  lcd.clear();
  lcd.begin(16,2);
  rtc.begin();
  rtc.setDOW(FRIDAY);
  rtc.setTime(14,28,10); 
  pinMode(8,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Place your id");
}
void loop(){ 
if(rfid.isCard()){
  if(rfid.readCardSerial()){
    rfidread=String(rfid.serNum[0])+" "+String(rfid.serNum[1])+" "+String(rfid.serNum[2])+" "+String(rfid.serNum[3]);
    if(rfidread=="106 31 153 19"){
      a=1;
    }
    else if(rfidread=="114 206 100 71"){
      a=2;
    }
    else if(rfidread=="130 35 239 71"){
      a=3;
    }
    else{
      a=0;
    }
  }
  switch (a){
    case 0:
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Access Denied");
    lcd.setCursor(0,1);
    lcd.print(rtc.getTimeStr());
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(1000);
    Serial.println("Access Denied");
    Serial.println(rtc.getTimeStr());
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Place your id ");
    break;
    
    case 1:
   
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("49032 PRESENT");
    lcd.setCursor(0,1);
    lcd.print(rtc.getTimeStr());
    Serial.println("49032 PRESENT");
    Serial.println(rtc.getTimeStr());
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Place your id ");
    break;
    
    case 2:

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("49033 PRESENT");
    lcd.setCursor(0,1);
    lcd.print(rtc.getTimeStr());
        digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
     Serial.println("49033 PRESENT");
    Serial.println(rtc.getTimeStr());
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Place your id ");
    break;

    case 3:

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("49023 PRESENT");
    lcd.setCursor(0,1);
    lcd.print(rtc.getTimeStr());
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
   Serial.print("49034 PRESENT");
   Serial.println(rtc.getTimeStr());
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Place your id ");
    break;
  }
 }
}
