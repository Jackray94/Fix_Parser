#include <charconv>
#include <optional>

#include "Reader.h"



namespace{
  using VpTagFields = std::vector<std::pair<int, std::string_view>>;
  static VpTagFields ParseTags(std::string_view fixMsg);

  struct SearchPositions{
    std::string_view::size_type startPos;
    std::string_view::size_type tagEnd;
    std::string_view::size_type fieldEnd;
  };


  using PairSVs = std::pair<std::string_view, std::string_view>;
  static std::optional<PairSVs> SplitMessage(std::string_view fixMessage, SearchPositions positions);

  static int ConvertField(std::string_view svTag);
};




Forwarder::VpTagFields Forwarder::TagList(std::string_view fixMessage)
{
  return ParseTags(fixMessage);
}




namespace{
  static Forwarder::VpTagFields ParseTags(std::string_view fixMsg){
    VpTagFields tagsAndFields;

    SearchPositions positions{.startPos = 0, .tagEnd = fixMsg.find('='), .fieldEnd = fixMsg.find('\001')};

    while(auto maybeTagAndField = SplitMessage(fixMsg, positions)){
      auto [tag, field] = *maybeTagAndField;

      int val = ConvertField(tag);

      tagsAndFields.push_back({val, field}); 

      positions.startPos = positions.fieldEnd + 1;
    }

    return tagsAndFields;
  }


  static std::optional<PairSVs> SplitMessage(std::string_view fixMessage, SearchPositions positions)
  {
    auto [startPos, tagEnd, fieldEnd] = positions;

    if(tagEnd == std::string_view::npos || fieldEnd == std::string_view::npos){
      return std::nullopt;
    }
    
    return PairSVs{std::string_view(fixMessage.data() + startPos, tagEnd - startPos), std::string_view(fixMessage.data() + startPos, tagEnd - startPos)};
  }


  int ConvertField(std::string_view svTag)
  {
      int val = 0;
      auto result = std::from_chars(svTag.data(), svTag.end()-1, val);
      if(result.ec != std::errc()){
        //todo - error handle / throw
      }
      return val;
  }
};

