#include "openJoystick-Win.h"
#include <windows.h>
#include <xinput.h>
#include <stdbool.h>

char updateState(int n,XINPUT_STATE *state)
{
    DWORD dwResult;
    if(n<0||n>4)
    {
        state=NULL;
        return 1;
    }
    ZeroMemory( state, sizeof(XINPUT_STATE) );

    // Simply get the state of the controller from XInput.
    dwResult = XInputGetState( n, state );

    if( dwResult == ERROR_SUCCESS )
    {
        // Controller is connected
        return 0;
    }

    return -1;

}

short getAxisLX(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.sThumbLX;
    return 0;
}

short getAxisLY(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.sThumbLY;
    return 0;
}

short getAxisRX(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.sThumbRX;
    return 0;
}

short getAxisRY(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.sThumbRY;
    return 0;
}

unsigned char getAxisLT(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.bLeftTrigger;
    return -1;
}

unsigned char getAxisRT(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.bRightTrigger;
    return -1;
}

//#include <stdio.h>
bool isButtonX(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        /*char s[10000];
        itoa(state.Gamepad.wButtons,s,2);
        printf("0x%hX-%s ",state.Gamepad.wButtons,s);*/
        return state.Gamepad.wButtons & 0x4000;
    }
    return 0;
}

bool isButtonY(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x8000;
    }
    return 0;
}

bool isButtonA(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x1000;
    }
    return 0;
}

bool isButtonB(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x2000;
    }
    return 0;
}

bool isButtonDPADup(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0001;
    }
    return 0;
}

bool isButtonDPADdown(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0002;
    }
    return 0;
}

bool isButtonDPADleft(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0004;
    }
    return 0;
}

bool isButtonDPADright(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0008;
    }
    return 0;
}

bool isButtonSTART(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0010;
    }
    return 0;
}

bool isButtonBACK(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0020;
    }
    return 0;
}

bool isButtonLEFTthumb(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0040;
    }
    return 0;
}

bool isButtonRIGHTthumb(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0080;
    }
    return 0;
}

bool isButtonLEFTshoulder(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0100;
    }
    return 0;
}

bool isButtonRIGHTshoulder(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0200;
    }
    return 0;
}

unsigned int listJoysticks(int a[])
{
    int count=0,i;
    XINPUT_STATE state;
    for(i=0;i<4;i++)
        if(updateState(i,&state)==0)
            a[count++]=i;
    return count;
}
