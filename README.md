# Asal Sayı Bulucu (Prime Number Finder)

Bu proje, büyük sayı dosyalarından asal sayıları bulmak ve bunları ayrı dosyalara yazmak için tasarlanmış çok iş parçacıklı (multi-threaded) bir C++ uygulamasıdır.

## Özellikler

- Çok iş parçacıklı işleme (Multi-threaded processing)
- Her iş parçacığı için ayrı çıktı dosyası
- Yüksek performanslı asal sayı kontrolü
- Otomatik iş yükü dağıtımı
- Türkçe hata ve durum mesajları

## Gereksinimler

- C++17 veya üzeri
- GCC/G++ derleyici
- Windows veya Linux işletim sistemi
- Make (derleme için)

## Kurulum

1. Projeyi klonlayın:
```bash
git clone [repo-url]
```

2. Proje dizinine gidin:
```bash
cd [project-directory]
```

3. Projeyi derleyin:
```bash
make all
```

## Kullanım

1. Girdi dosyasını `shared` klasörüne yerleştirin (varsayılan: `10000000.txt`)

2. Programı çalıştırın:
```bash
make run
```

3. Performans ölçümü yapın:
```bash
make measure
```

## Çıktı Dosyaları

Program, her iş parçacığı için ayrı bir çıktı dosyası oluşturur:
- `prime_numbers_thread_0.txt`
- `prime_numbers_thread_1.txt`
- `prime_numbers_thread_2.txt`
- ...

## Yapılandırma

`src/main.cpp` dosyasında aşağıdaki parametreleri değiştirebilirsiniz:

- `NUM_THREADS`: Kullanılacak iş parçacığı sayısı
- `BATCH_SIZE`: Her iş parçacığının işleyeceği sayı grubu boyutu

## Temizleme

Derleme çıktılarını temizlemek için:
```bash
make clean
```

## Performans

Program, iş parçacığı sayısına göre otomatik olarak iş yükünü dağıtır. Her iş parçacığı kendi çıktı dosyasına yazar, böylece yazma işlemleri arasında çakışma olmaz.

## Lisans

Bu proje MIT lisansı altında lisanslanmıştır. 