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
        txTransparentBlt(txDC(), x1,   y1, x2 - x1, y2-y1, baton, 0,0 ,TX_WHITE);
        txDrawText      (x1, y1, x2, y2, text);
    }
};

int main()
    {
    txCreateWindow(1200, 700);
    HDC  poni = txLoadImage ("Pictures/pony/unicorn.bmp");
    HDC  baton = txLoadImage ("Pictures/Menu_Button.bmp");
    HDC  head = txLoadImage ("Pictures/Head.bmp");

    MenuButton b[5];
    b[0] = {baton, 0,530,  0,130,"ÏÎÍÈ"};
    b[1] = {baton, 0,530,130,260,"ÕÂÎÑÒ"};
    b[2] = {baton, 0,530,260,390,"ÊÎÏÛÒÀ"};
    b[3] = {baton, 0,530,390,520,"ÃÎËÎÂÀ"};
    b[4] = {baton, 0,530,520,650,"ÒÅËÎ"};

    MapObject vybor_pony[3];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp")};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp")};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp")};
    bool vid = false;

    MapObject pic[2];
    pic[0] = {600,  0,1000,400,poni};
    pic[1] = {600,  0,1000,200,head};
    bool visible = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        for (int nomer_knopki = 0; nomer_knopki < 5; nomer_knopki++)
        {
            b[nomer_knopki].drawButton();

        }

        pic[0].drawMapObject();
        if(visible)
        {
         pic[1].drawMapObject();
        }


        /*for (int nomer_kart = 0; nomer_kart < 2; nomer_kart++)
        {
            pic[nomer_kart].drawMapObject();
        }

        if (vid)
        {
            vybor_pony[0].drawMapObject2();
            vybor_pony[1].drawMapObject2();
            vybor_pony[2].drawMapObject2();
        }

        //drawButton(0, 0, baton,   "ÏÎÍÈ"  ) ;
        /*drawButton(0, 130, baton, "ÕÂÎÑÒ" ) ;
        drawButton(0, 260, baton,"ÊÎÏÛÒÀ" ) ;
        drawButton(0, 390, baton,"ÃÎËÎÂÀ" ) ;
        drawButton(0, 520, baton, "ÒÅËÎ"  ) ;    */

        if (txMouseButtons() & 1 &&
            txMouseX() >= 100 &&
            txMouseX() <= 530 &&
            txMouseY() >=   0 + 30 &&
            txMouseY() <= 140 - 45)
        {
            visible = true;
        }

        if  (txMouseButtons() & 1 &&
            txMouseX() >= 100 &&
            txMouseX() <= 530 &&
            txMouseY() >=   0 + 30 &&
            txMouseY() <= 140 - 45)

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
    txDeleteDC (baton);

    return 0;
}