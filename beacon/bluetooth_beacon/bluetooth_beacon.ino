int Incoming_value = 0;
int led = 13;  
float proportion = 0.5;

void setup() 
{
  Serial.begin(9600);         
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);     
}

void loop()
{
  if(Serial.available() > 0) { 
    Incoming_value = Serial.read();   
  }        
  if(Incoming_value == 0){            
    digitalWrite(led, HIGH);  
  }
  else if(Incoming_value == 255){  
    digitalWrite(led, LOW);  
  }
  else {
    digitalWrite(led, HIGH);
    delay(int((1000/(int)Incoming_value)*(1-proportion)));
    Serial.print("in value: ");
    Serial.print(Incoming_value);
    Serial.print("\n");
    Serial.print("delay: ");
    Serial.print(int((1000/(int)Incoming_value)*(1-proportion)));    
    Serial.print("\n");
    digitalWrite(led, LOW);
    delay(int((1000/(int)Incoming_value)*(proportion)));
  }
}
                          
 
