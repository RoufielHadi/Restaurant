/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* riwayat.c - Implementasi Melihat Riwayat Pemesanan dan Total Keuntungan */

#include "riwayat.h"

void bacaRiwayatPembelian(Stack *riwayat) {
    FILE *file = fopen("riwayatPembelian.txt", "r");
    if (!file) {
        printf("\n===========================================\n");
        printf("|      Tidak ada riwayat pembelian!       |\n");
        printf("===========================================\n\n");
        return;
    }
    
    CreateStack(riwayat);
    char buffer[50];
    int harga;
    fgets(buffer, sizeof(buffer), file); // Lewati header "Riwayat Pembelian:"
    
    while (fscanf(file, "Rp %d\n", &harga) != EOF) {
        Push(riwayat, "Menu Tidak Diketahui", harga); // Perbaikan pemanggilan Push()
    }
    fclose(file);
}

void tampilkanRiwayatPembelian(Stack riwayat) {
    if (isEmptyStack(riwayat)) {
        printf("\n===========================================\n");
        printf("|       Tidak ada riwayat pembelian       |\n");
        printf("===========================================\n\n");
        return;
    }
    
    printf("\n===========================================\n");
    printf("|         RIWAYAT PEMBELIAN RESTORAN       |\n");
    printf("===========================================\n");
    Stack temp = riwayat;
    int count = 1;
    while (!isEmptyStack(temp)) {
        int harga;
        Pop(&temp, &harga);
        printf("| %2d. Harga: Rp %-10d             |\n", count++, harga);
    }
    printf("===========================================\n\n");
}

int hitungTotalKeuntungan(Stack riwayat) {
    int total = 0;
    Stack temp = riwayat;
    while (!isEmptyStack(temp)) {
        int harga;
        Pop(&temp, &harga);
        total += harga;
    }
    return total;
}

void tampilkanTotalKeuntungan(Stack riwayat) {
    int total = hitungTotalKeuntungan(riwayat);
    printf("===========================================\n");
    printf("| Total Keuntungan: Rp %-10d       |\n", total);
    printf("===========================================\n\n");
}

