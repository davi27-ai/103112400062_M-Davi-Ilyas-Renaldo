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
