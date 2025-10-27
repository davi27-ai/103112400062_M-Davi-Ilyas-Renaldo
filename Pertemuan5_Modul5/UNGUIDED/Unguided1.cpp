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
