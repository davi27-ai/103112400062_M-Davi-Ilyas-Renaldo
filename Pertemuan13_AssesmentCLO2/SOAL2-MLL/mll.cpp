#include "mll.h"

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent *P = new NodeParent;
    P->idGenre = id;
    P->namaGenre = nama;
    createListChild(P->childs);
    P->next = NULL;
    P->prev = NULL;
    return P;
}

NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild *C = new NodeChild;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertFirstParent(ListParent &L, NodeParent *P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(ListChild &L, NodeChild *C) {
    if (L.first == NULL) {
        L.first = C;
        L.last = C;
    } else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

void hapusListChild(ListChild &L) {
    NodeChild *P = L.first;
    while (P != NULL) {
        NodeChild *temp = P;
        P = P->next;
        delete temp;
    }
    L.first = NULL;
    L.last = NULL;
}

void deleteAfterParent(ListParent &L, NodeParent *prec, NodeParent *&P) {
    if (prec != NULL && prec->next != NULL) {
        P = prec->next;
        hapusListChild(P->childs);
        
        prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = prec;
        } else {
            L.last = prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void searchFilmByRatingRange(ListParent L, float minR, float maxR) {
    NodeParent *P = L.first;
    int posP = 1;
    while (P != NULL) {
        NodeChild *C = P->childs.first;
        int posC = 1;
        while (C != NULL) {
            if (C->ratingFilm >= minR && C->ratingFilm <= maxR) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << posC << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posC << endl;
                cout << "ID Film : " << C->idFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "-----------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posP << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "============================================" << endl;
            }
            C = C->next;
            posC++;
        }
        P = P->next;
        posP++;
    }
}

void printStrukturMLL(ListParent L) {
    NodeParent *P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->idGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        NodeChild *C = P->childs.first;
        int j = 1;
        while (C != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "    ID Film : " << C->idFilm << endl;
            cout << "    Judul Film : " << C->judulFilm << endl;
            cout << "    Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << C->tahunTayang << endl;
            cout << "    Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "-----------------------------" << endl;
        P = P->next;
        i++;
    }
}