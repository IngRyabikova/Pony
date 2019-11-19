#include "TXLib.h"
#include "Button.cpp"
#include "MapObjects.cpp"
#include "Files.cpp"
#include <fstream>
#include <string>

using namespace std;

//

int main()
{
    setlocale(LC_ALL, "Russian");
    txCreateWindow(1200, 700);
    txPlaySound("Pony.wav", SND_LOOP );

    const int COUNT_BUTT = 8;
    MenuButton buttons[COUNT_BUTT];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"����", 530, 140, "Pony"};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"�����", 530, 140, "xvost"};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"������", 530, 140, "kopta"};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"������", 530, 140, "Head"};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"����", 530, 140, "Telo"};
    buttons[5] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,450,540,"�������", 530, 140,""};
    buttons[6] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,540,630,"���������", 530, 140,""};
    buttons[7] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,630,720,"���������", 530, 140,""};

    const int COUNT_KAR = 13;
    MapObject variants[COUNT_KAR];
    variants[0] = {"Pictures/Pony/pony1.bmp"};
    variants[1] = {"Pictures/Pony/pony2.bmp"};
    variants[2] = {"Pictures/Pony/unicorn.bmp"};
    variants[3] = {"Pictures/Head/Head1.bmp"};
    variants[4] = {"Pictures/Head/Head2.bmp"};
    variants[5] = {"Pictures/Head/Head3.bmp"};
    variants[6] = {"Pictures/xvost/xvost1.bmp"};
    variants[7] = {"Pictures/xvost/xvost2.bmp"};
    variants[8] = {"Pictures/xvost/xvost3.bmp"};
    variants[9] = {"Pictures/kopta/kopta1.bmp"};
    variants[10] = {"Pictures/kopta/kopta2.bmp"};
    variants[11] = {"Pictures/kopta/kopta3.bmp"};
    variants[12] = {"Pictures/Telo/pony4.bmp"};
    //variants[13] = {"Pictures/Telo/pony6.bmp"};

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

        if (variants[i].Kategorya == "Pony")
        {
            variants[i].y = y_Pony;
            y_Pony  = y_Pony + 200;
        }

        if (variants[i].Kategorya == "Head")
        {
            variants[i].y = y_Head;
            y_Head  = y_Head + 200;
        }

        if (variants[i].Kategorya == "xvost")
        {
            variants[i].y = y_xvost;
            y_xvost  = y_xvost + 200;
        }

        if (variants[i].Kategorya == "kopta")
        {
            variants[i].y = y_kopta;
            y_kopta  = y_kopta + 200;
        }

        if (variants[i].Kategorya == "Telo")
        {
            variants[i].y = y_Telo;
            y_Telo  = y_Telo + 200;
        }

        variants[i].y2 = variants[i].y + 200;
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

        risyemKnopki (COUNT_BUTT, buttons) ;
        risyemKPony (COUNT_KAR, selected_category, variants);
        risyemChasti (COUNT_KAR, chasti) ;

        if (buttons[5].Click())
        {
            txSleep(200);
            bool stop = false;
            while (stop == false)
            {
            	txSetFillColor(TX_WHITE);
            	txSetColor(TX_BLACK);
                txRectangle (400, 100,800,500);
                txSelectFont("Arial", 40);
                txDrawText(400, 100,800,500,
                    "\n"
                    "������� ��������\n"
                    "\n"
                    "��� ����\n"
                    "��� ������ ����\n"
                    "��� �� ����� ������ ����������\n"
                    "\n"
                    "����\n");

                if (txMouseButtons() == 1 &&
                    txMouseX() > 400 &&
                    txMouseY() > 100 &&
                    txMouseX() < 800 &&
                    txMouseY() < 500)
                {
                    stop = true;
                }

                txSleep(10);
            }
        }

        if (buttons[6].Click())//����������
        {
        saveToFile (COUNT_KAR, chasti);

        }

        else if (buttons[7].Click()) //��������
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

            if (chasti[i].x < 300)
            {
                chasti[i].x = 300;
                chasti[i].x2 = chasti[i].x + width;
            }
            if (chasti[i].x2 > 950)
            {
                chasti[i].x2 = 950;
                chasti[i].x = chasti[i].x2 - width;
            }
        }

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


        risyemKChasti (COUNT_KAR, selected_category, variants, chasti);

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
    for (int i = 0; i <=COUNT_KAR; i++)
    {
        txDeleteDC (variants[i].picture);
        txDeleteDC (chasti[i].picture);
    }

    return 0;
}
