#include "linked_list.h"

void LinkedList::build_node_list(int k) {
    nodeCount = k;
    shared_ptr<Node> prev = nullptr;
    for (int i = 0; i < k; i++) {
        shared_ptr<Node> newNode = make_shared<Node>(i);
        if (!root) {
            root = newNode;
        }
        if (prev) {
            prev->next = newNode;
        }
        prev = newNode;
    }
}

LinkedList::CopyNode * LinkedList::build_copyNodes_weak_ptrs() {
    CopyNode * copyNodes = new CopyNode[nodeCount];
    shared_ptr<Node> current = root;
    for (int i = 0; i < nodeCount; i++) {
        copyNodes[i].weak_node_ptr = current;
        current = current->next;
    }
    return copyNodes;
}

void LinkedList::delete_node_shared_ptr_list() {
    root.reset();
}

void LinkedList::print_node_list_shared_ptrs() {
    shared_ptr<Node> current = root;
    while (current) {
        cout << current.get() << " shared_ptr count: [" << current.use_count() << "]" << endl;
        current = current->next;
    }
}

void LinkedList::print_node_array_weak_ptrs(CopyNode * copyNodes) {
    for (int i = 0; i < nodeCount; i++) {
        cout << copyNodes[i].weak_node_ptr.lock().get() << " weak_ptr to shared_ptr count: [" << copyNodes[i].weak_node_ptr.use_count() << "]" << endl;
    }
}

LinkedList::LinkedList() : root(nullptr), nodeCount(0) {}

LinkedList::~LinkedList() {
    delete_node_shared_ptr_list();
}
