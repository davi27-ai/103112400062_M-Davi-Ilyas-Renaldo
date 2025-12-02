#include "sll.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void SinglyLinkedList::insert_tail(const std::string& name) {
    Node* new_node = new Node(name);

    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

bool SinglyLinkedList::delete_first_occurrence(const std::string& name) {
    if (is_empty()) {
        return false;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != name) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    return true;
}

void SinglyLinkedList::display_list() const {
    if (is_empty()) {
        std::cout << "" << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int SinglyLinkedList::count_even_length_names() const {
    int count = 0;
    Node* current = head;
    

    while (current != nullptr) {
        if (current->data.length() % 2 == 0) {
            count++;
        }
        current = current->next;
    }

    return count;
}