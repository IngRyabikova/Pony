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

    MapObject vybor_pony[3];
    vybor_pony[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Pony/pony1.bmp"), 600, 400};
    vybor_pony[1] = {1000,200,1200,400,txLoadImage ("Pictures/Pony/pony2.bmp"), 600, 400};
    vybor_pony[2] = {1000,400,1200,600,txLoadImage ("Pictures/Pony/pony4.bmp"), 600, 400};
    bool vid = false;

    MapObject vybor_golova[3];
    vybor_golova[0] = {1000,  0,1200,200,txLoadImage ("Pictures/Head/Head1.bmp"), 259, 165};
    vybor_golova[1] = {1000,200,1200,400,txLoadImage ("Pictures/Head/Head2.bmp"), 253, 178};
    vybor_golova[2] = {1000,400,1200,600,txLoadImage ("Pictures/Head/Head3.bmp"), 284, 219};
    bool vid2 = false;

    MapObject vybor_chasti[2];
    vybor_chasti[0] = {400, 100, 1000, 500, txLoadImage ("Pictures/pony/unicorn.bmp"), 600, 400};
    vybor_chasti[1] = {400, 100, 640, 270, txLoadImage ("Pictures/Head/Head.bmp"), 280, 180};
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

		if (vid2)
        {
            vybor_golova[0].drawMapObject2();
            vybor_golova[1].drawMapObject2();
            vybor_golova[2].drawMapObject2();
        }

        if (buttons [3].Click())
        {
            vid2 = !vid2;
            txSleep(200);
        }

        if (buttons [0].Click())
        {
            vid = !vid;
            txSleep(200);
        }

        txSleep(10);
        txEnd();
    }

    //Удаление картинок
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
