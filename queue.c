/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* queue.c - Implementation File */
#include "queue.h"
#include <stdlib.h>

boolean isEmptyQueue(Queue Q) {
    return (Q.front == NULL);
}

void CreateQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void DeAlokasiQueue(address *p) {
    if (*p != NULL) {
        free(*p);
        *p = NULL;
    }
}

void Enqueue(Queue *Q, char *nama, infotype harga) {
    address PNew;
    Create_Node(&PNew, nama, harga);
    
    if (PNew != NULL) {
        if (isEmptyQueue(*Q)) {
            Q->front = PNew;
            Q->rear = PNew;
        } else {
            Q->rear->next = PNew;
            Q->rear = PNew;
        }
    }
}

void Dequeue(Queue *Q, infotype *X) {
    if (!isEmptyQueue(*Q)) {
        address temp = Q->front;
        *X = info(temp);
        Q->front = next(Q->front);
        
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        DeAlokasiQueue(&temp);
    }
}

int NbElmtQueue(Queue Q) {
    return NbElmt(Q.front);
}

void TampilQueue(Queue Q) {
    Tampil_List(Q.front);
}

infotype Front(Queue Q) {
    return isEmptyQueue(Q) ? 0 : info(Q.front);
}

infotype Rear(Queue Q) {
    return isEmptyQueue(Q) ? 0 : info(Q.rear);
}

void EnqueueVIP(Queue *Q, char *nama, infotype harga) {
    address PNew;
    Create_Node(&PNew, nama, harga);

    if (PNew != NULL) {
        if (isEmptyQueue(*Q)) {
            Q->front = PNew;
            Q->rear = PNew;
        } else {
            PNew->next = Q->front;
            Q->front = PNew;
        }
    }
}

