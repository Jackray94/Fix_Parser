#include "apple.h"
#include <fstream>
#include "address.pb.h"
#include <memory>

 void printThing()
 {
   tutorial::AddressBook ab;

   auto pers = ab.add_people();
   pers->set_id(32);
   pers->set_name(std::string("jack"));
   pers->set_email(std::string("123@gmail.com"));

   auto tf = ab.IsInitialized();

   std::cout << tf << "\n";
   std::cout << ab.DebugString() << "\n";

   std::cout << "asdfasdf\n";
 }

struct PersonFields
{
  int id = 0;
  std::string name;
  std::string email;
};

std::unique_ptr<PersonFields> PopulateFields()
{
  return std::make_unique<PersonFields>(PersonFields{.id = 32, .name{"myname"}, .email{"myemail@gmail.com"}});

}

//std::unique_ptr<tutorial::Person*> Message(PersonFields const& fields)
void Message(tutorial::Person* persSer, PersonFields const& fields)
{
  tutorial::AddressBook ab;
  auto persToSerialize =  PopulateFields();
  
  persSer->set_id(fields.id);
  persSer->set_name(fields.name);
  persSer->set_email(fields.email);

}

std::unique_ptr<tutorial::AddressBook> ControlProtoPerson()
{
  auto uptr_addressbook = std::make_unique<tutorial::AddressBook>();
  auto uptr_personToSerialze = std::make_unique<tutorial::Person *>(uptr_addressbook->add_people());
  auto uptr_person = PopulateFields();
  Message(*uptr_personToSerialze, *uptr_person);
  return uptr_addressbook;//intended to use with std::move or prvalue semantics

}


std::unique_ptr<std::fstream> openFile(std::string_view sv_fileLocation)
{
  return std::make_unique<std::fstream>(std::fstream{sv_fileLocation.data(), std::ios::out | std::ios::trunc | std::ios::binary});
}

void WriteAndReadThing(std::string_view sv_fileLocation)
{
  auto uptr_outFile = openFile(sv_fileLocation);
  auto uptr_controlProtoPerson{ControlProtoPerson()};
  uptr_controlProtoPerson->SerializePartialToOstream(uptr_outFile.get());


  std::fstream inFile("BinaryAddressBook.txt", std::ios::in | std::ios::binary);
  tutorial::AddressBook emptyAddressBook;
  emptyAddressBook.ParseFromIstream(&inFile);
  
  std::cout << emptyAddressBook.DebugString() << "\n";
  

}

