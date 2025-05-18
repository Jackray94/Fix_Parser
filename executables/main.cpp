#include <Fix_Parser/LibraryX/rough_start.h>
#include <Fix_Parser/LibraryX/messageFields.h>
#include <string_view>

int main()
{
  std::string_view s("8=fix.4.1\00119=12\00135=d\00134=1\00149=wncagxfk\00156=myself\00111=2025-05-17-1747512105733859354\00138=broken\00155=mchrbafu\00154=1\001");
  ParseStringFillIntsandStrings(s, s.size());
}
