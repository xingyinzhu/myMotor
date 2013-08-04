#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
//Board = Arduino Uno
#define __AVR_ATmega328P__
#define ARDUINO 105
#define __AVR__
#define F_CPU 16000000L
#define __cplusplus
#define __attribute__(x)
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__
#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

//
void readData();
void detectDistance();
void turnAround();
//

#include "D:\arduino\hardware\arduino\variants\standard\pins_arduino.h" 
#include "D:\arduino\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\sse\Documents\Arduino\myMotor\myMotor.ino"
#include "C:\Users\sse\Documents\Arduino\myMotor\MMotor.cpp"
#include "C:\Users\sse\Documents\Arduino\myMotor\MMotor.h"
#include "C:\Users\sse\Documents\Arduino\myMotor\SR04.cpp"
#include "C:\Users\sse\Documents\Arduino\myMotor\SR04.h"
#endif