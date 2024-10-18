//#include "Fix_Parser/LibraryX/rough_start.h"
//#include "spdlog/fmt/bundled/core.h"
#include <gtest/gtest.h>
#include <Fix_Parser/LibraryX/createFIXMessage.h>
#include <Fix_Parser/LibraryX/createFIXMessage.cpp>//<- to test anonymous helpers inside .cpp 



TEST(populateSectionOfFieldsTest, 2Fields)
{
  std::string msg;
  populateSectionOfFields(msg, {8,9}, define_FieldSetters());

  std::cout << "Printout of string built from fields:\n";
  std::cout << msg;
  std::cout << "\n";

  EXPECT_EQ(numberOfFields(msg), 2);
}


TEST(populateSectionOfFieldsTest, AllFields)
{
  std::string msg;
  populateSectionOfFields(msg, {8,9,35,34,49,56,11,38,55,54}, define_FieldSetters());

  std::cout << "Printout of string built from fields:\n";
  std::cout << msg;
  std::cout << "\n";

  EXPECT_EQ(numberOfFields(msg), 10);
}

TEST(GenerateRandomFIXMessage, 11FieldsPopulated)
{
   auto numCreatedFields = numberOfFields(CreateFIX::GenerateMessage());
   EXPECT_EQ(numCreatedFields, 11);
}

//Test fixture example:
// class PopulatedFieldsTest : public testing::Test
// {
//   protected:
//     PopulatedFieldsTest();
//     ~PopulatedFieldsTest();
//
//     CreateFIX::Message ms;
//     std::string build;
// };
//
// PopulatedFieldsTest::PopulatedFieldsTest()
// {
//   std::cout << "Test fixture constructed\n";
// }
// PopulatedFieldsTest::~PopulatedFieldsTest()
// {
//   std::cout << "Test fixture destructed\n";
// }
//
// TEST_F(PopulatedFieldsTest, MessageReturnedTest)
// {
//   auto numCreatedFields = numberOfFields(ms.GenerateMessage());
//   EXPECT_EQ(numCreatedFields, 11);
// }

