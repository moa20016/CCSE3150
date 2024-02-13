#include "linked_list.h"
#include <iostream>

void initializeLinkedList(Node* head) {
    Node* current = head;
    for (int i = 0; i < 4; ++i) { //length of linked list
        current->next = new Node();
        current = current->next;
    }
    current->next = current;
}

void pointerJumping(Node* head) {
    Node* current = head;
    Node* last = nullptr;
    while (current->next != current) {
        last = current->next;
        current = current->next;
    }
    current = head;
    while (current->next != current) {
        current->next = last;
        current = current->next;
    }
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current->next != current) {
        std::cout << current << " -> ";
        current = current->next;
    }
    std::cout << current << std::endl;
}
