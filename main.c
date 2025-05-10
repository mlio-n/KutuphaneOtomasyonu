#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Kitap {
    int numara;
    char isim[100];
    char yazar[50];
    int sayfa_sayisi;
};

struct Kullanici {
    int numara;
    char isim[50];
    char soyisim[50];
    char dogum_tarihi[20];
};

struct Odunc {
    int kullanici_numara;
    int kitap_numara;
    char baslangic_tarihi[20];
};

#define KITAP "kitaplar.txt"
#define KULLANICI "kullanicilar.txt"
#define ODUNC "odunc.txt"

void dosya_kontrol(FILE *dosya, const char *dosya_adi);
int rastgele_numara_uret(int min, int max);
int kitap_numara_uret();
int kullanici_numara_uret();
int kitap_odunc_alindi_mi(int kitap_numara);
int odunc_alinan_kitap_var_mi(int kullanici_numara);

void ana_menu();
void kitap_islemleri_menu();
void kullanici_islemleri_menu();
void odunc_alma_menu();

void kitap_ekle();
void kitap_listele();
void kitap_guncelle();
void kitap_sil();
void kitap_ara();

void kullanici_ekle();
void kullanici_listele();
void kullanici_guncelle();
void kullanici_sil();
void kullanici_ara();

void odunc_al();
void kitap_geri_getir();
void odunc_listele();

int main() {
    srand(time(NULL));
    ana_menu();
    return 0;
}

void dosya_kontrol(FILE *dosya, const char *dosya_adi) {
    if (dosya == NULL) {
        printf("%s dosyasi olusturulamadi veya acilamadi.\n", dosya_adi);
        exit(EXIT_FAILURE);
    }
}

