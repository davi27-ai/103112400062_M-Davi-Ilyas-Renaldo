#include "mll.h"

int main() {
    ListParent L;
    createListParent(L);

    insertFirstParent(L, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(L, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(L, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(L, alokasiNodeParent("G001", "Action"));

    NodeParent *P = L.first;
    insertLastChild(P->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    P = P->next;
    insertLastChild(P->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(P->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    P = P->next;
    insertLastChild(P->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    P = P->next;
    insertLastChild(P->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(P->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    cout << "--- STRUKTUR MLL AWAL ---" << endl;
    printStrukturMLL(L);
    cout << endl;

    cout << "--- SEARCH BY RATING RANGE (8.0 - 8.5) ---" << endl;
    searchFilmByRatingRange(L, 8.0, 8.5);
    cout << endl;

    NodeParent *del;
    deleteAfterParent(L, L.first, del);

    cout << "--- STRUKTUR MLL SETELAH DELETE G002 ---" << endl;
    printStrukturMLL(L);

    return 0;
}