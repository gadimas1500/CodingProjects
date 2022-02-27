int led[12];
const int del = 80;
const int len = 12;
int circle[] = {0, 2, 4, 6, 8, 10, 11, 9, 7, 5, 3, 1};
int half1[] = {0, 4, 8, 11, 7, 3};
int half2[] = {2, 6, 10, 9, 5, 1};
void setup() {
  int temp = 2;
  for(int i = 0; i < 12; i++)
  {
    led[i] = temp;
    pinMode(led[i], OUTPUT);
    temp++;
  }
}

void loop() 
{
  
  symmetryOn();
  delay(50);
  symmetryOff();
  delay(del);
  blinker(3);
  delay(del);
  allOn();
  delay(del);
  symmetryGhostLight();
  delay(del);
  allOn();
  singleGhostLight();
  delay(del);
  allOff();
  delay(500);
  singleFlowLight();
  delay(500);
  //halfAndHalf();
  delay(500);
  allOn();
  delay(5000);
  delay(5000);
  
  
  
}

void allOn()
{
  for(int i = 0; i < len; i++)
  {
    digitalWrite(led[i], HIGH);
  }
}

void allOff()
{
  for(int i = 0; i < len; i++)
  {
     digitalWrite(led[i], LOW);
  }  
}

void symmetryOn()
{
  for(int i = 0; i < len; i++)
  {
    digitalWrite(led[i], HIGH);
    digitalWrite(led[i+1], HIGH);
    delay(del);
  }
}

void symmetryOff()
{
  for(int i = 0; i < len; i++)
    {
      digitalWrite(led[i], LOW);
      delay(del);
    }
}

void blinker(int blinks)
{
  for(int i = 0; i < blinks; i++)
  {
    for(int r = 0; r < len; r++)
    {
      digitalWrite(led[r], HIGH);
    }
    delay(300);
    for(int r = 0; r < len; r++)
    {
      digitalWrite(led[r], LOW);
    }
    delay(300);
  }
}

void symmetryGhostLight()
{
  for(int r = 0; r < 3; r++)
  {
    for(int i = 0; i < len; i++)
    {
      if(i != 0)
          {
          if(i != 11)
            {
              digitalWrite(led[i], LOW);
              digitalWrite(led[i+1], LOW);
              delay(200);
              digitalWrite(led[i], HIGH);
              digitalWrite(led[i+1], HIGH);
              delay(200);
              i++;
            }
            else if(i == 11)
            {
              digitalWrite(led[i], LOW);
              delay(200);
              digitalWrite(led[i], HIGH);
              delay(200);
            }
          }
      else
      {
        digitalWrite(led[i], LOW);
        delay(200);
        digitalWrite(led[i], HIGH);
        delay(200);
      }
    }

  }
}

void singleGhostLight()
{
  for(int r = 0; r < 4; r++)
  {
      for(int i = 0; i < len; i++)
      {
        if(i != 0)
        {
          digitalWrite(led[circle[i]], LOW);
          delay(100);
          digitalWrite(led[circle[i]], HIGH);
        }
        else if( i == 0)
        {
          digitalWrite(led[i], LOW);
          delay(100);
          digitalWrite(led[i], HIGH);
        }
      }
      digitalWrite(led[0], HIGH);
  }
}

void singleFlowLight()
{
    for(int r = 0; r < 4; r++)
      {
          for(int i = 0; i < len; i++)
          {
            if(i != 0)
            {
              digitalWrite(led[circle[i]], HIGH);
              delay(100);
              digitalWrite(led[circle[i]], LOW);
            }
            else if( i == 0)
            {
              digitalWrite(led[i], HIGH);
              delay(100);
              digitalWrite(led[i], LOW);
            }
          }
          digitalWrite(led[0], LOW);
  }
}

void halfAndHalf()
{
  for(int i = 0; i < 3; i++)
  {
    for(int r = 0; r < 6; r++)
    {
      digitalWrite(led[half1[r]], HIGH);
    }
    delay(400);
    for(int r = 0; r < 6; r++)
    {
      digitalWrite(led[half1[r]], LOW);
    }
    for(int r = 0; r < 6; r++)
    {
      digitalWrite(led[half2[r]], HIGH);
    }
    delay(400);
    for(int r = 0; r < 6; r++)
    {
      digitalWrite(led[half2[r]], LOW);
    }
    
  }
}
