# <h1 align="center">Laporan Praktikum Modul 6 - Double Linked List (Bagian Pertama)</h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
Struktur data merupakan cara untuk menyimpan dan mengorganisasi data agar dapat diakses dan dimodifikasi secara efisien. Salah satu struktur data yang sering digunakan dalam pemrograman adalah Linked List, yaitu kumpulan elemen data (node) yang saling terhubung melalui pointer. Setiap node dalam Linked List biasanya terdiri atas dua bagian, yaitu data dan pointer yang mengarah ke node berikutnya. Berbeda dengan array yang memiliki ukuran tetap, Linked List bersifat dinamis karena dapat bertambah atau berkurang selama program berjalan.

Doubly Linked List (DLL) adalah pengembangan dari Single Linked List di mana setiap node memiliki dua pointer, yaitu next (penunjuk ke node berikutnya) dan prev (penunjuk ke node sebelumnya). Dengan adanya dua arah hubungan ini, proses penelusuran (traversal) data dapat dilakukan dari depan ke belakang maupun sebaliknya. DLL juga mempermudah operasi seperti penyisipan (insert) dan penghapusan (delete) elemen di bagian tengah list tanpa harus menelusuri dari awal seperti pada Single Linked List.

Dalam implementasinya menggunakan bahasa C++, Doubly Linked List banyak digunakan untuk mengelola data secara dinamis. Misalnya, untuk menyimpan data kendaraan dengan atribut seperti nomor polisi, warna, dan tahun pembuatan, program dapat menambahkan data baru, mencari data berdasarkan nomor polisi, atau menghapus data tertentu dengan mudah. Fungsi-fungsi yang umum digunakan antara lain:
1. insertLast() untuk menambahkan data di akhir list
2. findElm() untuk mencari data berdasarkan kriteria tertentu
3. deleteByNopol() atau deleteAfter() untuk menghapus elemen tertentu dalam list

Meskipun Doubly Linked List memiliki keunggulan dalam fleksibilitas dan efisiensi operasi insert/delete di posisi mana pun, struktur ini juga memiliki kelemahan berupa kebutuhan memori lebih besar dan potensi kesalahan pada pengelolaan pointer. Namun demikian, konsep DLL tetap menjadi dasar penting dalam pembelajaran struktur data karena prinsipnya banyak diterapkan pada berbagai aplikasi modern, seperti fitur undo/redo, navigasi forward-backward pada browser, dan playlist musik.

## Guided 
### 1. operasi insert & update list makanan
#### listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
#### listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

#### main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program C++ ini dibuat untuk menyimpan data makanan menggunakan struktur data Doubly Linked List. Setiap data makanan punya atribut seperti nama, jenis, harga, dan rating. Dalam Doubly Linked List, setiap node punya dua pointer, yaitu next dan prev, yang memungkinkan kita menjelajahi data dari dua arah, maju maupun mundur.

### 2.implementasi ADT list data kendaraan
#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

#### main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program C++ ini dibuat untuk menyimpan data kendaraan menggunakan Doubly Linked List. Setiap kendaraan memiliki atribut seperti nomor polisi, warna, dan tahun pembuatan. Program ini juga menampilkan cara melakukan pencarian (search) dan penghapusan (delete) data di dalam Doubly Linked List.

