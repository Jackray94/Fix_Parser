#include "ForwardsMessage.h"
#include "Reader.h"
#include "createFIXMessage.h"

void Forwarder::Driver()
{
  auto fixMsg = CreateFIX::GenerateMessage();

  auto vTagLists = TagList(fixMsg);

  
}
