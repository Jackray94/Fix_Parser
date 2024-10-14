#include <gtest/gtest.h>
#include <our_project/LibraryX/tools.h>


//Test stdout by way of gtest API
TEST(TestTopic, TrivialPrintHello) {
  testing::internal::CaptureStdout();
  our_project::tools::PrintHello();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Hello\n");
  // EXPECT_EQ(output, "Welcome\n");//<-- error
}

//Test stdout by way of a redirecting stdout to a buffer
// TEST(TestTopic, TrivialPrintHello) {
//   std::stringstream buffer;
//
//   std::streambuf * sbuf = std::cout.rdbuf();
//
//   std::cout.rdbuf(buffer.rdbuf());
//
//   our_project::tools::PrintHello();
//
//   
//   EXPECT_EQ(buffer.str(), "Hello\n");
//   EXPECT_EQ(buffer.str(), "Welcome\n");//<-- error
//
//   std::cout.rdbuf(sbuf);
// }


// //////////////////////////Notes from the tutorial/////////////////////////////////////////////////////
//
// // Must include the gtest header to use the testing library
// #include <gtest/gtest.h>
// namespace {
//   // We will test this dummy function but you can test
//   // any function from any library that you write too.
//   int GetMeaningOfLife() {  return 42; }
// }
//
// // All tests must live within TEST* blocks
// // Inside of the TEST block is a standard C++ scope
// // TestTopic defines a topic of our test, e.g. NameOfFunctionTest
// // TrivialEquality represents the name of this particular test
// // It should be descriptive and readable to the user
// // TEST is a macro, i.e., preprocessor replaces it with some code
// TEST(TestTopic, TrivialEquality) {
//   // We can test for equality, inequality etc.
//   // If the equality does not hold, the test fails.
//   // EXPECT_* are macros, i.e., also replaced by the preprocessor.
//   EXPECT_EQ(GetMeaningOfLife(), 42);
// }
//
// TEST(TestTopic, MoreEqualityTests) {
//   // ASSERT_* is similar to EXPECT_* but stops the execution
//   // of the test if fails.
//   // EXPECT_* continues execution on failure too.
//   ASSERT_EQ(GetMeaningOfLife(), 0) << "Oh no, a mistake!";
//   EXPECT_FLOAT_EQ(23.23F, 23.23F);
// }
// //////////////////////////////////////////////////////////////////////////////////////////////////////
