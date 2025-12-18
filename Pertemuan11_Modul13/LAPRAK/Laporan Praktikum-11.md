# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List </h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
Multi Linked List merupakan pengembangan dari struktur data Linked List yang memungkinkan setiap node memiliki lebih dari satu pointer untuk menghubungkan ke node lain. Struktur data ini digunakan untuk merepresentasikan hubungan data yang kompleks, seperti hubungan satu-ke-banyak atau banyak-ke-banyak. Dengan adanya lebih dari satu pointer pada sebuah node, Multi Linked List mampu menyimpan relasi antar data secara lebih fleksibel dibandingkan Single Linked List.

Dalam implementasinya, Multi Linked List terdiri dari node utama (parent) dan node turunan (child) yang saling terhubung melalui pointer. Setiap node umumnya menyimpan data serta beberapa pointer yang berfungsi untuk menunjuk ke node berikutnya atau ke node lain sesuai dengan kebutuhan relasi. Struktur ini sangat sesuai untuk memodelkan data bertingkat, misalnya hubungan antara mahasiswa dengan mata kuliah, dosen dengan mahasiswa bimbingan, atau data kategori dengan subkategori.

Pada bahasa pemrograman C++, Multi Linked List diimplementasikan menggunakan struktur struct dan pointer. Setiap struct dapat memiliki lebih dari satu pointer yang digunakan untuk mengelola hubungan antar node. Operasi dasar yang sering dilakukan pada Multi Linked List meliputi proses inisialisasi list, penambahan data, penghapusan data, penelusuran (traversal), dan pencarian data. Pengelolaan pointer harus dilakukan dengan cermat agar tidak menimbulkan kesalahan memori seperti memory leak.

Penggunaan Multi Linked List memiliki beberapa kelebihan, di antaranya mampu merepresentasikan hubungan data yang kompleks dan bersifat dinamis karena ukuran data dapat bertambah atau berkurang sesuai kebutuhan. Namun, struktur data ini juga memiliki kekurangan, yaitu tingkat kompleksitas implementasi yang lebih tinggi serta membutuhkan pemahaman yang baik mengenai konsep pointer dan manajemen memori. Oleh karena itu, Multi Linked List umumnya digunakan pada sistem yang membutuhkan pengelolaan relasi data yang saling terhubung.

## Guided 
### 1. MLL (Sistem Kategori Makanan)
#### multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct  nodeChild{ //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{ //list child
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{ //node parent
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak; //list child
};

struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};

//create list 
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

//alokasi &d elokasi parent
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

//alokasi & delokasi child
NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
```
#### multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++; 
        }
    }
}
```
#### main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    //1.instalasi List
    listInduk LInduk;
    createListInduk(LInduk);

    //2.membuat Data Parent (kategori makanan)
    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    //3.masukkan Data Child (menu makanan) ke kategori tertentu
    //-->isi kategori makanan berat (k01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    //--> isi kategori minuman (k02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    //--> isi kategori dessert (k03)
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    //4.print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5.searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6.delete node child
    deleteAfterChild(k01->L_Anak, M01);//menghapus node child ayam bakar madu
    cout<< endl;
    //7.delete node parent
    deleteAfterParent(LInduk, k02); //menghapus node parent minuman
    cout << endl;
    //8.print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
```
desk

## Unguided 
### 1. Insert & Print MLL
#### mll.cpp
```C++
#include "mll.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    createListChild(P->L_Child);
    P->next = NULL;
    P->prev = NULL;
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat,
                         bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        LParent.first = P->next;
        if (LParent.first != NULL)
            LParent.first->prev = NULL;
        else
            LParent.last = NULL;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        NPrev->next = P->next;
        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        LChild.first = C->next;
        if (LChild.first != NULL)
            LChild.first->prev = NULL;
        else
            LChild.last = NULL;
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL)
            C->next->prev = NPrev;
        else
            LChild.last = NPrev;
        deallocNodeChild(C);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int idxParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << idxParent++ << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int idxChild = 1;
            while (C != NULL) {
                cout << " - Child " << idxChild++ << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                cout << "    Ekor : " << C->isidata.ekor << endl;
                cout << "    Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << "-------------------------" << endl;
        P = P->next;
    }
}


