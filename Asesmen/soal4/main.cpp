#include "queue.h"
#include <limits> 

using namespace std;

Paket createPaket(string resi, string pengirim, int berat, string tujuan) {
    Paket p;
    p.KodeResi = resi;
    p.NamaPengirim = pengirim;
    p.BeratBarang = berat;
    p.Tujuan = tujuan;
    return p;
}

void display_menu() {
    cout << "\n--- Komaniya Ekspress ---" << endl;
    cout << "1. Input Data Paket" << endl;
    cout << "2. Hapus Data Paket" << endl;
    cout << "3. Tampilkan Queue" << endl;
    cout << "4. Hitung Total Biaya" << endl; 
    cout << "0. Exit" << endl;
    cout << "Pilihan anda: ";
}

int main() {
    QueueEkspedisi Q;
    Paket tempPaket;
    int choice;

    cout << "=== Program ADT Queue (Array) Ringkas ===" << endl;
    cout << setprecision(2) << fixed;
    
    cout << "\n[1] Create Queue" << endl;
    createQueue(Q);
    
    Paket dataPaket[5] = {
        createPaket("123456", "Hutao", 14, "Sumeru"),
        createPaket("234567", "Ayaka", 10, "Fontaine"),
        createPaket("345678", "Bennet", 7, "Natlan"),
        createPaket("456789", "Furina", 16, "Liyue"),
        createPaket("567890", "Nefer", 6, "Inazuma")
    };
    int data_count = 5;

    cout << "\n[3] Enqueue 5 Data" << endl;
    for (int i = 0; i < data_count; ++i) {
        enQueue(Q, dataPaket[i]);
    }

    cout << "\n[4] View Queue Setelah Input" << endl;
    viewQueue(Q);

    cout << "\n[5] Dequeue 1x" << endl;
    if (deQueue(Q, tempPaket)) {
        cout << "Dequeue: " << tempPaket.NamaPengirim << " (Resi: " << tempPaket.KodeResi << ")" << endl;
    } else {
        cout << "Dequeue Gagal: Queue Kosong." << endl;
    }

    cout << "\n[6] View Queue Setelah Dequeue" << endl;
    viewQueue(Q);
    
    cout << "\n=== Simulasi Menu Interaktif ===" << endl;
    
    do {
        display_menu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "Pengirim: "; getline(cin, tempPaket.NamaPengirim);
                cout << "Resi: "; getline(cin, tempPaket.KodeResi);
                cout << "Berat (kg): "; cin >> tempPaket.BeratBarang;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Tujuan: "; getline(cin, tempPaket.Tujuan);
                
                if (enQueue(Q, tempPaket)) {
                    cout << "EnQueue Berhasil." << endl;
                } else {
                    cout << "EnQueue Gagal: Queue Penuh." << endl;
                }
                break;
            case 2:
                if (deQueue(Q, tempPaket)) {
                    cout << "Dequeue: " << tempPaket.NamaPengirim << " (Resi: " << tempPaket.KodeResi << ")" << endl;
                } else {
                    cout << "Dequeue Gagal: Queue Kosong." << endl;
                }
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4:
                {
                    float total_biaya = TotalBiayaPengiriman(Q);
                    cout << "Total Biaya Pengiriman: Rp. " << total_biaya << endl;
                }
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}