int rastgele_numara_uret(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int kitap_numara_uret() {
    return rastgele_numara_uret(1, 1000);
}

int kullanici_numara_uret() {
    return rastgele_numara_uret(1, 100);
}

void ana_menu() {
    int secim;
    do {
        printf("\nAna Menu\n");
        printf("1. Kitap Islemleri\n");
        printf("2. Kullanici Islemleri\n");
        printf("3. Odunc Alma Islemleri\n");
        printf("0. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                kitap_islemleri_menu();
                break;
            case 2:
                kullanici_islemleri_menu();
                break;
            case 3:
                odunc_alma_menu();
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Hatali secim! Tekrar deneyin.\n");
        }
    } while (secim != 0);
}

void kitap_islemleri_menu() {
    int secim;
    do {
        printf("\nKitap Islemleri Menu\n");
        printf("1. Kitap Ekle\n");
        printf("2. Kitap Listele\n");
        printf("3. Kitap Guncelle\n");
        printf("4. Kitap Sil\n");
        printf("5. Kitap Ara\n");
        printf("0. Ana Menuye Don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                kitap_ekle();
                break;
            case 2:
                kitap_listele();
                break;
            case 3:
                kitap_guncelle();
                break;
            case 4:
                kitap_sil();
                break;
            case 5:
                kitap_ara();
                break;
            case 0:
                printf("Ana menuye donuluyor...\n");
                break;
            default:
                printf("Hatali secim! Tekrar deneyin.\n");
        }
    } while (secim != 0);
}

void kullanici_islemleri_menu() {
    int secim;
    do {
        printf("\nKullanici Islemleri Menu\n");
        printf("1. Kullanici Ekle\n");
        printf("2. Kullanici Listele\n");
        printf("3. Kullanici Guncelle\n");
        printf("4. Kullanici Sil\n");
        printf("5. Kullanici Ara\n");
        printf("0. Ana Menuye Don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                kullanici_ekle();
                break;
            case 2:
                kullanici_listele();
                break;
            case 3:
                kullanici_guncelle();
                break;
            case 4:
                kullanici_sil();
                break;
            case 5:
                kullanici_ara();
                break;
            case 0:
                printf("Ana menuye donuluyor...\n");
                break;
            default:
                printf("Hatali secim! Tekrar deneyin.\n");
        }
    } while (secim != 0);
}

void odunc_alma_menu() {
    int secim;
    do {
        printf("\nOdunc Alma Islemleri Menu\n");
        printf("1. Odunc Alma\n");
        printf("2. Kitap Geri Getir\n");
        printf("3. Odunc Listele\n");
        printf("0. Ana Menuye Don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                odunc_al();
                break;
            case 2:
                kitap_geri_getir();
                break;
            case 3:
                odunc_listele();
                break;
            case 0:
                printf("Ana menuye donuluyor...\n");
                break;
            default:
                printf("Hatali secim! Tekrar deneyin.\n");
        }
    } while (secim != 0);
}

void kitap_ekle() {
    struct Kitap yeni_kitap;
    FILE *dosya;
    dosya = fopen(KITAP, "a");
    dosya_kontrol(dosya, "Kitaplar");

    yeni_kitap.numara = kitap_numara_uret();

    printf("Kitap Adi: ");
    scanf("%s", yeni_kitap.isim);
    printf("Yazar: ");
    scanf("%s", yeni_kitap.yazar);
    printf("Sayfa Sayisi: ");
    scanf("%d", &yeni_kitap.sayfa_sayisi);

    fprintf(dosya, "%d %s %s %d\n", yeni_kitap.numara, yeni_kitap.isim, yeni_kitap.yazar, yeni_kitap.sayfa_sayisi);

    printf("Kitap basariyla eklendi.\n");
    fclose(dosya);
}

void kitap_listele() {
    FILE *dosya;
    struct Kitap kitap;
    dosya = fopen(KITAP, "r");
    dosya_kontrol(dosya, "Kitaplar");

    printf("\nKitap Listesi:\n");

    while (fscanf(dosya, "%d %s %s %d\n", &kitap.numara, kitap.isim, kitap.yazar, &kitap.sayfa_sayisi) != EOF) {
        printf("Numara: %d, Isim: %s, Yazar: %s, Sayfa Sayisi: %d\n", kitap.numara, kitap.isim, kitap.yazar, kitap.sayfa_sayisi);
    }

    fclose(dosya);
}

void kitap_guncelle() {
    int numara;
    printf("Guncellenecek kitap numarasini girin: ");
    scanf("%d", &numara);

    FILE *dosya, *temp_dosya;
    struct Kitap kitap;

    dosya = fopen(KITAP, "r");
    temp_dosya = fopen("temp_kitaplar.txt", "w");

    dosya_kontrol(dosya, "Kitaplar");
    dosya_kontrol(temp_dosya, "Gecici Kitaplar Dosyasi");

    int bulundu = 0;

    while (fscanf(dosya, "%d %s %s %d\n", &kitap.numara, kitap.isim, kitap.yazar, &kitap.sayfa_sayisi) != EOF) {
        if (kitap.numara == numara) {
            bulundu = 1;

            printf("Yeni Isim: ");
            scanf("%s", kitap.isim);
            printf("Yeni Yazar: ");
            scanf("%s", kitap.yazar);
            printf("Yeni Sayfa Sayisi: ");
            scanf("%d", &kitap.sayfa_sayisi);

            fprintf(temp_dosya, "%d %s %s %d\n", kitap.numara, kitap.isim, kitap.yazar, kitap.sayfa_sayisi);
            printf("Kitap basariyla guncellendi.\n");
        } else {
            fprintf(temp_dosya, "%d %s %s %d\n", kitap.numara, kitap.isim, kitap.yazar, kitap.sayfa_sayisi);
        }
    }

    if (!bulundu) {
        printf("Belirtilen numarada kitap bulunamadi.\n");
    }

    fclose(dosya);
    fclose(temp_dosya);

    remove(KITAP);
    rename("temp_kitaplar.txt", KITAP);
}

void kitap_sil() {
    int silinecek_numara;
    printf("Silinecek Kitap Numarasini Girin: ");
    scanf("%d", &silinecek_numara);

    FILE *temp_file, *dosya;
    struct Kitap kitap;

    temp_file = fopen("temp.txt", "w");
    dosya = fopen(KITAP, "r");

    dosya_kontrol(temp_file, "Temp");
    dosya_kontrol(dosya, "Kitaplar");

    int kitap_silindi = 0;

    while (fscanf(dosya, "%d %s %s %d\n", &kitap.numara, kitap.isim, kitap.yazar, &kitap.sayfa_sayisi) != EOF) {
        if (kitap.numara == silinecek_numara) {
            printf("Kitap Silindi: Numara: %d, Isim: %s, Yazar: %s, Sayfa Sayisi: %d\n", kitap.numara, kitap.isim, kitap.yazar, kitap.sayfa_sayisi);
            kitap_silindi = 1;
        } else {
            fprintf(temp_file, "%d %s %s %d\n", kitap.numara, kitap.isim, kitap.yazar, kitap.sayfa_sayisi);
        }
    }

    fclose(dosya);
    fclose(temp_file);

    if (!kitap_silindi) {
        printf("Kitap bulunamadi.\n");
    } else {
        temp_file = fopen("temp.txt", "r");
        dosya = fopen(KITAP, "w");

        dosya_kontrol(temp_file, "Temp");
        dosya_kontrol(dosya, "Kitaplar");

        while (fscanf(temp_file, "%d %s %s %d\n", &kitap.numara, kitap.isim, kitap.yazar, &kitap.sayfa_sayisi) != EOF) {
            fprintf(dosya, "%d %s %s %d\n", kitap.numara, kitap.isim, kitap.yazar, kitap.sayfa_sayisi);
        }

        fclose(dosya);
        fclose(temp_file);

        remove("temp.txt");
    }
}

void kitap_ara() {
    int numara;
    printf("Aranacak kitap numarasini girin: ");
    scanf("%d", &numara);

    FILE *dosya;
    struct Kitap kitap;

    dosya = fopen(KITAP, "r");
    dosya_kontrol(dosya, "Kitaplar");

    int bulundu = 0;

    while (fscanf(dosya, "%d %s %s %d\n", &kitap.numara, kitap.isim, kitap.yazar, &kitap.sayfa_sayisi) != EOF) {
        if (kitap.numara == numara) {
            bulundu = 1;

            printf("Numara: %d, Isim: %s, Yazar: %s, Sayfa Sayisi: %d\n", kitap.numara, kitap.isim, kitap.yazar, kitap.sayfa_sayisi);
            break;
        }
    }

    if (!bulundu) {
        printf("Belirtilen numarada kitap bulunamadi.\n");
    }

    fclose(dosya);
}

void kullanici_ekle() {
    struct Kullanici yeni_kullanici;
    FILE *dosya;
    dosya = fopen(KULLANICI, "a");
    dosya_kontrol(dosya, "Kullanicilar");

    yeni_kullanici.numara = kullanici_numara_uret();

    printf("Isim: ");
    scanf("%s", yeni_kullanici.isim);
    printf("Soyisim: ");
    scanf("%s", yeni_kullanici.soyisim);
    printf("Dogum Tarihi: ");
    scanf("%s", yeni_kullanici.dogum_tarihi);

    fprintf(dosya, "%d %s %s %s\n", yeni_kullanici.numara, yeni_kullanici.isim, yeni_kullanici.soyisim, yeni_kullanici.dogum_tarihi);

    printf("Kullanici basariyla eklendi.\n");
    fclose(dosya);
}

void kullanici_listele() {
    FILE *dosya;
    struct Kullanici kullanici;
    dosya = fopen(KULLANICI, "r");
    dosya_kontrol(dosya, "Kullanicilar");

    printf("\nKullanici Listesi:\n");

    while (fscanf(dosya, "%d %s %s %s\n", &kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi) != EOF) {
        printf("Numara: %d, Isim: %s, Soyisim: %s, Dogum Tarihi: %s\n", kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi);
    }

    fclose(dosya);
}

void kullanici_guncelle() {
    int numara;
    printf("Guncellenecek kullanici numarasini girin: ");
    scanf("%d", &numara);

    FILE *dosya, *temp_dosya;
    struct Kullanici kullanici;

    dosya = fopen(KULLANICI, "r");
    temp_dosya = fopen("temp_kullanicilar.txt", "w");

    dosya_kontrol(dosya, "Kullanicilar");
    dosya_kontrol(temp_dosya, "Gecici Kullanicilar Dosyasi");

    int bulundu = 0;

    while (fscanf(dosya, "%d %s %s %s\n", &kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi) != EOF) {
        if (kullanici.numara == numara) {
            bulundu = 1;

            printf("Yeni Isim: ");
            scanf("%s", kullanici.isim);
            printf("Yeni Soyisim: ");
            scanf("%s", kullanici.soyisim);
            printf("Yeni Dogum Tarihi: ");
            scanf("%s", kullanici.dogum_tarihi);

            fprintf(temp_dosya, "%d %s %s %s\n", kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi);
            printf("Kullanici basariyla guncellendi.\n");
        } else {
            fprintf(temp_dosya, "%d %s %s %s\n", kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi);
        }
    }

    if (!bulundu) {
        printf("Belirtilen numarada kullanici bulunamadi.\n");
    }

    fclose(dosya);
    fclose(temp_dosya);

    remove(KULLANICI);
    rename("temp_kullanicilar.txt", KULLANICI);
}

void kullanici_sil() {
    int numara;
    printf("Silinecek kullanici numarasini girin: ");
    scanf("%d", &numara);

    FILE *dosya, *temp_dosya;
    struct Kullanici kullanici;

    dosya = fopen(KULLANICI, "r");
    temp_dosya = fopen("temp_kullanicilar.txt", "w");

    dosya_kontrol(dosya, "Kullanicilar");
    dosya_kontrol(temp_dosya, "Gecici Kullanicilar Dosyasi");

    int bulundu = 0;

    while (fscanf(dosya, "%d %s %s %s\n", &kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi) != EOF) {
        if (kullanici.numara == numara) {
            bulundu = 1;
            printf("Silinen kullanici: %s %s\n", kullanici.isim, kullanici.soyisim);
        } else {
            fprintf(temp_dosya, "%d %s %s %s\n", kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi);
        }
    }

    if (!bulundu) {
        printf("Belirtilen numarada kullanici bulunamadi.\n");
    }

    fclose(dosya);
    fclose(temp_dosya);

    remove(KULLANICI);
    rename("temp_kullanicilar.txt", KULLANICI);
}

void kullanici_ara() {
    int numara;
    printf("Aranacak kullanici numarasini girin: ");
    scanf("%d", &numara);

    FILE *dosya;
    struct Kullanici kullanici;

    dosya = fopen(KULLANICI, "r");
    dosya_kontrol(dosya, "Kullanicilar");

    int bulundu = 0;

    while (fscanf(dosya, "%d %s %s %s\n", &kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi) != EOF) {
        if (kullanici.numara == numara) {
            bulundu = 1;

            printf("Numara: %d, Isim: %s, Soyisim: %s, Dogum Tarihi: %s\n", kullanici.numara, kullanici.isim, kullanici.soyisim, kullanici.dogum_tarihi);
            break;
        }
    }

    if (!bulundu) {
        printf("Belirtilen numarada kullanici bulunamadi.\n");
    }

    fclose(dosya);
}

void odunc_al() {
    int kullanici_numara, kitap_numara;
    char odunc_tarihi[20];

    printf("Kullanici numarasini girin: ");
    scanf("%d", &kullanici_numara);

    printf("Kitap numarasini girin: ");
    scanf("%d", &kitap_numara);

    if (kitap_odunc_alindi_mi(kitap_numara)) {
        printf("Belirtilen kitap zaten odunc alinmis.\n");
        return;
    }

    if (odunc_alinan_kitap_var_mi(kullanici_numara)) {
        printf("Bu öğrenci zaten bir kitap ödünç almış durumda.\n");
        return;
    }

    printf("Odunc alma tarihini girin (gg-aa-yyyy): ");
    scanf("%s", odunc_tarihi);

    FILE *dosya;
    dosya = fopen(ODUNC, "a");
    dosya_kontrol(dosya, "Odunc");

    fprintf(dosya, "%d %d %s\n", kullanici_numara, kitap_numara, odunc_tarihi);

    printf("Odunc alma islemi basariyla gerceklesti.\n");

    fclose(dosya);
}

void kitap_geri_getir() {
    int kullanici_numara, kitap_numara;
    char geri_getirme_tarihi[20];

    printf("Kullanici numarasini girin: ");
    scanf("%d", &kullanici_numara);

    printf("Kitap numarasini girin: ");
    scanf("%d", &kitap_numara);

    printf("Geri getirme tarihini girin (gg-aa-yyyy): ");
    scanf("%s", geri_getirme_tarihi);

    FILE *dosya, *temp_dosya;
    struct Odunc odunc;

    dosya = fopen(ODUNC, "r");
    temp_dosya = fopen("temp_odunc.txt", "w");

    dosya_kontrol(dosya, "Odunc");
    dosya_kontrol(temp_dosya, "Gecici Odunc Dosyasi");

    int bulundu = 0;

    while (fscanf(dosya, "%d %d %s\n", &odunc.kullanici_numara, &odunc.kitap_numara, odunc.baslangic_tarihi) != EOF) {
        if (odunc.kullanici_numara == kullanici_numara && odunc.kitap_numara == kitap_numara) {
            bulundu = 1;
            printf("Geri Getirilen Kitap: %d, Kullanici: %d, Odunc Tarihi: %s, Geri Getirme Tarihi: %s\n", odunc.kitap_numara, odunc.kullanici_numara, odunc.baslangic_tarihi, geri_getirme_tarihi);
        } else {
            fprintf(temp_dosya, "%d %d %s\n", odunc.kullanici_numara, odunc.kitap_numara, odunc.baslangic_tarihi);
        }
    }

    if (!bulundu) {
        printf("Belirtilen kitap odunc alinmamis.\n");
    }

    fclose(dosya);
    fclose(temp_dosya);

    remove(ODUNC);
    rename("temp_odunc.txt", ODUNC);
}

void odunc_listele() {
    FILE *dosya;
    struct Odunc odunc;
    dosya = fopen(ODUNC, "r");
    dosya_kontrol(dosya, "Odunc");

    printf("\nOdunc Listesi:\n");

    while (fscanf(dosya, "%d %d %s\n", &odunc.kullanici_numara, &odunc.kitap_numara, odunc.baslangic_tarihi) != EOF) {
        printf("Kullanici Numara: %d, Kitap Numara: %d, Baslangic Tarihi: %s\n",
               odunc.kullanici_numara, odunc.kitap_numara, odunc.baslangic_tarihi);
    }

    fclose(dosya);
}

int kitap_odunc_alindi_mi(int kitap_numara) {
    FILE *dosya = fopen(ODUNC, "r");
    if (dosya == NULL) {
        return 0;
    }

    struct Odunc odunc;

    while (fscanf(dosya, "%*d %d %*s %*s\n", &odunc.kitap_numara) != EOF) {
        if (odunc.kitap_numara == kitap_numara) {
            fclose(dosya);
            return 1;
        }
    }

    fclose(dosya);
    return 0;
}

int odunc_alinan_kitap_var_mi(int kullanici_numara) {
    FILE *dosya = fopen(ODUNC, "r");
    if (dosya == NULL) {
        return 0;
    }

    struct Odunc odunc;

    while (fscanf(dosya, "%d %*d %*s\n", &odunc.kullanici_numara) != EOF) {
        if (odunc.kullanici_numara == kullanici_numara) {
            fclose(dosya);
            return 1;
        }
    }

    fclose(dosya);
    return 0;
}