void deleteListChild(listChild &LChild) {
    while (LChild.first != NULL) {
        deleteFirstChild(LChild);
    }
}
```
#### mll.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent* NodeParent;
typedef struct nodeChild* NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent LParent);
void deleteListChild(listChild &LChild);

#endif
```
#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = allocNodeParent("G001", "Aves");
    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G3 = allocNodeParent("G003", "Pisces");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    NodeParent G5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    insertLastChild(G1->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",1,0.3));
    insertLastChild(G1->L_Child, allocNodeChild("AV002","Bebek","Air",1,2));

    insertLastChild(G2->L_Child, allocNodeChild("M001","Harimau","Hutan",1,200));
    insertLastChild(G2->L_Child, allocNodeChild("M003","Gorila","Hutan",0,160));
    insertLastChild(G2->L_Child, allocNodeChild("M002","Kucing","Darat",1,4));

    insertLastChild(G4->L_Child, allocNodeChild("AM001","Kodok","Sawah",0,0.2));

    printMLLStructure(LP);
    return 0;
}
```
### Output Unguided 1:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan11_Modul13/LAPRAK/Output-Unguided1.png)
Program C++ ini digunakan untuk membangun struktur Multi Linked List melalui proses penambahan data pada list parent dan list child. Setiap node parent merepresentasikan golongan hewan, sedangkan node child menyimpan data hewan yang termasuk ke dalam golongan tersebut. Setelah seluruh data berhasil dimasukkan, program akan menampilkan struktur Multi Linked List guna memperlihatkan hubungan hierarkis antara parent dan child.

### 2. Search Hewan MLL
#### mll.cpp
```C++
#include "mll.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    createListChild(P->L_Child);
    P->next = NULL;
    P->prev = NULL;
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat,
                         bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        LParent.first = P->next;
        if (LParent.first != NULL)
            LParent.first->prev = NULL;
        else
            LParent.last = NULL;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        NPrev->next = P->next;
        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        LChild.first = C->next;
        if (LChild.first != NULL)
            LChild.first->prev = NULL;
        else
            LChild.last = NULL;
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL)
            C->next->prev = NPrev;
        else
            LChild.last = NPrev;
        deallocNodeChild(C);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    while (P != NULL) {
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "  (Tidak ada child)" << endl;
        } else {
            while (C != NULL) {
                cout << "  - " << C->isidata.namaHewan
                     << " | Ekor: " << C->isidata.ekor
                     << " | Bobot: " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << "------------------------" << endl;
        P = P->next;
    }
}

void deleteListChild(listChild &LChild) {
    while (LChild.first != NULL) {
        deleteFirstChild(LChild);
    }
}
```
#### mll.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent* NodeParent;
typedef struct nodeChild* NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent LParent);
void deleteListChild(listChild &LChild);

#endif
```
#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");

    insertLastParent(LP, G2);
    insertLastParent(LP, G4);

    insertLastChild(G2->L_Child, allocNodeChild("M001","Harimau","Hutan",1,200));
    insertLastChild(G2->L_Child, allocNodeChild("M003","Gorila","Hutan",0,160));
    insertLastChild(G4->L_Child, allocNodeChild("AM001","Kodok","Sawah",0,0.2));

    NodeParent P = LP.first;
    int posParent = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while (C != NULL) {
            if (C->isidata.ekor == false) {
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;

                cout << "------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }

    return 0;
}
```
### Output Unguided 2:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan11_Modul13/LAPRAK/Output-Unguided2.png)
Program C++ ini melakukan proses pencarian data hewan yang tidak memiliki ekor dengan menelusuri seluruh list child pada setiap node parent. Apabila data tersebut ditemukan, program akan menampilkan informasi lengkap mengenai hewan yang dimaksud, termasuk golongan hewan serta posisi node parent dan child dalam struktur Multi Linked List.

### 3. Delete pada List Parent MLL
#### mll.cpp
```C++
#include "mll.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    createListChild(P->L_Child);
    P->next = NULL;
    P->prev = NULL;
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat,
                         bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        LParent.first = P->next;
        if (LParent.first != NULL)
            LParent.first->prev = NULL;
        else
            LParent.last = NULL;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        NPrev->next = P->next;
        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        LChild.first = C->next;
        if (LChild.first != NULL)
            LChild.first->prev = NULL;
        else
            LChild.last = NULL;
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL)
            C->next->prev = NPrev;
        else
            LChild.last = NPrev;
        deallocNodeChild(C);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int idxParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << idxParent++ << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int idxChild = 1;
            while (C != NULL) {
                cout << " - Child " << idxChild++ << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                cout << "    Ekor : " << C->isidata.ekor << endl;
                cout << "    Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << "-------------------------" << endl;
        P = P->next;
    }
}

