#include "TXLib.h"
#include "Button.cpp"
#include "MapObjects.cpp"
#include "Files.cpp"
#include <fstream>
#include <string>

using namespace std;

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

void risyemKnopki (int COUNT_BUTT, MenuButton buttons[])
{
    txSetColor(TX_WHITE);
    for (int i = 0; i <COUNT_BUTT; i++)
    {
        buttons[i].drawButton();
    }
}

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
    variants[0] = {  0,"Pictures/Pony/pony1.bmp"};
    variants[1] = {200,"Pictures/Pony/pony2.bmp"};
    variants[2] = {400,"Pictures/Telo/pony4.bmp"};
    variants[3] = {  0,"Pictures/Head/Head1.bmp"};
    variants[4] = {200,"Pictures/Head/Head2.bmp"};
    variants[5] = {400,"Pictures/Head/Head3.bmp"};
    variants[6] = {  0,"Pictures/xvost/xvost1.bmp"};
    variants[7] = {200,"Pictures/xvost/xvost2.bmp"};
    variants[8] = {400,"Pictures/xvost/xvost3.bmp"};
    variants[9] = {  0,"Pictures/kopta/kopta1.bmp"};
    variants[10] = {200,"Pictures/kopta/kopta2.bmp"};
    variants[11] = {400,"Pictures/kopta/kopta3.bmp"};
    variants[12] = {400,"Pictures/Pony/unicorn.bmp"};

    for (int i = 0; i < COUNT_KAR; i++)
    {
        variants[i].x = 1000;
        variants[i].x2 = 1200;
        variants[i].y2 = variants[i].y + 200;
        string stroka = variants[i].adress;
        int onepose = stroka.find("/");
        int twopose = stroka.find("/", onepose + 1);
        variants[i].Kategorya = stroka.substr(onepose + 1, twopose - onepose - 1);

        variants[i].picture = txLoadImage(variants[i].adress.c_str());
        variants[i].srk_width = get_widht(variants[i].adress);
        variants[i].srk_height = get_height(variants[i].adress);
        variants[i].visible = true;
    }


    string selected_category;

    int nomer_vybrannoi_kartinki = -1000;

    MapObject chasti[COUNT_KAR];

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
                txDrawText(400, 100,800,500,
                    "���\n"
                    "\n"
                    "\n"
                    "���\n"
                    "���\n"
                    "���\n");

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
            ofstream file1("Fail1.txt");

            for (int nomer = 0; nomer < COUNT_KAR; nomer++)
            {
                if (chasti[nomer].visible)
                {
                    file1 << chasti[nomer].x << endl;
                    file1 << chasti[nomer].y << endl;
                    file1 << chasti[nomer].adress << endl;
                }
            }

            file1.close();

            txMessageBox("��������� � Fail1.txt");
        }

        else if (buttons[7].Click()) //��������
        {
            for (int nomer = 0; nomer < COUNT_KAR; nomer++)
            {
            chasti[nomer].visible = false;
            }
            string strokaX;
            string strokaY;
            string adress;
            ifstream file("Fail1.txt");

            while (file.good())
            {
                getline(file, strokaX);
                if (strokaX.size() > 1)
                {
                    getline(file, strokaY);
                    getline(file, adress);

                    for (int nomer = 0; nomer < COUNT_KAR; nomer++)
                    {
                        if (adress == chasti[nomer].adress)
                        {
                            chasti[nomer].visible = true;
                            chasti[nomer].x = atoi(strokaX.c_str());
                            chasti[nomer].x2 = chasti[nomer].x + chasti[nomer].srk_width;
                            chasti[nomer].y = atoi(strokaY.c_str());
                            chasti[nomer].y2 = chasti[nomer].y + chasti[nomer].srk_height;
                        }
                    }
                }
            }
            file.close();
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
