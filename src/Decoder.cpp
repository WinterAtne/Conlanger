#include "Decoder.hpp"

std::map<std::string, func> Decoder::stringToFunction;
std::vector<std::string> Decoder::validFunctions;

void Decoder::AddFunction(std::string str, func fun) {
    stringToFunction[str] = fun;
    validFunctions.push_back(str);
}
func Decoder::GetFunction(std::string str) {
    return stringToFunction[str];
}
std::vector<std::string> Decoder::GetFunctionKeys() {
    return validFunctions;
}