#include "TXLib.h"
#include "Button.cpp"
#include "MapObjects.cpp"
#include "Files.cpp"

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
        for (int i = 0; i <COUNT_BUTT; i++)
        {
            buttons[i].drawButton();
        }
}

int main()
{
    txCreateWindow(1200, 700);

    txPlaySound("Pony.wav", SND_LOOP );

    const int COUNT_BUTT = 5;
    MenuButton buttons[COUNT_BUTT];
    buttons[0] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,  0, 90,"����", 530, 140, "Pony"};
    buttons[1] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400, 90,180,"�����", 530, 140, "xvost"};
    buttons[2] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,180,270,"������", 530, 140, "kopta"};
    buttons[3] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,270,360,"������", 530, 140, "Head"};
    buttons[4] = {txLoadImage ("Pictures/Menu_Button.bmp"), 0,400,360,450,"����", 530, 140, "Telo"};

    const int COUNT_KAR = 13;
    MapObject variants[COUNT_KAR];
    variants[0] = {1000,  0,1200,200,"Pictures/Pony/pony1.bmp", "Pony"};
    variants[1] = {1000,200,1200,400,"Pictures/Pony/pony2.bmp", "Pony"};
    variants[2] = {1000,400,1200,600,"Pictures/Pony/pony4.bmp", "Telo"};
    variants[3] = {1000,  0,1200,200,"Pictures/Head/Head1.bmp"};
    variants[4] = {1000,200,1200,400,"Pictures/Head/Head2.bmp", "Head"};
    variants[5] = {1000,400,1200,600,"Pictures/Head/Head3.bmp", "Head"};
    variants[6] = {1000,  0,1200,200,"Pictures/xvost/xvost1.bmp", "xvost"};
    variants[7] = {1000,200,1200,400,"Pictures/xvost/xvost2.bmp", "xvost"};
    variants[8] = {1000,400,1200,600,"Pictures/xvost/xvost3.bmp", "xvost"};
    variants[9] = {1000,  0,1200,200,"Pictures/kopta/kopta1.bmp", "kopta"};
    variants[10] = {1000,200,1200,400,"Pictures/kopta/kopta2.bmp", "kopta"};
    variants[11] = {1000,400,1200,600,"Pictures/kopta/kopta3.bmp", "kopta"};
    variants[12] = {1000,400,1200,600,"Pictures/Pony/unicorn.bmp"};

    for (int i = 0; i < COUNT_KAR; i++)
    {
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
    chasti[0] = {400, 100, 1000, 500};
    chasti[1] = {400, 100, 1000, 500};
    chasti[2] = {400, 100, 1000, 500};
    chasti[3] = {500, 100, 740, 270};
    chasti[4] = {500, 100, 740, 270};
    chasti[5] = {500, 100, 740, 270};
    chasti[6] = {750, 250, 990, 420};
    chasti[7] = {750, 250, 990, 420};
    chasti[8] = {750, 250, 990, 420};
    chasti[9] = {550, 400,800,500};
    chasti[10] = {550, 400,800,500};
    chasti[11] = {550, 400,800,500};
    chasti[12] = {400,100,1000,500};

    for (int i = 0; i < COUNT_KAR; i++)
    {
        chasti[i].picture = variants[i].picture;
        chasti[i].Kategorya = variants[i].Kategorya;
        chasti[i].srk_width = variants[i].srk_width;
        chasti[i].srk_height = variants[i].srk_height;
        chasti[i].visible = false;
    }

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_GREEN);
        txClear();

        risyemKnopki (COUNT_BUTT, buttons) ;
        risyemKPony (COUNT_KAR, selected_category, variants);
        risyemChasti (COUNT_KAR, chasti) ;



        for (int i = 0; i < COUNT_BUTT; i = i + 1)
        {
            if (buttons [i].Click())
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



        //for(/*int i*/ nomer_vybrannoi_kartinki = 0; nomer_vybrannoi_kartinki < COUNT_KAR; nomer_vybrannoi_kartinki++)
        if (nomer_vybrannoi_kartinki >= 0)
        {
            if (chasti[nomer_vybrannoi_kartinki].Click() and txGetPixel (txMouseX(), txMouseY()) != TX_GREEN)
            {
                chasti[nomer_vybrannoi_kartinki].najatieKartinki = true;
            }

            //if (txGetPixel (x, y) == TX_GREEN)


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
