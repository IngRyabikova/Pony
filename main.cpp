#include "TXLib.h"
#include "Button.cpp"
#include "MapObjects.cpp"
#include "Files.cpp"
#include <fstream>
#include <string>
#include <iostream>
#include <dirent.h>

const int ZONA_KNOPOK = 300;
const int ZONA_VYBORA_KARTINOK = 950;
const int SAVEBUTT = 5;
const int LOADBUTT = 6;
const int FOR_CHAINIKOV = 4;

using namespace std;

int chtenie(string adress, int COUNT_KAR, MapObject variants[])
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(adress.c_str())) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            if ((string)(ent->d_name) != ".."
                and (string)(ent->d_name) != ".")
            {
                variants[COUNT_KAR] = {adress + (string)(ent->d_name)};
                COUNT_KAR = COUNT_KAR + 1;
            }
        }
        closedir (dir);
    }

    return COUNT_KAR;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    txCreateWindow(1200, 700);
    txPlaySound("Pony.wav", SND_LOOP );

    HDC fon = txLoadImage("Pictures//fon//fon.bmp");

    const int COUNT_BUTT = 7;
    MenuButton buttons[COUNT_BUTT];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"Хвост", 530, 140, "xvost"};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"Копыта", 530, 140, "kopta"};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"Голова", 530, 140, "Head"};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"Тело", 530, 140, "Telo"};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"Справка", 530, 140, ""};
    buttons[5] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,450,540,"Сохранить", 530, 140,""};
    buttons[6] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,540,630,"Загрузить", 530, 140,""};

    int COUNT_KAR = 0;
    MapObject variants[1000];

    COUNT_KAR = chtenie("Pictures/Telo/",  COUNT_KAR, variants);
    COUNT_KAR = chtenie("Pictures/xvost/", COUNT_KAR, variants);
    COUNT_KAR = chtenie("Pictures/Head/",  COUNT_KAR, variants);
    COUNT_KAR = chtenie("Pictures/kopta/", COUNT_KAR, variants);

    int y_Pony = 0;
    int y_Head = 0;
    int y_xvost = 0;
    int y_kopta = 0;
    int y_Telo = 0;
    for (int i = 0; i < COUNT_KAR; i++)
    {
        variants[i].x = 1000;
        variants[i].x2 = 1200;
        string stroka = variants[i].adress;
        int onepose = stroka.find("/");
        int twopose = stroka.find("/", onepose + 1);
        variants[i].Kategorya = stroka.substr(onepose + 1, twopose - onepose - 1);

        /*if (variants[i].Kategorya == "Pony")
        {
            variants[i].y = y_Pony;
            y_Pony  = y_Pony + 160;
        }    */

        if (variants[i].Kategorya == "Head")
        {
            variants[i].y = y_Head;
            y_Head  = y_Head + 160;
        }

        if (variants[i].Kategorya == "xvost")
        {
            variants[i].y = y_xvost;
            y_xvost  = y_xvost + 160;
        }

        if (variants[i].Kategorya == "kopta")
        {
            variants[i].y = y_kopta;
            y_kopta  = y_kopta + 160;
        }

        if (variants[i].Kategorya == "Telo")
        {
            variants[i].y = y_Telo;
            y_Telo  = y_Telo + 160;
        }

        variants[i].y2 = variants[i].y + 160;
        variants[i].picture = txLoadImage(variants[i].adress.c_str());
        variants[i].srk_width = get_widht(variants[i].adress);
        variants[i].srk_height = get_height(variants[i].adress);
        variants[i].visible = true;
    }

    string selected_category;

    int nomer_vybrannoi_kartinki = -1000;

    MapObject chasti[COUNT_KAR];

    fillChasti (COUNT_KAR, chasti, variants);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_GREEN);
        txClear();
        risyemChasti (COUNT_KAR, chasti) ;

        if (nomer_vybrannoi_kartinki >= 0)
        {
            if (chasti[nomer_vybrannoi_kartinki].Click() and txGetPixel (txMouseX(), txMouseY()) != TX_GREEN)
            {
                chasti[nomer_vybrannoi_kartinki].najatieKartinki = true;
            }

            if ((txMouseButtons() & 1) &&  chasti[nomer_vybrannoi_kartinki].najatieKartinki)
            {
                int width = chasti[nomer_vybrannoi_kartinki].x2 - chasti[nomer_vybrannoi_kartinki].x;
                int hight = chasti[nomer_vybrannoi_kartinki].y2 - chasti[nomer_vybrannoi_kartinki].y;

                chasti[nomer_vybrannoi_kartinki].x = txMouseX() - width/2;
                chasti[nomer_vybrannoi_kartinki].x2 = chasti[nomer_vybrannoi_kartinki].x + width;

                chasti[nomer_vybrannoi_kartinki].y = txMouseY() - hight/2;
                chasti[nomer_vybrannoi_kartinki].y2 = chasti[nomer_vybrannoi_kartinki].y + hight;
            }

            if (!(txMouseButtons() & 1) && chasti[nomer_vybrannoi_kartinki].najatieKartinki)
            {
                chasti[nomer_vybrannoi_kartinki].najatieKartinki = false;
            }
        }


        txBitBlt(txDC(), 0,0, txGetExtentX(), txGetExtentY(), fon);
        risyemKnopki (COUNT_BUTT, buttons) ;
        risyemKPony (COUNT_KAR, selected_category, variants);
        risyemChasti (COUNT_KAR, chasti) ;
        risyemKChasti (COUNT_KAR, selected_category, variants, chasti);

        if (GetAsyncKeyState('W'))
        {
            txPlaySound("Pony.wav", SND_LOOP );
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            txPlaySound(NULL);
        }


        if (buttons[FOR_CHAINIKOV].Click())
        {
            txSleep(200);
            bool stop = false;
            while (stop == false)
            {
               txSetFillColor(TX_WHITE);
               txSetColor(TX_BLACK);
               txRectangle (0, 0,1200,1200);
               txSelectFont("Arial", 40);
               txDrawText(0, 0,1200,1200,
                    "\n"
                    "Здрасте Приехали\n"
                    "Это пони\n"
                    "Они просто есть\n"
                    "\n"
                    "* Если не помогло, перечислите мне на телефон рублей 300.          \n"
                    "  Умнее от этого вы не станете, но хоть поможете хорошему человеку.\n"
                    "  (89374575744)\n"
                    "* При нажатии на выбранную картинку ее можно передвигать в разные стороны\n"
                    " (стрелками и мышкой).\n"
                    "* Если после нажатия на выбраную картинку, еще нажать на + ИЛИ - то картинка изменит свой размер.\n"
                    "* Если добавить картинки в папку с картинками (pictures) то она появится в игре\n"
                    " (пссс... Вмещается 4 штуки)\n"
                    "* Если нажать на Сохранить или Загрузить то ваше творение загрузится или сохранится.\n"

                    "\n"
                    "ХОХО\n");

                if (txMouseButtons() == 1)
                {
                    stop = true;
                }

                txSleep(10);
            }
        }

        if (buttons[SAVEBUTT].Click())//Сохранение
        {
               saveToFile (COUNT_KAR, chasti);
        }

        else if (buttons[LOADBUTT].Click()) //Загрузка
        {
               loadFromFile (COUNT_KAR, chasti);
        }


        for (int i = 0; i < COUNT_BUTT; i = i + 1)
        {
            if (buttons [i].Click() && buttons[i].Kategorya != "")
            {
                selected_category = buttons[i].Kategorya;
                txSleep(200);
            }
        }

        for(int i = 0; i < COUNT_KAR; i++)
        {
            int width = chasti[i].x2 - chasti[i].x;

            if (chasti[i].x < ZONA_KNOPOK)
            {
                chasti[i].x = ZONA_KNOPOK;
                chasti[i].x2 = chasti[i].x + width;
            }
            if (chasti[i].x2 > ZONA_VYBORA_KARTINOK)
            {
                chasti[i].x2 = ZONA_VYBORA_KARTINOK;
                chasti[i].x = chasti[i].x2 - width;
            }
        }

        for(int i = 0; i < COUNT_KAR; i++)
        {
          if ( chasti[i].visible && chasti[i].Click())
          {
              nomer_vybrannoi_kartinki = i;
          }
        }

        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_LEFT))
           {
             chasti[nomer_vybrannoi_kartinki].x -= 3;
             chasti[nomer_vybrannoi_kartinki].x2 -= 3;
           }
        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_RIGHT))
           {
             chasti[nomer_vybrannoi_kartinki].x += 3;
             chasti[nomer_vybrannoi_kartinki].x2 += 3;
           }
         if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_UP))
           {
             chasti[nomer_vybrannoi_kartinki].y -= 3;
             chasti[nomer_vybrannoi_kartinki].y2 -= 3;
           }
        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_DOWN))
           {
             chasti[nomer_vybrannoi_kartinki].y += 3;
             chasti[nomer_vybrannoi_kartinki].y2 += 3;
           }
        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_OEM_MINUS))
           {
             chasti[nomer_vybrannoi_kartinki].x2 = chasti[nomer_vybrannoi_kartinki].x +
             (chasti[nomer_vybrannoi_kartinki].x2-chasti[nomer_vybrannoi_kartinki].x)*0.99;
             chasti[nomer_vybrannoi_kartinki].y2 = chasti[nomer_vybrannoi_kartinki].y +
             (chasti[nomer_vybrannoi_kartinki].y2-chasti[nomer_vybrannoi_kartinki].y)*0.99;
           }
        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_OEM_PLUS))
           {
            chasti[nomer_vybrannoi_kartinki].x2 = chasti[nomer_vybrannoi_kartinki].x +
             (chasti[nomer_vybrannoi_kartinki].x2-chasti[nomer_vybrannoi_kartinki].x)*1.01;
            chasti[nomer_vybrannoi_kartinki].y2 = chasti[nomer_vybrannoi_kartinki].y +
             (chasti[nomer_vybrannoi_kartinki].y2-chasti[nomer_vybrannoi_kartinki].y)*1.01;
           }


        txSleep(10);
        txEnd();
    }

    //Delete pictures
    txDeleteDC (fon);
    for (int i = 0; i <= COUNT_BUTT; i++)
    {
        txDeleteDC (buttons[i].baton);
     }
    for (int i = 0; i <= COUNT_KAR; i++)
    {
        txDeleteDC (variants[i].picture);
        txDeleteDC (chasti[i].picture);
    }

    return 0;
}
