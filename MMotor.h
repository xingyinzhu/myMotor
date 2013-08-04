#pragma once
#ifndef Mmotor_h //防止多次引用头文件
#define Mmotor_h


#include "Arduino.h"

class MMotor
{
public:
	MMotor(void);
	void setParam(int _e1,int _e2,int _m1,int _m2);
	void forward(int _speed);
	void back(int _speed);
	void left(int _speed);
	void right(int _speed);
	void leftback(int _speed);
	void rightback(int _speed);
	void stop();
	~MMotor(void);

private:
	int M_E1;
	int M_E2;
	int M_M1;
	int M_M2;
};

#endif