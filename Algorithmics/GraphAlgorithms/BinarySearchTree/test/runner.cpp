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
bool suite_BSTTest_init = false;
#include "test.hpp"

static BSTTest suite_BSTTest;

static CxxTest::List Tests_BSTTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_BSTTest( "test.hpp", 6, "BSTTest", suite_BSTTest, Tests_BSTTest );

static class TestDescription_suite_BSTTest_test_find_min : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_find_min() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 8, "test_find_min" ) {}
 void runTest() { suite_BSTTest.test_find_min(); }
} testDescription_suite_BSTTest_test_find_min;

static class TestDescription_suite_BSTTest_test_find_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_find_max() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 14, "test_find_max" ) {}
 void runTest() { suite_BSTTest.test_find_max(); }
} testDescription_suite_BSTTest_test_find_max;

static class TestDescription_suite_BSTTest_test_insertBST : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_insertBST() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 20, "test_insertBST" ) {}
 void runTest() { suite_BSTTest.test_insertBST(); }
} testDescription_suite_BSTTest_test_insertBST;

static class TestDescription_suite_BSTTest_test_buildBST : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_buildBST() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 35, "test_buildBST" ) {}
 void runTest() { suite_BSTTest.test_buildBST(); }
} testDescription_suite_BSTTest_test_buildBST;

static class TestDescription_suite_BSTTest_test_searchBST : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_searchBST() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 46, "test_searchBST" ) {}
 void runTest() { suite_BSTTest.test_searchBST(); }
} testDescription_suite_BSTTest_test_searchBST;

static class TestDescription_suite_BSTTest_test_deleteBST : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BSTTest_test_deleteBST() : CxxTest::RealTestDescription( Tests_BSTTest, suiteDescription_BSTTest, 55, "test_deleteBST" ) {}
 void runTest() { suite_BSTTest.test_deleteBST(); }
} testDescription_suite_BSTTest_test_deleteBST;

static TraversalTest suite_TraversalTest;

static CxxTest::List Tests_TraversalTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TraversalTest( "test.hpp", 80, "TraversalTest", suite_TraversalTest, Tests_TraversalTest );

static class TestDescription_suite_TraversalTest_test_inorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_inorder_rec() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 82, "test_inorder_rec" ) {}
 void runTest() { suite_TraversalTest.test_inorder_rec(); }
} testDescription_suite_TraversalTest_test_inorder_rec;

static class TestDescription_suite_TraversalTest_test_preorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_preorder_rec() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 89, "test_preorder_rec" ) {}
 void runTest() { suite_TraversalTest.test_preorder_rec(); }
} testDescription_suite_TraversalTest_test_preorder_rec;

static class TestDescription_suite_TraversalTest_test_postorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_postorder_rec() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 96, "test_postorder_rec" ) {}
 void runTest() { suite_TraversalTest.test_postorder_rec(); }
} testDescription_suite_TraversalTest_test_postorder_rec;

static class TestDescription_suite_TraversalTest_test_revinorder_rec : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_revinorder_rec() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 103, "test_revinorder_rec" ) {}
 void runTest() { suite_TraversalTest.test_revinorder_rec(); }
} testDescription_suite_TraversalTest_test_revinorder_rec;

static class TestDescription_suite_TraversalTest_test_inorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_inorder_it() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 110, "test_inorder_it" ) {}
 void runTest() { suite_TraversalTest.test_inorder_it(); }
} testDescription_suite_TraversalTest_test_inorder_it;

static class TestDescription_suite_TraversalTest_test_preorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_preorder_it() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 116, "test_preorder_it" ) {}
 void runTest() { suite_TraversalTest.test_preorder_it(); }
} testDescription_suite_TraversalTest_test_preorder_it;

static class TestDescription_suite_TraversalTest_test_postorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_postorder_it() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 122, "test_postorder_it" ) {}
 void runTest() { suite_TraversalTest.test_postorder_it(); }
} testDescription_suite_TraversalTest_test_postorder_it;

static class TestDescription_suite_TraversalTest_test_revinorder_it : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_revinorder_it() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 128, "test_revinorder_it" ) {}
 void runTest() { suite_TraversalTest.test_revinorder_it(); }
} testDescription_suite_TraversalTest_test_revinorder_it;

static class TestDescription_suite_TraversalTest_test_bfs : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraversalTest_test_bfs() : CxxTest::RealTestDescription( Tests_TraversalTest, suiteDescription_TraversalTest, 134, "test_bfs" ) {}
 void runTest() { suite_TraversalTest.test_bfs(); }
} testDescription_suite_TraversalTest_test_bfs;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
