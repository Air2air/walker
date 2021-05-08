


void Stride(int Hip, int Knee, int PWMHigh) {

  int PWMHip = PWMHigh;
  int PWMKnee = PWMHigh;

  int OppositeHip;
  int OppositeKnee;


  /* ---- Bias Adjustments ----*/
  if (Hip == LeftHip) {
    PWMHip = PWMHigh * BiasLeftHip;
  } else {
    PWMHip = PWMHigh * BiasRightHip;
  }

  if (Knee == LeftKnee) {
    PWMKnee = PWMHigh * BiasLeftKnee;
  } else {
    PWMKnee = PWMHigh * BiasRightKnee;
  }

  /* ---- Opposite ----*/

  //  if (Hip == LeftHip) {
  //    OppositeHip = RightHip;
  //  } else if (Hip == RightHip) {
  //    OppositeHip = LeftHip;
  //  }
  //
  //  if (Knee == LeftKnee) {
  //    OppositeKnee = RightKnee;
  //  } else if (Knee == RightKnee) {
  //    OppositeKnee = LeftKnee;
  //  }



  if (serialMonitor) {
    Serial.print("\n------------------------ Start New Leg ---------------------");

    Serial.print("\nCurrent Hip: pin ");
    Serial.print(Hip);

    if (Hip == LeftHip) {
      Serial.println(", Left Hip");
    } else {
      Serial.println(", Right Hip");
    }

    Serial.print("Current Knee: pin ");
    Serial.print(Knee);

    if (Knee == LeftKnee) {
      Serial.println(", Left Knee");
    } else {
      Serial.println(", Right Knee");
    }


    //    Serial.print("\nOpposite Hip: pin ");
    //    Serial.print(OppositeHip);
    //
    //    if (OppositeHip == LeftHip) {
    //      Serial.println(", Left Hip");
    //    } else {
    //      Serial.println(", Right Hip");
    //    }
    //
    //    Serial.print("Opposite Knee: pin ");
    //    Serial.print(OppositeKnee);
    //
    //    if (OppositeKnee == LeftKnee) {
    //      Serial.println(", Left Knee");
    //    } else {
    //      Serial.println(", Right Knee");
    //    }

  }

  RampUp(Knee, PWMKnee);

  Contract(Knee, PWMKnee);

  delay(ContractionTime);

  RampUp(Hip, PWMHip);
  RampDown(Knee, PWMKnee);

  delay(KneeSwitchDelay);

  //RampUp(OppositeKnee, PWMKnee);// Ramp Up New Knee before Ramping down old Hip

  RampDown(Hip, PWMHip);

  delay(HipSwitchDelay);


}

void GaitFast(int Loops) {
  {
    for ( int x = 0; x < Loops; x++ )
    {
      Serial.print("\nLoop number ");
      Serial.print(x + 1);
      Serial.print(" of ");
      Serial.print(Loops);
      Serial.println(".");
      Stride(RightHip, RightKnee, PWMHigh);
      Stride(LeftHip, LeftKnee, PWMHigh);
    }
  }
}