void deleteListChild(listChild &LChild) {
    while (LChild.first != NULL) {
        deleteFirstChild(LChild);
    }
}
```

#### mll.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent* NodeParent;
typedef struct nodeChild* NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent LParent);
void deleteListChild(listChild &LChild);

#endif
```

#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = allocNodeParent("G001", "Aves");
    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G3 = allocNodeParent("G003", "Pisces");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    NodeParent G5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    insertLastChild(G1->L_Child,
        allocNodeChild("AV001","Cendrawasih","Hutan",1,0.3));
    insertLastChild(G1->L_Child,
        allocNodeChild("AV002","Bebek","Air",1,2));

    insertLastChild(G2->L_Child,
        allocNodeChild("M001","Harimau","Hutan",1,200));
    insertLastChild(G2->L_Child,
        allocNodeChild("M003","Gorila","Hutan",0,160));
    insertLastChild(G2->L_Child,
        allocNodeChild("M002","Kucing","Darat",1,4));

    insertLastChild(G4->L_Child,
        allocNodeChild("AM001","Kodok","Sawah",0,0.2));

    deleteAfterParent(LP, G3);

    printMLLStructure(LP);
    return 0;
}
```
### Output Unguided 3:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan11_Modul13/LAPRAK/Output-Unguided3.png)
Program C++ ini melakukan proses penghapusan node parent G004 (Amfibi) beserta seluruh node child yang terkait. Setelah proses penghapusan selesai, struktur Multi Linked List ditampilkan kembali untuk memastikan bahwa node parent yang dihapus sudah tidak terdapat dalam struktur, serta hubungan antar node parent dan child lainnya tetap terjaga dengan baik.

## Kesimpulan
Dalam praktikum ini dipelajari dan diimplementasikan struktur data Multi Linked List yang terdiri dari list parent dan list child untuk merepresentasikan hubungan satu-ke-banyak melalui pointer antar node. Melalui operasi insert, delete, dan search, dapat diamati bagaimana node parent dan child dikelola secara dinamis sesuai dengan kebutuhan relasi data.

Berdasarkan hasil pengamatan, dapat disimpulkan bahwa Multi Linked List memiliki fleksibilitas tinggi dalam pengelolaan data berelasi karena memungkinkan penambahan dan penghapusan data tanpa memengaruhi elemen lain. Traversal pada list parent dan child juga mendukung pencarian serta penampilan data secara terstruktur, sehingga praktikum ini memberikan pemahaman dasar yang baik tentang penggunaan pointer pada struktur data yang lebih kompleks.

## Referensi
1. Abdul Kadir. Algoritma dan Struktur Data Menggunakan C++. Yogyakarta: Andi Offset.
2. Rinaldi Munir. Algoritma dan Struktur Data. Bandung: Informatika Bandung.
3. Rosa A. S. dan M. Shalahuddin. Struktur Data Terapan. Bandung: Informatika.
4. Modul Praktikum Struktur Data. Program Studi Teknik Informatika, Perguruan Tinggi di Indonesia.