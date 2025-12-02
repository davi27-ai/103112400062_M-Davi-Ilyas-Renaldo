#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    
    ~DoublyLinkedList();

    void insert_tail(int val);

    bool delete_tail();

    void display_forward() const;

    void display_backward() const;

    void reverse_list();

    bool is_empty() const { return head == nullptr; }
};

#endif