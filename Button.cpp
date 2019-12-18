/*!
\file
\brief Кнопки
*/

#include "TXLib.h"


struct MenuButton
{
    HDC baton;
    /// ЛЕВАЯ
    int x1;
    /// ПРАВАЯ
    int x2;
    /// ВЕРХ
    int y1;
    /// НИЗ
    int y2;
    /// Текст
    const char* text;
   ///Изначальная ширина
    int shirina;
   ///Изначальная высота
    int vysota;
    /// Категория картинки
    char* Kategorya;
    ///  Количество картинок в категории
    int countPics;

    /*!
     Рисование кнопки
    */
    void drawButton()
    {
        txSelectFont("Arial", 30);
        Win32::TransparentBlt(txDC(), x1,   y1, x2 - x1, y2-y1, baton, 0, 0, shirina, vysota, TX_BLACK);
        txDrawText      (x1, y1, x2, y2, text);
    }

    /*!
     Клик
    */
    bool Click()
    {
        if (txMouseButtons() == 1 &&
                txMouseX() > x1  &&
                txMouseX() < x2 &&
                txMouseY() > y1  &&
                txMouseY() < y2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
