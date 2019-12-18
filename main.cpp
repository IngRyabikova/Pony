/*!
\file
\brief ������� ���� ���������
*/

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

/*!
������ �� ���������� �� ������
*/
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

    /// �������� ��� ����
    HDC fon = txLoadImage("Pictures/fon/fon.bmp");
    HDC fan = txLoadImage("Pictures/fon/Java.bmp");
    HDC fen = txLoadImage("Pictures/fon/������.bmp");
    HDC fyn = txLoadImage("Pictures/fon/����.bmp");
    HDC fun = txLoadImage("Pictures/fon/���.bmp");
    HDC fin = txLoadImage("Pictures/fon/����.bmp");

     ///  ��������� ������
    const int COUNT_BUTT = 7;
    MenuButton buttons[COUNT_BUTT];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"�����", 530, 140, "xvost"};
    buttons[1] = {buttons[0].baton, 0,400, 90,180,"������", 530, 140, "kopta"};
    buttons[2] = {buttons[0].baton, 0,400,180,270,"������", 530, 140, "Head"};
    buttons[3] = {buttons[0].baton, 0,400,270,360,"����", 530, 140, "Telo"};
    buttons[4] = {buttons[0].baton, 0,400,360,450,"�������", 530, 140, ""};
    buttons[5] = {buttons[0].baton, 0,400,450,540,"���������", 530, 140,""};
    buttons[6] = {buttons[0].baton, 0,400,540,630,"���������", 530, 140,""};

    int COUNT_KAR = 0;
    MapObject variants[1000];

    /// ���������� ������� �������� ��� ������� �� ��������
    COUNT_KAR = chtenie("Pictures/Telo/",  COUNT_KAR, variants);
    COUNT_KAR = chtenie("Pictures/xvost/", COUNT_KAR, variants);
    COUNT_KAR = chtenie("Pictures/Head/",  COUNT_KAR, variants);
    COUNT_KAR = chtenie("Pictures/kopta/", COUNT_KAR, variants);

    int y_Head = 0;
    int y_xvost = 0;
    int y_kopta = 0;
    int y_Telo = 0;

     /// ��������� ���������� ������� �������� ��� ������� �� ��������
    for (int i = 0; i < COUNT_KAR; i++)
    {
        variants[i].x = 1000;
        variants[i].x2 = 1200;
        string stroka = variants[i].adress;
        int onepose = stroka.find("/");
        int twopose = stroka.find("/", onepose + 1);
        variants[i].Kategorya = stroka.substr(onepose + 1, twopose - onepose - 1);

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


    bool GemeStart = false;

     /// ����� ������ ����)))))))))))))))))))))))))))))))))))))))))))))))
    while (GemeStart == false)
    {
        txSelectFont("Arial", 95);
        txTextOut(100,10, "��� ����� ������ � ����?");

        Win32::TransparentBlt (txDC(), 100, 100, 300, 200, fon, 0, 0, 1200,700,-1);
        Win32::TransparentBlt (txDC(), 450, 100, 300, 200, fan, 0, 0, 1200,700,-1);
        Win32::TransparentBlt (txDC(), 800, 100, 300, 200, fen, 0, 0, 1200,700,-1);
        Win32::TransparentBlt (txDC(), 100, 400, 300, 200, fyn, 0, 0, 1200,700,-1);
        Win32::TransparentBlt (txDC(), 450, 400, 300, 200, fun, 0, 0, 1200,700,-1);
        Win32::TransparentBlt (txDC(), 800, 400, 300, 200, fin, 0, 0, 1200,700,-1);

        if (txMouseButtons() & 1)
        {
            GemeStart = true;
            if (    txMouseX() > 100  &&
                    txMouseX() < 100 + 300 &&
                    txMouseY() > 100  &&
                    txMouseY() < 100 + 200)
            {
                fon = fon;

            }
            if (    txMouseX() > 450  &&
                    txMouseX() < 450 + 300 &&
                    txMouseY() > 100  &&
                    txMouseY() < 100 + 200)
            {
                fon = fan;

            }

            if (    txMouseX() > 800  &&
                    txMouseX() < 800 + 300 &&
                    txMouseY() > 100  &&
                    txMouseY() < 100 + 200)
            {
                fon = fen;

            }
            if (    txMouseX() > 100  &&
                    txMouseX() < 100 + 300 &&
                    txMouseY() > 400  &&
                    txMouseY() < 400 + 200)
            {
                fon = fyn;

            }
            if (    txMouseX() > 450  &&
                    txMouseX() < 450 + 300 &&
                    txMouseY() > 400  &&
                    txMouseY() < 400 + 200)
            {
                fon = fun;

            }
            if (    txMouseX() > 800  &&
                    txMouseX() < 800 + 300 &&
                    txMouseY() > 400  &&
                    txMouseY() < 400 + 200)
            {
                fon = fin;

            }

        }

        txSleep(10);

    }


    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_GREEN);
        txClear();
        risyemChasti (COUNT_KAR, chasti) ;

        if (nomer_vybrannoi_kartinki >= 0)
        {
        	/// ����� ��������� ������ ����
            if (chasti[nomer_vybrannoi_kartinki].Click() and txGetPixel (txMouseX(), txMouseY()) != TX_GREEN)
            {
                chasti[nomer_vybrannoi_kartinki].najatieKartinki = true;
            }
            /// ������������ ���������� � ������� ����
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

        if  (GetAsyncKeyState(VK_RETURN))
        {
            for (int i = 0; i < COUNT_KAR; i++)
            {
                chasti[i].visible = false;
            }
        }
        /// ����� ��������
        if (GetAsyncKeyState('W'))
        {
            txPlaySound("Pony.wav", SND_LOOP );
        }
        /// ����� �� ��������
        else if (GetAsyncKeyState(VK_SPACE))
        {
            txPlaySound(NULL);
        }
        /// ������� ��� �����)))))))))
        if (buttons[FOR_CHAINIKOV].Click())
        {
            txSleep(200);
            bool stop = false;
            while (stop == false)
            {
               txSetFillColor(TX_WHITE);
               txSetColor(TX_BLACK);
               txRectangle (0, 0,1200,1200);
               txSelectFont("Arial", 30);
               txDrawText(0, 0,1200,1200,
                    "\n"
                    "������� ��������\n"
                    "��� ����\n"
                    "��� ������ ����\n"
                    "\n"
                    "  ���� ������ �� ������ �� ������ �����������(����� ����)\n"
                    "  �� ���� ��� ������ �� ������� (�� �� ��������) ������ ����� ������� ����� �� W\n"
                    "  ���� ������ �� ENTER �� ���� �������� �������\n"
                    "* ���� �� �������, ����������� ��� �� ������� ������ 300.          \n"
                    "  ����� �� ����� �� �� �������, �� ���� �������� �������� ��������.\n"
                    "  (89374575744)\n"
                    "* ��� ������� �� ��������� �������� �� ����� ����������� � ������ �������\n"
                    " (��������� � ������).\n"
                    "* ���� ����� ������� �� �������� ��������, ��� ������ �� + ��� - �� �������� ������� ���� ������.\n"
                    "* ���� �������� �������� � ����� � ���������� (pictures) �� ��� �������� � ����\n"
                    " (����... ��������� 4 �����)\n"
                    "* ���� ������ �� ��������� ��� ��������� �� ���� �������� ���������� ��� ����������.\n"

                    "\n"
                    "����\n");

                if (txMouseButtons() == 1)
                {
                    stop = true;
                    txSleep(200);
                }

                txSleep(20);
            }
        }


        /// �������� �� ������ ������

        if (GetAsyncKeyState(VK_SNAPSHOT))
        {
            ScreenCapture(395,50,575,500, "1.bmp", txWindow());
            txMessageBox("��������� � 1.bmp");
        }

        /// ���������� �� ������ ������

          if (buttons[SAVEBUTT].Click())
        {
               saveToFile (COUNT_KAR, chasti);
        }

         /// �������� �� ������ ������

        else if (buttons[LOADBUTT].Click())
        {
               loadFromFile (COUNT_KAR, chasti);
        }

        /// �������� ��� �� ��������� � ������

        for (int i = 0; i < COUNT_BUTT; i = i + 1)
        {
            if (buttons [i].Click() && buttons[i].Kategorya != "")
            {
                selected_category = buttons[i].Kategorya;

                bool vseNorm = false;
                for (int k = 0; k < COUNT_KAR; k++)
                {
                    if (variants[k].Kategorya == selected_category)
                        vseNorm = true;
                }

                if (!vseNorm)
                {
                    txMessageBox("����� ����� ������� �������� ��� ������������� �����, � � ���� �� ��������?");
                }

                txSleep(200);
            }
        }

         /// ������ ��������

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

        /// ������� �����

        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_LEFT))
           {
             chasti[nomer_vybrannoi_kartinki].x -= 3;
             chasti[nomer_vybrannoi_kartinki].x2 -= 3;
           }

       /// ������� ������

        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_RIGHT))
           {
             chasti[nomer_vybrannoi_kartinki].x += 3;
             chasti[nomer_vybrannoi_kartinki].x2 += 3;
           }

        /// ������� �����

        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_UP))
           {
             chasti[nomer_vybrannoi_kartinki].y -= 3;
             chasti[nomer_vybrannoi_kartinki].y2 -= 3;
           }

        /// ������� ����

        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_DOWN))
           {
             chasti[nomer_vybrannoi_kartinki].y += 3;
             chasti[nomer_vybrannoi_kartinki].y2 += 3;
           }

       /// ���������� ����������


        if (nomer_vybrannoi_kartinki >= 0 && GetAsyncKeyState(VK_OEM_MINUS))
           {
             chasti[nomer_vybrannoi_kartinki].x2 = chasti[nomer_vybrannoi_kartinki].x +
             (chasti[nomer_vybrannoi_kartinki].x2-chasti[nomer_vybrannoi_kartinki].x)*0.99;
             chasti[nomer_vybrannoi_kartinki].y2 = chasti[nomer_vybrannoi_kartinki].y +
             (chasti[nomer_vybrannoi_kartinki].y2-chasti[nomer_vybrannoi_kartinki].y)*0.99;
           }

        /// ���������� ����������

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

    /// �������� ���������

    txDeleteDC (fon);
    txDeleteDC (fan);
    txDeleteDC (fen);
    txDeleteDC (fyn);
    txDeleteDC (fun);
    txDeleteDC (fin);

    for (int i = 0; i < COUNT_BUTT; i++)
    {
        txDeleteDC (buttons[i].baton);
     }
    for (int i = 0; i < COUNT_KAR; i++)
    {
        txDeleteDC (variants[i].picture);
        txDeleteDC (chasti[i].picture);
    }

    return 0;
}
