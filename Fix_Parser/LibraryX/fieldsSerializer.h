#pragma once
#include <string_view>

namespace SerializeProto{

  void ProtoVerify();
  
  void ser_beginString(std::string_view);
};
