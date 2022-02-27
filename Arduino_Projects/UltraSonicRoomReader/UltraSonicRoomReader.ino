//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 2
#define ECHO_PIN 3
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long readDistance;
const int sound = 4;
const int freq = 600;
const int button = 5;
boolean DND = false;
const int statusLight = 11;
const int longDistRead = 220;
int light[5];
const int interval = 15;
long lastRead = 0;
long lastTwoRead = 0;
long lastThreeRead = 0;
int count;



void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(sound, OUTPUT);
   pinMode(statusLight, OUTPUT);
   pinMode(button, INPUT_PULLUP);
   int temp = 0;
   for(int i = 6; i < 11; i++){
      light[temp] = i;
      pinMode(light[temp], OUTPUT);
      temp++;
   }
}

void loop() {
   readDistance =sr04.Distance();
   Serial.print(readDistance);
   Serial.println("cm");
   Serial.print("Read Parameter:");
   Serial.println(longDistRead - (4*interval));
   Serial.println(DND);

   if(!DND){    //LETS US KNOW IF THE TONE IS ONE
    digitalWrite(statusLight, HIGH);
   }
   else{
    digitalWrite(statusLight, LOW);
   }
   if(!digitalRead(button)){
    DND = !DND;
    delay(300);
   }
   /**
   if(!(readDistance < lastRead) and readDistance < longDistRead){
    digitalWrite(light[0], HIGH);
   }
   else{
    digitalWrite(light[0], LOW);
   }
   if(!(readDistance < lastRead) and readDistance < longDistRead - interval){
    digitalWrite(light[1], HIGH);
   }
   else{
    digitalWrite(light[1], LOW);
   }
   if(!(readDistance < lastRead) and readDistance < longDistRead - (2*interval)){
    digitalWrite(light[2], HIGH);
   }
   else{
    digitalWrite(light[2], LOW);
   }
   if(!(readDistance < lastRead) and readDistance < longDistRead - (3*interval)){
    digitalWrite(light[3], HIGH);
   }
   else{
    digitalWrite(light[3], LOW);
   }
   **/
   if(!(readDistance < lastRead or readDistance < lastTwoRead or readDistance < lastThreeRead) and readDistance < longDistRead - (4*interval)){
    for(int i = 0; i < 5; i++)
    {
    digitalWrite(light[i], HIGH);
    }
   }
   else{
    for(int i = 0; i < 5; i++)
    {
    digitalWrite(light[i], LOW);
    }
   }

   while(!(readDistance < lastRead or readDistance < lastTwoRead or readDistance < lastThreeRead) and readDistance < longDistRead - (4*interval)){ //WHILE THE LAST LIGHT IS ON
      for(int i = 0; i < 7; i++){
        if(!DND){
          tone(sound, freq);
        }
        delay(100);
        noTone(sound);
        delay(100);
      }
      delay(2000);
      break;
      lastThreeRead = 0;
      lastTwoRead = 0;
      lastRead = 0;
   }
    lastThreeRead = lastTwoRead;
    lastTwoRead = lastRead;
    lastRead = readDistance;
   if (count % 3 == 0){
    count = 0;
   }
   count++;
}
