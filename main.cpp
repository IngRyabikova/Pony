#include "TXLib.h"
#include "Button.cpp"
#include "MapObjects.cpp"

int main()
    {
    txCreateWindow(1200, 700);

    MenuButton buttons[5];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"Пони", 530, 140};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"Хвост", 530, 140};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"Копыта", 530, 140};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"Голова", 530, 140};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"Тело", 530, 140};

    MapObject vybor_pony[6];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp"), "Пони", 600, 400, true};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp"), "Пони", 600, 400, true};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp"), "Пони", 600, 400, true};
    vybor_pony[3] = {1000,  0,1200,200,txLoadImage ("Pictures/Head/Head1.bmp"), "Хэд", 259, 165, true};
    vybor_pony[4] = {1000,200,1200,400,txLoadImage ("Pictures/Head/Head2.bmp"), "Хэд", 253, 178, true};
    vybor_pony[5] = {1000,400,1200,600,txLoadImage ("Pictures/Head/Head3.bmp"), "Хэд", 284, 219, true};
    char* Kategorya;

    MapObject vybor_chasti[6];
    vybor_chasti[0] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony1.bmp"), "Пони", 600, 400, true};
    vybor_chasti[1] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony2.bmp"), "Пони", 600, 400, true};
    vybor_chasti[2] = {400, 100, 1000, 500,txLoadImage ("Pictures/Pony/pony4.bmp"), "Пони", 600, 400, true};
    vybor_chasti[3] = {400, 100, 640, 270,txLoadImage ("Pictures/Head/Head1.bmp"), "Хэд", 259, 165, true};
    vybor_chasti[4] = {400, 100, 640, 270,txLoadImage ("Pictures/Head/Head2.bmp"), "Хэд", 253, 178, true};
    vybor_chasti[5] = {400, 100, 640, 270,txLoadImage ("Pictures/Head/Head3.bmp"), "Хэд", 284, 219, true};
    bool visible = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_GREEN);
        txClear();

        for (int i = 0; i < 5; i++)
        {
            buttons[i].drawButton();
        }

        for (int i = 0; i <= 5; i++)
        {
            if (Kategorya == vybor_pony[i].Kategorya)
            {
                vybor_pony[i].drawMapObject2();
            }
        }

        for (int i = 0; i <=2; i++)
        {
            if(vybor_chasti[i].visible)
            {
                vybor_chasti[i].drawMapObject2();
            }
        }

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

        for (int i = 0; i <=5; i++)
        {
            if (vybor_pony [i].Click())
            {
                vybor_chasti[i].visible = !vybor_chasti[i].visible;
                txSleep(200);
            }
        }

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
