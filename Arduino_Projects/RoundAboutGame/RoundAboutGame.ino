//GLOBAL CONSTANTS
const int button = 2;
const int lightNums = 11;
const int ledPinStart = 3;
int del = 85;
const int difficulty = 6; //INCREMENTATION FOR EACH LEVEL WON
const int blinkDel = 200; //DON'T CHANGE
int led[lightNums];
boolean gameMode = true;
int level = 1;
int lightWhenPushed;
int temp = ledPinStart;
boolean gameEnd = false;
void setup() {
  int val = 0;
  Serial.begin(9600);
  for(int i = 0; i < lightNums; i++)
  {
    led[i] = temp;
    pinMode(led[i], OUTPUT);
    temp++;
  }
  pinMode(button, INPUT_PULLUP);
  while(digitalRead(button)){
    gameMode = true;
    val++;
  }
  levelUp();
}

void loop() {
  while(gameEnd)  //TO PLAY ANOTHER GAME
  {
    del = 90;
    level = 1;
    if(!digitalRead(button))
    {
      gameEnd = false;
      gameMode = true;
      break;
    }
  }
  while (gameMode)
  {
    for(int i = 0; i < lightNums; i++)
    {
      if(!digitalRead(button))
      {
        lightWhenPushed = i;
        gameMode = false;
        break;
      }
      digitalWrite(led[i], HIGH);
      if(!digitalRead(button))
      {
        lightWhenPushed = i;
        gameMode = false;
        break;
      }
      delay(del);
      if(!digitalRead(button))
      {
        lightWhenPushed = i;
        gameMode = false;
        break;
      }
      digitalWrite(led[i], LOW);
      continue;
    }
    if(!gameMode)
    {
      break;
    }
  }
  Serial.println(!digitalRead(button));
  checkWinner(lightWhenPushed);
}

boolean checkPush()   //CHECKS IF THE BUTTON IS PUSHED
{
  if(!digitalRead(button))
  {
    return true;
  }
  else
  {
    return false;
  }
}

void checkWinner(int endingLight)//CHECKS IF WE HAVE A WINNER
{
  if(endingLight == 0)  //IF YOU GET THE GREEN LIGHT, YOU WIN
  {
    del -= difficulty;
    delay(300);
    winnerBlink();  
    gameMode = true;  
    levelUp();
  }
  else
  {
    for(int i = 0; i < 4; i++)
    {
      digitalWrite(led[lightWhenPushed], HIGH);
      delay(blinkDel);
      digitalWrite(led[lightWhenPushed], LOW);
      delay(blinkDel);
    }
    gameMode = true;
  }
}

void winnerBlink()//THE BLINK FUNCTION FOR IF A WINNER IS TRUE
{
  int blinkList[lightNums-1];
  for(int i = 1; i < lightNums; i++)
  {
    blinkList[i-1] = led[i];
  }

  //BLINKING
  for(int r = 0; r < 1; r++)
  {
    //ALL ON
    for(int i = 0; i < lightNums; i++)
    {
      digitalWrite(blinkList[i], HIGH);
      delay(del-5);
    }
    //ALL OFF
    for(int i = 0; i < lightNums; i++)
    {
      digitalWrite(blinkList[i], LOW);
      delay(del-5);
    }
    digitalWrite(led[0], LOW);
  }
  if(level == lightNums)//IF YOU PASS ALL OF THE LEVELS
  {
    for(int r = 0; r < 10; r++)
    {
      for(int i = 0; i < lightNums; i++)
      {
        if(i % 2 == 0)
        {
          digitalWrite(led[i], HIGH);
        }
      }
      delay(400);
      allOff();
      gameEnd = true;
      for(int i = 0; i < lightNums; i++)
      {
        if(i % 2 != 0)
        {
          digitalWrite(led[i], HIGH);
        }
      }
      delay(400);
      allOff();
    }
  }
  
}
void levelUp()//LEVEL UP FUNCTION
{
  //BEGINS AT LEVEL 1
  for(int i = 1; i < level; i++)//TURNS ON THE PRECEDING LIGHTS
  {
    digitalWrite(led[i], HIGH);
  }
  for(int r = 0; r < 3; r++)//TURNS ON THE CURRENT LEVEL LIGHT
  {
    digitalWrite(led[level], HIGH);
    delay(blinkDel);
    digitalWrite(led[level], LOW);
    delay(blinkDel);
  }
    digitalWrite(led[level], HIGH);
    delay(700);
    digitalWrite(led[level], LOW);
  for(int i = 0; i < lightNums; i++)//TURNS OFF ALL THE LIGHTS
  {
    digitalWrite(led[i], LOW);
  }
  level++;//PREPS FOR NEXT LEVEL
}

void allOff()
{
  for(int i = 0; i < lightNums; i++)
  {
    digitalWrite(led[i], LOW);
  }
}
