#include "dll.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::insert_tail(int val) {
    Node* new_node = new Node(val);

    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

bool DoublyLinkedList::delete_tail() {
    if (is_empty()) {
        return false;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }

    Node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    
    return true;
}

void DoublyLinkedList::display_forward() const {
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

void DoublyLinkedList::display_backward() const {
    if (is_empty()) {
        std::cout << "" << std::endl;
        return;
    }

    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->prev != nullptr) {
            std::cout << " ";
        }
        current = current->prev;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::reverse_list() {
    if (is_empty() || head == tail) {
        return;
    }

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}