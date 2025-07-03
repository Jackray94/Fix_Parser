#pragma once
#include "fixMessage.pb.h"
#include <vector>
#include <string_view>


namespace SerializeProto{

  class MessageCreator
  {
    public: 
      void SetMessageFields(std::vector<int> const& vTagList);

      void BeginString(std::string_view field);

      void BodyLength(std::string_view field);

      void MessageType(std::string_view field);

      void MessageSequenceNumber(std::string_view field); 

      void SenderCompID(std::string_view field);

      void TargetCompID(std::string_view field);

      void ClientOrderID(std::string_view field);

      void OrderQuantity(std::string_view field);

      void Symbol(std::string_view field);

      void Side(std::string_view field);

      void CheckSum(std::string_view field);
    private:
      fixIO::content ser;
  };

  //void ProtoVerify();//<move to main() - see function comments
  
};
