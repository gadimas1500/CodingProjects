*
 * Pins 2-7 are LEDs
 * Pins 38-45 are button pins
 * Pin 50 is the piezo
 */



int led[6];
int firstLed = 2;
int lastLed = 8;
int firstButton = 38;
int lastButton = 44;
int button[6];
int sound = 50;   //PIN NUM
int failSound = 50; //Hz
//int sequence[6];
//int userSequence[6];
int timeDel = 300;
int num;
const int level = 3;//NUMBER OF FLASHES INCREASES WITH THE INCREASED LEVEL
int sequence[15];
int soundFreq[level];
int toLight = level; //SAME AS LEVEL BUT WON'T MESS UP THE ARRAYS




void setup() {
  Serial.begin(9600);
  for(int i = firstLed; i < lastLed; i++)
  {
    led[i-firstLed] = i;
    pinMode(led[i-firstLed], OUTPUT);
  }
  for(int i = firstButton; i < lastButton; i++)
  {
    button[i-firstButton] = i;
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(sound, OUTPUT);
  changeSound(toLight);
  
  for(int i = 0; i < 6; i++)    //INTRODUCTION
  {
    digitalWrite(led[i], HIGH);
    delay(100);
    digitalWrite(led[i], LOW);
    delay(100);
  }
  delay(1000);

}

void loop() 
{
  levelOne(toLight);
  delay(1000);
  toLight++;
  changeSound(toLight);
}

void levelOne(int lightLevel)
{
  chooser(lightLevel);   //INITIATES THE SEQUENCE WITH A PARAM OF NUM CHOSEN
  Serial.println("START SEQ");
  for(int i = 0; i < lightLevel; i++)
  {
    Serial.print("User #");
    Serial.println(sequence[i]);
  }
  Serial.println("END SEQ");
  for(int i = 0; i < lightLevel; i++)    //SHOWS THE SEQUENCE IN ORDER OF THE SEQUENCE ARRAY
  {
    //int lightUp = sequence[i];
    digitalWrite(led[sequence[i]], HIGH); Serial.print("Board #"); Serial.println(led[sequence[i]]);
    tone(sound, soundFreq[i]);
    delay(timeDel);
    digitalWrite(led[sequence[i]], LOW);
    noTone(sound);
    delay(timeDel);
  }
  for(int i = 0; i < lightLevel; i++)//CHECKS THE BUTTONS
  {
    num = checkInput();
    while(num == 999) //REPEATS UNTIL A BUTTON IS PRESSED
    {
        num = checkInput();
    }
    if(num == sequence[i])  //IF A BUTTON IS PRESSED AND MATCHES THE NUM IN THE SEQUENCE
    {
      tone(sound, soundFreq[i]);
      digitalWrite(num+2, HIGH);
      delay(timeDel);
      digitalWrite(num+2, LOW);
      noTone(sound);
    }
    else
    {
      fail(sequence[i]);
      break;
    }
    Serial.println(num);
  } 
}

int checkInput()    //CHECKS USER INPUT
{
   for(int i = 0; i < 6; i++)
   {
      boolean input = !digitalRead(button[i]);
      if(input)
      {
        return i;
      }
   }
   return 999;
}

void chooser(int numFlashes)    //MAKES THE RANDOM SEQUENCE
{
  int randNum = random(numFlashes+1);
  boolean chosen[numFlashes];
  for(int i = 0; i < numFlashes; i++)
  {
    chosen[i] = false;
  }
  for(int i = 0; i < numFlashes; i++)
  {
    randNum = random(numFlashes+1);
    while(chosen[randNum])
    {
      randNum = random(numFlashes+1);
    }
    sequence[randNum] = i;
    chosen[randNum] = true;
  }

}

void winner()
{
  for(int i = 0; i < 3; i++)
  {
    for(int r = 0; r < 6; r++)
    {
      digitalWrite(led[r], HIGH);
      delay(30);
    }
    tone(sound, 500);
    
    delay(30);

    for(int r = 0; r < 6; r++)
    {
      digitalWrite(led[r], LOW);
      delay(30);
    }
    noTone(sound);

    delay(30);
    
  }
}
void fail(int wrong)//TAKES IN WHAT THE CORRECT NUMBER SHOULD HAVE BEEN
{
    tone(sound, failSound);
    delay(timeDel);
    noTone(sound);
    for(int i = 0; i < 5; i++)
    {
      digitalWrite(wrong+2, HIGH);
      delay(timeDel);
      digitalWrite(wrong+2, LOW);
      delay(timeDel);  
    }
}
void changeSound(int soundLev)  //ADJUSTS ACCORDING THO THE LEVEL WE ARE ON
{
  for(int i = 0; i < soundLev; i++)
  {
    soundFreq[i] = 100 * (i+1);
    Serial.print("Freq: ");
    Serial.println(soundFreq[i]);
  }
}
