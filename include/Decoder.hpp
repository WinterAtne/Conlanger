#pragma once
#include <vector>
#include <string>
#include <map>
#include <functional>

using func=std::function<int(std::vector<std::string>)>;

class Decoder {
private:
    static std::map<std::string, func> stringToFunction;
public:
    static void AddFunction(std::string str, func fun);
    static func GetFunction(std::string str);
};