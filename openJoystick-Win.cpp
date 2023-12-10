#include "openJoystick-Win.h"
#include <windows.h>
#include <xinput.h>

char updateState(int n,XINPUT_STATE *state)
{
    DWORD dwResult;
    if(n<1||n>4)
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

char getAxisLT(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.bLeftTrigger;
    return -1;
}

char getAxisRT(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
        return state.Gamepad.bRightTrigger;
    return -1;
}

char isButtonX(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x4000;
    }
    return -1;
}

char isButtonY(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x8000;
    }
    return -1;
}

char isButtonA(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x1000;
    }
    return -1;
}

char isButtonB(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x2000;
    }
    return -1;
}

char isButtonDPADup(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0001;
    }
    return -1;
}

char isButtonDPADdown(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0002;
    }
    return -1;
}

char isButtonDPADleft(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0004;
    }
    return -1;
}

char isButtonDPADright(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0008;
    }
    return -1;
}

char isButtonSTART(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0010;
    }
    return -1;
}

char isButtonBACK(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0020;
    }
    return -1;
}

char isButtonLEFTthumb(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0040;
    }
    return -1;
}

char isButtonRIGHTthumb(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0080;
    }
    return -1;
}

char isButtonLEFTshoulder(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0100;
    }
    return -1;
}

char isButtonRIGHTshoulder(int n)
{
    XINPUT_STATE state;
    if(updateState(n,&state)==0)
    {
        return state.Gamepad.wButtons & 0x0200;
    }
    return -1;
}

unsigned int listJoysticks(int a[])
{
    int count=0;
    XINPUT_STATE state;
    for(int i=0;i<4;i++)
        if(updateState(i,&state)==0)
            a[count++]=i;
    return count;
}
