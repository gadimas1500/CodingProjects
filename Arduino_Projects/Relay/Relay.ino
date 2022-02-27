const int photo = A0;
const int light = 12;
const int relay = 4;
const int waterLevel = A1;
int temp;

void setup() {
  // put your setup code here, to run once:
  pinMode(light, OUTPUT);
  pinMode(relay, OUTPUT);
 Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Iteration: ");
  Serial.print(temp);
  Serial.print("  --> ");
  Serial.println(analogRead(photo));
  Serial.println("\t");
  Serial.print(analogRead(waterLevel));
  Serial.println();
  temp++;
  delay(300);
  if(analogRead(photo) < 250)
  {
    digitalWrite(light, HIGH);
    digitalWrite(relay, HIGH);
  }
  else
  {
    digitalWrite(light, LOW);
    digitalWrite(relay, LOW);
  }
 
}
