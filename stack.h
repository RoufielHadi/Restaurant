/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef STACK_H
#define STACK_H

#include "boolean.h"
#include "linked.h"

// Definisi struktur Stack
typedef struct {
    address top;
} Stack;

boolean isEmptyStack(Stack S);
/* Tujuan : Memeriksa apakah stack kosong */
/* Stack kosong jika S.top == NULL */
/* Parameter : S (input) */

void CreateStack(Stack *S);
/* Tujuan : Membuat stack kosong */
/* Parameter : S (output) */

void Push(Stack *S, char *nama, infotype nilai);
/* Tujuan : Menambahkan elemen ke stack (push) */
/* Parameter : S (input-output), nama (input), nilai (input) */

void Pop(Stack *S, infotype *X);
/* Tujuan : Menghapus elemen dari stack (pop) */
/* Elemen yang dihapus disimpan dalam X */
/* Parameter : S (input-output), X (output) */

infotype Top(Stack S);
/* Tujuan : Mengembalikan elemen di puncak stack tanpa menghapusnya */
/* Parameter : S (input) */

int NbElmtStack(Stack S);
/* Tujuan : Menghitung jumlah elemen dalam stack */
/* Parameter : S (input) */

void TampilStack(Stack S);
/* Tujuan : Menampilkan isi stack */
/* Parameter : S (input) */

void DeAlokasiStack(address *p);
/* Tujuan : Menghapus node dari memori */
/* Parameter : p (input-output) */

#endif
