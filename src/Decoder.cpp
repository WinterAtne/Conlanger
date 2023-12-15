#include "Decoder.hpp"

std::map<std::string, func> Decoder::stringToFunction;

void Decoder::AddFunction(std::string str, func fun) {
    stringToFunction[str] = fun;
}
func Decoder::GetFunction(std::string str) {
    return stringToFunction[str];
}
bool Decoder::ValidateKey(std::string str) {
    if (stringToFunction.find(str) != stringToFunction.end()) return true;
    else return false;
}