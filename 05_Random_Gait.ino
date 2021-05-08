
long RandSelection;

int ChooseGait() {

  RandSelection = random(0, 30);

  if (UseRandomGait) {

    if (RandSelection <= 10)
    {
      Serial.print("\nRunning 1 Stride and stopping for ");
      Serial.print(StridePause);
      Serial.println("ms.");
      GaitFast(1);
    }

    else if ((RandSelection > 10) && (RandSelection <= 20))

    {
      Serial.print("\nRunning 2 Strides and stopping for ");
      Serial.print(StridePause);
      Serial.println("ms.");
      GaitFast(2);
    }

    else if ((RandSelection > 20) && (RandSelection <= 30))

    {
      Serial.print("\nRunning 3 Strides and stopping for ");
      Serial.print(StridePause);
      Serial.println("ms.");
      GaitFast(3);
    }

  } else {
    Serial.println("\nNot running Random, running Fast.");
    GaitFast(3);
  }




  if (serialMonitor) {
    Serial.println("\n\n&&&&&&&&&&&&&&  Movement Ended  &&&&&&&&&&&&&&");
    Serial.print("\nWill wait for ");
    Serial.print(StridePause);
    Serial.println("ms now.");
  }

  analogWrite(LeftHip, 0);
  analogWrite(LeftKnee, 0);
  analogWrite(RightHip, 0);
  analogWrite(RightKnee, 0);

  delay(StridePause);

  if (serialMonitor) {
    Serial.print("\nWaited ");
    Serial.print(StridePause);
    Serial.println("ms and resuming.");

    if (UseRandomGait) {
      Serial.print("For next loop - RandomRange: ");
      Serial.print(RandSelection);
      Serial.println(".\n");
    } else {
      Serial.print("Not Using Random Gait");
    }
  }

  Serial.println("\n\n&&&&&&&&&&&&&&  Loop Ended  &&&&&&&&&&&&&&");

}
