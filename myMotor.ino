#include "MMotor.h"
#include "SR04.h"
#include "Servo.h"


/**

*  蓝牙控制小车

*  BY YFRobot
*  //16进制数据（前进、后退、左转、右转、停止）
*  FORWARD = {(byte) 0xFF, 0x5A, 0x5B, 0x00, 0x01, (byte) 0xFF};
*  BACK    = {(byte) 0xFF, 0x5A, 0x5B, 0x00, 0x05, (byte) 0xFF};
*  STOP    = {(byte) 0xFF, 0x5A, 0x5B, 0x00, 0x03, (byte) 0xFF};
*  LEFT    = {(byte) 0xFF, 0x5A, 0x5B, 0x00, 0x02, (byte) 0xFF};
*  RIGHT   = {(byte) 0xFF, 0x5A, 0x5B, 0x00, 0x04, (byte) 0xFF};
*  LEFTBACK = {(byte) 0xFF, 0x5A, 0x5B, 0x00, 0x06, (byte) 0xFF};
*  RIGHTBACK = {(byte) 0xFF, 0x5A, 0x5B, 0x00, 0x07, (byte) 0xFF};
**/


char BT_val;
int BT_array[5];

/*for sr04 module */
#define TRIG_PIN 2
#define ECHO_PIN 3
/*for sr04 module */

/* for arduino summer*/
#define E1 5  //PWMA
#define M1 4  //DIRA
#define E2 6  //PWMB                     
#define M2 7  //DIRB
/* for arduino summer*/

#define servoPort 12

#define SPEED 200

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
MMotor motor;
Servo myservo;
bool forwardFlag = true;

void setup()
{
	Serial.begin(9600);
	motor.setParam(E1,E2,M1,M2);
	//attachInterrupt(1,detectDistance,CHANGE);
	//myservo.attach(servoPort);
}

void readData()
{
	for(int n=0;n<=5;n++)
	{
		BT_val = Serial.read();
		BT_array[n]=BT_val;
	}
}

void detectDistance()
{
	long dis = sr04.Distance();
	Serial.println(dis);

	if (dis < 10)
	{
		forwardFlag = false;
		motor.back(SPEED);
		delay(200);
		motor.stop();
	}
	else
	{
		forwardFlag = true;
	}
}

void turnAround()
{
	int pos;
	for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
	{                                  // in steps of 1 degree 
		myservo.write(pos);              // tell servo to go to position in variable 'pos' 
		delay(15);                       // waits 15ms for the servo to reach the position 
	}

	/*
	for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
	{                                
		myservo.write(pos);              // tell servo to go to position in variable 'pos' 
		delay(15);                       // waits 15ms for the servo to reach the position 
	} 
	*/
}

void loop()
{
	//turnAround();
	detectDistance();
	readData();	

	if(BT_array[0]==0XFFFFFFFF && BT_array[1]==0x5A && BT_array[2]==0x5B && BT_array[5]==0XFFFFFFFF)
	{
		switch (BT_array[3]=0x00)      //根据键值不同，执行不同的内容
		{
			case 0x00:
				switch(BT_array[4])  //根据数据位的值来进行选择执行不同的动作
				{
					case 0x01:
						//5cm
						if (forwardFlag == true)
						motor.forward(SPEED);
						break;
					case 2:
						motor.left(SPEED);
						break;
					case 3:
						motor.stop();
						break; 
					case 4:
						motor.right(SPEED);
						break;             
					case 5:
						motor.back(SPEED);
						break;
					case 6:
						motor.leftback(SPEED);
						break;
					case 7:
						motor.rightback(SPEED);
						break;
					default:
						break;
				}
				break;
		}
	}
}
