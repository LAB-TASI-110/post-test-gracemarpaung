#include <stdio.h>
#include <string.h>

int main() {
    int pilihan, jumlah;
    float total = 0;
    char lanjut;

    printf("=== Sistem Operasional Kafeteria ===\n");
    printf("1. Nasi Goreng  - Rp 15.000\n");
    printf("2. Ayam Penyet  - Rp 18.000\n");
    printf("3. Es Teh Manis - Rp 5.000\n");
    printf("====================================\n");

    do {
        printf("\nMasukkan nomor menu: ");
        scanf("%d", &pilihan);
        printf("Masukkan jumlah porsi: ");
        scanf("%d", &jumlah);

        if (pilihan == 1) total += 15000 * jumlah;
        else if (pilihan == 2) total += 18000 * jumlah;
        else if (pilihan == 3) total += 5000 * jumlah;
        else printf("Menu tidak tersedia.\n");

        printf("Tambah pesanan lain? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    printf("\nTotal yang harus dibayar: Rp %.2f\n", total);
    printf("Terima kasih telah memesan!\n");

    return 0;
}