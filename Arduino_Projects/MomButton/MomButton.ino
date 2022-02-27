const int red = 7;
const int green = 11;
const int button = 4;
boolean redLed = true;
boolean greenLed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT_PULLUP);

 // digitalWrite(red, HIGH);

}

void loop() 
{
  if(redLed)                  //RED LIGHT
  {
    digitalWrite(red, HIGH);
  }
  else
  {
    digitalWrite(red, LOW);
  }
  if(greenLed)                //GREEN LIGHT
  {
    digitalWrite(green, HIGH);
  }
  else
  {
    digitalWrite(green, LOW);
  }
  if(push())
  {
    changeColor();
    Serial.println("Pushed");
    delay(500);
  }
}

boolean push()
{
  return !digitalRead(button);
}

void changeColor()    //BOTH LIGHTS CHANGE STATES
{  
    redLed = !redLed;
    greenLed = !greenLed;
}
