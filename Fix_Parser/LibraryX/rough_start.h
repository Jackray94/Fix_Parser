#ifndef ROUGH_START_H
#define ROUGH_START_H

#include "spdlog/common.h"
#include <external/spdlog/include/spdlog/common.h>
//#include "gmock/gmock.h"
//#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <charconv>
#include <exception>
#include <format>
#include <functional>
#include <iostream>
#include <fstream>
#include <chrono>
#include <bits/chrono.h>
#include <iterator>
#include <memory>
#include <spdlog/spdlog.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

class FileReader;
class MessageFields;
class FixReader;
class FixManager;
class Parser;
// template<typename T>
// void intermediateFoo(T);
//
// void protocol_BeginString(std::string& buildMessage);
// void protocol_BodyLength(std::string& buildMessage);
// void protocol_MessageType(std::string& buildMessage);
// void protocol_MsgSeqNum(std::string& buildMessage);
// void protocol_SenderCompID(std::string& buildMessage);
// void protocol_TargetCompID(std::string& buildMessage);
// void protocol_ClientOrderID(std::string& buildMessage);
// void protocol_OrderQty(std::string& buildMessage);
// void protocol_Symbol(std::string& buildMesasge);
// void protocol_Side(std::string& buildMessage);
// void populateFields(std::string& buildMesage);
// int numberOfFields(std::string_view message);
// std::vector<std::pair<int, void(*)(std::string&)>> define_FieldSetters();
// void populateSectionOfFields(std::string& buildmessage, std::vector<int> const& vSubsetOfFieldsByTag, std::vector<std::pair<int, void(*)(std::string&)>> const& vpallfieldstobuild);
// void protocol_Checksum(std::string& buildMessage);

#endif // ROUGH_START_H
