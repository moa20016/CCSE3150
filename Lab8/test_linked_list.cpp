#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("LinkedList test") {
    LinkedList list;

    SUBCASE("build_node_list") {
        list.build_node_list(3);
        REQUIRE(list.root != nullptr);
        CHECK(list.root->data == 0);
        CHECK(list.root->next != nullptr);
        CHECK(list.root->next->data == 1);
        CHECK(list.root->next->next != nullptr);
        CHECK(list.root->next->next->data == 2);
        CHECK(list.root->next->next->next == nullptr);
    }

    SUBCASE("print_node_list_shared_ptrs") {
        list.build_node_list(3);
        std::ostringstream oss;
        auto old_buf = std::cout.rdbuf(oss.rdbuf()); 
        list.print_node_list_shared_ptrs();
        std::cout.rdbuf(old_buf); // Restore cout
        std::string output = oss.str();
        CHECK(output.find("shared_ptr count: [1]") == std::string::npos);
    }

    SUBCASE("build_copyNodes_weak_ptrs") {
        list.build_node_list(3);
        LinkedList::CopyNode* copyNodes = list.build_copyNodes_weak_ptrs();
        CHECK(copyNodes[0].weak_node_ptr.lock()->data == 0);
        CHECK(copyNodes[1].weak_node_ptr.lock()->data == 1);
        CHECK(copyNodes[2].weak_node_ptr.lock()->data == 2);
        delete[] copyNodes;
    }
}
