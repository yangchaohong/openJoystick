#ifndef _OPENJOYSTICK_H_
#define _OPENJOYSTICK_H_

#include <stdbool.h>

short getAxisLX(int n);
short getAxisLY(int n);
short getAxisRX(int n);
short getAxisRY(int n);
unsigned char getAxisLT(int n);
unsigned char getAxisRT(int n);
bool isButtonX(int n);
bool isButtonY(int n);
bool isButtonA(int n);
bool isButtonB(int n);
bool isButtonDPADup(int n);
bool isButtonDPADdown(int n);
bool isButtonDPADleft(int n);
bool isButtonDPADright(int n);
bool isButtonSTART(int n);
bool isButtonBACK(int n);
bool isButtonLEFTthumb(int n);
bool isButtonRIGHTthumb(int n);
bool isButtonLEFTshoulder(int n);
bool isButtonRIGHTshoulder(int n);
unsigned int listJoysticks(int a[]);

#endif
