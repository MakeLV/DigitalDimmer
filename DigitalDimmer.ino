// DIGITAL DIMMER
// LVTech 2/12/2013

// store some information in these variables
int sensorValue = 0;
int fadeValue = 0;

// select the pins for the components
int ledPin = 9;
int sensorPin = A5;

void setup() {
  // put your setup code here, to run once:
  
  // set the pin mode of the LED pin to output
  pinMode(ledPin, OUTPUT);
  // fire up serial at 9600 baud
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly: 
  
  // read our sensor or pot, store in sensorValue (0-1023)
  sensorValue = analogRead(sensorPin);
  // map our sensorValue (0-1023) to a PWM value (0-254)
  fadeValue = map(sensorValue, 0, 1023, 0, 254);
  // output some feedback via serial
  Serial.print(sensorValue);
  Serial.print(" - ");
  Serial.println(fadeValue);
  // write our PWM value to the LED
  analogWrite(ledPin, fadeValue);
}
