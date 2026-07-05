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
    printf("calue     : %.2f\n", sensor.value);
    printf("time     : %ld\n", sensor.timestamp);

    // verileri dosyaya atma

    FILE* fp = fopen("veri.log", "wb"); // dosya açıldı.(wb olduğu için tekrar açıldığında içindekiler silincek)
    if (fp == NULL)
    {
        printf("dosya acilmadi!!!");
        return 1;
    }
    fwrite(&sensor, sizeof(struct SensorPacket), 1, fp);

    fclose(fp);

    printf("\nPaket 'veri.log' dosyasina yazildi.\n\n");

    struct SensorPacket okunan;
    
    fp = fopen("veri.log", "rb");

    if (fp == NULL) {

        printf("dosya acilmadi!!!");
        return 1;
    }

    fread(&okunan, sizeof(struct SensorPacket), 1, fp);

    printf("=== Okunan Paket ===\n");

    switch (okunan.id)
    {
        case derinlik:
            printf("sensor: derinlik (ID:%d)\n",derinlik);
            printf("value:%f\n",okunan.value);
            printf("time: %ld\n",okunan.timestamp);
            break;
        case pil:
            printf("sensor: pil (ID:%d)\n",pil);
            printf("value:%f\n", okunan.value);
            printf("time: %ld\n", okunan.timestamp);
            break;
        case GPS:
            printf("sensor: GPS (ID:%d)\n",GPS);
            printf("value:%.2f\n", okunan.value);
            printf("time: %ld\n", okunan.timestamp);
            break;
        default:
            printf("hatalı sensor");
            break;
    }

    fclose(fp);

    return 0;
}

