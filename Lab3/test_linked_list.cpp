#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("LinkedList functionality") {
    SUBCASE("Initialization") {
        Node* head = new Node();
        initializeLinkedList(head);
        Node* current = head;
        for (int i = 0; i < 5; ++i) {
            REQUIRE(current->next != nullptr);
            current = current->next;
        }
        REQUIRE(current->next == current); // Check if last element points to itself
        delete head; 
    }

    SUBCASE("Pointer jumping") {
        Node* head = new Node();
        initializeLinkedList(head);
        pointerJumping(head);
        Node* current = head;
        Node* last = nullptr;
        // Find the last element
        while (current->next != current) {
            last = current->next;
            current = current->next;
        }
        current = head;
        // Check if all elements point to the last element
        while (current->next != current) {
            REQUIRE(current->next == last);
            current = current->next;
        }
        delete head;
    }
}
