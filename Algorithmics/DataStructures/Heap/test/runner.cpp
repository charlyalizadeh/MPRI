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
bool suite_MaxBinaryHeapTest_init = false;
#include "test.hpp"

static MaxBinaryHeapTest suite_MaxBinaryHeapTest;

static CxxTest::List Tests_MaxBinaryHeapTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MaxBinaryHeapTest( "test.hpp", 6, "MaxBinaryHeapTest", suite_MaxBinaryHeapTest, Tests_MaxBinaryHeapTest );

static class TestDescription_suite_MaxBinaryHeapTest_test_constructors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_constructors() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 8, "test_constructors" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_constructors(); }
} testDescription_suite_MaxBinaryHeapTest_test_constructors;

static class TestDescription_suite_MaxBinaryHeapTest_test_merge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_merge() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 15, "test_merge" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_merge(); }
} testDescription_suite_MaxBinaryHeapTest_test_merge;

static class TestDescription_suite_MaxBinaryHeapTest_test_meld : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_meld() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 26, "test_meld" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_meld(); }
} testDescription_suite_MaxBinaryHeapTest_test_meld;

static class TestDescription_suite_MaxBinaryHeapTest_test_peek : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_peek() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 36, "test_peek" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_peek(); }
} testDescription_suite_MaxBinaryHeapTest_test_peek;

static class TestDescription_suite_MaxBinaryHeapTest_test_pop : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_pop() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 41, "test_pop" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_pop(); }
} testDescription_suite_MaxBinaryHeapTest_test_pop;

static class TestDescription_suite_MaxBinaryHeapTest_test_delete_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_delete_node() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 49, "test_delete_node" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_delete_node(); }
} testDescription_suite_MaxBinaryHeapTest_test_delete_node;

static class TestDescription_suite_MaxBinaryHeapTest_test_replace : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_replace() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 57, "test_replace" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_replace(); }
} testDescription_suite_MaxBinaryHeapTest_test_replace;

static class TestDescription_suite_MaxBinaryHeapTest_test_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_size() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 65, "test_size" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_size(); }
} testDescription_suite_MaxBinaryHeapTest_test_size;

static class TestDescription_suite_MaxBinaryHeapTest_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_empty() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 70, "test_empty" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_empty(); }
} testDescription_suite_MaxBinaryHeapTest_test_empty;

static class TestDescription_suite_MaxBinaryHeapTest_test_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_left_child() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 77, "test_left_child" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_left_child(); }
} testDescription_suite_MaxBinaryHeapTest_test_left_child;

static class TestDescription_suite_MaxBinaryHeapTest_test_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_right_child() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 83, "test_right_child" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_right_child(); }
} testDescription_suite_MaxBinaryHeapTest_test_right_child;

static class TestDescription_suite_MaxBinaryHeapTest_test_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_parent() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 88, "test_parent" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_parent(); }
} testDescription_suite_MaxBinaryHeapTest_test_parent;

static class TestDescription_suite_MaxBinaryHeapTest_test_get_height : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_get_height() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 95, "test_get_height" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_get_height(); }
} testDescription_suite_MaxBinaryHeapTest_test_get_height;

static class TestDescription_suite_MaxBinaryHeapTest_test_has_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_has_left_child() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 102, "test_has_left_child" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_has_left_child(); }
} testDescription_suite_MaxBinaryHeapTest_test_has_left_child;

static class TestDescription_suite_MaxBinaryHeapTest_test_has_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_has_right_child() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 110, "test_has_right_child" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_has_right_child(); }
} testDescription_suite_MaxBinaryHeapTest_test_has_right_child;

static class TestDescription_suite_MaxBinaryHeapTest_test_has_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_has_parent() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 118, "test_has_parent" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_has_parent(); }
} testDescription_suite_MaxBinaryHeapTest_test_has_parent;

static class TestDescription_suite_MaxBinaryHeapTest_test_has_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_has_child() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 124, "test_has_child" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_has_child(); }
} testDescription_suite_MaxBinaryHeapTest_test_has_child;

static class TestDescription_suite_MaxBinaryHeapTest_test_get_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MaxBinaryHeapTest_test_get_vector() : CxxTest::RealTestDescription( Tests_MaxBinaryHeapTest, suiteDescription_MaxBinaryHeapTest, 132, "test_get_vector" ) {}
 void runTest() { suite_MaxBinaryHeapTest.test_get_vector(); }
} testDescription_suite_MaxBinaryHeapTest_test_get_vector;

static MinBinaryHeapTest suite_MinBinaryHeapTest;

static CxxTest::List Tests_MinBinaryHeapTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MinBinaryHeapTest( "test.hpp", 142, "MinBinaryHeapTest", suite_MinBinaryHeapTest, Tests_MinBinaryHeapTest );

static class TestDescription_suite_MinBinaryHeapTest_test_constructors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_constructors() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 144, "test_constructors" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_constructors(); }
} testDescription_suite_MinBinaryHeapTest_test_constructors;

static class TestDescription_suite_MinBinaryHeapTest_test_merge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_merge() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 149, "test_merge" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_merge(); }
} testDescription_suite_MinBinaryHeapTest_test_merge;

static class TestDescription_suite_MinBinaryHeapTest_test_meld : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_meld() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 160, "test_meld" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_meld(); }
} testDescription_suite_MinBinaryHeapTest_test_meld;

