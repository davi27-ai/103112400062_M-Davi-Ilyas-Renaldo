# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
Singly Linked List merupakan salah satu bentuk struktur data dinamis yang tersusun dari elemen-elemen yang disebut node, di mana setiap node berisi data dan pointer yang menunjuk ke node berikutnya. Berbeda dengan array yang memiliki ukuran tetap, linked list bersifat dinamis dan dapat bertambah atau berkurang selama program berjalan, sehingga memungkinkan penggunaan memori yang lebih efisien.

Struktur dasar singly linked list biasanya terdiri atas dua komponen utama:
1. Data field, yaitu bagian yang menyimpan nilai atau informasi.
2. Pointer field (next), yaitu bagian yang menunjuk ke node berikutnya dalam list.

Operasi dasar yang umum dilakukan pada singly linked list antara lain:
1. insertFirst, insertLast, dan insertAfter untuk menambahkan node.
2. deleteFirst, deleteLast, dan deleteAfter untuk menghapus node.
3. printList untuk menampilkan isi list.
4. nbList untuk menghitung jumlah node.
5. deleteList untuk menghapus seluruh isi list.

Dalam implementasinya, pointer head digunakan untuk menunjuk node pertama dalam list. Jika head = NULL, maka list dianggap kosong (isEmpty). Penggunaan pointer global dapat memudahkan pengelolaan list pada program berskala kecil, namun pada sistem besar, struktur data ini biasanya dikelola melalui kelas atau objek.

Penerapan linked list banyak dijumpai dalam berbagai bidang komputasi, seperti manajemen memori, struktur antrian (queue), stack, hingga graf dan tree. Pemahaman konsep ini menjadi dasar penting untuk memahami struktur data yang lebih kompleks serta optimasi algoritma pada pemrograman.

## Guided 

### 1. Implementasi Singly Linked List pada Data Mahasiswa
#### list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif // LIST_H
```
#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}  
```
#### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    return 0;
}
```
Program c++ ini memanfaatkan struktur singly linked list untuk mengelola data mahasiswa. Implementasinya terbagi menjadi tiga file: list.h sebagai header yang berisi definisi struktur mahasiswa, node, dan linked list beserta deklarasi fungsinya; list.cpp yang berisi implementasi detail dari fungsi-fungsi tersebut seperti alokasi, insertFirst, insertLast, insertAfter, dan printList; serta main.cpp sebagai program utama yang berfungsi untuk membuat list, menambahkan data mahasiswa, dan menampilkannya. Program ini menunjukkan penerapan dasar operasi penyisipan pada singly linked list.

### 2. Operasi Tambahan pada Singly Linked List Mahasiswa
#### list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
#### list.cpp
```C++
// list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
#### main.cpp
```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    return 0;
}
```
Program C++ ini mengembangkan versi sebelumnya dengan menambahkan fitur penghapusan data pada singly linked list mahasiswa. Fungsi baru seperti delFirst, delLast, delAfter, nbList, dan deleteList digunakan untuk menghapus node serta menghitung jumlahnya. Pada main.cpp, program menampilkan proses lengkap dari pembuatan list, penambahan, penampilan, hingga penghapusan data beserta jumlah node setelah tiap operasi.

## Unguided 
### 1. Implementasi singly linked list 
#### singlyList.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>

// Definisikan struktur Node
struct Node {
    int data;
    Node* next;
};

// Deklarasikan pointer head global
extern Node* head;

// Prototype fungsi
void init();
bool isEmpty();
void insertFirst(int value);
void insertLast(int value);
void insertAfter(int value, int key);
void deleteFirst();
void deleteLast();
void deleteAfter(int key);
void printList();
int nbList();
void deleteList();

#endif // SINGLYLIST_H
```

#### singlyList.cpp
```C++
#include "Singlylist.h"

Node* head;

void init() {
    head = nullptr;
}

bool isEmpty() {
    return head == nullptr;
}

void insertFirst(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(int value, int key) {
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst() {
    if (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteLast() {
    if (!isEmpty()) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }
}

void deleteAfter(int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp != nullptr && temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int nbList() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteList() {
    while (!isEmpty()) {
        deleteFirst();
    }
}
```

#### main.cpp
```C++
#include "Singlylist.h"

int main() {
    init();

    //soal1
    std::cout << "Soal 1:" << std::endl;
    insertFirst(9);
    insertLast(12);
    insertLast(2);
    insertAfter(8, 12);
    insertAfter(0, 8);
    printList();

    //soal2
    std::cout << "\nSoal 2:" << std::endl;
    deleteFirst();
    deleteLast();
    deleteAfter(12);
    printList();
    std::cout << "Jumlah node : " << nbList() << std::endl;
    deleteList();
    std::cout << "- List Berhasil Terhapus -" << std::endl;
    std::cout << "Jumlah node : " << nbList() << std::endl;

    return 0;
}
```
### Output Unguided:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan4_Modul4/LAPRAK/Output-Unguided.png)

Program C++ ini menerapkan singly linked list sederhana untuk menyimpan data bertipe integer dengan menggunakan pointer global head sebagai pengelola list. File Singlylist.h memuat definisi struktur Node dan deklarasi fungsi, sedangkan Singlylist.cpp berisi implementasi fungsi seperti init, isEmpty, insertFirst, insertLast, insertAfter, deleteFirst, deleteLast, deleteAfter, printList, nbList, dan deleteList. Program utama di main.cpp menampilkan penerapan fungsi-fungsi tersebut dalam operasi penyisipan, penghapusan, dan penampilan data sesuai skenario yang diberikan.

## Kesimpulan
Dari praktikum ini, saya memahami bahwa singly linked list merupakan salah satu struktur data dinamis yang memungkinkan penyimpanan dan pengelolaan data secara efisien melalui node yang saling terhubung menggunakan pointer. Melalui implementasi bertahap dalam beberapa program, dipelajari berbagai operasi dasar seperti penyisipan (insert), penghapusan (delete), penghitungan jumlah node (nbList), dan penghapusan seluruh list (deleteList). Penggunaan file terpisah seperti header, implementasi fungsi, dan program utama membantu menciptakan kode yang lebih terstruktur dan mudah dikelola. Secara keseluruhan, konsep ini memberikan dasar penting dalam memahami cara kerja struktur data dinamis serta manajemen memori pada bahasa C++.

## Referensi
1. Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in C++ (2nd ed.). Wiley.
2. Malik, D. S. (2018). C++ Programming: Program Design Including Data Structures (8th ed.). Cengage Learning.
3. Harahap, H., & Lubis, M. (2020). “Implementasi Struktur Data Linked List pada Bahasa Pemrograman C++ untuk Pengelolaan Data Dinamis.” Jurnal Teknologi Informasi dan Komputer (JTIK), 6(2), 45–52.
4. Rahman, A., & Sari, D. P. (2021). “Analisis dan Implementasi Struktur Data Linked List dalam Pengembangan Sistem Informasi Akademik.” Jurnal Ilmiah Informatika, 9(1), 12–18.
