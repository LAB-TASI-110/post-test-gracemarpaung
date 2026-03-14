#include <stdio.h>
#include <string.h>

// Fungsi untuk Tugas 1: Del-Express
void programDelExpress() {
    char kode[10], namaKota[30], asuransi[30];
    float beratButet, beratUcok, totalBerat, hargaPerKg, totalOngkos, diskon;

    printf("\n--- Selamat Datang di Sistem Del-Express ---\n");
    
    while (1) {
        printf("Masukkan Kode Kota (MDN/BLG/JKT/SBY) atau ketik 'END': ");
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) break;

        printf("Masukkan Berat Paket Butet (kg): ");
        scanf("%f", &beratButet);

        // Logika Data Master sesuai gambar
        if (strcmp(kode, "MDN") == 0) {
            strcpy(namaKota, "Medan");
            hargaPerKg = 8000;
            strcpy(asuransi, "-");
        } else if (strcmp(kode, "BLG") == 0) {
            strcpy(namaKota, "Balige");
            hargaPerKg = 5000;
            strcpy(asuransi, "-");
        } else if (strcmp(kode, "JKT") == 0) {
            strcpy(namaKota, "Jakarta");
            hargaPerKg = 12000;
            strcpy(asuransi, "Gratis (Luar Pulau)");
        } else if (strcmp(kode, "SBY") == 0) {
            strcpy(namaKota, "Surabaya");
            hargaPerKg = 13000;
            strcpy(asuransi, "Gratis (Luar Pulau)");
        } else {
            printf("Kode kota tidak terdaftar!\n\n");
            continue;
        }

        // Hitung Berat Ucok (1.5x Butet sesuai gambar timbangan)
        beratUcok = 1.5 * beratButet;
        totalBerat = beratButet + beratUcok;
        totalOngkos = totalBerat * hargaPerKg;

        // Promo Lebaran: Diskon 10% jika berat > 10kg
        diskon = 0;
        if (totalBerat > 10) {
            diskon = 0.10 * totalOngkos;
            totalOngkos -= diskon;
        }

        // Tampilan Output Struk
        printf("\n============================================\n");
        printf("         STRUK PEMBAYARAN DEL-EXPRESS       \n");
        printf("============================================\n");
        printf("Kota Tujuan       : %s\n", namaKota);
        printf("Berat Paket Butet : %.2f kg\n", beratButet);
        printf("Berat Paket Ucok  : %.2f kg\n", beratUcok);
        printf("Total Berat       : %.2f kg\n", totalBerat);
        printf("--------------------------------------------\n");
        printf("Diskon Lebaran    : Rp %.0f\n", diskon);
        printf("Asuransi          : %s\n", asuransi);
        printf("TOTAL BAYAR       : Rp %.0f\n", totalOngkos);
        printf("============================================\n\n");
    }
}

// Fungsi untuk Tugas 2: Stok Gudang
void programStokGudang() {
    int n, kategori, totalStok = 0;

    printf("\n--- Sistem Manajemen Stok Gudang ---\n");
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &n);

    int stok[n];
    printf("Masukkan %d deret stok (pisahkan dengan spasi): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stok[i]);
    }

    printf("Pilih Kategori (1 untuk Ganjil, 0 untuk Genap): ");
    scanf("%d", &kategori);

    // Menghitung total stok berdasarkan pola posisi ganjil/genap
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == kategori) {
            totalStok += stok[i];
        }
    }

    printf("\n>>> Total stok untuk kategori %s adalah: %d\n\n", 
           (kategori == 1 ? "Ganjil" : "Genap"), totalStok);
}

// Fungsi Utama (Main)
int main() {
    int pilihan;

    do {
        printf("=== MENU TUGAS PRAKTIKUM ===\n");
        printf("1. Program Del-Express (Pengiriman)\n");
        printf("2. Program Stok Gudang (Rak Barang)\n");
        printf("0. Keluar\n");
        printf("Pilih menu (0-2): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: programDelExpress(); break;
            case 2: programStokGudang(); break;
            case 0: printf("Keluar dari program. Semangat kuliahnya!\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}