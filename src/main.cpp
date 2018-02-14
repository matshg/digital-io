#include <Arduino.h>

#define BTN0 (1 << 1)

#define LED0 (1 << 2)
#define LED1 (1 << 3)
#define LED2 (1 << 4)

#define PIN_LEDS (LED0 | LED1 | LED2)

// Create define for the DDR (Data Direction Register)
//#define PORT_B_DDR *(uint8_t*)0x24

// Create define for the Data Register
//#define PORT_B_DATA *(uint8_t*)0x25

const int sensorPin = A0;
//int switchState = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);

    // Pull-Up - Normalt høy
    PORTB |= BTN0;

    //pinMode(9, INPUT);

    //DDRB |= (7 << 2)

    // Set port B pin 9 to input and pins 10, 11, 12 to output
    DDRB |= 0x1C;

    /*
    for (int pinNumber = 10; pinNumber < 13; pinNumber++) {
      pinMode(pinNumber, OUTPUT);
      digitalWrite(pinNumber, LOW);
    }
    */

}

void loop() {
    // put your main code here, to run repeatedly:

    // Read data from pin 9 and store in switchState
    //switchState = digitalRead(9);

    int sensorVal = analogRead(sensorPin);

    //Serial.println('Value: ');


    char LED[3] = {LED0, LED1, LED2};

    // convert the ADC reading to voltavge
    //float voltage = (sensorVal/1024) * 5.0;

while (!(PINB & BTN0))
{
  for (int i = 0; i < 3; i++){
    if (!(PINB & BTN0)){
      PORTB |= LED[i];
      sensorVal = analogRead(sensorPin);
      delay(sensorVal);
      Serial.println(sensorVal);
      }
    }
  for (int z = 2; z>= 0; z--){
    if(!(PINB & BTN0)){
      PORTB &= ~LED[z];
      sensorVal = analogRead(sensorPin);
      delay(sensorVal);
      Serial.println(sensorVal);
      }
    }

} // END WHILE loop

Serial.println("Button not pressed");
PORTB &= ~PIN_LEDS;

/*
    if (!(PINB & BTN0)) { //Turn the LED on if BTN0 is pressed
      PORTB |= LED0;
    if (!(PINB & BTN0))
      delay(sensorVal);
      PORTB |= LED1;
    if (!(PINB & BTN0))
      delay(sensorVal);
    if (!(PINB & BTN0))
      PORTB |= LED2;
    if (!(PINB & BTN0))
      delay(sensorVal);
    if (!(PINB & BTN0))
      PORTB &= ~LED2;
    if (!(PINB & BTN0))
      delay(sensorVal);
    if (!(PINB & BTN0))
      PORTB &= ~LED1;
    if (!(PINB & BTN0))
      delay(sensorVal);
    if (!(PINB & BTN0))
      PORTB &= ~LED0;
    if (!(PINB & BTN0))
      delay(sensorVal);
    }
*/
    //delay(100);
}
