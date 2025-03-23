/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* riwayat.h - Melihat Riwayat Pemesanan dan Total Keuntungan */

#ifndef RIWAYAT_H
#define RIWAYAT_H

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void bacaRiwayatPembelian(Stack *riwayat);
/* Tujuan : Membaca riwayat pembelian dari file "riwayatPembelian.txt" dan memasukannya ke dalam stack */
/* IS     : Stack mungkin kosong atau memiliki data sebelumnya */
/* FS     : Stack diisi dengan data dari file */

void tampilkanRiwayatPembelian(Stack riwayat);
/* Tujuan : Menampilkan riwayat pemesanan yang tersimpan dalam stack */
/* IS     : Stack mungkin kosong atau berisi data */
/* FS     : Semua data riwayat pembelian ditampilkan */

int hitungTotalKeuntungan(Stack riwayat);
/* Tujuan : Menghitung total keuntungan dari semua transaksi dalam stack */
/* IS     : Stack mungkin kosong atau berisi data */
/* FS     : Mengembalikan total keuntungan dalam bentuk integer */

void tampilkanTotalKeuntungan(Stack riwayat);
/* Menampilkan total keuntungan dari riwayat pembelian */

#endif
