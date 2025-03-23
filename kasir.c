/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "kasir.h"
#include <stdio.h>
#include <stdlib.h>
#include "clear.h"

void tungguEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}

void tampilkanLayar(Queue *Q, Kasir kasir[MAX_KASIR]) {
    clearScreen();
    printf("********************************************\n");
    for (int i = 0; i < MAX_KASIR; i++) {
        printf("* Kasir %d: ", kasir[i].id);
        if (kasir[i].sedang_melayani)
            printf("Melayani pelanggan %d ", kasir[i].sedang_melayani);
        else
            printf("Kosong ");
        printf("                        *\n");
    }
    printf("********************************************\n");
    printf("\nDaftar Antrian: ");
    tampilkanDaftarAntrian(*Q);
}

void prosesPembelian(Stack *riwayat, List *menuList) {
    char namaMenu[MAX_MENU_NAME];
    int harga;
    address P = menuList->First;

    printf("\nPilih menu yang ingin dibeli:\n");
    PrintHargaAscending(menuList->First);
    printf("Masukkan nama menu: ");
    scanf(" %[^\n]", namaMenu);

    while (P != NULL) {
        if (strcmp(namaMenu, P->namaMenu) == 0) {
            harga = P->info;
            break;
        }
        P = P->next;
    }

    if (P == NULL) {
        printf("Menu tidak ditemukan!\n");
        return;
    }

    Push(riwayat, namaMenu, harga);
    printf("Pesanan dengan harga Rp %d telah ditambahkan ke riwayat pembelian.\n", harga);

    // Simpan riwayat pembelian otomatis setelah transaksi
    simpanRiwayatPembelian(*riwayat);
}

void simpanRiwayatPembelian(Stack riwayat) {
    FILE *file = fopen("riwayatPembelian.txt", "w");
    if (!file) {
        printf("Gagal menyimpan riwayat pembelian!\n");
        return;
    }

    Stack temp = riwayat;
    fprintf(file, "Riwayat Pembelian:\n");
    while (!isEmptyStack(temp)) {
        int harga;
        Pop(&temp, &harga);  // Menghapus argumen namaMenu karena stack hanya menyimpan harga
        fprintf(file, "Rp %d\n", harga);
    }
    fclose(file);
    printf("Riwayat pembelian telah disimpan ke riwayatPembelian.txt\n");
}

void menuUtama() {
    int choice;
    Queue antrian;
    Kasir kasir[MAX_KASIR];
    Stack riwayat;
    List menuList;
    int counter = 0;

    CreateStack(&riwayat);
    CreateQueue(&antrian);
    menuList.First = NULL;
    initAntrian(&antrian, kasir);

    do {
        tampilkanLayar(&antrian, kasir);
        printf("1. Ambil Nomor Antrian\n");
        printf("2. Ambil Pesanan Online\n");
        printf("3. Proses Antrian\n");
        printf("4. Kosongkan Kasir Bergantian\n");
        printf("5. Tampilkan Daftar Antrian\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                ambilAntrian(&antrian, &counter, 0);
                break;
            case 2:
                ambilAntrian(&antrian, &counter, 1);
                break;
            case 3:
                prosesAntrian(&antrian, kasir);
                prosesPembelian(&riwayat, &menuList);
                break;
            case 4:
                kosongkanKasirBergantian(kasir);
                break;
            case 5:
                tampilkanDaftarAntrian(antrian);
                break;
            case 0:
                printf("Terima kasih telah menggunakan sistem antrian restoran!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
        tungguEnter();
    } while (choice != 0);
}

