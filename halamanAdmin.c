/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#include "halamanAdmin.h"
#include "clear.h"

void loadFromFile(List *L) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;
    
    char namaMenu[MAX_MENU_NAME];
    int harga;
    while (fscanf(file, "%[^,],%d\n", namaMenu, &harga) != EOF) {
        address newNode;
        Create_Node(&newNode, namaMenu, harga);
        InsertSorted(&L->First, newNode);
    }
    fclose(file);
}

void saveToFile(List L) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) return;
    
    address P = L.First;
    while (P != NULL) {
        fprintf(file, "%s,%d\n", P->namaMenu, P->info);
        P = P->next;
    }
    fclose(file);
}

void tambahMenuMakanan(List *L) {
    clearScreen();
    puts("**************************TAMBAH MENU MAKANAN**************************");
    
    char namaMenu[MAX_MENU_NAME];
    int harga;
    InputMenu(namaMenu, &harga);
    
    address newNode;
    Create_Node(&newNode, namaMenu, harga);
    InsertSorted(&L->First, newNode);
    saveToFile(*L);
    printf("Menu berhasil ditambahkan!\n");
}

void editMenuMakanan(List *L) {
    clearScreen();
    puts("**************************EDIT MENU MAKANAN**************************");
    PrintHargaAscending(L->First);
    
    int hargaLama, hargaBaru;
    char namaBaru[MAX_MENU_NAME];
    printf("Masukkan Harga Menu yang Ingin Diubah: ");
    scanf("%d", &hargaLama);
    getchar();
    
    address P = Search(L->First, hargaLama);
    if (P == NULL) {
        printf("Menu tidak ditemukan!\n");
        return;
    }
    
    printf("Masukkan Nama Baru: ");
    fgets(namaBaru, sizeof(namaBaru), stdin);
    namaBaru[strcspn(namaBaru, "\n")] = 0;
    printf("Masukkan Harga Baru: ");
    scanf("%d", &hargaBaru);
    getchar();
    
    EditMenu(P, namaBaru, hargaBaru);
    saveToFile(*L);
    printf("Menu berhasil diperbarui!\n");
}

void hapusMenuMakanan(List *L) {
    clearScreen();
    puts("**************************HAPUS MENU MAKANAN**************************");
    PrintHargaAscending(L->First);
    
    int harga;
    printf("Masukkan Harga Menu yang Ingin Dihapus: ");
    scanf("%d", &harga);
    getchar();
    
    address P = Search(L->First, harga);
    if (P == NULL) {
        printf("Menu tidak ditemukan!\n");
        return;
    }
    
    Del_Awal(&L->First, &harga);
    saveToFile(*L);
    printf("Menu berhasil dihapus!\n");
}

void lihatMenuMakanan(List L) {
    int choice;
    do {
        clearScreen();
        puts("**************************LIHAT MENU MAKANAN**************************");
        puts("1. Urutkan berdasarkan Nama (Ascending)");
        puts("2. Urutkan berdasarkan Harga (Ascending)");
        puts("3. Urutkan berdasarkan Harga (Descending)");
        puts("4. Kembali ke Dashboard");
        printf("Pilihan: ");
        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        switch (choice) {
            case 1:
                PrintNamaAscending(L.First);
                break;
            case 2:
                PrintHargaAscending(L.First);
                break;
            case 3:
                PrintHargaDescending(L.First);
                break;
        }

        if (choice != 4) {
            printf("\nTekan Enter untuk kembali ke menu...");
            getchar();
        }
    } while (choice != 4);
}

void dashboard(List *L) {
    int choice;
    do {
        clearScreen();
        puts("**************************DASHBOARD UTAMA**************************");
        puts("1. Tambah Menu Makanan");
        puts("2. Edit Menu Makanan");
        puts("3. Hapus Menu Makanan");
        puts("4. Lihat Menu Makanan");
        puts("5. Keluar");
        printf("Pilihan: ");
        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        switch (choice) {
            case 1:
                tambahMenuMakanan(L);
                break;
            case 2:
                editMenuMakanan(L);
                break;
            case 3:
                hapusMenuMakanan(L);
                break;
            case 4:
                lihatMenuMakanan(*L);
                break;
        }
    } while (choice != 5);
}
