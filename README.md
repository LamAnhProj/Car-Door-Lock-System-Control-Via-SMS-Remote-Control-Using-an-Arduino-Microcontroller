# Car-Door-Lock-System-Control-Via-SMS-Remote-Control-Using-an-Arduino-Microcontroller
Car Door Lock System Control Via SMS &amp; Remote Control Using an Arduino Microcontroller


Introduction

  This project allows you to control your cars lock system, to lock or unlock your car doors from nearby using a remote as in a normal car alarm system and if the remote is out of range you may send an SMS to your car. 
  By sending a unique command via SMS to the GSM/GPRS shield connected to the Arduino Mega microcontroller reads the command and sends a signal to the relay connected to the cars lock system; locking or unlocking the car. 



Components Used: 

•	Arduino Mega microcontroller (X 1)
•	Arduino GSM/GPRS shield ( X 1)
 ( The one we used turned out to be a Chinese copy which wasn’t as easy to deal with, we were forced to use AT commands in our code to get it to work.)
•	Bread board ( X 1 )
•	Relay module ( X 2 )
•	Remote with receiver circuit ( X 1 )
•	Wires 

Instructions for Building 


1.	Connect the GSM/GPRS shield by mounting it above the Arduino Mega. Then connect the shields TX, RX pins to pins 50, 51 on your Arduino Mega. 

2.	Connect the remote’s receiver VCC and GND pins and connect the D0 and D1 to the digital pins 17 and 18 on the Arduino. 
In this project we won’t be using the other two buttons of the remote control which correspond to D2, D3 of the receiver circuit. 

3.	Connect the relay pins VCC, GND, IN1 and IN2. In this project we are using 2 relay so we have to corresponding inputs to control the relay.  Connect the VCC to the 5 volt VCC and IN1, IN2 to pins 10, 11 on the Arduino. You can always change the pins, just be sure to adjust the code for it to work.

A relay is an electrically operated switch that allows you to turn on or off a circuit using voltage and/or current much higher than the Arduino could handle. There is no connection between the low voltage circuit operated by Arduino and the high power circuit. The relay protects each circuit from each other.
Warning: We don't recommend you operate circuits powered at more than 24V without the supervision of an expert.
Input: The relay is a simple mechanical on/off switch. It activates when the input reaches 5v and turns off when the input is 0v. You can control it though the digitalWrite() function on Arduino.

The module provides three connections labeled COM, NC and NO. NC stands for "NORMALLY CLOSED"***. This means that when the relay has no signal (LOW or 0V from an Arduino), the connected circuit wil be active; conversely, if you apply 5V or pull the pin HIGH, it will turn the connected circuit off. **NO stands for "NORMALLY OPEN", and functions in the opposite way; when you apply 5V the circuit turns on, and at 0V the circuit turns off. Relays can replace a manual switch. Remove the switch and connect its wires to COM and NO. When the relay is activated the circuit is closed and current can flow to the device you are controlling.

4.	Now, connect the Arduino Mega to your computer and open the Arduino IDE. Copy and paste the project code. Next compile and upload the code to the Arduino Mega.

 
5.	The next step is connecting the circuit to your car. You might have a hard time with this depending on the year and model of your car. But in most cases it’s the same and if you face any trouble just ask a car alarm technician to help you find which wires control the door lock system. 

Under the steering wheel you should find a standard connecter which connects to the normal car alarm control circuits. 

Before continuing you will have figure out which wires when connected with the 12 V wire “Usually a black wire” wire lock or unlock the cars doors. The lock and unlock wires are two separate wires usually white. Figure out which is which by carefully connecting the 12 V wire and one of the white wires and then test the other white wire.  

Once you figured out which wire locks and which unlock your car. Connect the 12 V wire to the relay COM connection, and connect the lock wire to first relay NO “Normally Open”. Connect the unlock wire in the same manner to the second relay also. 

6.	Connect your Arduino Mega to a 6-12 V DC power source and turn on the GSM/GPRS shield.

7.	Now test your project. Send an SMS “#1” for lock or “#2” for unlock, and test the remote control also.





References 

Links:
http://www.arduino.cc
http://www.geeetech.com/wiki/index.php/Arduino_GPRS_Shield#Serial_Port.28UART.29_Communication
http://www.cooking-hacks.com/documentation/tutorials/arduino-gprs-gsm-quadband-sim900#step1
http://www.developershome.com/sms/cmgsCommand3.asp
http://www.geeetech.com/Documents/SIM900_AT_Command_Manual_V1.03.pdf
http://christinefarion.com/2014/12/gprs-shield-sim900/



