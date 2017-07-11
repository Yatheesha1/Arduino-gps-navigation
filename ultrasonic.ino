void ultrasonic()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 Serial.print("Distance:");
 Serial.print(distance);
 Serial.println(" cm");
 if(distance<50)
   {
    analogWrite(m1, 0);
    delay(1000);
    analogWrite(m1, 1023);
   }
  else
    delay(1000);
}