static class TestDescription_suite_MinBinaryHeapTest_test_peek : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_peek() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 170, "test_peek" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_peek(); }
} testDescription_suite_MinBinaryHeapTest_test_peek;

static class TestDescription_suite_MinBinaryHeapTest_test_pop : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_pop() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 175, "test_pop" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_pop(); }
} testDescription_suite_MinBinaryHeapTest_test_pop;

static class TestDescription_suite_MinBinaryHeapTest_test_delete_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_delete_node() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 183, "test_delete_node" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_delete_node(); }
} testDescription_suite_MinBinaryHeapTest_test_delete_node;

static class TestDescription_suite_MinBinaryHeapTest_test_replace : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_replace() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 191, "test_replace" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_replace(); }
} testDescription_suite_MinBinaryHeapTest_test_replace;

static class TestDescription_suite_MinBinaryHeapTest_test_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_size() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 199, "test_size" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_size(); }
} testDescription_suite_MinBinaryHeapTest_test_size;

static class TestDescription_suite_MinBinaryHeapTest_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_empty() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 204, "test_empty" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_empty(); }
} testDescription_suite_MinBinaryHeapTest_test_empty;

static class TestDescription_suite_MinBinaryHeapTest_test_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_left_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 211, "test_left_child" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_left_child(); }
} testDescription_suite_MinBinaryHeapTest_test_left_child;

static class TestDescription_suite_MinBinaryHeapTest_test_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_right_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 217, "test_right_child" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_right_child(); }
} testDescription_suite_MinBinaryHeapTest_test_right_child;

static class TestDescription_suite_MinBinaryHeapTest_test_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_parent() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 222, "test_parent" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_parent(); }
} testDescription_suite_MinBinaryHeapTest_test_parent;

static class TestDescription_suite_MinBinaryHeapTest_test_get_height : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_get_height() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 229, "test_get_height" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_get_height(); }
} testDescription_suite_MinBinaryHeapTest_test_get_height;

static class TestDescription_suite_MinBinaryHeapTest_test_has_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_has_left_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 236, "test_has_left_child" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_has_left_child(); }
} testDescription_suite_MinBinaryHeapTest_test_has_left_child;

static class TestDescription_suite_MinBinaryHeapTest_test_has_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_has_right_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 244, "test_has_right_child" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_has_right_child(); }
} testDescription_suite_MinBinaryHeapTest_test_has_right_child;

static class TestDescription_suite_MinBinaryHeapTest_test_has_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_has_parent() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 252, "test_has_parent" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_has_parent(); }
} testDescription_suite_MinBinaryHeapTest_test_has_parent;

static class TestDescription_suite_MinBinaryHeapTest_test_has_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_has_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 258, "test_has_child" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_has_child(); }
} testDescription_suite_MinBinaryHeapTest_test_has_child;

static class TestDescription_suite_MinBinaryHeapTest_test_get_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapTest_test_get_vector() : CxxTest::RealTestDescription( Tests_MinBinaryHeapTest, suiteDescription_MinBinaryHeapTest, 266, "test_get_vector" ) {}
 void runTest() { suite_MinBinaryHeapTest.test_get_vector(); }
} testDescription_suite_MinBinaryHeapTest_test_get_vector;

static MinBinaryHeapNodeTest suite_MinBinaryHeapNodeTest;

static CxxTest::List Tests_MinBinaryHeapNodeTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MinBinaryHeapNodeTest( "test.hpp", 316, "MinBinaryHeapNodeTest", suite_MinBinaryHeapNodeTest, Tests_MinBinaryHeapNodeTest );

static class TestDescription_suite_MinBinaryHeapNodeTest_test_constructors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_constructors() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 318, "test_constructors" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_constructors(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_constructors;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_merge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_merge() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 323, "test_merge" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_merge(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_merge;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_meld : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_meld() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 334, "test_meld" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_meld(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_meld;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_peek : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_peek() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 344, "test_peek" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_peek(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_peek;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_pop : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_pop() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 349, "test_pop" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_pop(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_pop;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_delete_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_delete_node() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 357, "test_delete_node" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_delete_node(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_delete_node;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_replace : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_replace() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 365, "test_replace" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_replace(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_replace;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_size() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 373, "test_size" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_size(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_size;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_empty() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 378, "test_empty" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_empty(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_empty;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_left_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 385, "test_left_child" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_left_child(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_left_child;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_right_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 391, "test_right_child" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_right_child(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_right_child;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_parent() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 396, "test_parent" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_parent(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_parent;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_get_height : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_get_height() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 403, "test_get_height" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_get_height(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_get_height;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_has_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_has_left_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 410, "test_has_left_child" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_has_left_child(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_has_left_child;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_has_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_has_right_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 418, "test_has_right_child" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_has_right_child(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_has_right_child;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_has_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_has_parent() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 426, "test_has_parent" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_has_parent(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_has_parent;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_has_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_has_child() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 432, "test_has_child" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_has_child(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_has_child;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_get_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_get_vector() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 440, "test_get_vector" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_get_vector(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_get_vector;

static class TestDescription_suite_MinBinaryHeapNodeTest_test_decrease_key : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MinBinaryHeapNodeTest_test_decrease_key() : CxxTest::RealTestDescription( Tests_MinBinaryHeapNodeTest, suiteDescription_MinBinaryHeapNodeTest, 445, "test_decrease_key" ) {}
 void runTest() { suite_MinBinaryHeapNodeTest.test_decrease_key(); }
} testDescription_suite_MinBinaryHeapNodeTest_test_decrease_key;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
