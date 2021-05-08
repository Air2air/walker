

void setup( void )
{
  pinMode(LeftHip, OUTPUT);
  pinMode(LeftKnee, OUTPUT);
  pinMode(RightHip, OUTPUT);
  pinMode(RightKnee, OUTPUT);

  analogWrite(LeftHip, 0);
  analogWrite(LeftKnee, 0);
  analogWrite(RightHip, 0);
  analogWrite(RightKnee, 0);

  reseedRandom( &reseedRandomSeed );

  if (serialMonitor) {
    Serial.begin(115200);
    while (! Serial);
  }
}

unsigned long SeedValue = analogRead(A0);

void loop( void )
{
  ChooseGait();
}
