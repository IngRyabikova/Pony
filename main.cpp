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

    const int COUNT_BUTT = 6;
    MenuButton buttons[COUNT_BUTT];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"Пони", 530, 140};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"Хвост", 530, 140};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"Копыта", 530, 140};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"Голова", 530, 140};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"Тело", 530, 140};

    const int COUNT_KAR = 6;
    MapObject vybor_pony[COUNT_KAR];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp"), "Пони", 600, 400, true};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp"), "Пони", 600, 400, true};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp"), "Пони", 600, 400, true};
    vybor_pony[3] = {1000,  0,1200,200,txLoadImage ("Pictures/Head/Head1.bmp"), "Хэд", 259, 165, true};
    vybor_pony[4] = {1000,200,1200,400,txLoadImage ("Pictures/Head/Head2.bmp"), "Хэд", 253, 178, true};
    vybor_pony[5] = {1000,400,1200,600,txLoadImage ("Pictures/Head/Head3.bmp"), "Хэд", 284, 219, true};
    char* Kategorya;

    MapObject vybor_chasti[COUNT_KAR];
    vybor_chasti[0] = {480, 100, 1080, 500,txLoadImage ("Pictures/Pony/pony1.bmp"), "Пони", 600, 400, false};
    vybor_chasti[1] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony2.bmp"), "Пони", 600, 400, false};
    vybor_chasti[2] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony4.bmp"), "Пони", 600, 400, false};
    vybor_chasti[3] = {500, 100, 740, 280,txLoadImage ("Pictures/Head/Head1.bmp"), "Хэд", 259, 165, false};//400, 100, 640, 270
    vybor_chasti[4] = {500, 100, 740, 280,txLoadImage ("Pictures/Head/Head2.bmp"), "Хэд", 253, 178, false};
    vybor_chasti[5] = {500, 100, 740, 280,txLoadImage ("Pictures/Head/Head3.bmp"), "Хэд", 284, 219, false};
    bool visible = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_GREEN);
        txClear();

        risyemKnopki (5, buttons) ;

        risyemKPony (6, Kategorya, vybor_pony);

        risyemChasti (6, vybor_chasti) ;

        if (buttons [3].Click())
        {
            Kategorya = "Хэд";
            txSleep(200);
        }

        if (buttons [0].Click())
        {
            Kategorya = "Пони";
            txSleep(200);
        }

        risyemKChasti (6, Kategorya, vybor_pony, vybor_chasti);

        txSleep(10);
        txEnd();
    }

    //Удаление картинок
    for (int i = 0; i <=5; i++)
    {
        txDeleteDC (vybor_pony[i].picture);
    }
    for (int i = 0; i <=1; i++)
    {
        txDeleteDC (vybor_chasti[i].picture);
    }

    return 0;
}
