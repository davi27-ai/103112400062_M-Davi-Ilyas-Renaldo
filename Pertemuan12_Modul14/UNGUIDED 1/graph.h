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