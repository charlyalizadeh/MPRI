#include <cxxtest/TestSuite.h>
#include <iostream>
#include "../node.hpp"
#include "../bst.hpp"
#include "../avl.hpp"

class NodeTest: public CxxTest::TestSuite {
    public:
        void test_find_min() {
            Node<int> root(5);
            root.right = new Node<int>(7);
            root.left = new Node<int>(3);
            TS_ASSERT_EQUALS((root.find_min())->value, 3);
        }
        void test_find_max() {
            Node<int> root(5);
            root.right = new Node<int>(7);
            root.left = new Node<int>(3);
            TS_ASSERT_EQUALS((root.find_max())->value, 7);
        }
        void test_search() {
            Node<int>* root = buildBST(std::vector<int>({3, 2, 4}));
            TS_ASSERT(root->search(3));
            TS_ASSERT(root->search(2));
            TS_ASSERT(root->search(4));
            TS_ASSERT(!(root->search(5)));
            delete root;
        }
        void test_is_balanced() {
            Node<int>* node1 = new Node<int>(1);
            Node<int>* node2 = new Node<int>(2);
            Node<int>* node3 = new Node<int>(3);        
            Node<int>* node4 = new Node<int>(4);
            node1->left = node2;
            node2->left = node3;
            TS_ASSERT(!is_balanced(node1));
            node1->right = node4;
            TS_ASSERT(is_balanced(node1));
            delete node1;
        }
        void test_compute_height() {
            Node<int>* node1 = nullptr;
            TS_ASSERT_EQUALS(compute_height(node1), -1);
            node1 = new Node<int>(2);
            Node<int>* node2 = new Node<int>(1);
            Node<int>* node3 = new Node<int>(3);        
            node1->left = node2;
            node1->right = node3;
            node2->height = 5;
            node3->height = 4;
            TS_ASSERT_EQUALS(compute_height(node1), 1);
            TS_ASSERT_EQUALS(compute_height(node2), 0);
            TS_ASSERT_EQUALS(compute_height(node3), 0);
            delete node1;
        }
        void test_compute_balance() {
            Node<int>* node1 = nullptr;
            TS_ASSERT_EQUALS(compute_balance(node1), 0);
            node1 = new Node<int>(2);
            Node<int>* node2 = new Node<int>(1);
            Node<int>* node3 = new Node<int>(3);        
            node1->left = node2;
            node1->right = node3;
            node2->height = 5;
            node3->height = 4;
            TS_ASSERT_EQUALS(compute_balance(node1), 0);
            delete node1;
        }
        void test_inorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            root->inorder_rec(order);
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
            delete root;
        }
        void test_preorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            root->preorder_rec(order);
            TS_ASSERT_EQUALS(order, std::vector<int>({4, 2, 1, 3, 6, 5, 7}));
            delete root;
        }
        void test_postorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            root->postorder_rec(order);
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 3, 2, 5, 7, 6, 4}));
            delete root;
        }
        void test_revinorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            root->revinorder_rec(order);
            TS_ASSERT_EQUALS(order, std::vector<int>({7, 6, 5, 4, 3, 2, 1}));
            delete root;
        }
        void test_inorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = root->inorder_it();
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
            delete root;
        }
        void test_preorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = root->preorder_it();
            TS_ASSERT_EQUALS(order, std::vector<int>({4, 2, 1, 3, 6, 5, 7}));
            delete root;
        }
        void test_postorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = root->postorder_it();
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 3, 2, 5, 7, 6, 4}));
            delete root;
        }
        void test_revinorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = root->revinorder_it();
            TS_ASSERT_EQUALS(order, std::vector<int>({7, 6, 5, 4, 3, 2, 1}));
            delete root;
        }
        void test_bfs() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = root->bfs();
            TS_ASSERT_EQUALS(order, std::vector<int>({4, 2, 6, 1, 3, 5, 7}));
            delete root;
        }
};

