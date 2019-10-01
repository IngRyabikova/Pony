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

    void drawMapObject2()
    {
        Win32::TransparentBlt(txDC(), x,  y, x2 - x, y2 - y, picture, 0, 0, 600, 400, TX_WHITE);
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
        Win32::TransparentBlt(txDC(), x1,   y1, x2 - x1, y2-y1, baton, 0, 0, 530, 140, TX_WHITE);
        txDrawText      (x1, y1, x2, y2, text);
    }
};

int main()
    {
    txCreateWindow(1200, 700);
    HDC  poni = txLoadImage ("Pictures/pony/unicorn.bmp");
    HDC  baton = txLoadImage ("Pictures/Menu_Button.bmp");
    HDC  head = txLoadImage ("Pictures/Head/Head.bmp");

    MenuButton buttons[5];
    buttons[0] = {baton, 0,400,  0, 90,"онмх"};
    buttons[1] = {baton, 0,400, 90,180,"убняр"};
    buttons[2] = {baton, 0,400,180,270,"йношрю"};
    buttons[3] = {baton, 0,400,270,360,"цнкнбю"};
    buttons[4] = {baton, 0,400,360,450,"рекн"};

    MapObject vybor_pony[3];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp")};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp")};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp")};
    bool vid = false;

    MapObject pic[2];
    pic[0] = {500, 100, 900, 500, poni};
    pic[1] = {500, 100, 900, 300, head};
    bool visible = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        for (int nomer_knopki = 0; nomer_knopki < 5; nomer_knopki++)
        {
            buttons[nomer_knopki].drawButton();
        }

        pic[0].drawMapObject();
        if(visible)
        {
            pic[1].drawMapObject();
        }


        /*for (int nomer_kart = 0; nomer_kart < 2; nomer_kart++)
        {
            pic[nomer_kart].drawMapObject();
        } */

        if (vid)
        {
            vybor_pony[0].drawMapObject2();
            vybor_pony[1].drawMapObject2();
            vybor_pony[2].drawMapObject2();
        }

        if (txMouseButtons() & 1 &&
            txMouseX() >= buttons[0].x1 &&
            txMouseX() <= buttons[0].x2 &&
            txMouseY() >= buttons[0].y1 &&
            txMouseY() <= buttons[0].y2)
        {
            visible = true;
        }

        if  (txMouseButtons() & 1 &&
            txMouseX() >= buttons[1].x1 &&
            txMouseX() <= buttons[1].x2 &&
            txMouseY() >= buttons[1].y1 &&
            txMouseY() <= buttons[1].y2)
        {
            vid = true;
        }

        txSleep(10);
        txEnd();
    }


    txDeleteDC (vybor_pony[0].picture);
    txDeleteDC (vybor_pony[1].picture);
    txDeleteDC (vybor_pony[2].picture);
    txDeleteDC (pic[0].picture);
    txDeleteDC (pic[1].picture);
    txDeleteDC (baton);

    return 0;
}
