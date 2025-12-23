#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct NodeChild {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild *next, *prev;
};

struct ListChild {
    NodeChild *first;
    NodeChild *last;
};

struct NodeParent {
    string idGenre;
    string namaGenre;
    ListChild childs; 
    NodeParent *next, *prev;
};

struct ListParent {
    NodeParent *first;
    NodeParent *last;
};

void createListParent(ListParent &L);
void createListChild(ListChild &L);
NodeParent* alokasiNodeParent(string id, string nama);
NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(NodeParent *P);
void dealokasiNodeChild(NodeChild *C);

void insertFirstParent(ListParent &L, NodeParent *P);
void insertLastChild(ListChild &L, NodeChild *C);
void hapusListChild(ListChild &L);
void deleteAfterParent(ListParent &L, NodeParent *prec, NodeParent *&P);

void searchFilmByRatingRange(ListParent L, float minR, float maxR);
void printStrukturMLL(ListParent L);

#endif