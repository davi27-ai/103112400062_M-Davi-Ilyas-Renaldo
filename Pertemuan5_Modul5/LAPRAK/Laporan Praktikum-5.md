# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori


## Guided 
### 1. Linked List Buah
#### listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H

#define Nil NULL
#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

// ==== DEKLARASI / PROTOTYPE ====
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void printList(linkedlist List);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// === Fungsi update data ===
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);

#endif
```
#### ListBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
#### main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program C++ ini menerapkan Single Linked List untuk menyimpan data buah, dengan menyediakan operasi penambahan data (melalui insertFirst, insertLast, dan insertAfter) serta operasi pembaruan data (melalui updateFirst, updateLast, dan updateAfter).

### 2. Linear dan Binary Search
#### linear.cpp
```C++
#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi linear search untuk mencari nilai dalam linked list
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* linearSearch(Node* head, int key) {
    Node* current = head;              // Mulai dari node pertama
    while (current != nullptr) {       // Traverse seluruh list
        if (current->data == key) {    // Jika data ditemukan
            return current;            // Kembalikan pointer node tersebut
        }
        current = current->next;       // Pindah ke node berikutnya
    }
    return nullptr;                    // Tidak ditemukan, return nullptr
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan beberapa elemen ke linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20); // Panggil fungsi linear search

  cout << (result ? "Found" : "Not Found") << endl; // Tampilkan hasil pencarian

    return 0;
}
```
Program C++ ini menggunakan Singly Linked List untuk menerapkan algoritma Linear Search, di mana fungsi append() menambahkan node baru dan linearSearch() menelusuri list untuk menemukan nilai tertentu serta menampilkan pesan “Found” atau “Not Found”.

#### binary.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* & head, int value) {
    Node* newNode = new Node {value,nullptr};
    
    if(!head) head = newNode;

    else {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current -> next) size++;
    Node *start = head;
    Node *end = nullptr;

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        for (int i = 0; i < mid; i++) {
            midNode = midNode -> next;
        }

        if (midNode -> data == key ) return midNode;
        if (midNode -> data < key) {
            start = midNode -> next;
    }
    else {
        end = midNode;
    }
    size -= mid;
}
return nullptr;
}
int main(){
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    Node* result = binarySearch(head, 10);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program C++ ini menerapkan algoritma Binary Search untuk mencari data pada array yang telah terurut. Pencarian dilakukan dengan membagi dua rentang data secara berulang, dilanjutkan ke kanan jika nilai tengah lebih kecil dari target, atau ke kiri jika lebih besar. Program menampilkan pesan “Found” jika data ditemukan dan “Not Found” jika tidak.

## Unguided 
### 1. Binary Search
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    cout << "\n=== Struktur Linked List ===" << endl;
    Node* temp = head;
    while (temp) {
        cout << "[" << temp->data << "]";
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

Node* middleNode(Node* start, Node* end) {
    if (start == nullptr)
        return nullptr;

    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int iterasi = 1;

    cout << "\n=== Proses Pencarian Nilai " << key << " ===" << endl;

    do {
        Node* mid = middleNode(start, end);

        if (mid == nullptr) {
            cout << ">> Tidak ada elemen yang tersisa dalam pencarian." << endl;
            return nullptr;
        }

        cout << "Iterasi ke-" << iterasi++ << " :" << endl;
        cout << "Nilai tengah saat ini= " << mid->data << endl;

        if (mid->data == key) {
            cout << "Ditemukan! Nilai cocok dengan " << key << endl;
            return mid;
        } else if (mid->data < key) {
            cout << "Nilai tengah lebih kecil, lanjut ke bagian KANAN." << endl;
            start = mid->next;
        } else {
            cout << "Nilai tengah lebih besar, lanjut ke bagian KIRI." << endl;
            end = mid;
        }

        cout << "_____________________________________" << endl;
    } while (end == nullptr || end != start);

    cout << ">> Pencarian selesai. Nilai tidak ditemukan." << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "=====================================" << endl;
    cout << "  PROGRAM BINARY SEARCH LINKED LIST  " << endl;
    cout << "=====================================" << endl;
    printList(head);

    int searchValue1 = 40;
    cout << "\nMencari nilai: " << searchValue1 << endl;
    Node* result1 = binarySearch(head, searchValue1);

    if (result1) {
        cout << "\n======= HASIL PENCARIAN =======" << endl;
        cout << "Nilai " << searchValue1 << " ditemukan dalam linked list!" << endl;
        cout << "Alamat Node : " << result1 << endl;
        cout << "Isi Node    : " << result1->data << endl;
        cout << "Node Berikut: ";
        if (result1->next) cout << result1->next->data << endl;
        else cout << "NULL" << endl;
    }

    int searchValue2 = 25;
    cout << "\nMencari nilai: " << searchValue2 << endl;
    Node* result2 = binarySearch(head, searchValue2);

    if (!result2) {
        cout << "\n=== HASIL PENCARIAN ===" << endl;
        cout << "Nilai " << searchValue2 << " TIDAK ditemukan dalam linked list!" << endl;
    }

    cout << "\n=== PROGRAM SELESAI ===" << endl;
    return 0;
}

```
### Output Unguided 1:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan5_Modul5/LAPRAK/Output-Unguided1.png)

