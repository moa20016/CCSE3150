#include <iostream>
#include <memory>
#include "linked_list.h"

using namespace std;

int main() {
    LinkedList list;
    list.build_node_list(5);

    cout << "build_node_list_shared_ptrs START" << endl;
    list.print_node_list_shared_ptrs();
    cout << "build_node_list_shared_ptrs END" << endl;

    LinkedList::CopyNode * copyNodes = list.build_copyNodes_weak_ptrs();

    cout << "print_node_list_shared_ptrs START" << endl;
    list.print_node_list_shared_ptrs();
    cout << "print_node_list_shared_ptrs END" << endl;

    cout << "print_node_array_weak_ptrs START" << endl;
    list.print_node_array_weak_ptrs(copyNodes);
    cout << "print_node_array_weak_ptrs END" << endl;

    list.delete_node_shared_ptr_list();

    cout << "delete_node_shared_ptr_list START" << endl;
    list.print_node_array_weak_ptrs(copyNodes);
    cout << "delete_node_shared_ptr_list END" << endl;

    delete[] copyNodes;

    return 0;
}
