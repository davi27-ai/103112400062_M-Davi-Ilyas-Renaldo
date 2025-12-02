#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 5;
const int BIAYA_PER_KG = 8250; 

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(const QueueEkspedisi& Q);
bool isFull(const QueueEkspedisi& Q);
void createQueue(QueueEkspedisi& Q);
bool enQueue(QueueEkspedisi& Q, const Paket& inputData);
bool deQueue(QueueEkspedisi& Q, Paket& outputData);
void viewQueue(const QueueEkspedisi& Q);

float TotalBiayaPengiriman(const QueueEkspedisi& Q);

#endif