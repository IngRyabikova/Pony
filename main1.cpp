

#include <iostream>
#include <fstream>
#include "TXLib.h"

using namespace std;

int main()
{
    char header[54];
    std::ifstream bmp;
    bmp.open("pony1.bmp");
    bmp.read(header, 54);

    uint16_t width = (uint8_t)header[23];
    width <<= 8;
    width += (uint8_t)header[22];
    cout << width << endl;

    uint16_t width = (uint8_t)header[19];
    width <<= 8;
    width += (uint8_t)header[18];
    cout << width << endl;

system("PAUSE");
}

