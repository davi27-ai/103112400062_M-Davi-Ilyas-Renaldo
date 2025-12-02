#include "queue.h"

bool isEmpty(const QueueEkspedisi& Q) {
    return Q.Tail == -1; 
}

bool isFull(const QueueEkspedisi& Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi& Q) {
    Q.Head = 0; 
    Q.Tail = -1; 
}

bool enQueue(QueueEkspedisi& Q, const Paket& inputData) {
    if (isFull(Q)) {
        return false;
    }
    
    Q.Tail++;
    Q.dataPaket[Q.Tail] = inputData;
    return true;
}

bool deQueue(QueueEkspedisi& Q, Paket& outputData) {
    if (isEmpty(Q)) {
        return false;
    }
    
    outputData = Q.dataPaket[Q.Head]; 
    
    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }
    
    Q.Tail--; 
    return true;
}

void viewQueue(const QueueEkspedisi& Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
        return;
    }

    cout << "--- Isi Queue ---" << endl;
    cout << "Pos | Kode Resi | Pengirim | Berat | Tujuan" << endl;
    
    cout << setprecision(0) << fixed;
    
    for (int i = Q.Head; i <= Q.Tail; i++) {
        const Paket& p = Q.dataPaket[i];
        
        cout << setw(3) << i + 1 
             << " | " << setw(9) << left << p.KodeResi
             << " | " << setw(8) << p.NamaPengirim 
             << " | " << setw(5) << p.BeratBarang << " kg"
             << " | " << setw(7) << left << p.Tujuan 
             << (i == Q.Head ? " (H)" : "")
             << (i == Q.Tail ? " (T)" : "") << endl;
    }
    cout << "-----------------" << endl;
}

float TotalBiayaPengiriman(const QueueEkspedisi& Q) {
    float total_berat = 0.0f;
    
    if (isEmpty(Q)) {
        return 0.0f;
    }

    for (int i = Q.Head; i <= Q.Tail; i++) {
        total_berat += Q.dataPaket[i].BeratBarang;
    }

    return total_berat * BIAYA_PER_KG;
}