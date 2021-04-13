#include <cxxtest/TestSuite.h>
#include "../node.hpp"
#include "../bst.hpp"
#include "../traversal.hpp"

class BSTTest: public CxxTest::TestSuite {
    public:
        void test_find_min() {
            Node<int> root(5);
            root.right = new Node<int>(7);
            root.left = new Node<int>(3);
            TS_ASSERT_EQUALS(find_min(&root)->value, 3);
        }
        void test_find_max() {
            Node<int> root(5);
            root.right = new Node<int>(7);
            root.left = new Node<int>(3);
            TS_ASSERT_EQUALS(find_max(&root)->value, 7);
        }
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
        void test_searchBST() {
            Node<int>* root = buildBST(std::vector<int>({3, 2, 4}));
            TS_ASSERT(searchBST(root, 3));
            TS_ASSERT(searchBST(root, 2));
            TS_ASSERT(searchBST(root, 4));
            TS_ASSERT(!searchBST(root, 5));
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

class TraversalTest: public CxxTest::TestSuite {
    public:
        void test_inorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            inorder_rec(root, order);
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
            delete root;
        }
        void test_preorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            preorder_rec(root, order);
            TS_ASSERT_EQUALS(order, std::vector<int>({4, 2, 1, 3, 6, 5, 7}));
            delete root;
        }
        void test_postorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            postorder_rec(root, order);
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 3, 2, 5, 7, 6, 4}));
            delete root;
        }
        void test_revinorder_rec() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            std::vector<int> order;
            revinorder_rec(root, order);
            TS_ASSERT_EQUALS(order, std::vector<int>({7, 6, 5, 4, 3, 2, 1}));
            delete root;
        }
        void test_inorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = inorder_it(root);
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
            delete root;
        }
        void test_preorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = preorder_it(root);
            TS_ASSERT_EQUALS(order, std::vector<int>({4, 2, 1, 3, 6, 5, 7}));
            delete root;
        }
        void test_postorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = postorder_it(root);
            TS_ASSERT_EQUALS(order, std::vector<int>({1, 3, 2, 5, 7, 6, 4}));
            delete root;
        }
        void test_revinorder_it() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = revinorder_it(root);
            TS_ASSERT_EQUALS(order, std::vector<int>({7, 6, 5, 4, 3, 2, 1}));
            delete root;
        }
        void test_bfs() {
            Node<int>* root = buildBST(std::vector<int>({4, 2, 3, 1, 6, 5, 7}));
            auto order = bfs(root);
            TS_ASSERT_EQUALS(order, std::vector<int>({4, 2, 6, 1, 3, 5, 7}));
            delete root;
        }
};
