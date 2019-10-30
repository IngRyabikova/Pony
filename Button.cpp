#include "TXLib.h"


struct MenuButton
{
    HDC baton;

    int x1;
    int x2;
    int y1;
    int y2;
    const char* text;
    int shirina;
    int vysota;
    char* Kategorya;

    void drawButton()
    {
        txSelectFont("Arial", 30);
        Win32::TransparentBlt(txDC(), x1,   y1, x2 - x1, y2-y1, baton, 0, 0, shirina, vysota, TX_BLACK);
        txDrawText      (x1, y1, x2, y2, text);
    }


    bool Click()
    {
        if (txMouseButtons() == 1 &&
                txMouseX() > x1  &&
                txMouseX() < x2 &&
                txMouseY() > y1  &&
                txMouseY() < y2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
