
void RampDown(int Pin, int ChosenHighPWM) {

  int ActiveWire = Pin;

  if (serialMonitor) {
    Serial.print("\nRamping Down ");
    if (ActiveWire == LeftHip) {
      Serial.print("Left Hip");
    } else if (ActiveWire == RightHip) {
      Serial.print("Right Hip");
    }  else if (ActiveWire == LeftKnee) {
      Serial.print("Left Knee");
    } else {
      Serial.print("Right Knee");
    }
        Serial.print(" from ");
    Serial.print(ChosenHighPWM);
  }

  

  for (int motorValue = ChosenHighPWM; motorValue >= LowPWM; motorValue -= RampDownIncrement) {
    analogWrite(ActiveWire, motorValue);
    delay(RampDownIncrementDuration);
    if (serialLoop) {
      Serial.print("PWM: ");
      Serial.print(motorValue);
      Serial.print("\tIncrement ");
      Serial.print(RampDownIncrement);
      Serial.print("\tIncrement Duration ");
      Serial.print(RampDownIncrementDuration);
      Serial.println("ms");
    }
  }


  if (serialMonitor) {
    Serial.println("\t\tCompleted.");
  }

}