class BSTTest: public CxxTest::TestSuite {
    public:
        void test_insertBST() {
            Node<int> root(5);
            insertBST(&root, 7);
            insertBST(&root, 3);
            insertBST(&root, 9);
            insertBST(&root, 1);
            insertBST(&root, 2);
            insertBST(&root, 8);
            TS_ASSERT_EQUALS(root.right->value, 7);
            TS_ASSERT_EQUALS(root.left->value, 3);
            TS_ASSERT_EQUALS(root.right->right->value, 9);
            TS_ASSERT_EQUALS(root.left->left->value, 1);
            TS_ASSERT_EQUALS(root.left->left->right->value, 2);
            TS_ASSERT_EQUALS(root.right->right->left->value, 8);
        }
        void test_buildBST() {
            Node<int>* root = buildBST(std::vector<int>({5, 7, 3, 9, 1, 2, 8}));
            TS_ASSERT_EQUALS(root->right->value, 7);
            TS_ASSERT_EQUALS(root->left->value, 3);
            TS_ASSERT_EQUALS(root->right->right->value, 9);
            TS_ASSERT_EQUALS(root->left->left->value, 1);
            TS_ASSERT_EQUALS(root->left->left->right->value, 2);
            TS_ASSERT_EQUALS(root->right->right->left->value, 8);
            delete root;
            root = nullptr;
        }
        void test_deleteBST() {
            // No children
            Node<int>* root_no = buildBST(std::vector<int>({2, 3, 1}));
            root_no = deleteBST(root_no, 1);
            TS_ASSERT(!searchBST(root_no, 1));
            TS_ASSERT(!(root_no->left));
            delete root_no; root_no = nullptr;

            // One child
            Node<int>* root_one = buildBST(std::vector<int>({3, 5, 4}));
            root_one = deleteBST(root_one, 5);
            TS_ASSERT(!searchBST(root_one, 5));
            TS_ASSERT_EQUALS(root_one->right->value, 4);
            delete root_one; root_one = nullptr;

            // Two children
            Node<int>* root_two = buildBST(std::vector<int>({3, 5, 4, 6}));
            root_two = deleteBST(root_two, 5);
            TS_ASSERT(!searchBST(root_one, 5));
            TS_ASSERT_EQUALS(root_two->right->value, 6);
            TS_ASSERT_EQUALS(root_two->right->left->value, 4);
            delete root_two; root_two = nullptr;
        }
};

