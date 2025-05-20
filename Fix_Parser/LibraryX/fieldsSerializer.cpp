#include "fieldsSerializer.h"
#include <string_view>
#include <fixMessage.pb.h>

void SerializeProto::ProtoVerify()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
}

void ser_beginString(std::string_view)
{

}
