// define the buzzer 


#include<Arduino.h>


const int buzzer = 3 ;

void setup(){
    // define the bud rate in this case i am using 9600 bits per second 
    Serial.begin(9600);

    pinMode(buzzer , OUTPUT);
}

void loop(){

    digitalWrite(buzzer , 1);
    delay(1000);

    digitalWrite(buzzer , 0 );
    delay(1000);
    

}