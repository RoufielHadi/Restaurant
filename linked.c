/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "linked.h"
#include <stdlib.h>

int info(address p) {
    return p->info;
}

address next(address p) {
    return p->next;
}

boolean isEmpty(address p) {
    return (p == NULL);
}

void Create_Node(address *p, char *nama, int harga) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        strcpy((*p)->namaMenu, nama); 
        (*p)->info = harga; 
        (*p)->next = NULL;    
    }
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        (*p)->info = nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    while (p != NULL) {
        printf("%d -> ", info(p));
        p = next(p);
    }
    printf("NULL\n");
}

void Ins_Awal(address *p, address PNew) {
    if (PNew != NULL) {
        PNew->next = *p;
        *p = PNew;
    }
}

void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
    } else {
        address temp = *p;
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        temp->next = PNew;
    }
}

address Search(address p, infotype nilai) {
    while (p != NULL) {
        if (info(p) == nilai) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void InsertAfter(address *pBef, address PNew) {
    if (*pBef != NULL && PNew != NULL) {
        PNew->next = next(*pBef);
        (*pBef)->next = PNew;
    }
}

void Del_Awal(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p;
        *X = info(temp);
        *p = next(temp);
        free(temp);
    }
}

void Del_Akhir(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p, prev = NULL;
        while (next(temp) != NULL) {
            prev = temp;
            temp = next(temp);
        }
        *X = info(temp);
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *p = NULL;
        }
        free(temp);
    }
}

void Del_After(address *pBef, infotype *X) {
    if (*pBef != NULL && next(*pBef) != NULL) {
        address temp = next(*pBef);
        *X = info(temp);
        (*pBef)->next = next(temp);
        free(temp);
    }
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

int NbElmt(address p) {
    if (p == NULL) return 0;
    return 1 + NbElmt(next(p));
}

infotype Min(address p) {
    if (p == NULL) return 0;
    infotype minVal = info(p);
    while (p != NULL) {
        if (info(p) < minVal) {
            minVal = info(p);
        }
        p = next(p);
    }
    return minVal;
}

infotype Rerata(address p) {
    if (p == NULL) return 0;
    int sum = 0, count = 0;
    while (p != NULL) {
        sum += info(p);
        count++;
        p = next(p);
    }
    return (count == 0) ? 0 : (sum / count);
}

address BalikList(address p) {
    address prev = NULL, current = p, tempNext;
    while (current != NULL) {
        tempNext = next(current);
        current->next = prev;
        prev = current;
        current = tempNext;
    }
    return prev;
}

