/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

/* utilitas.h */
#ifndef UTILITAS_H
#define UTILITAS_H

#include "linked.h"
#include "boolean.h"

// =====================================================
// =========== FUNGSI TAMBAHAN UNTUK PROGRAM ==========
// =====================================================

void InsertSorted(address *L, address P);
// Tujuan : Menambahkan elemen P ke dalam list dalam urutan ascending berdasarkan info (harga)
// IS     : L mungkin kosong atau sudah berisi elemen yang terurut berdasarkan info
// FS     : P dimasukkan ke posisi yang tepat agar list tetap terurut secara ascending

void PrintDescending(address L);
// Tujuan : Menampilkan semua elemen dalam list secara descending berdasarkan info
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dari terbesar ke terkecil

void PrintNamaAscending(address L);
// Tujuan : Menampilkan semua elemen dalam list secara ascending berdasarkan namaMenu
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dalam urutan alfabetis

void CopyHargaDiAtas50K(address L1, address *L2);
// Tujuan : Menyalin elemen dari L1 ke L2 jika info > 50000
// IS     : L1 mungkin kosong atau berisi elemen
// FS     : L2 berisi salinan elemen dari L1 dengan info > 50000

void RemoveDuplicates(address *L);
// Tujuan : Menghapus elemen dengan info yang sama dalam list, hanya menyisakan satu
// IS     : List mungkin kosong atau berisi elemen dengan duplikasi info
// FS     : Semua elemen dalam list unik berdasarkan info

// =====================================================
// =========== FUNGSI UNTUK MEMASUKKAN & EDIT DATA =====
// =====================================================

void InputMenu(char *namaMenu, int *harga);
// Tujuan : Memasukkan data nama menu dan harga makanan dari input pengguna
// IS     : namaMenu dan harga belum diisi
// FS     : namaMenu dan harga diisi oleh pengguna

void EditMenu(address P, char *namaMenu, int harga);
// Tujuan : Mengedit data nama menu dan harga pada node tertentu
// IS     : P terdefinisi
// FS     : Data dalam node P diperbarui dengan nama dan harga baru

// =====================================================
// ========== FUNGSI SORTING BERDASARKAN INFO ==========
// =====================================================

void PrintHargaAscending(address L);
// Tujuan : Menampilkan daftar menu berdasarkan info secara ascending
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dalam urutan dari terkecil ke terbesar

void PrintHargaDescending(address L);
// Tujuan : Menampilkan daftar menu berdasarkan info secara descending
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dalam urutan dari terbesar ke terkecil

#endif
