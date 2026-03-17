#include <stdio.h>
#include <string.h>

int main() {
    char kode[5];
    float berat, total_berat = 0;
    int ongkir_perkg;
    float total_ongkir = 0;
    
    printf("=== DEL EXPRESS ===\n");
    printf("DAFTAR ONGKOS KIRIM:\n");
    printf("MDN - Medan     : 8000/kg (Dalam Pulau)\n");
    printf("BLG - Balige    : 5000/kg (Dalam Pulau)\n");
    printf("JKT - Jakarta   : 12000/kg (Luar Pulau)\n");
    printf("SBY - Surabaya  : 13000/kg (Luar Pulau)\n");
    printf("Ketik END untuk selesai\n\n");

    while (1) {
        printf("Masukkan kode kota: ");
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            break;
        }

        printf("Masukkan berat paket (kg): ");
        scanf("%f", &berat);

        // Tentukan ongkir
        if (strcmp(kode, "MDN") == 0) {
            ongkir_perkg = 8000;
            printf("Tujuan: Medan\n");
        } else if (strcmp(kode, "BLG") == 0) {
            ongkir_perkg = 5000;
            printf("Tujuan: Balige\n");
        } else if (strcmp(kode, "JKT") == 0) {
            ongkir_perkg = 12000;
            printf("Tujuan: Jakarta\n");
        } else if (strcmp(kode, "SBY") == 0) {
            ongkir_perkg = 13000;
            printf("Tujuan: Surabaya\n");
        } else {
            printf("Kode tidak valid!\n\n");
            continue;
        }

        total_berat += berat;
        total_ongkir += berat * ongkir_perkg;

        printf("--------------------------\n");
    }

    // Promo
    float diskon = 0;
    int asuransi = 0;

    if (total_berat > 10) {
        diskon = 0.1 * total_ongkir;
    }

    // cek luar pulau (JKT / SBY)
    if (strstr("JKT SBY", kode) != NULL) {
        asuransi = 1;
    }

    float total_bayar = total_ongkir - diskon;

    printf("\n=== HASIL AKHIR ===\n");
    printf("Total Berat Paket : %.2f kg\n", total_berat);
    printf("Total Ongkir      : Rp %.0f\n", total_ongkir);
    printf("Diskon            : Rp %.0f\n", diskon);
    printf("Total Bayar       : Rp %.0f\n", total_bayar);

    if (asuransi) {
        printf("Promo             : Asuransi GRATIS (Luar Pulau)\n");
    }

    if (diskon > 0) {
        printf("Promo             : Diskon 10%% (Lebih dari 10kg)\n");
    }

    return 0;
}