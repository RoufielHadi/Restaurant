/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "linked.h"
#include "boolean.h"

typedef struct {
    address front;
    address rear;
} Queue;

/* *** Konstruktor & Destructor *** */
boolean isEmptyQueue(Queue Q);
// Tujuan : Memeriksa apakah queue kosong
// Queue kosong jika front == NULL

void CreateQueue(Queue *Q);
// Tujuan : Membuat queue kosong
// IS : Q belum terdefinisi
// FS : Q terdefinisi dengan front dan rear = NULL

void DeAlokasiQueue(address *p);
// Tujuan : Menghapus node queue dari memori (dealokasi)
// IS : p terdefinisi
// FS : p dikembalikan ke sistem (dealokasi)

/* *** Operasi Enqueue & Dequeue *** */
void Enqueue(Queue *Q, char *nama, infotype harga);
// Tujuan : Menambahkan elemen baru ke belakang queue
// IS : Queue mungkin kosong
// FS : Elemen baru ditambahkan di belakang queue

void Dequeue(Queue *Q, infotype *X);
// Tujuan : Menghapus elemen dari depan queue dan menyimpannya ke X
// IS : Queue tidak kosong
// FS : Elemen depan dihapus, nilai disimpan dalam X

/* *** Operasi Tambahan *** */
int NbElmtQueue(Queue Q);
// Tujuan : Mengembalikan jumlah elemen dalam queue
// Jika queue kosong, mengembalikan 0

void TampilQueue(Queue Q);
// Tujuan : Menampilkan isi queue dari depan ke belakang
// Format: "elemen1 -> elemen2 -> ... -> NULL"

infotype Front(Queue Q);
// Tujuan : Mengembalikan nilai elemen terdepan tanpa menghapusnya
// IS : Queue tidak kosong
// FS : Mengembalikan nilai front->info

infotype Rear(Queue Q);
// Tujuan : Mengembalikan nilai elemen terakhir dalam queue tanpa menghapusnya
// IS : Queue tidak kosong
// FS : Mengembalikan nilai rear->info

void EnqueueVIP(Queue *Q, char *nama, infotype harga);
// Menambahkan elemen VIP ke dalam queue dengan prioritas lebih tinggi

#endif
