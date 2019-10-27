
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


/*int main()
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

system("PAUSE");    *
}
    */
