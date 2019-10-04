#include "TXLib.h"

struct MapObject
{
    int x;
    int y;
    int x2;
    int y2;
    HDC picture;
    int srk_width;
    int srk_height;

    void drawMapObject()
    {
        txBitBlt(txDC(), x,  y, x2 - x, y2 - y, picture);
    }

    void drawMapObject2()
    {
        Win32::TransparentBlt(txDC(), x,  y, x2 - x, y2 - y, picture, 0, 0, srk_width, srk_height, TX_WHITE);
    }
};

#include "Button.cpp"
#include "MapObjects.cpp"

int main()
    {
    txCreateWindow(1200, 700);
  
    MenuButton buttons[5];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"ÏÎÍÈ", 530, 140};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"ÕÂÎÑÒ", 530, 140};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"ÊÎÏÛÒÀ", 530, 140};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"ÃÎËÎÂÀ", 530, 140};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"ÒÅËÎ", 530, 140};

    MapObject vybor_pony[3];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp")};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp")};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp")};
    bool vid = false;

    MapObject vybor_chasti[2];
    vybor_chasti[0] = {500, 100, 900, 500, txLoadImage ("Pictures/pony/unicorn.bmp")};
    vybor_chasti[1] = {500, 100, 900, 300, txLoadImage ("Pictures/Head/Head.bmp")};
    bool visible = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_GREEN);
        txClear();

        for (int nomer_knopki = 0; nomer_knopki < 5; nomer_knopki++)
        {
            buttons[nomer_knopki].drawButton();
        }

        vybor_chasti[0].drawMapObject2();
        if(visible)
        {
            vybor_chasti[1].drawMapObject2();
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

        if (buttons [0].Click())
        {
            visible = !visible;
            txSleep(200);
        }

        if (buttons [1].Click())
        {
            vid = !vid;
            txSleep(200);
        }

        txSleep(10);
        txEnd();
    }

    //Óäàëåíèå êàðòèíîê
    for (int i = 0; i <=2; i++)
    {
        txDeleteDC (vybor_pony[i].picture);
    }
    for (int i = 0; i <=1; i++)
    {
        txDeleteDC (vybor_chasti[i].picture);
    }

    return 0;
}
