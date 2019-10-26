#include "TXLib.h"

struct MapObject
{
    int x;
    int y;
    int x2;
    int y2;
    string adress;
    const char* Kategorya;
    HDC picture;
    int srk_width;
    int srk_height;
    bool visible;
    bool najatieKartinki;

    void drawMapObject()
    {
        txBitBlt(txDC(), x,  y, x2 - x, y2 - y, picture);
    }

    void drawMapObject2()
    {
        Win32::TransparentBlt(txDC(), x,  y, x2 - x, y2 - y, picture, 0, 0, srk_width, srk_height, TX_WHITE);
    }

      bool Click()
    {
        if (txMouseButtons() == 1 &&
                txMouseX() > x  &&
                txMouseX() < x2 &&
                txMouseY() > y  &&
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

