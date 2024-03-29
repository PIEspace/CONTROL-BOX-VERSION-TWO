// this software is control box version two 

#include<Arduino.h>
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

// define the ce and cns pins 
const int CE_PIN = 7;
const int CNS_PIN = 8;


//define the radio
RF24 radio (CE_PIN , CNS_PIN);

//define the address 
const byte address[][7] = {"12345" , "123456"};


struct data_package
{
    byte First_Joystick_X;
    byte First_Joystick_Y;
    byte Second_Joystick_X;
    byte Second_Joystick_Y;
    byte First_Potentiometer;
    byte Second_Potentiometer;
    byte First_Button;
    byte Second_Button;
    byte Third_Button;
    byte Fourth_Button;
    byte Roll;
    byte Pitch;
    byte Yaw;

};
data_package data;


void setup(){
    // define the bud rate 
    // in this case i am using 9600 bits per second 
    Serial.begin(9600);

    radio.begin();
    radio.openWritingPipe(address[1]); //the address is = 12345
    radio.openReadingPipe(1 , address[0]); //the address is = 123456
    radio.setPALevel(RF24_PA_HIGH);
    radio.startListening();
}

void loop(){

    radio.read(&data , sizeof(data_package));


    data.Roll;

    Serial.print("roll ");
    Serial.println(data.Roll);

    delay(15);

}