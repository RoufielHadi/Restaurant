/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* stack.c - Implementation File */
#include "stack.h"
#include <stdlib.h>

boolean isEmptyStack(Stack S) {
    return (S.top == NULL);
}

void CreateStack(Stack *S) {
    S->top = NULL;
}

void Push(Stack *S, char *nama, infotype nilai) {
    address PNew;
    Create_Node(&PNew, nama, nilai);
    if (PNew != NULL) {
        PNew->next = S->top;
        S->top = PNew;
    } else {
        printf("Gagal mengalokasikan memori untuk elemen baru!\n");
    }
}

void Pop(Stack *S, infotype *X) {
    if (isEmptyStack(*S)) {
        printf("Stack kosong! Tidak dapat melakukan Pop.\n");
        return;
    }
    address temp = S->top;
    *X = info(temp);
    S->top = next(temp);
    DeAlokasi(&temp);
}

infotype Top(Stack S) {
    if (!isEmptyStack(S)) {
        return info(S.top);
    }
    printf("Stack kosong! Tidak ada elemen di puncak.\n");
    return 0;
}

int NbElmtStack(Stack S) {
    return NbElmt(S.top);
}

void TampilStack(Stack S) {
    if (isEmptyStack(S)) {
        printf("Stack kosong!\n");
    } else {
        Tampil_List(S.top);
    }
}

void DeAlokasiStack(address *p) {
    if (*p != NULL) {
        DeAlokasi(p);
    }
}

