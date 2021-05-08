

void Contract(int ActiveWire, int ChosenHighPWM) {
  analogWrite(ActiveWire, ChosenHighPWM);

  if (serialMonitor) {
    Serial.print("\nContracting ");
    if (ActiveWire == LeftHip) {
      Serial.print("Left Hip");
    } else if (ActiveWire == RightHip) {
      Serial.print("Right Hip");
    }  else if (ActiveWire == LeftKnee) {
      Serial.print("Left Knee");
    } else {
      Serial.print("Right Knee");
    }
    Serial.print(" at ");
    Serial.println(ChosenHighPWM);
  }




}
