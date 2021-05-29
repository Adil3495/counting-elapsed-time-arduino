#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

unsigned long start, finished, elapsed;

const int button1 = 8; //Button 1
const int button2 = 7; //Button 2
const int led = 13;    // Led Pin

int button1state = 0;
int button2state = 0;

void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
lcd.begin(16,2);
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(led, OUTPUT);
digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
button1state = digitalRead(button1);
if(button1state == HIGH){
  start=millis();
  while(1){
    digitalWrite(led, HIGH);
    button2state = digitalRead(button2);
    //Serial.println("Inside Loop");
    lcd.print("Counting...");
    if(button2state == HIGH){
      digitalWrite(led, LOW);
      finished=millis();
      elapsed=finished-start;
      //Serial.println(elapsed);
      lcd.setCursor(0,0);
      lcd.print(elapsed);
      lcd.print(" milli seconds");
      delay(100);
      break;
    }
    }
  }
  lcd.clear();
}
