#include "bst.h"

bool isEmpty(Node* root) {
    return root == NULL;
}

Node* createTree() {
    return NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* baru = new Node();
    baru->namaMember = nama;
    baru->beratBadan = berat;
    baru->tierMember = tier;
    baru->left = baru->right = NULL;
    return baru;
}

Node* insertNode(Node* root, string nama, float berat, string tier) {
    if (root == NULL) return newNode(nama, berat, tier);
    
    if (berat < root->beratBadan)
        root->left = insertNode(root->left, nama, berat, tier);
    else if (berat > root->beratBadan)
        root->right = insertNode(root->right, nama, berat, tier);
    
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

void mostLeft(Node* root) {
    if (isEmpty(root)) return;
    Node* current = root;
    while (current->left != NULL) current = current->left;
    cout << "Node MostLeft  : " << current->beratBadan << endl;
}

void mostRight(Node* root) {
    if (isEmpty(root)) return;
    Node* current = root;
    while (current->right != NULL) current = current->right;
    cout << "Node MostRight : " << current->beratBadan << endl;
}

void printDetail(Node* node) {
    if (node == NULL) cout << "(Tidak ada data)" << endl;
    else {
        cout << "Nama Member : " << node->namaMember << endl;
        cout << "Berat Badan : " << node->beratBadan << endl;
        cout << "Tier Member : " << node->tierMember << endl;
    }
}

void searchByBeratBadan(Node* root, float target) {
    Node *current = root, *parent = NULL, *sibling = NULL;

    while (current != NULL && current->beratBadan != target) {
        parent = current;
        if (target < current->beratBadan) {
            current = current->left;
            sibling = parent->right;
        } else {
            current = current->right;
            sibling = parent->left;
        }
    }

    if (current == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    cout << "Data ditemukan didalam BST!" << endl;
    cout << "--- Data Node Yang Dicari ---" << endl;
    printDetail(current);
    cout << "-----------------------------" << endl;
    cout << "--- Data Parent ---" << endl;
    printDetail(parent);
    cout << "-----------------------------" << endl;
    if (sibling == NULL) cout << "Tidak Memiliki Sibling" << endl;
    else {
        cout << "--- Data Sibling ---" << endl;
        printDetail(sibling);
    }
    cout << "-----------------------------" << endl;
    cout << "--- Data Child Kiri ---" << endl;
    printDetail(current->left);
    cout << "-----------------------------" << endl;
    cout << "--- Data Child Kanan ---" << endl;
    printDetail(current->right);
    cout << "-----------------------------" << endl;
}