#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    Node* next;
};

void initializeLinkedList(Node* head);
void pointerJumping(Node* head);
void printLinkedList(Node* head);

#endif 
