/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#ifndef HALAMAN_H
#define HALAMAN_H

#include <stdlib.h>
#include <string.h>
#include "utilitas.h"
#include "boolean.h"

#define FILE_NAME "dataMenu.txt"

// =====================================================
// ============= OPERASI FILE DAN DATA ================
// =====================================================
void loadFromFile(List *L);
// Tujuan : Memuat data dari file ke dalam linked list menu makanan
// IS     : List mungkin kosong atau sudah berisi elemen
// FS     : List berisi data dari file jika tersedia

void saveToFile(List L);
// Tujuan : Menyimpan data dari linked list menu makanan ke file
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list disimpan ke dalam file

// =====================================================
// =============== NAVIGASI DAN MENU ==================
// =====================================================
void dashboard(List *L);
// Tujuan : Menampilkan dashboard utama

void tambahMenuMakanan(List *L);
// Tujuan : Menu untuk menambah data menu makanan

void editMenuMakanan(List *L);
// Tujuan : Menu untuk mengedit data menu makanan

void hapusMenuMakanan(List *L);
// Tujuan : Menu untuk menghapus data menu makanan

void lihatMenuMakanan(List L);
// Tujuan : Menu untuk melihat data menu makanan dengan berbagai sorting

#endif

