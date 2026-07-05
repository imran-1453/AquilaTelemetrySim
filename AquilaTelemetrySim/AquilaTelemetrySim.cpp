#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Sensor{derinlik,batarya,GPS};

struct SensorPacket {
    int id;  // 0 = derinlik, 1 = batarya, 2 = GPS
    float value; // olculen deger
    long timestamp; // degerin olculdugu zaman
};



int main()
{
    return 0;
}

