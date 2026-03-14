#include <stdio.h>
#include <string.h>

int main() {
    char kode[10];
    float beratButet, beratUcok, totalBerat, ongkirPerKg, totalOngkos;
    char namaKota[20];
    char asuransi[20];
    float diskon = 0;

    while (1) {
        // Input Kode Kota
        printf("Masukkan Kode Kota (atau 'END' untuk berhenti): ");
        scanf("%s", kode);

        // Cek jika input adalah END
        if (strcmp(kode, "END") == 0) {
            break;
        }

        // Input Berat Paket Butet
        printf("Masukkan Berat Paket Butet (kg): ");
        scanf("%f", &beratButet);

        // Menentukan Harga dan Nama Kota berdasarkan Kode
        if (strcmp(kode, "MDN") == 0) {
            strcpy(namaKota, "Medan");
            ongkirPerKg = 8000;
            strcpy(asuransi, "-");
        } else if (strcmp(kode, "BLG") == 0) {
            strcpy(namaKota, "Balige");
            ongkirPerKg = 5000;
            strcpy(asuransi, "-");
        } else if (strcmp(kode, "JKT") == 0) {
            strcpy(namaKota, "Jakarta");
            ongkirPerKg = 12000;
            strcpy(asuransi, "Gratis"); // Luar Pulau
        } else if (strcmp(kode, "SBY") == 0) {
            strcpy(namaKota, "Surabaya");
            ongkirPerKg = 13000;
            strcpy(asuransi, "Gratis"); // Luar Pulau
        } else {
            printf("Kode Kota tidak valid!\n\n");
            continue;
        }

        // Logika Perhitungan Berat (Ucok = 1.5 * Butet)
        beratUcok = 1.5 * beratButet;
        totalBerat = beratButet + beratUcok;

        // Hitung Ongkos Dasar
        totalOngkos = totalBerat * ongkirPerKg;

        // Logika Promo Lebaran (Diskon 10% jika berat > 10kg)
        diskon = 0;
        if (totalBerat > 10) {
            diskon = 0.10 * totalOngkos;
            totalOngkos = totalOngkos - diskon;
        }

        // Output Struk Pembayaran
        printf("\n========== STRUK PEMBAYARAN DEL-EXPRESS ==========\n");
        printf("Kota Tujuan         : %s\n", namaKota);
        printf("Berat Paket Butet   : %.2f kg\n", beratButet);
        printf("Berat Paket Ucok    : %.2f kg\n", beratUcok);
        printf("Total Berat         : %.2f kg\n", totalBerat);
        printf("--------------------------------------------------\n");
        printf("Diskon (10%%)        : Rp %.2f\n", diskon);
        printf("Asuransi            : %s\n", asuransi);
        printf("TOTAL ONGKOS KIRIM  : Rp %.2f\n", totalOngkos);
        printf("==================================================\n\n");
    }

    printf("Program Selesai. Terima kasih!\n");

    return 0;
}