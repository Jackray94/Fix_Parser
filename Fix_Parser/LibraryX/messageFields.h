#pragma once

#include <string>

struct fields;
void start();
void CS(unsigned int i);
void bs(std::string s);
void loadMessage();
void ParseStringFillIntsandStrings(std::string_view str, unsigned long size);
