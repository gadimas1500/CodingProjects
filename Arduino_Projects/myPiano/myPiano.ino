const int buttA = 7;
const int led = 13;
const int sound = 3;
const int poten = A7;
boolean push;
int butt[5];
int val;
int output;

void setup() {
  for(int i = 8; i < 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  for(int i = 28; i < 33; i++)
  {
    butt[i-28] = i;
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(sound, OUTPUT);
}

void loop() {
  val = analogRead(poten);
  output = map(val, 50, 1000, 0 , 1023);
  int which = checkPush();  
  if(!digitalRead(butt[0]))
  {
    tone(sound, output-45);
    digitalWrite(8, HIGH);
  } else 
  {
    digitalWrite(8, LOW);
    noTone(sound);
  }

  if(!digitalRead(butt[1]))
  {
    tone(sound, output-30);
    digitalWrite(9, HIGH);
  } else 
  {
    digitalWrite(9, LOW);
    noTone(sound);
  }
  
  if(!digitalRead(butt[2]))
  {
    tone(sound, output); 
    digitalWrite(10, HIGH);
  } else 
  {
    digitalWrite(10, LOW);
    noTone(sound);
  }
  if(!digitalRead(butt[3]))
  {
    tone(sound, output+30);
    digitalWrite(11, HIGH);
  } else
  {
    digitalWrite(11, LOW);
    noTone(sound);
  }
  
  if(!digitalRead(butt[4]))
  {
    tone(sound, output+45);
    digitalWrite(12, HIGH);
  }else
  {
    digitalWrite(12, LOW);
    noTone(sound);
  }
  
}

int checkPush()
{
  
}
