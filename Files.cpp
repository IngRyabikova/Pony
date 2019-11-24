#include <fstream>
#include <string>

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

void saveToFile (int COUNT_CAR, MapObject chasti[])
{
    ofstream file1("Fail1.txt");

    for (int nomer = 0; nomer < COUNT_CAR; nomer++)
    {
        if (chasti[nomer].visible)
        {
            file1 << chasti[nomer].x << endl;
            file1 << chasti[nomer].y << endl;
            file1 << chasti[nomer].adress << endl;
        }
    }

    file1.close();

    txMessageBox("Сохранено в Fail1.txt");
}

void loadFromFile (int COUNT_KAR, MapObject chasti[])
{
	string strokaX;
	string strokaY;
	string adress;
	ifstream file("Fail1.txt");
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
