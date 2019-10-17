#include "TXLib.h"
#include "Button.cpp"
#include "MapObjects.cpp"

void risyemKChasti (int COUNT_KAR, char* Kategorya, MapObject vybor_pony[], MapObject vybor_chasti[])
{
    for (int i = 0; i < COUNT_KAR; i++)
     {
       if (vybor_pony [i].Click() &&
            (vybor_pony[i].Kategorya == Kategorya))
        {
            vybor_chasti[i].visible = !vybor_chasti[i].visible;

            for ( int n = 0; n < COUNT_KAR; n++)
            {
                if (vybor_chasti[i].visible &&
                    i !=n &&
                    vybor_pony[n].Kategorya == vybor_pony[i].Kategorya)
                    {
                      vybor_chasti[n].visible = false;
                    }
            }

            txSleep(200);
        }
    }
}

void risyemChasti (int COUNT_KAR, MapObject vybor_chasti[])
{
    for (int i = 0; i < COUNT_KAR; i++)
        {
            if(vybor_chasti[i].visible)
            {
                vybor_chasti[i].drawMapObject2();
            }
        }
}

void risyemKPony (int COUNT_KAR, char* Kategorya, MapObject vybor_pony[])
{
    for (int i = 0; i < COUNT_KAR; i++)
        {
            if (Kategorya == vybor_pony[i].Kategorya)
            {
                vybor_pony[i].drawMapObject2();
            }
        }
}

void risyemKnopki (int COUNT_BUTT, MenuButton buttons[])
{
        for (int i = 0; i <COUNT_BUTT; i++)
        {
            buttons[i].drawButton();
        }
}

