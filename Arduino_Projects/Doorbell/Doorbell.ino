const int sound = 2;
const int inLight = 3;
const int doorButton = 4;
const int answered = 5;
const int outsideSound = 13;
const int blinkDel = 200;
int outLight[4];
const int busyLight = 10;
const int innerGreen = 11;
boolean pressed = false;
boolean busy = false;
int freq = 670;
int count = 0;
const int repeatNum = 7;
const int busySwitch = 12;
void setup() {
  // put your setup code here, to run once:
  int temp;
  pinMode(inLight, OUTPUT);
  pinMode(sound, OUTPUT);
  pinMode(busyLight, OUTPUT);
  pinMode(innerGreen, OUTPUT);
  pinMode(outsideSound, OUTPUT);
  pinMode(doorButton, INPUT_PULLUP);
  pinMode(answered, INPUT_PULLUP);
  pinMode(busySwitch, INPUT_PULLUP);
  for(int i = 6; i < 10; i++){
    pinMode(i, OUTPUT);
    outLight[temp] = i;
    temp++;
  }
  

}

void loop() {
    checkBusyButton();
  // put your main code here, to run repeatedly:
  if (!busy){
      digitalWrite(inLight, LOW);
      digitalWrite(busyLight, LOW);
      digitalWrite(innerGreen, HIGH);
      for(int i = 0; i < 4; i++){
        digitalWrite(outLight[i], HIGH);
      }
      if(checkPressed()){     //IF THE DOORBELL IS RUNG
        for(int i = 0; i < 4; i++)
        {
          digitalWrite(outLight[i], LOW);
        }
        pressed = true;
        for(int i = 0; i < 5; i++){
          tone(sound, freq);
          for(int r = 0; r < 4; r++){
            digitalWrite(outLight[r], HIGH);
            digitalWrite(inLight, HIGH);
            digitalWrite(outsideSound, HIGH);
            delay(blinkDel-100);
            digitalWrite(outLight[r], LOW);
            digitalWrite(outsideSound, LOW);
            digitalWrite(inLight, LOW);
            delay(blinkDel-100);
            }
          
          noTone(sound);
          if(freq == 670){
             freq = 400;
             }
          else if (freq == 400){
                freq = 670;
             }
          delay(blinkDel);
          }
          freq = 670;
        }
      
      while(pressed){
        count++;
        if(checkAnswer()){
          break;
        }
         for(int i = 0; i < 4; i++){
          digitalWrite(outLight[i], HIGH);
          digitalWrite(inLight, HIGH);
          delay(blinkDel);
          digitalWrite(outLight[i], LOW);
          digitalWrite(inLight, LOW);
          delay(blinkDel);

          if(checkAnswer()){
            break;
            }
         }
    
        if(checkAnswer()){
          break;
        }
          if(count % 10 == 0){
            for(int i = 0; i < repeatNum; i++){
              tone(sound, freq);
              digitalWrite(inLight, HIGH);
              for(int i = 0; i < 4; i++){
                digitalWrite(outLight[i], HIGH);
                }
              delay(blinkDel);
              noTone(sound);
              digitalWrite(inLight, LOW);
              for(int i = 0; i < 4; i++){
                digitalWrite(outLight[i], LOW);
                }
              delay(blinkDel);
              }
          }
    }
  }

  checkBusyButton();
  if(busy){
    busyMode();
    if(!digitalRead(doorButton)){
      for(int r = 0; r < 3; r++)
      {
        tone(outsideSound, 100);
        delay(50);
        noTone(outsideSound);
        delay(50);
      }
      for(int i = 0; i < 5; i++)
      {
        digitalWrite(busyLight, HIGH);
        delay(blinkDel);
        digitalWrite(busyLight, LOW);
        delay(blinkDel);
          }
        }
      }
   checkBusyButton();
 
}

boolean checkPressed(){
  return !digitalRead(doorButton);
}

void checkBusyButton(){
     if(!digitalRead(busySwitch)){
        for(int i = 0; i < 3; i++){
          digitalWrite(innerGreen, HIGH);
          digitalWrite(busyLight, HIGH);
          for(int r = 0; r < 4; r++){
            digitalWrite(outLight[r], HIGH);
             }
          delay(blinkDel);
          for(int r = 0; r < 4; r++){
            digitalWrite(outLight[r], LOW);
             }
          digitalWrite(innerGreen, LOW);
          digitalWrite(busyLight, LOW);
          delay(blinkDel);
        }
        busy = !busy;
        //delay(300);
      }
}


boolean checkAnswer(){
    if(!digitalRead(answered) || count > 70){
        pressed = false;
        count = 0;
        return true;
      }
      else{
        return false;
      }
}

void busyMode(){
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(outLight[i], LOW);
  }
  digitalWrite(busyLight, HIGH);
  digitalWrite(innerGreen, LOW);
}
