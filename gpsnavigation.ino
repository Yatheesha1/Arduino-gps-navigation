#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// The TinyGPS++ object
TinyGPSPlus gps;

static const int RXPin = 2, TXPin = 3;
// The serial connection to the GSM device
SoftwareSerial gpsSerial(RXPin, TXPin);


#define m1 A1
#define m2 A2
#define m3 A3
#define m4 A4
#define m5 A5


#define trigger 7
#define echo 6

float time=0,distance=0;
String latitude,longitude;
double longi,lati;

double locatelati1=12.876;
double locatelongi1=74.848;

double locatelati2=12;
double locatelongi2=74;

double locatelati3=12;
double locatelongi3=74;

double locatelati4=12;
double locatelongi4=74;


int flag=0;

void setup()
{
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  gpsSerial.begin(9600); 
  delay(1000);
}

void loop()
{
  while (gpsSerial.available())
  {
    if (gps.encode(gpsSerial.read()))
    {
      Gpslocate();
      flag=0;
      ultrasonic();
    }
  }    

  if (millis() > 5000 && gps.charsProcessed() < 10 )
  {
    if(flag==0)
    {
      Serial.println(F("No GPS detected: check wiring.      "));
      flag=1;
    }
    ultrasonic();
  }
}

