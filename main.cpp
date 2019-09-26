#include "TXLib.h"

struct MapObject
{
    int x;
    int y;
    int x2;
    int y2;
    HDC picture;

    void drawMapObject()
    {
        txBitBlt(txDC(), x,  y, x2 - x, y2 - y, picture);
    }
};

struct MenuButton
{
    HDC baton;

    int x1;
    int x2;
    int y1;
    int y2;
    const char* text;


    void drawButton()
    {

        txSelectFont("Arial", 30);
        txTransparentBlt(txDC(), x1,   y1, x2 - x1, y2-y1, baton, 0,0 ,TX_WHITE);
        txDrawText      (x1, y1, x2, y2, text);
    }
};

int main()
    {
    txCreateWindow(1200, 700);
    HDC  poni = txLoadImage ("Pictures/pony/unicorn.bmp");
    HDC  baton = txLoadImage ("Pictures/Menu_Button.bmp");

    MenuButton b[5];
    b[0] = {baton, 0,530,  0,130,"����"};
    b[1] = {baton, 0,530,130,260,"�����"};
    b[2] = {baton, 0,530,260,390,"������"};
    b[3] = {baton, 0,530,390,520,"������"};
    b[4] = {baton, 0,530,520,650,"����"};



    MapObject pic[2];
    pic[0] = {600,  0,800,250,poni};
    pic[1] = {700,200,900,550,poni};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();



        for (int nomer_knopki = 0; nomer_knopki < 5; nomer_knopki++)
        {
            b[nomer_knopki].drawButton();
        }

        for (int nomer_kart = 0; nomer_kart < 2; nomer_kart++)
        {
            pic[nomer_kart].drawMapObject();
        }


        //drawButton(0, 0, baton,   "����"  ) ;
        /*drawButton(0, 130, baton, "�����" ) ;
        drawButton(0, 260, baton,"������" ) ;
        drawButton(0, 390, baton,"������" ) ;
        drawButton(0, 520, baton, "����"  ) ;    */


        if (txMouseButtons() & 1 &&
            txMouseX() >= 100 &&
            txMouseX() <= 530 &&
            txMouseY() >=   0 + 30 &&
            txMouseY() <= 140 - 45)
        {
            txMessageBox("1", "2");
        }

        if  (txMouseX() >= 100 &&
            txMouseX() <= 530 &&
            txMouseY() >=   0 + 30 &&
            txMouseY() <= 140 - 45)
        {
            txTextOut(500, 50, "dsf");
        }

        txSleep(10);
    }


    //txDeleteDC (poni);
    txDeleteDC (baton);

    return 0;
}
