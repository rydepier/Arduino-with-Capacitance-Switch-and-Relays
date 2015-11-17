/********************************************************* 

Up to 5 Relays operated by up to 5 capacitance switches

Chris Rouse Nov. 2015

The Capcitance switches are mounted on a small board
connections, G (Gnd) V (Vcc) and Out ( the switch outputs)
The switch outputs go LOW when pressed

Connect Gnd to Arduino Gnd
Connect Vcc to Arduino 5 volts
Connect Outputs to Arduino pins 7 to 12

The relays are switched on by a LOW signal

Connect the Relay board to Gnd and 5 volts
and the control pins to Arduino pins 2 to 6
*********************************************************/

int relay;
int capSwitch;
boolean relay1 = false;
boolean relay2 = false;
boolean relay3 = false;
boolean relay4 = false;
boolean relay5 = false;
boolean pressButton;

# define LED 13 // onboard LED

void setup() {
Serial.begin(9600); // used for debugging
// setup relay switching outputs
for (relay = 1; relay<6; relay++){
  pinMode(relay, OUTPUT);
  digitalWrite(relay,LOW); // turn OFF the relay
}
//setup capacitance switch inputs
for(capSwitch = 7; capSwitch< 11; capSwitch++){
  pinMode(capSwitch, INPUT_PULLUP); // pull any unused inputs HIGH
}
//
// setup onboard LED
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW); // turn LED off
//
Serial.println("This sketch will control upto 5 relays from a bank of upto 5 capacitanc e switches");
Serial.println("At the start all relays should be switched off");
Serial.println("Touching a switch will latch the relay ON, touching that switch again will turn the relay OFF");
}

void loop() {
// turn switch ON on first touch
// OFF on second press
  delay(200); // helps stop false triggering
  pressButton = false;
  relay = 0;
  for(capSwitch =7; capSwitch < 11; capSwitch++){
    if(pressButton == false){
      if ((digitalRead(capSwitch) == HIGH)) {
        digitalWrite(LED, HIGH); // turn LED ON to show button press
        relay = capSwitch-5; // the pin the relay is connected to
        pressButton = true;
        // now toggle relay state
        switch(relay){
          case 2:
          if (relay1){digitalWrite(relay, LOW);relay1 = false; Serial.println("Relay 1 OFF");} // relay ON
          else{digitalWrite(relay, HIGH);relay1 = true; Serial.println("Relay 1 ON");} // relay OFF
          break;
        
          case 3:
          if (relay2 == true){digitalWrite(relay, LOW);relay2 = false; Serial.println("Relay 2 OFF");} // relay ON
          else{digitalWrite(relay, HIGH);relay2 = true; Serial.println("Relay 2 ON");} // relay OFF
          break;
        
          case 4:
          if (relay3 == true){digitalWrite(relay, LOW);relay3 = false; Serial.println("Relay 3 OFF");} // relay ON
          else{digitalWrite(relay, HIGH);relay3 = true; Serial.println("Relay 3 ON");} // relay OFF
          break;

          case 5:
          if (relay4 == true){digitalWrite(relay, LOW);relay4 = false; Serial.println("Relay 4 OFF");} // relay ON
          else{digitalWrite(relay, HIGH);relay4 = true; Serial.println("Relay 4 ON");} // relay OFF
          break;

          case 6:
          if (relay5 == true){digitalWrite(relay, LOW);relay5 = false; Serial.println("Relay 5 OFF");} // relay ON
          else{digitalWrite(relay, HIGH);relay5 = true; Serial.println("Relay 5 ON");} // relay OFF
          break;        
       
       }
       // wait here until the cap switch is no longer touched
       while (digitalRead(capSwitch) == HIGH){
        // wait for switch to be released
       }
       digitalWrite(LED, LOW); // turn LED OFF as button now released
      }
    }
  }
}
