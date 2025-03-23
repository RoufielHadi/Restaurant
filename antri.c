/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* antri.c - Implementasi Sistem Antrian Restoran dengan Pesanan Online */

#include "antri.h"
#include <stdio.h>
#include <string.h>

void initAntrian(Queue *Q, Kasir kasir[MAX_KASIR]) {
    CreateQueue(Q);
    for (int i = 0; i < MAX_KASIR; i++) {
        kasir[i].id = i + 1;
        kasir[i].sedang_melayani = 0; // Tidak ada pelanggan
    }
}

void ambilAntrian(Queue *Q, int *counter, int isOnlineOrder) {
    (*counter)++;
    char nomorAntrian[10];
    sprintf(nomorAntrian, "A-%d", *counter);
    printf("Nomor antrian %s telah ditambahkan ke antrian.\n", nomorAntrian);
    
    if (isOnlineOrder) {
        printf("[Pesanan Online] Antrian %s mendapat prioritas lebih tinggi!\n", nomorAntrian);
        EnqueueVIP(Q, nomorAntrian, *counter);
    } else {
        Enqueue(Q, nomorAntrian, *counter);
    }
}

void prosesAntrian(Queue *Q, Kasir kasir[MAX_KASIR]) {
    int pelanggan;
    for (int i = 0; i < MAX_KASIR; i++) {
        if (kasir[i].sedang_melayani == 0 && !isEmptyQueue(*Q)) {
            Dequeue(Q, &pelanggan);
            kasir[i].sedang_melayani = pelanggan;
            printf("Kasir %d sedang melayani pelanggan %d.\n", kasir[i].id, pelanggan);
        }
    }
}

void tampilkanStatusKasir(Kasir kasir[MAX_KASIR]) {
    printf("\nStatus Kasir:\n");
    for (int i = 0; i < MAX_KASIR; i++) {
        if (kasir[i].sedang_melayani == 0) {
            printf("Kasir %d: Tidak ada pelanggan\n", kasir[i].id);
        } else {
            printf("Kasir %d: Melayani pelanggan %d\n", kasir[i].id, kasir[i].sedang_melayani);
        }
    }
}

void tampilkanDaftarAntrian(Queue Q) {
    printf("\nDaftar Antrian: ");
    TampilQueue(Q);
}

void kosongkanKasirBergantian(Kasir kasir[MAX_KASIR]) {
    for (int i = 0; i < MAX_KASIR; i++) {
        if (kasir[i].sedang_melayani != 0) {
            printf("Kasir %d selesai melayani pelanggan %d.\n", kasir[i].id, kasir[i].sedang_melayani);
            kasir[i].sedang_melayani = 0;
            return; // Mengosongkan satu kasir dalam satu panggilan fungsi
        }
    }
}
