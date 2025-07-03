#include <vector>
#include <string_view>

#pragma once

namespace Forwarder{
  using VpTagFields = std::vector<std::pair<int, std::string_view>>;
   VpTagFields TagList(std::string_view fixMessage);
};
