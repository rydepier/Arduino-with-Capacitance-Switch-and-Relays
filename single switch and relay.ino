/* Simple sketch to show the operation of a capacitance switch
  
Chris Rouse Nov 2015
   
The switch used here is mounted on a small board
with three connections, G (Gnd) V (Vcc) ans Out ( the switch output)
The switch output goes LOW when pressed

Connect Gnd to Arduino pin 5 - supplies 0v
Connect Vcc to Arduino pin 6 - supplies 5 volts
Connect Out to Arduino pin 7

The relay used is a Ywrobot board with 1 relay
The relay is switched on by a HIGH signal

Connect the Relay board to Gnd and 5 volts
and the control pin to Arduino pin 8
*/
boolean latch = false; 

# define relay 8 // this is the pin used to switch the relay
# define Gnd 5 // this is the pin used to act as Gnd for the switch
# define Vcc 6 // this is the pin used to act as +5v for the switch
# define capSwitch 7 // this is the capacitance switch output
# define LED 13 // onboard LED

void setup() {
Serial.begin(9600); // used for debugging
pinMode(relay, OUTPUT);
digitalWrite(relay,LOW); // turn OFF the relay
pinMode(capSwitch, INPUT);
pinMode(Vcc, OUTPUT);
digitalWrite(Vcc,HIGH);// this pin will supply 5 volts
pinMode(Gnd, OUTPUT);
digitalWrite(Gnd,LOW); // this pin will supply the GND to the board
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW); // turn LED off
}

void loop() {

// turn switch ON on first touch
if ((digitalRead(capSwitch) == HIGH) && (latch == false)) {
digitalWrite(relay, HIGH); // relay ON
Serial.println("Relay ON");
digitalWrite(LED, HIGH); // turn LED ON
latch = true;
// wait here until the cap switch is no longer touched
while ((digitalRead(capSwitch) == HIGH)){
digitalWrite(LED, LOW); // turn LED OFF
delay(500); // try to stop debounce
}
}

// turn relay OFF on second touch
if ((digitalRead(capSwitch) == HIGH) && (latch == true)) {
digitalWrite(relay, LOW); // relay OFF
Serial.println("Relay OFF");
digitalWrite(LED, HIGH); // turn LED ON
latch = false;
// wait here until the cap switch is no longer touched
while ((digitalRead(capSwitch) == HIGH)){
digitalWrite(LED, LOW); // turn LED OFF
delay(500); // try to stop debounce
}
}
}
