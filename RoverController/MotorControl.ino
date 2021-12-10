#define SPEED_HIGH 96
#define SPEED_HALF 64
#define SPEED_QUART 32
#define SPEED_LOW 18

void SetStop(int d)
{
  SetBrake(0,0);
//  SetSpeed(0, true, 0);
  SetBrake(1,0);
//  SetSpeed(1, true, 0);
  delay(d);
}

void ForwardAccel(int d)
{
  SetAccel(0, true, SPEED_LOW);
  SetAccel(1, true, SPEED_LOW);
  delay(d);
}

void BackwardAccel(int d)
{
  SetAccel(0, false, SPEED_LOW);
  SetAccel(1, false, SPEED_LOW);
  delay(d);
}

void SteerRightAccel(int d)
{
  SetAccel(0, true, SPEED_LOW);
  SetAccel(1, true, 0);
  SetBrakeAccel(1,0);
  delay(d);
}

void SteerLeftAccel(int d)
{
  SetBrakeAccel(0,0);
  SetAccel(0, true, 0);
  SetAccel(1, true, SPEED_LOW);
  delay(d);
}

void Forward(int d)
{
  SetSpeed(0, true, SPEED_LOW); 
  SetSpeed(1, true, SPEED_LOW);
  delay(d);
}

void Backward(int d)
{
  SetSpeed(0, false, SPEED_LOW);
  SetSpeed(1, false, SPEED_LOW);
  delay(d);
}

void SteerLeft(int d)
{
  SetSpeed(0, true, 0);
  SetBrake(0,0);
  SetSpeed(1, true, SPEED_LOW);
  delay(d);
}

void SteerRight(int d)
{
  SetSpeed(0, true, SPEED_LOW);
  SetSpeed(1, true, 0);
  SetBrake(1,0);
  delay(d);
}

void SetBrake(int MotorIndex, int Speed)
{
  if(MotorIndex < 0 || MotorIndex > 2)
    return;

  if(Speed < 0)
    Speed = 0;
  else if(Speed > 127)
    Speed = 127;
    
  unsigned char SendByte = 0;
  if(MotorIndex == 0)
    SendByte = 0xC3; // set motor1 0xC0
  else if(MotorIndex == 1)
    SendByte = 0xCB; // set motor2 0xC8

  trex.write(SendByte);
  trex.write(Speed);
}

void SetBrakeAccel(int MotorIndex, int Speed)
{
  if(MotorIndex < 0 || MotorIndex > 2)
    return;

  if(Speed < 0)
    Speed = 0;
  else if(Speed > 127)
    Speed = 127;
    
  unsigned char SendByte = 0;
  if(MotorIndex == 0)
    SendByte = 0xC7;
  else if(MotorIndex == 1)
    SendByte = 0xCF;

  trex.write(SendByte);
  trex.write(Speed);
}

void SetSpeed(int MotorIndex, boolean Forward, int Speed)
{
  // Validate motor index
  if(MotorIndex < 0 || MotorIndex > 2)
    return;

  // Validate speed
  if(Speed < 0)
    Speed = 0;
  else if(Speed > 127)
    Speed = 127;

  // Send the "set" command based on the motor
  // Note that we do not accelerate to the
  // speed, we just instantly set it
  unsigned char SendByte = 0;
  if(MotorIndex == 0)
    SendByte = 0xC2; // set motor1 0xC0-0xC3
  else if(MotorIndex == 1)
    SendByte = 0xCA; // set motor2 0xC8-0xCB
  else if(MotorIndex == 2)
    SendByte = 0xF0; // set aux motor

  // If we go backwards, the commands are the same
  // but minus one
  if(!Forward)
    SendByte--;

  // Send the set speed command byte
  trex.write(SendByte);
  // Send the speed data byte
  trex.write(Speed);
}

void SetAccel(int MotorIndex, boolean Forward, int Speed)
{
  // Validate motor index
  if(MotorIndex < 0 || MotorIndex > 2)
    return;

  // Validate speed
  if(Speed < 0)
    Speed = 0;
  else if(Speed > 127)
    Speed = 127;
    
  unsigned char SendByte = 0;
  if(MotorIndex == 0)
    SendByte = 0xC6; // set motor1 0xC4-0xC7
  else if(MotorIndex == 1)
    SendByte = 0xCE; // set motor2 0xCC-0xCF
  else if(MotorIndex == 2)
    SendByte = 0xF1; // set aux motor
  
  // If we go backwards, the commands are the same
  // but minus one
  if(!Forward)
    SendByte--;

  // Send the set speed command byte
  trex.write(SendByte);
  // Send the speed data byte
  trex.write(Speed);
}
