# <h1 align="center">Laporan Praktikum Modul 14 - Multi Linked List </h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
Graph merupakan struktur data non-linier yang merepresentasikan hubungan kompleks antara sekumpulan simpul (vertex) melalui himpunan sisi (edge). Dalam implementasi C++, pendekatan Adjacency List berbasis pointer sering digunakan karena efisiensinya dalam mengelola memori secara dinamis, di mana setiap simpul hanya menyimpan daftar simpul lain yang terhubung langsung dengannya tanpa bergantung pada struktur statis. Pada Graph Tidak Berarah (Undirected Graph), setiap hubungan bersifat timbal balik, sehingga penambahan sisi dilakukan secara dua arah di antara kedua simpul yang bersangkutan.

Untuk menavigasi struktur ini, diperlukan metode penelusuran sistematis seperti Depth First Search (DFS) yang mengeksplorasi cabang hingga kedalaman maksimal secara rekursif, serta Breadth First Search (BFS) yang memetakan simpul berdasarkan level kedekatan menggunakan bantuan antrean (queue). Guna menjamin keakuratan proses traversal dan menghindari siklus tak terbatas, variabel penanda visited wajib disematkan pada setiap simpul untuk memastikan bahwa setiap elemen hanya diproses satu kali. Pemahaman terhadap struktur ini menjadi fondasi penting dalam penyelesaian masalah keterhubungan data dan optimasi jalur dalam komputasi modern.

## Guided 
### 1. Graph
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode nextNode;
};

struct elmGraph {
    adrNode first;
};

typedef struct elmGraph *Graph;

//Prototype
void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```
#### graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}
```
#### graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}
```
#### graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}
```
#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Pada program C++ ini mengimplementasikan Adjacency List dengan pemanfaatan pointer secara dinamis. Struktur ElmNode berperan menyimpan informasi node dan status kunjungan, sementara ElmEdge berfungsi sebagai penghubung antar simpul. Program ini memfasilitasi pembuatan graph dari tahap awal hingga tahap visualisasi hubungan antar node. Melalui pendekatan ini, terlihat bagaimana pointer digunakan untuk merepresentasikan hubungan data yang kompleks, menjadikannya referensi yang efektif untuk memahami konsep graph dan alokasi memori dinamis.

## Unguided 
### 1. Graph Tidak Berarah
#### graph.cpp
```C++
#include "graph.h"
#include <queue> // Untuk membantu proses BFS

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // Karena Graph Tidak Berarah, buat edge dari N1 ke N2 dan N2 ke N1
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

// No 2: Depth First Search (Rekursif)
void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) return;
    
    cout << N->info << " ";
    N->visited = 1;
    
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

// No 3: Breadth First Search (Queue)
void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;
    
    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";

        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// Definisi tipe data sesuai soal
typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; // Digunakan untuk DFS/BFS
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node; // Node tujuan
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prosedur sesuai soal
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

// Tambahan soal no 2 & 3
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
#### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    // 1. Insert semua node A-H
    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (char c : nodes) {
        InsertNode(G, c);
    }

    // 2. Connect sesuai gambar ilustrasi 14-14
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'F'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'G'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'E'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'F'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'G'), FindNode(G, 'H'));

    cout << "--- Struktur Graph (Adjacency List) ---" << endl;
    PrintInfoGraph(G);

    cout << "\n--- Penelusuran DFS (Mulai dari A) ---" << endl;
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));
    cout << endl;

    cout << "\n--- Penelusuran BFS (Mulai dari A) ---" << endl;
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));
    cout << endl;

    return 0;
}
```
### Output Unguided 1:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan12_Modul14/LAPRAK/Output-Unguided1.png)

Program C++ ini merepresentasikan konsep graph tidak berarah melalui pendekatan Adjacency List berbasis pointer. Setiap elemen dalam graph didefinisikan secara mendetail melalui ElmNode dan ElmEdge yang saling terhubung secara dinamis di bawah kendali struktur utama Graph. Fokus utama program terletak pada visualisasi hasil traversal melalui dua metode populer: DFS yang mengeksplorasi cabang hingga tuntas dan BFS yang memetakan node berdasarkan kedekatan level. Dengan memanfaatkan variabel kontrol visited, program secara efektif mengelola status kunjungan setiap simpul. Output akhir program menyajikan urutan node secara sistematis, memberikan gambaran logis mengenai bagaimana algoritma pencarian bekerja dalam struktur data yang saling terhubung.

## Kesimpulan
Praktikum ini membuktikan efektivitas struktur Graph dalam merepresentasikan relasi data yang saling terhubung secara kompleks. Dengan mengimplementasikan adjacency list melalui pointer, pengelolaan graph tidak berarah menjadi lebih efisien karena tidak terbatas pada ukuran statis. Perbedaan karakteristik penelusuran antara DFS (mendalam) dan BFS (per level) memberikan gambaran nyata tentang bagaimana algoritma traversal berinteraksi dengan struktur data dinamis. Penguasaan teknik ini tidak hanya memperkuat konsep manipulasi pointer, tetapi juga menjadi dasar penting dalam memecahkan persoalan struktur data yang lebih rumit di masa depan.

## Referensi
1. Sjukani, Moh. (2014). Struktur Data (Algoritma & Struktur Data 2) dengan C, C++. Jakarta: Mitra Wacana Media.
2. Sutedjo, Budi & Nur Wijaya, Michael. (2010). Struktur Data dan Algoritma dengan C++. Yogyakarta: Andi Offset.
3. Munir, Rinaldi. (2010). Matematika Diskrit. Bandung: Informatika. (Menyediakan landasan matematis graph yang mendalam).
4. Siahaan, Vivian & Sianipar, R.H. (2020). Panduan Praktis Pemrograman C++ dan Struktur Data. Jakarta: Balige Publishing.