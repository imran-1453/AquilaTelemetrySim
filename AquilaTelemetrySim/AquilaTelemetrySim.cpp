#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Sensor{derinlik,pil,GPS};

struct SensorPacket {
    int id;  // 0 = derinlik, 1 = pil, 2 = GPS
    float value; // olculen deger
    long timestamp; // degerin olculdugu zaman

};

int main()
{
    struct SensorPacket sensor;

    sensor = { pil,57,(long)time(NULL) }; /// ornek bir deger atadım.

    /// sensor verileri ekrana yazdirildi 

    printf("=== Olusturulan Paket ===\n");
    printf("Sensor ID : %d\n", sensor.id);
    printf("Deger     : %.2f\n", sensor.value);
    printf("Zaman     : %ld\n", sensor.timestamp);

    // verileri dosyaya atma

    FILE* fp = fopen("veri.log", "wb"); // dosya açıldı.(wb olduğu için tekrar açıldığında içindekiler silincek)
    if (fp == NULL)
    {
        printf("dosya acilmadi!!!");
        return 1;
    }
    fwrite(&sensor, sizeof(struct SensorPacket), 1, fp);

    fclose(fp);

    printf("\nPaket 'veri.log' dosyasina yazildi.\n");


    return 0;
}

