#include <Arduino.h>

const int sensorPin = A0;
int switchState = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);

    pinMode(9, INPUT);

    for (int pinNumber = 10; pinNumber < 13; pinNumber++) {
      pinMode(pinNumber, OUTPUT);
      digitalWrite(pinNumber, LOW);
    }

}

void loop() {
    // put your main code here, to run repeatedly:

    switchState = digitalRead(9);

    int sensorVal = analogRead(sensorPin);

    //Serial.println('Value: ');
    Serial.println(sensorVal);

    // convert the ADC reading to voltavge
    //float voltage = (sensorVal/1024) * 5.0;

    if (switchState == HIGH) {
      digitalWrite(10, HIGH);
      delay(sensorVal);
      digitalWrite(11, HIGH);
      delay(sensorVal);
      digitalWrite(12, HIGH);
      delay(sensorVal);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(sensorVal);
    }

    //delay(100);
}
