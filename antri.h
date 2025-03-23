/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* antri.h - Header untuk Sistem Antrian Restoran */

#ifndef ANTRI_H
#define ANTRI_H

#include "queue.h"

#define MAX_KASIR 1 // Jumlah kasir yang tersedia

typedef struct {
    int id;
    int sedang_melayani;
} Kasir;

/* *** Konstruktor *** */
void initAntrian(Queue *Q, Kasir kasir[MAX_KASIR]);
/* Tujuan: Inisialisasi antrian dan status kasir */
/* IS: Queue belum terdefinisi, kasir belum memiliki pelanggan */
/* FS: Queue kosong, kasir siap melayani */

/* *** Operasi Antrian *** */
void ambilAntrian(Queue *Q, int *counter, int isOnlineOrder);
/* Tujuan: Menambahkan pelanggan ke antrian */
/* IS: Queue mungkin kosong atau berisi beberapa pelanggan */
/* FS: Pelanggan baru ditambahkan ke antrian dengan nomor unik */
/* Jika isOnlineOrder == 1, pelanggan dimasukkan ke dalam antrian prioritas */

void prosesAntrian(Queue *Q, Kasir kasir[MAX_KASIR]);
/* Tujuan: Memproses antrian dengan kasir yang tersedia */
/* IS: Kasir mungkin kosong atau sedang melayani pelanggan */
/* FS: Jika kasir kosong dan ada pelanggan, pelanggan dilayani oleh kasir */

/* *** Tampilan Status *** */
void tampilkanStatusKasir(Kasir kasir[MAX_KASIR]);
/* Tujuan: Menampilkan status setiap kasir */
/* IS: Kasir mungkin kosong atau sedang melayani pelanggan */
/* FS: Status setiap kasir ditampilkan di layar */

void tampilkanDaftarAntrian(Queue Q);
/* Tujuan: Menampilkan daftar antrian keseluruhan */
/* IS: Queue mungkin kosong atau berisi beberapa pelanggan */
/* FS: Daftar nomor antrian ditampilkan */

void kosongkanKasirBergantian(Kasir kasir[MAX_KASIR]);
/* Tujuan: Mengosongkan kasir secara berurutan */
/* IS: Kasir mungkin sedang melayani pelanggan */
/* FS: Salah satu kasir yang sedang melayani menjadi kosong */

#endif

