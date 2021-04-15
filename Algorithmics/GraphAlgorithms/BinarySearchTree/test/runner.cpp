/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_NodeTest_init = false;
#include "test.hpp"

static NodeTest suite_NodeTest;

static CxxTest::List Tests_NodeTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_NodeTest( "test.hpp", 7, "NodeTest", suite_NodeTest, Tests_NodeTest );

static class TestDescription_suite_NodeTest_test_find_min : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_find_min() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 9, "test_find_min" ) {}
 void runTest() { suite_NodeTest.test_find_min(); }
} testDescription_suite_NodeTest_test_find_min;

static class TestDescription_suite_NodeTest_test_find_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_find_max() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 15, "test_find_max" ) {}
 void runTest() { suite_NodeTest.test_find_max(); }
} testDescription_suite_NodeTest_test_find_max;

static class TestDescription_suite_NodeTest_test_search : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_search() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 21, "test_search" ) {}
 void runTest() { suite_NodeTest.test_search(); }
} testDescription_suite_NodeTest_test_search;

static class TestDescription_suite_NodeTest_test_is_balanced : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_is_balanced() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 29, "test_is_balanced" ) {}
 void runTest() { suite_NodeTest.test_is_balanced(); }
} testDescription_suite_NodeTest_test_is_balanced;

static class TestDescription_suite_NodeTest_test_compute_height : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_compute_height() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 41, "test_compute_height" ) {}
 void runTest() { suite_NodeTest.test_compute_height(); }
} testDescription_suite_NodeTest_test_compute_height;

static class TestDescription_suite_NodeTest_test_compute_balance : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_compute_balance() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 56, "test_compute_balance" ) {}
 void runTest() { suite_NodeTest.test_compute_balance(); }
} testDescription_suite_NodeTest_test_compute_balance;

static class TestDescription_suite_NodeTest_test_inorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_inorder_rec() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 69, "test_inorder_rec" ) {}
 void runTest() { suite_NodeTest.test_inorder_rec(); }
} testDescription_suite_NodeTest_test_inorder_rec;

static class TestDescription_suite_NodeTest_test_preorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_preorder_rec() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 76, "test_preorder_rec" ) {}
 void runTest() { suite_NodeTest.test_preorder_rec(); }
} testDescription_suite_NodeTest_test_preorder_rec;

static class TestDescription_suite_NodeTest_test_postorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_postorder_rec() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 83, "test_postorder_rec" ) {}
 void runTest() { suite_NodeTest.test_postorder_rec(); }
} testDescription_suite_NodeTest_test_postorder_rec;

static class TestDescription_suite_NodeTest_test_revinorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_revinorder_rec() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 90, "test_revinorder_rec" ) {}
 void runTest() { suite_NodeTest.test_revinorder_rec(); }
} testDescription_suite_NodeTest_test_revinorder_rec;

static class TestDescription_suite_NodeTest_test_inorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_inorder_it() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 97, "test_inorder_it" ) {}
 void runTest() { suite_NodeTest.test_inorder_it(); }
} testDescription_suite_NodeTest_test_inorder_it;

static class TestDescription_suite_NodeTest_test_preorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_preorder_it() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 103, "test_preorder_it" ) {}
 void runTest() { suite_NodeTest.test_preorder_it(); }
} testDescription_suite_NodeTest_test_preorder_it;

static class TestDescription_suite_NodeTest_test_postorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_postorder_it() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 109, "test_postorder_it" ) {}
 void runTest() { suite_NodeTest.test_postorder_it(); }
} testDescription_suite_NodeTest_test_postorder_it;

static class TestDescription_suite_NodeTest_test_revinorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_revinorder_it() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 115, "test_revinorder_it" ) {}
 void runTest() { suite_NodeTest.test_revinorder_it(); }
} testDescription_suite_NodeTest_test_revinorder_it;

static class TestDescription_suite_NodeTest_test_bfs : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_NodeTest_test_bfs() : CxxTest::RealTestDescription( Tests_NodeTest, suiteDescription_NodeTest, 121, "test_bfs" ) {}
 void runTest() { suite_NodeTest.test_bfs(); }
} testDescription_suite_NodeTest_test_bfs;

static BSTTest suite_BSTTest;

static CxxTest::List Tests_BSTTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_BSTTest( "test.hpp", 129, "BSTTest", suite_BSTTest, Tests_BSTTest );

static class TestDescription_suite_BSTTest_test_insertBST : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_insertBST() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 131, "test_insertBST" ) {}
 void runTest() { suite_BSTTest.test_insertBST(); }
} testDescription_suite_BSTTest_test_insertBST;

static class TestDescription_suite_BSTTest_test_buildBST : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_buildBST() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 146, "test_buildBST" ) {}
 void runTest() { suite_BSTTest.test_buildBST(); }
} testDescription_suite_BSTTest_test_buildBST;

