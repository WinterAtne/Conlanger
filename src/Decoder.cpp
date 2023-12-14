#include "Decoder.hpp"

std::map<std::string, func> Decoder::stringToFunction;

void Decoder::AddFunction(std::string str, func fun) {
    stringToFunction[str] = fun;
}
func Decoder::GetFunction(std::string str) {
    return stringToFunction[str];
}