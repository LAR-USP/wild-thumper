#include <SoftwareSerial.h>
#include <ros.h>
#include <std_msgs/Int32.h>

#define TXPIN 4
#define RXPIN 5
SoftwareSerial trex(RXPIN, TXPIN);
ros::NodeHandle nh;
unsigned int direct = 0;
bool bSteered = false;

void motorCb(const std_msgs::Int32& msg)
{
  int data = msg.data;
  if (!bSteered) {
    switch(data){
    case 0: // go forward
        Forward(300);
    break;
    case 1: // turn right 
        bSteered = true;
        SteerRight(1600);
        bSteered = false;
    break;
    case 2: // turn left
        bSteered = true;
        SteerLeft(1600);
        bSteered = false;
    break;
    case 3: // backward
        Backward(300);
    case 4: // stop
        SetStop(100);
    break;
    default:
        SetStop(100);
    break;
    }
  }
}

ros::Subscriber<std_msgs::Int32> sub("pololu/move", &motorCb);

void setup() {
  pinMode(RXPIN, INPUT);
  pinMode(TXPIN, OUTPUT);
  trex.begin(19200);
  nh.initNode();
  nh.subscribe(sub);
  delay(5);
}

void loop() {
  nh.spinOnce();
  delay(10);
}
