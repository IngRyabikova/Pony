#include <fstream>
#include <string>
#pragma once
#include <Windows.h>
//#include <string>
using namespace std;
using namespace std;

int get_height  (string adress)
{
	unsigned char info[54];
	FILE*f = fopen (adress.c_str() , "r");
	fread (info, sizeof (unsigned char), 54, f);
	int height =* (int*) &info[22];

	return height;
}

int get_widht  (string adress)
{
	unsigned char info[54];
	FILE*f = fopen (adress.c_str() , "r");
	fread (info, sizeof (unsigned char), 54, f);
	int widht =* (int*) &info[18];

	return widht;
}

string selectFile(HWND hWnd, bool save)
{
	const int SIZE = 100;
	char nameFile[SIZE];
	OPENFILENAMEA ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = nameFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = SIZE;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_CREATEPROMPT;

    if (save)
    {
        GetSaveFileNameA(&ofn);
    }
    else
    {
        GetOpenFileNameA(&ofn);
	}
	return nameFile;
}

void saveToFile (int COUNT_CAR, MapObject chasti[])
{
    string newNameFile = selectFile(txWindow(), true);
	ofstream file(newNameFile);

    for (int nomer = 0; nomer < COUNT_CAR; nomer++)
    {
        if (chasti[nomer].visible)
        {
            file << chasti[nomer].x << endl;
            file << chasti[nomer].y << endl;
            file << chasti[nomer].adress << endl;
        }
    }

    file.close();

    txMessageBox("Сохранено в Fail1.txt");
}

void loadFromFile (int COUNT_KAR, MapObject chasti[])
{
	string strokaX;
	string strokaY;
	string adress;
    string newNameFile = selectFile(txWindow(), false);
	ifstream file(newNameFile);
	for (int nomer = 0; nomer < COUNT_KAR; nomer++)
	{
		chasti[nomer].visible = false;
	}

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
