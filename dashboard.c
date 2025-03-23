/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <stdlib.h>
#include "dashboard.h"
#include "clear.h"

void welcomeScreen() {
    clearScreen();
    printf("******************************************\n");
    printf("*        SELAMAT DATANG DI RESTORAN      *\n");
    printf("*             MADODET SYSTEM             *\n");
    printf("******************************************\n");
    printf("Tekan Enter untuk melanjutkan...\n");
    getchar();
}

void mainMenu() {
    int pilihan;
    List menuList; 
    Stack riwayat;
    CreateStack(&riwayat);
    
    loadFromFile(&menuList); // Load menu dari file jika ada
    
    do {
        clearScreen();
        printf("*****************MENU UTAMA******************\n");
        printf("* 1. Dashboard Admin                         *\n");
        printf("* 2. Kasir                                   *\n");
        printf("* 3. Riwayat Pembelian                       *\n");
        printf("* 4. Keluar                                  *\n");
        printf("*********************************************\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();  // Membuang karakter newline

        switch (pilihan) {
            case 1:
                dashboard(&menuList);
                break;
            case 2:
                menuUtama();
                break;
            case 3:
                clearScreen();
                printf("**************RIWAYAT PEMBELIAN**************\n");
                bacaRiwayatPembelian(&riwayat);
                tampilkanRiwayatPembelian(riwayat);
                printf("*********************************************\n");
                printf("\nTekan Enter untuk kembali...");
                getchar();
                break;
            case 4:
                printf("Terima kasih telah menggunakan sistem restoran!\n");
                break;
            default:
                printf("Pilihan tidak valid! Tekan Enter untuk kembali...");
                getchar();
        }
    } while (pilihan != 4);
}

