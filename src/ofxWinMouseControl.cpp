#include "ofxWinMouseControl.h"

ofxWinMouseControl::ofxWinMouseControl()
{
    //ctor
}

ofxWinMouseControl::~ofxWinMouseControl()
{
    //dtor
}

void ofxWinMouseControl::leftMouseDown()
{
 INPUT    Input= {0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    SendInput(1,&Input,sizeof(INPUT));
    _isLeftPressed=true;
    ZeroMemory(&Input,sizeof(INPUT));
}

void ofxWinMouseControl::leftMouseUp()
{
     INPUT    Input= {0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    SendInput(1,&Input,sizeof(INPUT));
    _isLeftPressed=false;
    ZeroMemory(&Input,sizeof(INPUT));
}

bool ofxWinMouseControl::isLeftPressed()
{
    return _isLeftPressed;
}

void ofxWinMouseControl::leftMouseClick()
{
    leftMouseDown();
    leftMouseUp();
}

void ofxWinMouseControl::rightMouseDown()
{
     INPUT    Input= {0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1,&Input,sizeof(INPUT));
    ZeroMemory(&Input,sizeof(INPUT));
}

void ofxWinMouseControl::rightMouseUp()
{
     INPUT    Input= {0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
    SendInput(1,&Input,sizeof(INPUT));
    ZeroMemory(&Input,sizeof(INPUT));
}

void ofxWinMouseControl::rightMouseClick()
{
    rightMouseDown();
    rightMouseUp();
}

void ofxWinMouseControl::leftMouseDoubleClick()
{
    for(int clicks=0;clicks<2;clicks++){
    leftMouseClick();
    }
}

void ofxWinMouseControl::moveMouse(int x, int y)
{
 INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.mouseData = 0;
    Input.mi.dx =  x*(65536/GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
    Input.mi.dy =  y*(65536/GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
    Input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
    SendInput(1,&Input,sizeof(INPUT));
    ZeroMemory(&Input,sizeof(INPUT));
}
