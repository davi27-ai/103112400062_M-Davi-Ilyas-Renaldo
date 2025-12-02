# <h1 align="center">Laporan Praktikum Modul 8 - Queue </h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
Queue adalah salah satu Abstract Data Type (ADT) yang paling fundamental dalam ilmu komputer, berfungsi untuk menyimpan koleksi elemen data berdasarkan prinsip FIFO (First In, First Out), yang secara harfiah berarti elemen yang pertama kali masuk akan menjadi elemen yang pertama kali keluar. Secara konseptual, queue memiliki dua ujung utama: Head (Front), tempat elemen dihapus (operasi Dequeue), dan Tail (Rear), tempat elemen baru ditambahkan (operasi Enqueue). Implementasi queue dalam C++ dapat menggunakan array (alokasi statis) atau linked list (alokasi dinamis). Implementasi array menghasilkan Linear Queue yang rentan terhadap masalah "penuh semu" atau fragmentasi jika head bergerak maju, meskipun masalah ini dapat diatasi secara optimal melalui Circular Queue yang menggunakan operasi modulo untuk memungkinkan head dan tail berputar kembali ke awal array, menjadikannya implementasi array yang paling efisien dalam penggunaan memori. Sementara itu, implementasi berbasis Linked List unggul dalam hal fleksibilitas ukuran karena dapat menyesuaikan kapasitas secara dinamis tanpa batasan array, menghindari isu shifting atau penuh semu sama sekali. Semua operasi utama, seperti Enqueue dan Dequeue, idealnya dirancang untuk memiliki kompleksitas waktu $O(1)$ (waktu konstan). Pemahaman terhadap karakteristik unik setiap implementasi (Linear, Circular, dan Linked List) sangat penting untuk menentukan solusi queue yang paling sesuai dengan kebutuhan sistem yang mengutamakan pengolahan data secara teratur dan berurutan.

