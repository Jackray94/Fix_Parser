#include "fieldsSerializer.h"
#include <fixMessage.pb.h>
#include <string>


using SerializeProto::MessageCreator;

void SetMessageFields()
{
}


//todo: make names better in fixMessage.proto and rebuild it

void MessageCreator::BeginString(std::string_view field)
{
  ser.set_beginstringfixversion(field.data());
}

void MessageCreator::BodyLength(std::string_view field)
{
  std::string copy{field};
  ser.set_bodylength(std::stoi(copy));
}


void MessageCreator::MessageType(std::string_view field)
{
  ser.set_messagetype(field);
}


void MessageCreator::MessageSequenceNumber(std::string_view field)
{
  std::string copy{field};
  ser.set_messagesequencenum(std::stoi(copy));
}

void MessageCreator::SenderCompID(std::string_view field)
{
  ser.set_sendercompid(field);
}

void MessageCreator::TargetCompID(std::string_view field)
{
  ser.set_targetcompid(field);
}

void MessageCreator::ClientOrderID(std::string_view field)
{
  ser.set_clientorderid(field);
}

void MessageCreator::OrderQuantity(std::string_view field)
{
  std::string copy{field};
  ser.set_orderquantity(std::stoi(copy));
}

void MessageCreator::Symbol(std::string_view field)
{
  ser.set_symbol(field);
}

void MessageCreator::Side(std::string_view field)
{
  ser.set_side(field);
}

void MessageCreator::CheckSum(std::string_view field)
{
  std::string copy{field};
 ser.set_checksum(std::stoi(copy));
}
