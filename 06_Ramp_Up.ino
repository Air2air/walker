

void RampUp(int Pin, int ChosenHighPWM) {

  int ActiveWire = Pin;

  if (serialMonitor) {
    Serial.print("\nRamping Up ");
    if (ActiveWire == LeftHip) {
      Serial.print("Left Hip");
    } else if (ActiveWire == RightHip) {
      Serial.print("Right Hip");
    }  else if (ActiveWire == LeftKnee) {
      Serial.print("Left Knee");
    } else {
      Serial.print("Right Knee");
    }
    Serial.print(" to ");
    Serial.print(ChosenHighPWM);
  }

  for (int motorValue = LowPWM; motorValue <= ChosenHighPWM; motorValue += RampUpIncrement) {
    analogWrite(ActiveWire, motorValue);
    delay(RampUpIncrementDuration);
    if (serialLoop) {
      Serial.print("PWM: ");
      Serial.print(motorValue);
      Serial.print("\tIncrement ");
      Serial.print(RampUpIncrement);
      Serial.print("\tIncrement Duration ");
      Serial.print(RampUpIncrementDuration);
      Serial.println("ms");
    }
  }

  if (serialMonitor) {
    Serial.println("\t\tCompleted.");
  }

}
