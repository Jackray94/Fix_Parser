#include "messageFields.h"
#include "fixMessage.pb.h"
#include <algorithm>
#include <array>
#include <functional>
#include <string>
#include <iostream>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string_view>

struct Fields
{
  std::string beginString;
  unsigned int bodyLength;
  std::string messageType;
  unsigned int messageSequenceNum;
  std::string senderComdId;
  std::string targetCompId;
  std::string clientOrderId;
  unsigned int orderQuantity;
  std::string symbol;
  std::string side;
  unsigned int checksum;
};


fixIO::content message;

void start()
{

  //fixIO::content message;
  
  std::string s1 = "FIX.4.1";
  message.set_beginstringfixversion(s1);

  unsigned int int1 = 444;
  message.set_bodylength(int1);

  std::string s2 = "C";
  message.set_messagetype(s2);

  unsigned int int2 = 555;
  message.set_messagesequencenum(int2);

  std::string s3 = "A";
  message.set_sendercompid(s3);

  std::string s4 = "abc";
  message.set_targetcompid(s4);

  std::string s5 = "F";
  message.set_clientorderid(s5);

  unsigned int int3 = 4321;
  message.set_orderquantity(int3);

  std::string s6 = "jack";
  message.set_symbol(s6);

  std::string s7 = "R";
  message.set_side(s7);

 unsigned int int4 = 606;
 message.set_checksum(int4);

  std::cout << "check if initialized = " << message.IsInitialized() << '\n';
}

void CS(unsigned int i){message.set_checksum(i); std::cout << "called CS\n";}
void bs(std::string s){message.set_beginstringfixversion(s); std::cout << "called bs\n";}

struct Operators
{
  Operators(std::string sArg) : sArg_(sArg){}
  Operators(unsigned int iArg) : iArg_(iArg){}
  void operator()(std::function<void(unsigned int)> fptr1){fptr1(iArg_);}
  void operator()(std::function<void(std::string)> fptr2){fptr2(sArg_);}
  std::string sArg_;
  unsigned int iArg_{};
};

void loadMessage()
{
  using setterStringArg = std::function<void(std::string)>;
  using setterIntArgs = std::function<void(unsigned int)>;
  using varType = std::variant<setterStringArg, setterIntArgs>;
  varType var;

  std::vector<varType> functionCollection;

  functionCollection.emplace_back(CS);
  functionCollection.emplace_back(bs);

  unsigned int fourtyfour = 44;
  for(auto const & visitingFunction : functionCollection){
    std::visit(Operators{"asfasdf"}, visitingFunction);
  }


  using tag = unsigned int;
  std::unordered_map<tag, varType> collectionOfFunctions;

}
//8=FIX.4.1^A9=12^A35=D^A34=1^A49=WNCAGXFK^A56=Myself^A11=2025-05-17-1747512105733859354^A38=^^^A55=MCHRBAFU^A54=1^A
void ParseStringFillIntsandStrings(std::string_view str, unsigned long const size)
{

  //parse a tag-value field
  //check enum lookup if its a string or an int
  char arr[size];
  std::vector<char> buffer(size);
  char const fieldDelimeter = 0x01;
  char const tagDelimeter = '=';
  std::string_view::size_type posToSearchFrom = 0;
  auto nextTagPos = str.find(tagDelimeter, posToSearchFrom);
  auto nextFieldPos = str.find(fieldDelimeter, posToSearchFrom);



  auto strCurPos = str.data();
  auto bufferCurPos = buffer.data();
  auto bufferNextPos = bufferCurPos;
  bufferNextPos = std::copy(strCurPos, strCurPos + nextTagPos, bufferCurPos);
  bufferCurPos = bufferNextPos;

  
  

  std::cout << buffer.data() << "\n";
  
}