class AVLTest: public CxxTest::TestSuite {
    public:
        void test_get_height() {
            Node<int>* node = nullptr;
            TS_ASSERT_EQUALS(get_height(node), -1);
            node = new Node<int>(1);
            node->height = 5;
            TS_ASSERT_EQUALS(get_height(node), 5);
            delete node;
        }
        void test_update_height() {
            Node<int>* node1 = new Node<int>(2);
            Node<int>* node2 = new Node<int>(1);
            Node<int>* node3 = new Node<int>(3);        
            node1->update_height();
            TS_ASSERT_EQUALS(node1->height, 0);
            node1->left = node2;
            node1->right = node3;
            node2->height = 5;
            node3->height = 4;
            node1->update_height();
            TS_ASSERT_EQUALS(node1->height, 6);
            delete node1;
        }
        void test_get_balance() {
            Node<int>* node1 = nullptr;
            TS_ASSERT_EQUALS(get_balance(node1), 0);
            node1 = new Node<int>(2);
            Node<int>* node2 = new Node<int>(1);
            Node<int>* node3 = new Node<int>(3);        
            node1->left = node2;
            node1->right = node3;
            node2->height = 5;
            node3->height = 4;
            TS_ASSERT_EQUALS(get_balance(node1), -1);
            delete node1;
        }
        void test_right_rotate() {
            Node<int>* node1 = new Node<int>(1);
            Node<int>* node2 = new Node<int>(2);
            Node<int>* node3 = new Node<int>(3);        
            Node<int>* node4 = new Node<int>(4);
            node1->left = node2;
            node2->left = node3;
            node2->right = node4;
            node1 = right_rotate(node1);
            TS_ASSERT_EQUALS(node1->value, 2);
            TS_ASSERT_EQUALS(node1->left->value, 3);
            TS_ASSERT_EQUALS(node1->right->value, 1);
            TS_ASSERT_EQUALS(node1->right->left->value, 4);
            delete node1;
        }
        void test_left_rotate() {
            Node<int>* node1 = new Node<int>(1);
            Node<int>* node2 = new Node<int>(2);
            Node<int>* node3 = new Node<int>(3);        
            Node<int>* node4 = new Node<int>(4);
            node1->right = node2;
            node2->right = node3;
            node2->left = node4;
            node1 = left_rotate(node1);
            TS_ASSERT_EQUALS(node1->value, 2);
            TS_ASSERT_EQUALS(node1->right->value, 3);
            TS_ASSERT_EQUALS(node1->left->value, 1);
            TS_ASSERT_EQUALS(node1->left->right->value, 4);
            delete node1;
        }
        void test_left_right_rotate() {
            Node<int>* node1 = new Node<int>(1);
            Node<int>* node2 = new Node<int>(2);
            Node<int>* node3 = new Node<int>(3);        
            Node<int>* node4 = new Node<int>(4);
            node1->left = node2;
            node2->left = node3;
            node2->right = node4;
            node1 = left_right_rotate(node1);
            TS_ASSERT_EQUALS(node1->value, 4);
            TS_ASSERT_EQUALS(node1->left->value, 2);
            TS_ASSERT_EQUALS(node1->left->left->value, 3);
            TS_ASSERT_EQUALS(node1->right->value, 1);
            delete node1;
        }
        void test_right_left_rotate() {
            Node<int>* node1 = new Node<int>(1);
            Node<int>* node2 = new Node<int>(2);
            Node<int>* node3 = new Node<int>(3);        
            Node<int>* node4 = new Node<int>(4);
            Node<int>* node5 = new Node<int>(5);
            node1->left = node5;
            node1->right = node2;
            node2->right = node3;
            node2->left = node4;
            node1 = right_left_rotate(node1);
            TS_ASSERT_EQUALS(node1->value, 4);
            TS_ASSERT_EQUALS(node1->right->value, 2);
            TS_ASSERT_EQUALS(node1->right->right->value, 3);
            TS_ASSERT_EQUALS(node1->left->value, 1);
            TS_ASSERT_EQUALS(node1->left->left->value, 5);
            delete node1;
        }
        void test_insertAVL_left_left() {
            Node<int>* root = new Node<int>(3);
            root = insertAVL(root, 2);
            root = insertAVL(root, 1);
            TS_ASSERT_EQUALS(root->value, 2);
            TS_ASSERT_EQUALS(root->right->value, 3);
            TS_ASSERT_EQUALS(root->left->value, 1);
        }
        void test_insertAVL_right_right() {
            Node<int>* root = new Node<int>(1);
            root = insertAVL(root, 2);
            root = insertAVL(root, 3);
            TS_ASSERT_EQUALS(root->value, 2);
            TS_ASSERT_EQUALS(root->right->value, 3);
            TS_ASSERT_EQUALS(root->left->value, 1);
        }
        void test_insertAVL_left_right() {
            Node<int>* root = new Node<int>(4);
            root = insertAVL(root, 5);
            root = insertAVL(root, 3);
            root = insertAVL(root, 1);
            root = insertAVL(root, 2);
            TS_ASSERT_EQUALS(root->value, 4);
            TS_ASSERT_EQUALS(root->right->value, 5);
            TS_ASSERT_EQUALS(root->left->value, 2);
            TS_ASSERT_EQUALS(root->left->left->value, 1);
            TS_ASSERT_EQUALS(root->left->right->value, 3);
        }
        void test_insertAVL_right_left() {
            Node<int>* root = new Node<int>(2);
            root = insertAVL(root, 1);
            root = insertAVL(root, 3);
            root = insertAVL(root, 5);
            root = insertAVL(root, 4);
            TS_ASSERT_EQUALS(root->value, 2);
            TS_ASSERT_EQUALS(root->left->value, 1);
            TS_ASSERT_EQUALS(root->right->value, 4);
            TS_ASSERT_EQUALS(root->right->left->value, 3);
            TS_ASSERT_EQUALS(root->right->right->value, 5);
            delete root;
        }
        void test_deleteAVL_left_left() {
            Node<int>* root = new Node<int>(3);
            root = insertAVL(root, 2);
            root = insertAVL(root, 4);
            root = insertAVL(root, 1);
            root = deleteAVL(root, 4);
            TS_ASSERT_EQUALS(root->value, 2);
            TS_ASSERT_EQUALS(root->right->value, 3);
            TS_ASSERT_EQUALS(root->left->value, 1);
        }
        void test_deleteAVL_right_right() {
            Node<int>* root = new Node<int>(2);
            root = insertAVL(root, 1);
            root = insertAVL(root, 3);
            root = insertAVL(root, 4);
            root = deleteAVL(root, 1);
            TS_ASSERT_EQUALS(root->value, 3);
            TS_ASSERT_EQUALS(root->right->value, 4);
            TS_ASSERT_EQUALS(root->left->value, 2);
        }
        void test_deleteAVL_left_right() {
            Node<int>* root = new Node<int>(3);
            root = insertAVL(root, 1);
            root = insertAVL(root, 4);
            root = insertAVL(root, 2);
            root = deleteAVL(root, 4);
            TS_ASSERT_EQUALS(root->value, 2);
            TS_ASSERT_EQUALS(root->right->value, 3);
            TS_ASSERT_EQUALS(root->left->value, 1);
        }
        void test_deleteAVL_right_left() {
            Node<int>* root = new Node<int>(2);
            root = insertAVL(root, 1);
            root = insertAVL(root, 3);
            root = insertAVL(root, 4);
            root = deleteAVL(root, 1);
            TS_ASSERT_EQUALS(root->value, 3);
            TS_ASSERT_EQUALS(root->right->value, 4);
            TS_ASSERT_EQUALS(root->left->value, 2);
        }
};
