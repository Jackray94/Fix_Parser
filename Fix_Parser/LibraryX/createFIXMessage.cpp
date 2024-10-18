
#include <stdexcept>
#include <chrono>
//#include <bits/chrono>
#include <algorithm>
#include <sstream>


#include "createFIXMessage.h"

//using CreateFIX::Message;

namespace{//impl helpers

  void protocol_BeginString(std::string& generatedMessage) {
    generatedMessage += "FIX.4.1";
  }

  void protocol_BodyLength(std::string& generatedMessage)//Tested
  {
    if(generatedMessage.size() == 0){
      throw std::logic_error("Attemped to calculate {Tag=2, Value=Length of message body} on a empty message");
    }
    generatedMessage += std::to_string(generatedMessage.size());
  }

  void protocol_MessageType(std::string& generatedMessage)
  {
    //todo: Will eventually be randomized for the set of message types I want to run.
    generatedMessage += "D";//<For now is fixed
  }

  void protocol_MsgSeqNum(std::string& generatedMessage)
  {
    generatedMessage += "1";//<For now is fixed
  }

  void protocol_SenderCompID(std::string& generatedMessage)
  {
    Random::Generator re;
    //Give this a random name which can be no more than 6 letters long becuase its a random rule i'm placing until I have a better idea of the requirements.
    auto temp = re.generateWord();
    generatedMessage += temp;
  }

  void protocol_TargetCompID(std::string& generatedMessage)
  {
    generatedMessage += "Myself";
  }

  void protocol_ClientOrderID(std::string& generatedMessage)//Tested
  {
    //Make order ID unique by inlcluding the year-month-day, plus the current time.
    std::chrono::time_point const nowTime{std::chrono::system_clock::now()};
    std::chrono::year_month_day const ymd{std::chrono::floor<std::chrono::days>(nowTime)};

    std::stringstream ss;

    auto time = nowTime.time_since_epoch().count();


    ss << ymd << '-' << time;
    generatedMessage += ss.str();
  }


  void protocol_OrderQty(std::string& generatedMessage)//Tested
  {
    Random::Generator re;
    generatedMessage += re.generateUint();
  }

  void protocol_Symbol(std::string& buildMesasge)//Tested
  {
    Random::Generator re;
    buildMesasge += re.generateWord();
  }

  void protocol_Side(std::string& generatedMessage)//Tested
  {
    Random::Generator re;
    generatedMessage += (re.generateUint() % 2 == 0) ? "1" : "2" ;//<Fix spec shows 1="Buy" and 2="Sell"
  }

  void protocol_Checksum(std::string& generatedMessage)//Tested
  {
    auto numBytes = generatedMessage.size();
    generatedMessage += std::to_string(numBytes % 256);
  }


  std::vector<std::pair<int, void(*)(std::string&)>> define_FieldSetters()
  {
    //RVO
    return std::vector<std::pair<int, void(*)(std::string&)>>{
      {8, &protocol_BeginString},
      {9, &protocol_BodyLength},
      {35, &protocol_MessageType},
      {34, &protocol_MsgSeqNum},
      {49, &protocol_SenderCompID},
      {56, &protocol_TargetCompID},
      {11, &protocol_ClientOrderID},
      {38, &protocol_OrderQty},
      {55, &protocol_Symbol},
      {54, &protocol_Side},
      {10, &protocol_Checksum}
    };
  }



  void populateSectionOfFields(std::string& buildmessage, std::vector<int> const& vSubsetOfFieldsByTag, std::vector<std::pair<int, void(*)(std::string&)>> const& vpallfieldstobuild)
  {
    for(auto const& target : vSubsetOfFieldsByTag){
      auto fieldBuilder = std::find_if(vpallfieldstobuild.begin(), vpallfieldstobuild.end(),
                                [&](std::pair<int, void(*)(std::string&)> pfield){ return target == pfield.first; });

      if(fieldBuilder != vpallfieldstobuild.end()){
        buildmessage += std::to_string(target);
        buildmessage += "=";

        fieldBuilder->second(buildmessage);

        buildmessage += '\x01';
      }

    }
  }


  void populateFields(std::string& buildMesage)
  {
    auto vpAllFields = define_FieldSetters();

    std::string firstField;
    populateSectionOfFields(firstField, {8}, vpAllFields);
    buildMesage += firstField;

    std::string bodyLength;
    populateSectionOfFields(bodyLength, {9}, vpAllFields);
    buildMesage += bodyLength;

    std::string bodyFields;
    populateSectionOfFields(buildMesage, {35, 34, 49, 56, 11, 38, 55, 54}, vpAllFields);
    buildMesage += bodyFields;

    std::string checkSum;
    populateSectionOfFields(buildMesage, {10}, vpAllFields);
    buildMesage += bodyFields;

  }

  int numberOfFields(std::string_view message)
  {
    return std::count(message.begin(), message.end(), 0x01);
  }


};

// std::string_view Message::GenerateMessage()
// {
//   populateFields(generatedMessage);
//   return generatedMessage;
// }

 std::string CreateFIX::GenerateMessage()
 {
   std::string generatedMessage;
   populateFields(generatedMessage);
   return generatedMessage;
 }
