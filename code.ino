//  ============   Simple Car Lock and Unlock System Via SMS  ================

// Project by: Mohammed Okasha & Abdullah Alhesnawi 
// University of Tripoli - Computer Engineering Department 
// Class project for Microcontrollers 2

// =============================================


#include <SoftwareSerial.h> 
char inchar; 
// Will hold the incoming character from the GSM shield

SoftwareSerial SIM900(50, 51); 
// TX and RX pins connected to ports 50, 51 or the Arduino Mega.
// You can use any ports just be sure to change them here. 


int lock = 10;
    // This pin connects to the relay which locks the car 

int unlock = 11;
  // This pin connects to the relay which unlocks the car

char command; 
 // This stores the command sent via SMS. "1" to lock the car and "2" to lock the car 
 

int D0 = 17;  // connected to remote control button 1 (lock)
int D1 = 18;  // connected to remote control button 2 (unlock)


void setup(){

pinMode(lock, OUTPUT);	

pinMode(unlock, OUTPUT);

Serial.begin(19200);

 
  SIM900.begin(19200);
  delay(20000);  // give time to log on to network.
  SIM900.print("AT+CMGF=1\r");  // set SMS mode to text
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r"); 
  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
  delay(100);
  Serial.println("Ready...");


} // End of setup()




void loop(){
	

  digitalWrite(unlock, HIGH);
digitalWrite(lock, HIGH);

// Check to see if there is any incomming comands via SMS

  if(SIM900.available() >0)
  {

   inchar=SIM900.read(); 
   Serial.print(inchar);
  
  }
  
  
   if (inchar=='#'){
     delay(10);
     inchar=SIM900.read();
   command = inchar;
   
      if (command == '1'){

  digitalWrite(lock, LOW); 
  delay(200);	
    
  	

  }else if(command == '2'){
   
    digitalWrite(unlock, LOW);
    delay(200);
  
  }
   }
  
  // Check for any incomming comands from the remote control
  
   if(digitalRead(D0)== 1){
   
    digitalWrite(lock, LOW);
    delay(100);
    
     
    
  }else if(digitalRead(D1) ==1){
    
     digitalWrite(unlock, LOW);  
     delay(100);
    
       
  }
  
  
 
} // End of loop()

