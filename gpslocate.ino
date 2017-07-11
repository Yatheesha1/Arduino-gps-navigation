void Gpslocate()
{ 
  Serial.print(F("Location: ")); 
  lati=0;
  longi=0;
  if (gps.location.isValid())
  {
    lati=gps.location.lat();
    longi=gps.location.lng();
    latitude=String(lati,6);
    latitude=String(longi,6);
    Serial.print(lati,6);
    Serial.print(F(","));
    Serial.print(longi, 6);
    Serial.print("    ");
    if((lati<locatelati1+0.001 && lati>locatelati1-0.001) &&(longi<locatelongi1+1.5532 && longi>locatelongi1-1.2393))//Location 1
    {
    analogWrite(m2, 0);
    Serial.print("Location 1 Reached    ");
    delay(1000);
    analogWrite(m2, 1023);
    }
    if((lati<locatelati2+0.001 && lati>locatelati2-0.001) &&(longi<locatelongi2+1.5532 && longi>locatelongi2-1.2393))//Location 2
    {
    analogWrite(m3, 0);
    Serial.print("Location 2 Reached    ");
    delay(1000);
    analogWrite(m3, 1023);
    }
    if((lati<locatelati3+0.001 && lati>locatelati3-0.001) &&(longi<locatelongi3+1.5532 && longi>locatelongi3-1.2393))//Location 3
    {
    analogWrite(m4, 0);
    Serial.print("Location 3 Reached    ");
    delay(1000);
    analogWrite(m4, 1023);
    }
    if((lati<locatelati4+0.001 && lati>locatelati4-0.001) &&(longi<locatelongi4+1.5532 && longi>locatelongi4-1.2393))//Location 4
    {
    analogWrite(m5, 0);
    Serial.print("Location 4 Reached    ");
    delay(1000);
    analogWrite(m5, 1023);
    }
    ultrasonic();
  }
  else
  {
    Serial.print(F("INVALID      "));
  }
}
