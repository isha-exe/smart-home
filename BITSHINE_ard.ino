float temp;

char incoming_value = 0;
int p = 0 ;

int waterVal; 



void setup() 
{
 
 pinMode(12, OUTPUT);        // bluetooth led
 pinMode(11, OUTPUT); 
 

 pinMode(8, OUTPUT);         // fire alarm

 pinMode(7, OUTPUT);         // water pump
 

 Serial.begin(9600);

}


void loop() 
{
 
// bluetooth connected led and servo 
{
if(Serial.available() > 0)
   {     
      incoming_value = Serial.read();
      Serial.print(incoming_value);
      Serial.print("\n");
         if(incoming_value == '1')
        digitalWrite(11, HIGH);
      else if(incoming_value == '0')
         digitalWrite(11, LOW); 
       else if(incoming_value == '2')
        digitalWrite(12, HIGH);
      else if(incoming_value == '3')
         digitalWrite(12, LOW); 
      
      
      }
 
}
  






 //fire alarm   
   
  temp = analogRead(A0);
  temp = temp*0.48828125;
  Serial.print("TEMPERATURE = ");
  Serial.print(temp);
  Serial.print(" C");
  Serial.println(); 


 if(temp < 40)
 {

  digitalWrite(8, LOW);
  delay(500); 
}

else
{
digitalWrite(8, HIGH);
  delay(500); 
  digitalWrite(8, LOW);
  delay(500); 
}



 //water pump

 waterVal = analogRead(A1); 
  
  Serial.println(waterVal); 
  
if (waterVal <= 300){
  digitalWrite(7, HIGH);
}
else{
  digitalWrite(7, LOW);
}




}