## Unguided 
### 1. Doublylist nomor kendaraan
#### doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) {
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            (L.last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

#### doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

address findElm(List L, string nopol);

void deleteByNopol(List &L, string nopol);

void printInfo(List L);

#endif 
```

#### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

void requestInput(string& nopol, string& warna, int& tahun) {
    cout << "masukkan nomor polisi: ";
    cin >> nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> warna;
    cout << "masukkan tahun kendaraan: ";
    while (!(cin >> tahun)) {
        cout << "Input tahun tidak valid. Masukkan angka: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    List L;
    CreateList(L);

    string nopol;
    string warna;
    int tahun;
    infotype dataBaru;
    address P;

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);
    
    return 0;
}
```
### Output Unguided 1:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan6_Modul6/LAPRAK/Output-Unguided1.png)

Program C++ ini dibuat untuk menambahkan data kendaraan ke dalam Doubly Linked List, dengan fitur yang mencegah adanya nomor polisi yang sama. Setiap data kendaraan yang dimasukkan pengguna mencakup nomor polisi, warna kendaraan, dan tahun pembuatannya. Program ini meminta pengguna untuk memasukkan beberapa data kendaraan satu per satu. Setiap kali ada data baru, sistem akan mengecek dulu apakah nomor polisi tersebut sudah ada di dalam list lewat fungsi findElm. Kalau nomor itu sudah terdaftar, program menolak data dan menampilkan pesan (nomor polisi sudah terdaftar). Kalau belum ada, program membuat node baru dengan alokasi lalu menambahkannya ke akhir list menggunakan insertLast.

### 2. mencari elemen dengan findElm
#### doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) {
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            (L.last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

#### doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

address findElm(List L, string nopol);

void deleteByNopol(List &L, string nopol);

void printInfo(List L);

#endif 
```

#### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;

    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna : " << found->info.warna << endl;
        cout << "Tahun : " << found->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << cariNopol << " tidak ditemukan." << endl;
    }

    return 0;
}
```
### Output Unguided 2:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan6_Modul6/LAPRAK/Output-Unguided2.png)

Program C++ ini berfungsi untuk mencari data kendaraan di Doubly Linked List berdasarkan nomor polisi yang dimasukkan pengguna. Proses pencarian menggunakan fungsi findElm, yang menelusuri setiap elemen dari awal hingga akhir list. Jika nomor polisi yang dicari, seperti D001, ditemukan, program akan menampilkan informasi kendaraan tersebut—dalam contoh ini, kendaraan D001 berwarna hitam dan dibuat pada tahun 1990.

### 3. hapus elm dengan delete
#### doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) {
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            (L.last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

#### doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

address findElm(List L, string nopol);

void deleteByNopol(List &L, string nopol);

void printInfo(List L);

#endif 
```

#### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    string hapusNopol;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address beforeDelete = findElm(L, hapusNopol);
    if (beforeDelete != Nil) {
        deleteByNopol(L, hapusNopol);
        cout << endl << "DATA LIST 1" << endl;
        printInfo(L);
    } else {
        cout << "Nomor Polisi " << hapusNopol << " tidak ditemukan." << endl;
    }

    return 0;
}
```
### Output Unguided 3:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan6_Modul6/LAPRAK/Output-Unguided3.png)

Program C++ ini digunakan untuk menghapus data kendaraan dari Doubly Linked List berdasarkan nomor polisi yang dimasukkan pengguna. Dalam contoh ini, data dengan nomor polisi D004 dihapus karena posisinya berada di akhir list, sehingga program memakai prosedur deleteAfter. Setelah penghapusan, program menampilkan pesan bahwa data D004 berhasil dihapus dan menunjukkan sisa data dalam list, yaitu kendaraan dengan nomor polisi D001 dan D003 beserta warna dan tahunnya.

## Kesimpulan
Pada praktikum ini, dipelajari konsep dan penerapan Doubly Linked List (DLL) sebagai salah satu bentuk Abstract Data Type (ADT) List. Struktur ini memungkinkan setiap node saling terhubung dua arah melalui pointer next dan prev, sehingga memudahkan proses penambahan, penghapusan, dan penelusuran data secara efisien. Melalui implementasi program C++, diperoleh pemahaman bahwa DLL unggul dalam hal fleksibilitas dan efisiensi, terutama saat melakukan operasi insert atau delete di posisi tengah list. Meski demikian, DLL juga memiliki kekurangan, seperti kebutuhan memori yang lebih besar dan potensi kesalahan dalam pengelolaan pointer. Dari hasil pengujian beberapa fungsi seperti insertLast, findElm, dan deleteByNopol, dapat disimpulkan bahwa struktur ini mendukung manajemen data yang dinamis dan efisien. Praktikum ini juga memperlihatkan bagaimana hubungan antar-node diatur dalam memori serta pentingnya penerapan modularitas, keamanan memori, dan abstraksi dalam pemrograman struktur data. Penerapan konsep Doubly Linked List sendiri banyak digunakan dalam kehidupan nyata, misalnya pada fitur undo/redo di editor teks, navigasi forward-backward pada browser, maupun pengelolaan playlist musik. Secara keseluruhan, praktikum ini memberikan pemahaman yang kuat tentang bagaimana struktur data dinamis dapat diterapkan dalam berbagai aplikasi komputer modern.

## Referensi
1. Arifin, Z. (2020). Struktur Data dan Algoritma dengan C++. Yogyakarta: Deepublish.
2. Siregar, A. (2019). Konsep dan Implementasi Struktur Data. Jakarta: Mitra Wacana Media.
3. Lestari, D., & Saputra, A. (2021). "Penerapan Doubly Linked List dalam Pengelolaan Data Dinamis Menggunakan Bahasa C++". Jurnal Teknologi dan Sistem Informasi Universitas Bina Insani, 5(2), 45–52.
4. Nugroho, A. (2018). Algoritma dan Struktur Data. Bandung: Informatika.