#include "TXLib.h"

struct MapObject
{
    string adress;
    int x;
    int y;
    int x2;
    int y2;
    string Kategorya;
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

void risyemKChasti (int COUNT_KAR, string selected_category, MapObject vybor_pony[], MapObject chasti[])
{
    for (int i = 0; i < COUNT_KAR; i++)
    {
       if (vybor_pony [i].Click() &&
            (vybor_pony[i].Kategorya == selected_category))
        {
            chasti[i].visible = !chasti[i].visible;

            for ( int n = 0; n < COUNT_KAR; n++)
            {
                if (chasti[i].visible &&
                    i !=n &&
                    vybor_pony[n].Kategorya == vybor_pony[i].Kategorya)
                    {
                      chasti[n].visible = false;
                    }
            }

            txSleep(200);
        }
    }
}


void risyemKnopki (int COUNT_BUTT, MenuButton buttons[])
{
    txSetColor(TX_WHITE);
    for (int i = 0; i <COUNT_BUTT; i++)
    {
        buttons[i].drawButton();
    }
}

void risyemChasti (int COUNT_KAR, MapObject chasti[])
{
    for (int i = 0; i < COUNT_KAR; i++)
    {
        if(chasti[i].visible)
        {
            chasti[i].drawMapObject2();
        }
    }
}

void risyemKPony (int COUNT_KAR, string selected_category, MapObject vybor_pony[])
{
    for (int i = 0; i < COUNT_KAR; i++)
    {
        if (selected_category == vybor_pony[i].Kategorya)
        {
            vybor_pony[i].drawMapObject2();
        }
    }
}

void fillChasti (int COUNT_KAR, MapObject chasti[], MapObject variants[])
{
    for (int i = 0; i < COUNT_KAR; i++)
    {
        chasti[i].picture = variants[i].picture;
        chasti[i].adress = variants[i].adress;
        chasti[i].Kategorya = variants[i].Kategorya;
        chasti[i].srk_width = variants[i].srk_width;
        chasti[i].srk_height = variants[i].srk_height;
        chasti[i].visible = false;

        if (chasti[i].Kategorya == "xvost")
        {
            chasti[i].x =  750;
            chasti[i].y =  250;
            chasti[i].x2 =  990;
            chasti[i].y2 =  420;
        }

        if (chasti[i].Kategorya == "Pony" ||
            chasti[i].Kategorya == "Telo")
        {
            chasti[i].x =  400;
            chasti[i].y =  100;
            chasti[i].x2 =  1000;
            chasti[i].y2 =  500;
        }

        if (chasti[i].Kategorya == "Head")
        {
            chasti[i].x =  500;
            chasti[i].y =  100;
            chasti[i].x2 =  740;
            chasti[i].y2 =  270;
        }

        if (chasti[i].Kategorya == "kopta")
        {
            chasti[i].x =  550;
            chasti[i].y =  400;
            chasti[i].x2 = 800;
            chasti[i].y2 = 500;
        }
    }
}

