#ifndef OFXWINMOUSECONTROL_H
#define OFXWINMOUSECONTROL_H
#define _WIN32_WINNT 0x05010100 //xp sp1<

#include <vector>
#include <windows.h>
#include <iostream>

class ofxMouseControl
{
    public:
        ofxMouseControl();
        void moveMouse(int x,int y);
        void leftMouseDown();
        void leftMouseUp();
        void leftMouseClick();
        void leftMouseDoubleClick();
        void rightMouseClick();
        void rightMouseDown();
        void rightMouseUp();
        bool isLeftPressed();
        virtual ~ofxWinMouseControl();
    protected:
    private:
    bool _isLeftPressed;
};

#endif OFXWINMOUSECONTROL_H
