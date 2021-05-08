
/*---------- serialMonitor -----------*/
bool serialMonitor = 1;
bool serialLoop = 0;

/*---------- Pin Assignment ----------- */
byte LeftHip = 9;
byte RightHip = 11;

byte LeftKnee = 5;
byte RightKnee = 10;

/*---------- Bias Adjustment ----------- */
float BiasLeftHip = 1;
float BiasRightHip = 1;

float BiasLeftKnee = .7;
float BiasRightKnee = 1.4;

/*---------- Use Random  -----------*/
const bool UseRandomGait = 0;
const int StridePause = 8000;// Pause time between strides if random gait

/*---------- Ramp -----------*/
const byte RampUpIncrement = 1;//1
const byte RampUpIncrementDuration = 40;//80;

const byte RampDownIncrement = 1;//2
const byte RampDownIncrementDuration = 130;//20;

/*---------- PWM  -----------*/
const int PWMHigh = 20;//18
const int LowPWM = 0;

/*---------- Timing ---------*/
const int ContractionTime = 100;
const int KneeSwitchDelay = 2000;//3000 Increases stride length: Delay between starting knee rampdown and opposite knee start
const int HipSwitchDelay = 0;//3000 Delay between hip rampdown and loop end
