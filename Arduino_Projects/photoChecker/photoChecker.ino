const int photo = A5;
const int led = 11;
int val;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(photo);
  Serial.println(val);
  if(val < 1000)
  {
    ledBlink();
  }
  else
  {
    digitalWrite(led, LOW);
    delay(200);
  }
}

void ledBlink()
{
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}














/*int light = 0; // store the current light value

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600); //configure serial to talk to computer
    pinMode(44, OUTPUT); // configure digital pin 13 as an output
}

void loop() {
    // put your main code here, to run repeatedly:
    light = analogRead(A0); // read and save value from PR
    
    Serial.println(light); // print current light value
 
    if(light > 450) { // If it is bright...
        Serial.println("It is quite light!");
        digitalWrite(44,LOW); //turn left LED off
    }
    else if(light > 229 && light < 451) { // If it is average light...
        Serial.println("It is average light!");
       digitalWrite(44, HIGH); // turn left LED on
    }
    else { // If it's dark...
        Serial.println("It is pretty dark!");
        digitalWrite(44,HIGH); // Turn left LED on
    }
    delay(1000); // don't spam the computer!
}*/