Program C++ ini merupakan implementasi binary search pada linked list, di mana data pada linked list diurutkan dan pencarian dilakukan dengan cara membagi daftar menjadi dua bagian menggunakan fungsi middleNode. Program ini menampilkan setiap langkah proses pencarian dengan informasi nilai tengah yang diperiksa pada setiap iterasi, kemudian menentukan apakah pencarian dilanjutkan ke bagian kiri atau kanan hingga data ditemukan atau tidak ditemukan.

### 2. Linear Search
```C++
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next; 
};

void printList(Node* node) {
    cout << "\n=== STRUKTUR LINKED LIST ===" << endl;
    while (node != NULL) {
        cout << "[" << node->data << "]";
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    cout << "\n=== PROSES PENCARIAN NILAI " << key << " ===" << endl;
    Node* current = head;
    int position = 1;
    bool found = false;

    while (current != NULL) {
        cout << "Memeriksa Node ke- " << position << "Nilai: " << current->data;

        if (current->data == key) {
            cout << " Cocok! (DITEMUKAN)" << endl;
            found = true;
            return current;
        } else {
            cout << " Tidak sama, lanjut ke node berikutnya" << endl;
        }

        current = current->next;
        position++;
    }

    cout << "Tidak ada node lagi yang tersisa. Nilai " << key << " tidak ditemukan." << endl;
    return nullptr;
}

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "=============================================" << endl;
    cout << "   PROGRAM LINEAR SEARCH PADA LINKED LIST   " << endl;
    cout << "=============================================" << endl;

    printList(head);

    // Pencarian pertama
    int cari1 = 30;
    cout << "\nMencari nilai: " << cari1 << endl;
    Node* result = linearSearch(head, cari1);

    if (result != NULL) {
        cout << "\n=== HASIL PENCARIAN ===" << endl;
        cout << "Nilai " << result->data << " ditemukan pada linked list!" << endl;
        cout << "Alamat Node : " << result << endl;
        cout << "Isi Node    : " << result->data << endl;
        cout << "Node Berikut: ";
        if (result->next)
            cout << result->next->data << endl;
        else
            cout << "NULL" << endl;
    } else {
        cout << "\nNilai " << cari1 << " tidak ditemukan dalam linked list." << endl;
    }

    // Pencarian kedua
    int cari2 = 25;
    cout << "\nMencari nilai: " << cari2 << endl;
    result = linearSearch(head, cari2);

    if (result != NULL) {
        cout << "\n=== HASIL PENCARIAN ===" << endl;
        cout << "Nilai " << result->data << " ditemukan pada linked list!" << endl;
    } else {
        cout << "\nNilai " << cari2 << " tidak ditemukan dalam linked list." << endl;
    }

    cout << "\n=== PROGRAM SELESAI ===" << endl;
    return 0;
}

```
### Output Unguided 2:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan5_Modul5/LAPRAK/Output-Unguided2.png)

Program C++ ini merupakan pengimplementasian linear search pada linked list yang melakukan pencarian data secara berurutan dari node pertama hingga node terakhir. Program menampilkan proses pemeriksaan setiap node, menunjukkan apakah data pada node tersebut sama dengan nilai yang dicari dan berhenti ketika data ditemukan atau semua node telah diperiksa. Keduanya menampilkan hasil pencarian lengkap beserta alamat dan isi node yang ditemukan, dengan tampilan output yang lebih informatif dan terstruktur.

## Kesimpulan
Pada praktikum modul ini dipelajari konsep dan penerapan algoritma searching yaitu Linear Search dan Binary Search pada struktur data Singly Linked List. Melalui latihan yang telah diberikan, diperoleh pemahaman tentang perbedaan efisiensi kedua algoritma dalam mencari data. Linear Search lebih sederhana untuk list tidak terurut, sedangkan Binary Search lebih cepat pada data terurut namun lebih kompleks diimplementasikan pada linked list. Praktikum ini juga menekankan pentingnya analisis kompleksitas waktu serta pemilihan algoritma yang tepat sesuai dengan struktur data dan karakteristik dataset.

## Referensi
1. Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in C++ (2nd ed.). Wiley.
2. Malik, D. S. (2018). C++ Programming: Program Design Including Data Structures (8th ed.). Cengage Learning.
3. Harahap, H., & Lubis, M. (2020). “Implementasi Struktur Data Linked List pada Bahasa Pemrograman C++ untuk Pengelolaan Data Dinamis.” Jurnal Teknologi Informasi dan Komputer (JTIK), 6(2), 45–52.
4. Rahman, A., & Sari, D. P. (2021). “Analisis dan Implementasi Struktur Data Linked List dalam Pengembangan Sistem Informasi Akademik.” Jurnal Ilmiah Informatika, 9(1), 12–18.
5. Sari, N. P., & Nugroho, D. (2020). Analisis Perbandingan Algoritma Linear Search dan Binary Search pada Struktur Data. Jurnal Ilmiah Teknologi dan Rekayasa (JITERA), 5(1), 23–30.