# AquilaTelemetrySim

Basit bir sensör telemetri simülasyonu. Bir su altı robotunun (derinlik, pil, GPS) 
sensör verilerini struct olarak paketleyip binary dosyaya yazma ve geri okuma 
mantığını gösterir.

## Amaç
AQUILA-S (su altı robotu) projesinde kullanılacak Pixhawk/MAVLink 
tarzı veri paketleme mantığını küçük ölçekte öğrenmek için yazıldı.

## Özellikler
- `struct SensorPacket` ile sensör verisi modelleme
- `enum` ile sensör tipi tanımlama (derinlik, pil, GPS)
- Binary dosyaya yazma (`fwrite`) ve okuma (`fread`)
- `switch` ile sensör tipine göre farklı çıktı

## Nasıl çalıştırılır
Visual Studio ile açıp derleyin (C konsol uygulaması).