static class TestDescription_suite_BSTTest_test_deleteBST : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_deleteBST() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 157, "test_deleteBST" ) {}
 void runTest() { suite_BSTTest.test_deleteBST(); }
} testDescription_suite_BSTTest_test_deleteBST;

static AVLTest suite_AVLTest;

static CxxTest::List Tests_AVLTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AVLTest( "test.hpp", 182, "AVLTest", suite_AVLTest, Tests_AVLTest );

static class TestDescription_suite_AVLTest_test_get_height : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_get_height() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 184, "test_get_height" ) {}
 void runTest() { suite_AVLTest.test_get_height(); }
} testDescription_suite_AVLTest_test_get_height;

static class TestDescription_suite_AVLTest_test_update_height : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_update_height() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 192, "test_update_height" ) {}
 void runTest() { suite_AVLTest.test_update_height(); }
} testDescription_suite_AVLTest_test_update_height;

static class TestDescription_suite_AVLTest_test_get_balance : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_get_balance() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 206, "test_get_balance" ) {}
 void runTest() { suite_AVLTest.test_get_balance(); }
} testDescription_suite_AVLTest_test_get_balance;

static class TestDescription_suite_AVLTest_test_right_rotate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_right_rotate() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 219, "test_right_rotate" ) {}
 void runTest() { suite_AVLTest.test_right_rotate(); }
} testDescription_suite_AVLTest_test_right_rotate;

static class TestDescription_suite_AVLTest_test_left_rotate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_left_rotate() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 234, "test_left_rotate" ) {}
 void runTest() { suite_AVLTest.test_left_rotate(); }
} testDescription_suite_AVLTest_test_left_rotate;

static class TestDescription_suite_AVLTest_test_left_right_rotate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_left_right_rotate() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 249, "test_left_right_rotate" ) {}
 void runTest() { suite_AVLTest.test_left_right_rotate(); }
} testDescription_suite_AVLTest_test_left_right_rotate;

static class TestDescription_suite_AVLTest_test_right_left_rotate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_right_left_rotate() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 264, "test_right_left_rotate" ) {}
 void runTest() { suite_AVLTest.test_right_left_rotate(); }
} testDescription_suite_AVLTest_test_right_left_rotate;

static class TestDescription_suite_AVLTest_test_insertAVL_left_left : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_insertAVL_left_left() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 282, "test_insertAVL_left_left" ) {}
 void runTest() { suite_AVLTest.test_insertAVL_left_left(); }
} testDescription_suite_AVLTest_test_insertAVL_left_left;

static class TestDescription_suite_AVLTest_test_insertAVL_right_right : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_insertAVL_right_right() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 290, "test_insertAVL_right_right" ) {}
 void runTest() { suite_AVLTest.test_insertAVL_right_right(); }
} testDescription_suite_AVLTest_test_insertAVL_right_right;

static class TestDescription_suite_AVLTest_test_insertAVL_left_right : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_insertAVL_left_right() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 298, "test_insertAVL_left_right" ) {}
 void runTest() { suite_AVLTest.test_insertAVL_left_right(); }
} testDescription_suite_AVLTest_test_insertAVL_left_right;

static class TestDescription_suite_AVLTest_test_insertAVL_right_left : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_insertAVL_right_left() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 310, "test_insertAVL_right_left" ) {}
 void runTest() { suite_AVLTest.test_insertAVL_right_left(); }
} testDescription_suite_AVLTest_test_insertAVL_right_left;

static class TestDescription_suite_AVLTest_test_deleteAVL_left_left : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_deleteAVL_left_left() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 323, "test_deleteAVL_left_left" ) {}
 void runTest() { suite_AVLTest.test_deleteAVL_left_left(); }
} testDescription_suite_AVLTest_test_deleteAVL_left_left;

static class TestDescription_suite_AVLTest_test_deleteAVL_right_right : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_deleteAVL_right_right() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 333, "test_deleteAVL_right_right" ) {}
 void runTest() { suite_AVLTest.test_deleteAVL_right_right(); }
} testDescription_suite_AVLTest_test_deleteAVL_right_right;

static class TestDescription_suite_AVLTest_test_deleteAVL_left_right : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_deleteAVL_left_right() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 343, "test_deleteAVL_left_right" ) {}
 void runTest() { suite_AVLTest.test_deleteAVL_left_right(); }
} testDescription_suite_AVLTest_test_deleteAVL_left_right;

static class TestDescription_suite_AVLTest_test_deleteAVL_right_left : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AVLTest_test_deleteAVL_right_left() : CxxTest::RealTestDescription( Tests_AVLTest, suiteDescription_AVLTest, 353, "test_deleteAVL_right_left" ) {}
 void runTest() { suite_AVLTest.test_deleteAVL_right_left(); }
} testDescription_suite_AVLTest_test_deleteAVL_right_left;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
