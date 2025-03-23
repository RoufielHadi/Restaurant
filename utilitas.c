/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#include <stdlib.h>
#include <string.h>
#include "utilitas.h"
#include "linked.h"

// Memasukkan elemen secara ascending berdasarkan harga
void InsertSorted(address *L, address P) {
    if (P != NULL) {
        if (*L == NULL || P->info < (*L)->info) {
            P->next = *L;
            *L = P;
        } else {
            address temp = *L;
            while (temp->next != NULL && temp->next->info < P->info) {
                temp = temp->next;
            }
            P->next = temp->next;
            temp->next = P;
        }
    }
}

// Menampilkan list secara ascending berdasarkan nama menu
void PrintHargaAscending(address L) {
    if (L == NULL) {
        printf("List kosong!\n");
        return;
    }

    address arr[100]; // Array untuk menyimpan elemen sementara
    int count = 0;
    address P = L;
    while (P != NULL) {
        arr[count++] = P;
        P = P->next;
    }

    // Sorting berdasarkan harga (Ascending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j]->info > arr[j + 1]->info) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Menampilkan hasil
    printf("\nDaftar Berdasarkan Harga (Ascending):\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Harga: %d\n", arr[i]->namaMenu, arr[i]->info);
    }
}

// Menampilkan list secara descending berdasarkan harga
void PrintHargaDescending(address L) {
    if (L == NULL) {
        printf("List kosong!\n");
        return;
    }
    address arr[100];
    int count = 0;
    address P = L;
    while (P != NULL) {
        arr[count++] = P;
        P = P->next;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j]->info < arr[j + 1]->info) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nDaftar Berdasarkan Harga (Descending):\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Harga: %d\n", arr[i]->namaMenu, arr[i]->info);
    }
}

// Menyalin elemen dengan harga > 50000 ke L2
void CopyHargaDiAtas50K(address L1, address *L2) {
    address P = L1;
    while (P != NULL) {
        if (P->info > 50000) {
            address newNode;
            Create_Node(&newNode, P->namaMenu, P->info);
            InsertSorted(L2, newNode);
        }
        P = P->next;
    }
}

// Menghapus elemen duplikat berdasarkan harga
void RemoveDuplicates(address *L) {
    if (*L == NULL) return;
    address P = *L;
    while (P != NULL && P->next != NULL) {
        if (P->info == P->next->info) {
            address temp = P->next;
            P->next = P->next->next;
            free(temp);
        } else {
            P = P->next;
        }
    }
}

// Memasukkan data menu
void InputMenu(char *namaMenu, int *harga) {
    printf("Masukkan Nama Menu: ");
    scanf("%s", namaMenu);
    printf("Masukkan Harga: ");
    scanf("%d", harga);
}

// Mengedit data menu
void EditMenu(address P, char *namaMenu, int harga) {
    if (P != NULL) {
        strcpy(P->namaMenu, namaMenu);
        P->info = harga;
    }
}

void PrintNamaAscending(address L) {
    if (L == NULL) {
        printf("List kosong!\n");
        return;
    }

    address arr[100]; // Array untuk menyimpan elemen sementara
    int count = 0;
    address P = L;
    while (P != NULL) {
        arr[count++] = P;
        P = P->next;
    }

    // Sorting berdasarkan nama (Ascending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(arr[j]->namaMenu, arr[j + 1]->namaMenu) > 0) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Menampilkan hasil
    printf("\nDaftar Berdasarkan Nama (Ascending):\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Harga: %d\n", arr[i]->namaMenu, arr[i]->info);
    }
}