int main()
    {
    txCreateWindow(1200, 700);

    const int COUNT_BUTT = 5;
    MenuButton buttons[COUNT_BUTT];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"����", 530, 140};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"�����", 530, 140};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"������", 530, 140};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"������", 530, 140};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"����", 530, 140};

    const int COUNT_KAR = 13;
    MapObject vybor_pony[COUNT_KAR];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp"), "Pony", 600, 400, true};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp"), "Pony", 600, 400, true};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp"), "Telo", 600, 400, true};
    vybor_pony[3] = {1000,  0,1200,200,txLoadImage ("Pictures/Head/Head1.bmp"), "Head", 259, 165, true};
    vybor_pony[4] = {1000,200,1200,400,txLoadImage ("Pictures/Head/Head2.bmp"), "Head", 253, 178, true};
    vybor_pony[5] = {1000,400,1200,600,txLoadImage ("Pictures/Head/Head3.bmp"), "Head", 284, 219, true};
    vybor_pony[6] = {1000,  0,1200,200,txLoadImage ("Pictures/xvost/xvost1.bmp"), "Xvost", 230, 250, true};
    vybor_pony[7] = {1000,200,1200,400,txLoadImage ("Pictures/xvost/xvost2.bmp"), "Xvost", 230, 250, true};
    vybor_pony[8] = {1000,400,1200,600,txLoadImage ("Pictures/xvost/xvost3.bmp"), "Xvost", 230, 250, true};
    vybor_pony[9] = {1000,  0,1200,200,txLoadImage ("Pictures/kopta/kopta1.bmp"), "kopta", 189, 49, true};
    vybor_pony[10] = {1000,200,1200,400,txLoadImage ("Pictures/kopta/kopta2.bmp"), "kopta", 252, 60, true};
    vybor_pony[11] = {1000,400,1200,600,txLoadImage ("Pictures/kopta/kopta3.bmp"), "kopta", 142, 59, true};
    vybor_pony[12] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/unicorn.bmp"), "Pony", 600, 400, true};

    char* Kategorya;

    MapObject vybor_chasti[COUNT_KAR];
    vybor_chasti[0] = {400, 100, 1080, 500,txLoadImage ("Pictures/Pony/pony1.bmp"), "Pony", 600, 400, false};
    vybor_chasti[1] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony2.bmp"), "Pony", 600, 400, false};
    vybor_chasti[2] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony4.bmp"), "Telo", 600, 400, false};
    vybor_chasti[3] = {500, 100, 740, 270,txLoadImage ("Pictures/Head/Head1.bmp"), "Head", 259, 165, false};
    vybor_chasti[4] = {500, 100, 740, 270,txLoadImage ("Pictures/Head/Head2.bmp"), "Head", 253, 178, false};
    vybor_chasti[5] = {500, 100, 740, 270,txLoadImage ("Pictures/Head/Head3.bmp"), "Head", 284, 219, false};
    vybor_chasti[6] = {750, 250, 990, 420,txLoadImage ("Pictures/xvost/xvost1.bmp"), "Xvost", 230, 250, false};
    vybor_chasti[7] = {750, 250, 990, 420,txLoadImage ("Pictures/xvost/xvost2.bmp"), "Xvost", 230, 250, false};
    vybor_chasti[8] = {750, 250, 990, 420,txLoadImage ("Pictures/xvost/xvost3.bmp"), "Xvost", 230, 250, false};
    vybor_chasti[9] = {550, 400,800, 500,txLoadImage ("Pictures/kopta/kopta1.bmp"), "kopta", 189, 49, false};
    vybor_chasti[10] = {550, 400,800,500,txLoadImage ("Pictures/kopta/kopta2.bmp"), "kopta", 252, 60, false};
    vybor_chasti[11] = {550, 400,800,500,txLoadImage ("Pictures/kopta/kopta3.bmp"), "kopta", 142, 59, false};
    vybor_chasti[12] = {400,100,1000,500,txLoadImage ("Pictures/Pony/unicorn.bmp"), "Pony", 600, 400, false};

    int nKartinki = -100;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_GREEN);
        txClear();

        risyemKnopki (COUNT_BUTT, buttons) ;
        risyemKPony (COUNT_KAR, Kategorya, vybor_pony);
        risyemChasti (COUNT_KAR, vybor_chasti) ;

        if (buttons [3].Click())
        {
            Kategorya = "Head";
            txSleep(200);
        }

        if (buttons [0].Click())
        {
            Kategorya = "Pony";
            txSleep(200);
        }

        if (buttons [1].Click())
        {
            Kategorya = "Xvost";
            txSleep(200);
        }

        if (buttons [2].Click())
        {
            Kategorya = "kopta";
            txSleep(200);
        }

        if (buttons [4].Click())
        {
            Kategorya = "Telo";
            txSleep(200);
        }

        risyemKChasti (COUNT_KAR, Kategorya, vybor_pony, vybor_chasti);

        for (int i = 0; i <= COUNT_KAR; i++)
        {
            if (vybor_chasti[i].Click() && vybor_chasti[i].visible)
            {
                nKartinki = i;
            }
        }

        if (GetAsyncKeyState(VK_OEM_PLUS) && nKartinki >= 0)
        {
            vybor_chasti[nKartinki].x2 +=3;
            vybor_chasti[nKartinki].y2 +=3;
        }

        if (GetAsyncKeyState(VK_OEM_MINUS) && nKartinki >= 0)
        {
            vybor_chasti[nKartinki].x2 -=3;
            vybor_chasti[nKartinki].y2 -=3;
        }

        if (GetAsyncKeyState(VK_LEFT)  && nKartinki >= 0)
        {
            vybor_chasti[nKartinki].x  -=3;
            vybor_chasti[nKartinki].x2 -=3;
        }

        if (GetAsyncKeyState(VK_RIGHT) && nKartinki >= 0)
        {
            vybor_chasti[nKartinki].x  +=3;
            vybor_chasti[nKartinki].x2 +=3;
        }

        if (GetAsyncKeyState(VK_DOWN)    && nKartinki >= 0)
        {
            vybor_chasti[nKartinki].y  +=3;
            vybor_chasti[nKartinki].y2 +=3;
        }


        if (GetAsyncKeyState(VK_UP)  && nKartinki >= 0)
        {
            vybor_chasti[nKartinki].y  -=3;
            vybor_chasti[nKartinki].y2 -=3;
        }


        txSleep(20);
        txEnd();
    }

    //Delete pictures
    for (int i = 0; i <=COUNT_KAR; i++)
    {
        txDeleteDC (vybor_pony[i].picture);
        txDeleteDC (vybor_chasti[i].picture);
    }





    /* for (int a = 0; a < COUNT_PICS; a++)
        {
            if (txMouseButtons() == 1 &&
                txMouseX() > pic[a].x &&
                txMouseX() < pic[a].x + pic[a].shirina &&
                txMouseY() > pic[a].y &&
                txMouseY() < pic[a].y + pic[a].visota &&
                (pic[a].category == category || pic[a].category == category2))
            {
                mapParts[a].visible = !mapParts[a].visible;

                for (int n = 0; n < COUNT_PICS; n++)
                {
                    if (mapParts[a].visible &&
                        a != n &&
                        pic[n].category == pic[a].category)
                    {
                        mapParts[n].visible = false;
                    }
                }

                txSleep(200);
            }
        }
         */
    return 0;
}
