#pragma once
#include <random>
#include <string>

namespace Random{

  class Seeder
  {
    public:
      Seeder();
      long seed() const;

    private:

      long const _seed;
  };


  class Generator
  {
    public:
      unsigned int generateUint();
      std::string generateWord();

    private:
      static const Seeder rando;
      static std::mt19937 prn_engine;
      std::uniform_int_distribution<unsigned int> distribtuionUInts{1, 10'000/*arbitrary*/};
      std::uniform_int_distribution<unsigned int> distribtuionChars{0, 255};
  };
  
};
