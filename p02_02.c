#include <stdio.h>

int main() {
    int n, i;
    int kategori[100];
    int stok[100];
    int pilih;
    int total = 0;

    // input jumlah data
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    // input kategori dan stok
    for(i = 0; i < n; i++) {
        printf("\nData ke-%d\n", i+1);
        printf("Kode kategori (1=Dasi, 2=Gula, 3=Rok Pramuka, 4=Minyak): ");
        scanf("%d", &kategori[i]);

        printf("Jumlah stok: ");
        scanf("%d", &stok[i]);
    }

    // pilih kategori yang ingin dihitung
    printf("\nPilih kategori yang ingin dihitung:\n");
    printf("1. Dasi (22 pcs)\n");
    printf("2. Gula (85 pcs)\n");
    printf("3. Rok Pramuka (5 pcs)\n");
    printf("4. Minyak (120 pcs)\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilih);

    // proses perhitungan total
    for(i = 0; i < n; i++) {
        if(kategori[i] == pilih) {
            total += stok[i];
        }
    }

    // output hasil
    printf("\nTotal stok kategori yang dipilih = %d pcs\n", total);

    return 0;
}