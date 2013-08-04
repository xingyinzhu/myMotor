#include "MMotor.h"
//#include "SR04.h"

MMotor::MMotor(void)
{
}

void MMotor::setParam(int _e1,int _e2,int _m1,int _m2)
{
	M_E1 = _e1;
	M_E2 = _e2;
	M_M1 = _m1;
	M_M2 = _m2;
	pinMode(M_M1, OUTPUT); 
    pinMode(M_M2, OUTPUT);
	pinMode(M_E1, OUTPUT);
	pinMode(M_E2, OUTPUT);
}

void MMotor::forward(int _speed)
{		
	digitalWrite(M_M1,LOW); 
	digitalWrite(M_M2,LOW);

	analogWrite(M_E1, _speed);
	analogWrite(M_E2, _speed);
	delay(100);
	//stop();
}

void MMotor::back(int _speed)
{
	digitalWrite(M_M1,HIGH); 
	digitalWrite(M_M2,HIGH);

	analogWrite(M_E1, _speed);
	analogWrite(M_E2, _speed);

	delay(100);
}

void MMotor::stop()
{
	analogWrite(M_E1, 0);
	analogWrite(M_E2, 0);

	digitalWrite(M_M1,LOW); 
	digitalWrite(M_M2,LOW);
}

void MMotor::right(int _speed)
{
	digitalWrite(M_M1,LOW); 
	digitalWrite(M_M2,LOW);

	analogWrite(M_E1, 0);
	analogWrite(M_E2, _speed);

	delay(100);
}

void MMotor::left(int _speed)
{
	digitalWrite(M_M1,LOW); 
	digitalWrite(M_M2,LOW);

	analogWrite(M_E1, _speed);
	analogWrite(M_E2, 0);

	delay(100);
}

void MMotor::leftback(int _speed)
{
	digitalWrite(M_M1,HIGH); 
	digitalWrite(M_M2,HIGH);

	analogWrite(M_E1, _speed);
	analogWrite(M_E2, 0);

	delay(100);
}

void MMotor::rightback(int _speed)
{
	digitalWrite(M_M1,HIGH); 
	digitalWrite(M_M2,HIGH);

	analogWrite(M_E1, 0);
	analogWrite(M_E2, _speed);
	delay(100);
}

MMotor::~MMotor(void)
{
}
