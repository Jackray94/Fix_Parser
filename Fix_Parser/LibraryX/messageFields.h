#pragma once

#include <functional>
#include <string>

struct fields;
void start();
void CS(unsigned int i);
void bs(std::string s);
void loadMessage();
void ParseStringFillIntsandStrings(std::string_view str, unsigned long size);

void bar(std::string_view sv){
}



void parser()
{
}

class Holder
{
  public:
    //Holder() : table{{1, bar}} {}
    void foo(int i, std::string_view s){
      table[i](s);
    }
  std::unordered_map<int, std::function<void(std::string_view)>> table{{1, bar}};
};
