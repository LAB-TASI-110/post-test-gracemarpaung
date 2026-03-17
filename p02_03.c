#include <stdio.h>
#include <string.h>

int main() {
    int pilihan;
    float berat, total = 0, harga = 0, diskon = 0;
    char nim[20];
    char lagi;

    do {
        printf("\n=== KASIR LAUNDRY DEL ===\n");
        printf("1. Cuci Kering        : Rp5000/kg\n");
        printf("2. Cuci Setrika       : Rp7000/kg\n");
        printf("3. Setrika saja       : Rp4000/kg\n");

        printf("Pilih layanan (1-3): ");
        scanf("%d", &pilihan);

        printf("Masukkan berat (kg): ");
        scanf("%f", &berat);

        // menentukan harga
        switch(pilihan) {
            case 1: harga = 5000; break;
            case 2: harga = 7000; break;
            case 3: harga = 4000; break;
            default:
                printf("Pilihan tidak valid!\n");
                harga = 0;
        }

        total += harga * berat;

        printf("Tambah transaksi? (y/n): ");
        scanf(" %c", &lagi);

    } while(lagi == 'y' || lagi == 'Y');

    // input NIM untuk diskon
    printf("\nMasukkan NIM (jika mahasiswa, jika tidak isi 0): ");
    scanf("%s", nim);

    if(strcmp(nim, "0") != 0) {
        diskon = 0.1 * total;
    }

    float bayar = total - diskon;

    // output struk
    printf("\n===== STRUK LAUNDRY DEL =====\n");
    printf("Total        : Rp%.0f\n", total);
    printf("Diskon       : Rp%.0f\n", diskon);
    printf("Total Bayar  : Rp%.0f\n", bayar);
    printf("Terima kasih!\n");

    return 0;
}