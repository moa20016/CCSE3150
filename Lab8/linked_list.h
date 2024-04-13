#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>

using namespace std;

struct LinkedList {
    struct Node {
        int data;
        shared_ptr<Node> next;
        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
    };

    struct CopyNode {
        weak_ptr<Node> weak_node_ptr;
    };

    shared_ptr<Node> root;
    int nodeCount;

    void build_node_list(int k);
    CopyNode * build_copyNodes_weak_ptrs();
    void delete_node_shared_ptr_list();
    void print_node_list_shared_ptrs();
    void print_node_array_weak_ptrs(CopyNode * copyNodes);

    LinkedList();
    ~LinkedList();
};

#endif
