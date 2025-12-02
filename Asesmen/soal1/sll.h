#ifndef SLL_H
#define SLL_H

#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;

    Node(const std::string& name) : data(name), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList();
    
    ~SinglyLinkedList();

    void insert_tail(const std::string& name);

    bool delete_first_occurrence(const std::string& name);

    void display_list() const;

    int count_even_length_names() const;

    bool is_empty() const { return head == nullptr; }
};

#endif