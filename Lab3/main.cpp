#include <iostream>
#include "linked_list.h"

int main() {
    Node* head = new Node();
    initializeLinkedList(head);
    std::cout << "Original linked list:\n";
    printLinkedList(head);
    pointerJumping(head);
    std::cout << "After pointer jumping:\n";
    printLinkedList(head);

    Node* current = head;
    while (current->next != current) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    delete current;

    return 0;
}
