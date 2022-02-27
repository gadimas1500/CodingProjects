const int sound = 6;
int lights[22];
const int numLights = 22;
const int start = 22;
int freq;
const int del = 40;
void setup() {
  // put your setup code here, to run once:
  pinMode(sound, OUTPUT);
  for(int i = 0; i < numLights; i++)
  {
    lights[i] = i+start;
    pinMode(lights[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
     for(int i = 0; i < numLights; i++)
    {
      digitalWrite(lights[i], HIGH);
      freq = 600*i;
      tone(sound, freq);
      delay(del);
    }
    noTone(sound);
    delay(500);
    for(int i = lights[numLights-1]; i >= 0; i--)
    {
      digitalWrite(lights[i], LOW);
      tone(sound, freq);
      freq = freq/(i+1);
      delay(del);
    }
    noTone(sound);
    delay(1000);

  
}
