/* Pushbutton with Pullup, Teensyduino Tutorial #3
   http://www.pjrc.com/teensy/tutorial3.html

   This example code is in the public domain.
*/

#include <Adafruit_NeoPixel.h> // neopixel library
#define PIN 3 //pin 3 is the tx pin for the neopixels
#define NUMPIXELS 26 // number of neopixels on your string
long randRed = 100; // random red variable with a start intensity of 200 of 255 on the red color
long randBlue = 0; // random blue variable
long randGreen = 0; // random green variable
int count = 0; 
float heartRate = 80; //this sets the heart rate at 80 bpm
float heartDelay = 0; // the delay time of one heart beat
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int button1 =11;
int button2 =12;
int button3 = 20;
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.                
  Serial.begin(9600);
  Serial3.begin(9600);
  randomSeed(analogRead(2));
  pinMode(button1, INPUT_PULLUP); // this button increases the heart rate
  pinMode(button2, INPUT_PULLUP); // this button decreases the heart rate
  pinMode(button3, INPUT_PULLUP); // this button changes the color of the heart
}

void loop()                     
{
  int heartRateInt = heartRate;  // this variable is for the lcd screen to show the heart rate without a period
    Serial3.write(12);                 // Clear 
    delay(10);
    Serial3.print("Haley's Heart");  // First line
    Serial3.write(13);                 // Form feed
    delay(10);
    Serial3.print(heartRateInt);  // First line
    delay(10);
    Serial3.print(" BPM ");  // First line
    delay(10);
    Serial3.write(17);                 // Turn backlight on
    delay(10);
    
  if (digitalRead(button1) == HIGH) {
  } else {
    while(digitalRead(button1) == LOW && heartRate <= 420)
    {
        heartRate++;
        delay(70);
        Serial3.write(12);                 // Clear 
        delay(10);
        Serial3.print(heartRate);  // First line
        delay(10);
        Serial3.print(" BPM ");  // First line
        delay(10);
        if(heartRate >=420)
        {
          break;
        }
    }
  }
  
    if (digitalRead(button2) == HIGH && heartRate > 40) {
  } else {
      while(digitalRead(button2) == LOW)
       { 
        heartRate--;
        delay(70);
        Serial3.write(12);                 // Clear 
        delay(10);
        Serial3.print(heartRate);  // First line
        delay(10);
        Serial3.print(" BPM ");  // First line
        delay(10);
        if(heartRate <=40)
        {
          break;
        }
       }
  }
    if (digitalRead(button3) == HIGH) {
  } else {
      while(digitalRead(button3) == LOW)
      {
        Serial3.write(12);                 // Clear 
        Serial3.print("New Color :)");  // First line
        randRed = random(150);
        randBlue = random(150);
        randGreen = random(150);
        for(int i=0;i<NUMPIXELS;i++)
        {
            pixels.setPixelColor(i, pixels.Color(randRed,randBlue,randGreen)); 
            pixels.show(); // This sends the updated pixel color to the hardware
        }
        delay(20);
      }
  }
      

         
         heartDelay = (1000 * (60/heartRate))/4;                          

         delay(heartDelay);
         for(int i = 25; i >= 16; i--)
         {
            pixels.setPixelColor(i, pixels.Color(randRed,randBlue,randGreen)); 
            pixels.show(); // This sends the updated pixel color to the hardware.
            delay(heartDelay*0.1);
         }
         for(int i = 25; i >= 13; i--)
         {
            pixels.setPixelColor(i, pixels.Color(0,0,0)); 
            pixels.show(); // This sends the updated pixel color to the hardware.
         }

         delay(heartDelay/10);
         delay(heartDelay/10);
         for(int i = 0; i <= 9; i++)
         {
            pixels.setPixelColor(i, pixels.Color(randRed,randBlue,randGreen)); 
            pixels.show(); // This sends the updated pixel color to the hardware.
            delay(heartDelay*0.1);
         }
         for(int i = 0; i <= 9; i++)
         {
            pixels.setPixelColor(i, pixels.Color(0,0,0)); 
            pixels.show(); // This sends the updated pixel color to the hardware.
         }

         delay(heartDelay);
  
}

