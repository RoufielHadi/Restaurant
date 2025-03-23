/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* kasir.h - Sistem Antrian Kasir Restoran */

#ifndef KASIR_H
#define KASIR_H

#include "antri.h"
#include "stack.h"
#include "linked.h"
#include "clear.h"

void menuUtama();
/* Tujuan : Menampilkan menu utama aplikasi restoran */
/* IS : Aplikasi dalam keadaan siap */
/* FS : Menu utama ditampilkan dan pengguna dapat memilih opsi */

void tampilkanLayar(Queue *Q, Kasir kasir[MAX_KASIR]);
/* Tujuan : Menampilkan status kasir dan daftar antrian dalam format kotak */
/* IS : Queue dan kasir memiliki data */
/* FS : Tampilan status kasir dan antrian ditampilkan di layar */

void tungguEnter();
/* Tujuan : Menunggu pengguna menekan Enter sebelum melanjutkan */
/* IS : Program dalam keadaan berjalan */
/* FS : Program berhenti sementara sampai pengguna menekan Enter */

void prosesPembelian(Stack *riwayat, List *menuList);
/* Tujuan : Memproses pembelian pelanggan dari antrian */
/* IS : Pelanggan telah mencapai kasir */
/* FS : Pelanggan memilih menu, transaksi dicatat ke dalam stack */

void simpanRiwayatPembelian(Stack riwayat);
/* Tujuan : Menyimpan riwayat pembelian ke dalam file "riwayatPembelian.txt" */
/* IS : Stack mungkin kosong atau berisi riwayat pembelian */
/* FS : Riwayat pembelian disimpan dalam file */

#endif
