char inchar; //Will hold the incoming character from the Serial Port.


 int led1 = 8;
 int led2 = 9;
 int relay1=7;
 int relay2=6;
 void setup()
 {
 // prepare the digital output pins
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 Serial.begin(9600);
 pinMode(relay1, OUTPUT);
 pinMode(relay2, OUTPUT);
 digitalWrite(7,HIGH);
 digitalWrite(6,HIGH);
 Serial.print("pin state low\n");
 delay(3000); // give time for GSM module to register on network.
 Serial.println("AT+CMGF=1"); // set SMS mode to text
 delay(200);
 Serial.println("AT+CNMI=2,2,0,0,0"); // set module to send SMS data to serial out upon receipt 
 delay(200);
 }
 void loop() 
 {
 //If #a1b1c1d1 comes as sms, all led's should light up.
 if(Serial.available() >0)
 {
 inchar=Serial.read(); 
       if (inchar=='#')
        {
            delay(10);
            inchar=Serial.read(); 
            //first led
            if (inchar=='a')//closed
             {
               delay(10);
               inchar=Serial.read();
               if (inchar=='0')//closed
                   {
                    digitalWrite(led1, LOW);
                    delay(1000);
                    digitalWrite(relay1,HIGH);
                    Serial.print("Relay 1 LOW\n");
                    // delay(1000);
                  //  Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"9894273273\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("Power OFF");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                    }
                       else if (inchar=='1')
                          {
                          digitalWrite(led1, HIGH);
                          delay(1000);
                          digitalWrite(relay1, LOW);
                          Serial.print("Relay 1 HIGH\n");
                          // delay(1000);
                      //    Serial.println("AT+CMGD=1,4");                   //Delete all message
                          delay(500);
                          Serial.println("AT+CMGF=1");
                          delay(500);
                          Serial.println("AT+CMGS=\"9894273273\"");//Change the receiver phone number
                          delay(500);
                          Serial.print("Power ON");    //the message you want to send
                          delay(500);
                          Serial.write(26);
                          delay(500);
                          }
                  
        delay(10);
        inchar=Serial.read();
        if(inchar=='b')
        {
        delay(10);
        inchar=Serial.read();
          if (inchar=='0')
            {
             digitalWrite(led2, LOW);
             delay(500);
             digitalWrite(relay2,HIGH);
             Serial.print("Relay 2 LOW\n");
             //Serial.println("AT+CMGD=1,4");                   //Delete all message
           /*  delay(500);
             Serial.println("AT+CMGF=1");
             delay(500);
             Serial.println("AT+CMGS=\"9894273273\"");//Change the receiver phone number
             delay(500);
             Serial.print("Light OFF");    //the message you want to send
             delay(500);
             Serial.write(26);
             delay(500);*/
           //  Serial.print("Light OFF");
             }
               else if (inchar=='1')
                 {
                    digitalWrite(led2, HIGH);
                    delay(500);
                    digitalWrite(relay2, LOW);
                    Serial.print("Relay 2 HIGH\n");
                   // Serial.println("AT+CMGD=1,4");                   //Delete all message
                    /*delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"9894273273\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("Light ON");//the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);*/
                 //   Serial.print("Light ON");
                  }
                }
             }
              Serial.println("AT+CMGD=1,4");
        }
          
    }
}
                        
                  
