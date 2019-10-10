#include "TXLib.h"
#include "Button.cpp"
#include "MapObjects.cpp"

void risyemKChasti (int COUNT_KAR, char* Kategorya, MapObject vybor_pony[], MapObject vybor_chasti[])
{
    for (int i = 0; i <=COUNT_KAR; i++)
        {
            if (vybor_pony [i].Click() and vybor_pony[i].Kategorya == Kategorya)
            {
                vybor_chasti[i].visible = !vybor_chasti[i].visible;
                txSleep(200);
            }
        }
}

void risyemChasti (int COUNT_KAR, MapObject vybor_chasti[])
{
    for (int i = 0; i <=COUNT_KAR; i++)
        {
            if(vybor_chasti[i].visible)
            {
                vybor_chasti[i].drawMapObject2();
            }
        }
}

void risyemKPony (int COUNT_KAR, char* Kategorya, MapObject vybor_pony[])
{
    for (int i = 0; i <=COUNT_KAR; i++)
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
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"Ïîíè", 530, 140};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"Õâîñò", 530, 140};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"Êîïûòà", 530, 140};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"Ãîëîâà", 530, 140};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"Òåëî", 530, 140};

    const int COUNT_KAR = 9;
    MapObject vybor_pony[COUNT_KAR];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp"), "Ïîíè", 600, 400, true};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp"), "Ïîíè", 600, 400, true};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp"), "Ïîíè", 600, 400, true};
    vybor_pony[3] = {1000,  0,1200,200,txLoadImage ("Pictures/Head/Head1.bmp"), "Õýä", 259, 165, true};
    vybor_pony[4] = {1000,200,1200,400,txLoadImage ("Pictures/Head/Head2.bmp"), "Õýä", 253, 178, true};
    vybor_pony[5] = {1000,400,1200,600,txLoadImage ("Pictures/Head/Head3.bmp"), "Õýä", 284, 219, true};
    vybor_pony[6] = {1000,  0,1200,200,txLoadImage ("Pictures/xvost/xvost1.bmp"), "Õâîñò", 230, 250, true};
    vybor_pony[7] = {1000,200,1200,400,txLoadImage ("Pictures/xvost/xvost2.bmp"), "Õâîñò", 230, 250, true};
    vybor_pony[8] = {1000,400,1200,600,txLoadImage ("Pictures/xvost/xvost3.bmp"), "Õâîñò", 230, 250, true};
    char* Kategorya;

    MapObject vybor_chasti[COUNT_KAR];
    vybor_chasti[0] = {480, 100, 1080, 500,txLoadImage ("Pictures/Pony/pony1.bmp"), "Ïîíè", 600, 400, false};
    vybor_chasti[1] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony2.bmp"), "Ïîíè", 600, 400, false};
    vybor_chasti[2] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony4.bmp"), "Ïîíè", 600, 400, false};
    vybor_chasti[3] = {400, 100, 640, 270,txLoadImage ("Pictures/Head/Head1.bmp"), "Õýä", 259, 165, false};
    vybor_chasti[4] = {400, 100, 640, 270,txLoadImage ("Pictures/Head/Head2.bmp"), "Õýä", 253, 178, false};
    vybor_chasti[5] = {400, 100, 640, 270,txLoadImage ("Pictures/Head/Head3.bmp"), "Õýä", 284, 219, false};
    vybor_chasti[6] = {750, 250, 990, 420,txLoadImage ("Pictures/xvost/xvost1.bmp"), "Õâîñò", 230, 250, false};
    vybor_chasti[7] = {750, 250, 990, 420,txLoadImage ("Pictures/xvost/xvost2.bmp"), "Õâîñò", 230, 250, false};
    vybor_chasti[8] = {750, 250, 990, 420,txLoadImage ("Pictures/xvost/xvost3.bmp"), "Õâîñò", 230, 250, false};

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
            Kategorya = "Õýä";
            txSleep(200);
        }

        if (buttons [0].Click())
        {
            Kategorya = "Ïîíè";
            txSleep(200);
        }

        if (buttons [1].Click())
        {
            Kategorya = "Õâîñò";
            txSleep(200);
        }

        risyemKChasti (COUNT_KAR, Kategorya, vybor_pony, vybor_chasti);

        txSleep(10);
        txEnd();
    }

    //Delete pictures
    for (int i = 0; i <=COUNT_KAR; i++)
    {
        txDeleteDC (vybor_pony[i].picture);
        txDeleteDC (vybor_chasti[i].picture);
    }

    return 0;
}