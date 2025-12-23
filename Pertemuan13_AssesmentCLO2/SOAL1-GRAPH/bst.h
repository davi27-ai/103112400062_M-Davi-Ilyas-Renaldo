#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right;
};

bool isEmpty(Node* root);
Node* createTree();
Node* newNode(string nama, float berat, string tier);
Node* insertNode(Node* root, string nama, float berat, string tier);
void inOrder(Node* root);
void mostLeft(Node* root);
void mostRight(Node* root);
void searchByBeratBadan(Node* root, float target);
void printDetail(Node* node);

#endif