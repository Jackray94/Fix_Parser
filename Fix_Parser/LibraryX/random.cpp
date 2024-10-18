#include "random.h"
#include <cctype>
#include <chrono>
#include <cstdlib>
#include <random>

using Random::Seeder;
using Random::Generator;

namespace{

  bool CheckHardwareOption()
  {
    std::random_device rd;
    return rd.entropy();
  }
  unsigned int HardwareOption()
  {
    std::random_device rd;
    return rd();
  }

  unsigned int SoftwareOption()
  {
    auto x = std::chrono::steady_clock::now().time_since_epoch().count();
    return x;
  }

  unsigned int CheckOptions()
  {
    if(CheckHardwareOption()){ return HardwareOption(); }
    else{ return SoftwareOption(); }
  }

  unsigned int SeedingOption()
  {
    return CheckOptions();
  }

};


Seeder::Seeder() : _seed(SeedingOption())
{}

long Seeder::seed() const
{
  return _seed;
}




namespace{
  bool IsValidLetter(char maybeLetter) { return std::isalpha(maybeLetter); }
}

Seeder const Generator::rando{};
std::mt19937 Generator::prn_engine{ static_cast<std::mt19937::result_type>(rando.seed()) };

unsigned int Generator::generateUint()
{
  return distribtuionUInts(prn_engine);
}


std::string Generator::generateWord()
{
  std::string resultWord;
  char randomChar = '\0';

  unsigned int const MaxWordSize = 8;
  for(int i = 0; i < MaxWordSize; ){

    randomChar = distribtuionChars(prn_engine);

    if(IsValidLetter(randomChar)){

      resultWord += std::toupper(randomChar);
      ++i;

    }

  }

  return resultWord;

}