## Guided 
### 1. queue linked list
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(address &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif 
```
#### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
#### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;
    
    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```
Program C++ ini mengimplementasikan struktur data Queue (Antrian) menggunakan linked list. Sesuai prinsip FIFO (First In, First Out), operasi enqueue menambahkan elemen baru di belakang antrian, sementara dequeue menghapus elemen dari depan. Keunggulan utama implementasi ini adalah fleksibilitas ukuran karena linked list memungkinkan antrian bertambah tanpa batas kapasitas yang kaku seperti pada array. Selain itu, kode ini juga menyertakan fungsionalitas untuk mengubah nilai elemen pada posisi spesifik dan mencari data tertentu, serta menampilkan seluruh isi queue.

### 2. circular queue
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
#### queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

#### main.cpp
```C++
#include<iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout<<"\n enqueue 3 elemen"<< endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout<<"\n dequeue 1 elemen"<< endl;
    cout<<"elemen keluar"<< dequeue(Q)<< endl;
    printInfo(Q);
    cout<<"\n enqueue 1 elemen"<< endl;
    enqueue(Q, 4);
    printInfo(Q);
    cout<<"\n dequeue 2 elemen"<<endl;
    cout<< "elemen keluar"<< dequeue(Q) <<endl;
    cout<< "elemen keluar"<<dequeue(Q)<< endl;
    printInfo(Q);
    return 0;

}
```
Program C++ ini mengimplementasikan Circular Queue menggunakan array dengan kapasitas yang telah ditentukan. Inti dari implementasi ini adalah penggunaan operasi modulo (%) yang memungkinkan indeks head dan tail untuk bergerak melingkar. Dengan cara ini, enqueue meletakkan data baru di lokasi tail yang diperbarui, dan dequeue mengambil elemen dari lokasi head yang diperbarui. Keuntungan utamanya adalah efisiensi, karena pendekatan sirkular ini menghindari kebutuhan untuk menggeser elemen seperti pada antrian linear, sekaligus memastikan pemanfaatan optimal dari semua slot array. Program ini juga menyediakan fungsi penting seperti pengecekan kondisi penuh/kosong dan pencetakan isi antrian secara berurutan.

## Unguided 
### 1. Alternatif 1 (head diam, tail bergerak)
#### queue.cpp
```C++
#include <iostream>
#include <iomanip>
#include "queue.h"

using namespace std;

void createQueue(Queue *Q) {
    Q->head = -1;
    Q->tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

bool enqueue(Queue *Q, infotype x) {
    if (isFullQueue(*Q)) {
        return false; 
    }

    if (isEmptyQueue(*Q)) {
        Q->head = 0;
        Q->tail = 0;
    } else {
        Q->tail++;
    }

    Q->info[Q->tail] = x;
    return true;
}

infotype dequeue(Queue *Q) {
    if (isEmptyQueue(*Q)) {
        return -1; 
    }

    infotype dequeued_value = Q->info[Q->head];
    
    if (Q->head == Q->tail) {
        createQueue(Q); 
    } else {
        Q->head++;
    }

    return dequeued_value;
}

void printInfo(Queue Q) {
    cout << setw(3) << Q.head 
         << " | " << setw(3) << Q.tail 
         << " | ";

    if (isEmptyQueue(Q)) {
        cout << setw(10) << "empty queue" << endl;
    } else {
        for (int i = 0; i < MAX_QUEUE; ++i) {
            if (i >= Q.head && i <= Q.tail) {
                cout << Q.info[i];
            } else if (i < Q.head) {
                cout << " "; 
            } else if (i > Q.tail) {
                cout << " ";
            }

            if (i < MAX_QUEUE - 1) {
                cout << " "; 
            }
        }
        cout << endl;
    }
}
```
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_QUEUE 5

typedef int infotype; 

typedef struct {
    infotype info[MAX_QUEUE]; 
    int head;
    int tail;
} Queue;

void createQueue(Queue *Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
bool enqueue(Queue *Q, infotype x);
infotype dequeue(Queue *Q);
void printInfo(Queue Q);

#endif
```
#### main.cpp
```C++
#include <iostream>
#include <iomanip>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;
    
    cout << "Hello World!" << endl;
    createQueue(&Q);

    cout << "----------------------" << endl;
    cout << " H | T | Queue Info" << endl;
    cout << "----------------------" << endl;
    
    printInfo(Q); 
    
    enqueue(&Q, 5); printInfo(Q); 
    enqueue(&Q, 2); printInfo(Q); 
    enqueue(&Q, 7); printInfo(Q); 
    
    dequeue(&Q); printInfo(Q); 
    enqueue(&Q, 4); printInfo(Q); 
    
    dequeue(&Q); printInfo(Q); 
    dequeue(&Q); printInfo(Q); 
    dequeue(&Q); printInfo(Q); 
    
    return 0;
}
```
### Output Unguided 1:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan8_Modul8/LAPRAK/Output-Unguided1.png)
Program C++ ini mengimplementasikan antrian (Queue) dengan mempertahankan posisi head selalu berada di indeks 0 array. Akibat dari desain ini, setiap operasi dequeue harus diikuti oleh penggeseran (shifting) seluruh elemen yang tersisa ke kiri satu posisi. Meskipun pendekatan ini menawarkan pemahaman konsep yang intuitif karena meniru antrean fisik, ia kurang efisien dari segi kinerja, terutama untuk antrian besar, karena membutuhkan waktu pemrosesan untuk penggeseran di setiap penghapusan.

### 2. Alternatif 2 (head bergerak, tail bergerak)
#### queue.cpp
```C++
#include <iostream>
#include <iomanip>
#include "queue.h"

using namespace std;

void createQueue(Queue *Q) {
    Q->head = -1; 
    Q->tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

bool enqueue(Queue *Q, infotype x) {
    if (isFullQueue(*Q)) {
        return false;
    }

    if (isEmptyQueue(*Q)) {
        Q->head = 0; 
        Q->tail = 0;
    } else {
        Q->tail++;
    }

    Q->info[Q->tail] = x;
    return true;
}

infotype dequeue(Queue *Q) {
    if (isEmptyQueue(*Q)) {
        return -1;
    }

    infotype dequeued_value = Q->info[Q->head]; 

    if (Q->head == Q->tail) {
        createQueue(Q); 
    } else {
        for (int i = Q->head + 1; i <= Q->tail; i++) {
            Q->info[i - 1] = Q->info[i];
        }
        
        Q->tail--;
    }

    return dequeued_value;
}

void printInfo(Queue Q) {
    cout << setw(3) << Q.head 
         << " | " << setw(3) << Q.tail 
         << " | ";

    if (isEmptyQueue(Q)) {
        cout << setw(10) << "empty queue" << endl;
    } else {
        for (int i = 0; i < MAX_QUEUE; ++i) {
            if (i <= Q.tail) {
                cout << Q.info[i];
            } else {
                cout << " ";
            }

            if (i < MAX_QUEUE - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
```
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> 

#define MAX_QUEUE 5

typedef int infotype; 

typedef struct {
    infotype info[MAX_QUEUE]; 
    int head;
    int tail;
} Queue;

void createQueue(Queue *Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
bool enqueue(Queue *Q, infotype x);
infotype dequeue(Queue *Q);
void printInfo(Queue Q);

#endif
```
#### main.cpp
```C++
#include <iostream>
#include <iomanip>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;
    
    cout << "Hello World!" << endl;
    createQueue(&Q);

    cout << "----------------------" << endl;
    cout << " H | T | Queue Info" << endl;
    cout << "----------------------" << endl;
    
    printInfo(Q); 
    
    enqueue(&Q, 5); printInfo(Q); 
    enqueue(&Q, 2); printInfo(Q); 
    enqueue(&Q, 7); printInfo(Q); 
    
    dequeue(&Q); printInfo(Q); 
    enqueue(&Q, 4); printInfo(Q); 
    
    dequeue(&Q); printInfo(Q); 
    
    dequeue(&Q); printInfo(Q); 
    dequeue(&Q); printInfo(Q); 
    
    return 0;
}
```
### Output Unguided 2:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan8_Modul8/LAPRAK/Output-Unguided2.png)
Program C++ ini mengimplementasikan Queue Linear di mana head dan tail bergerak maju secara independen tanpa operasi shifting yang mahal. Implementasi ini jauh lebih efisien dalam hal waktu pemrosesan dibandingkan dengan skema shifting (Alternatif 1) karena menghindari pergeseran elemen pada setiap dequeue. Namun, kelemahan utamanya adalah munculnya masalah 'penuh semu' (false full). Kondisi ini terjadi ketika tail mencapai batas akhir array dan tidak bisa lagi menerima elemen baru, meskipun slot-slot di awal array sudah kosong akibat head yang telah bergerak maju.

### 3. Alternatif 3 (head dan tail berputar)
#### queue.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % 5;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail){
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % 5;
    }

    return x;
}

void printInfo(Queue Q){
    cout << Q.head << " - " << Q.tail << " \t| ";

    if (isEmptyQueue(Q)){
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true){
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % 5;
    }

    cout << endl;
}
```

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q);    printInfo(Q);
    enqueue(Q,4);  printInfo(Q);

    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 3:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan8_Modul8/LAPRAK/Output-Unguided3.png)
Program C++ ini mengimplementasikan Antrian Melingkar (Circular Queue) menggunakan array dengan cerdas. Kuncinya terletak pada pemanfaatan operasi modulo yang memungkinkan indeks head dan tail untuk berputar kembali ke awal array setelah mencapai batas. Pendekatan sirkular ini secara efektif mengatasi masalah 'penuh semu' yang terjadi pada antrian linear dan menghilangkan overhead dari shifting elemen, menjadikannya implementasi yang paling efisien dan optimal dalam memanfaatkan memori array.

## Kesimpulan
Praktikum ini menunjukkan bahwa meskipun Circular Queue adalah implementasi berbasis array yang paling efisien karena mengatasi masalah penuh semu dan menghilangkan shifting, pemahaman terhadap kelebihan Linked List dalam hal fleksibilitas ukuran adalah kunci untuk memilih implementasi Queue (FIFO) yang tepat sesuai dengan kebutuhan aplikasi.

## Referensi
1. Ahyar, A. G., Laksono, E., & Fazly. (2021). Pembelajaran Array, Linked List, Stack, Dan Queue. Jurnal Struktur Data, STIKOM Tunas Bangsa Pematangsiantar.
2. Prasetiyo, S. M., Lanfai, A. E., Gymnastiar, A. N., Hafizh, F., & Mirniati. (2024). Konsep Dasar Dan Ruang Lingkup SIM. JRIIN : Jurnal Riset Informatika dan Inovasi, 2(3).
3. Sari, I. P., Batubara, I. H., Ramadhani, F., & Wardani, S. (2025). Perancangan Sistem Antrian pada Wahana Hiburan dengan Metode First In First Out (FIFO). sudo Jurnal Teknik Informatika - Ilmu Bersama Center, 1(3).
4. Wijoyo, A., Prasetiyo, A. R., Salsabila, A. A., Nife, K., Murni, & Nadapdap, P. B. (2024). Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1244–1246.