#include <Servo.h>

#define ANALOG_PIN A0       // Analog input at pin A0.
#define LED_PIN D0            // LED at D1
#define SERVO_PIN D2

Servo myservo;

int analogValue = 0;        // Variable for store analog value

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);       // set serial port at 115200 bps
  myservo.attach(SERVO_PIN);
}

void loop()
{
  analogValue = analogRead(ANALOG_PIN);   // Read analog input at pin An 0.
  analogWrite(LED_PIN, analogValue);              // sets the value (0 to 255)
  
  analogValue = map(analogValue, 0, 1023, 0, 30);
  myservo.write(analogValue);
  
  Serial.print("Analog input0 = ");       // Send string to serial port.
  Serial.println(analogValue);            // Send analog value to serial port.
  delay(1000);                            // Delay 0.3 second.
}
