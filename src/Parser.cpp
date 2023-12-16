#include "Parser.hpp"
#include "Spliter.hpp"
#include "Decoder.hpp"
#include "Executer.hpp"
#include "Sanitizer.hpp"


int Parser::Parse(const std::string input) {
    std::vector<std::string> splitInput = Spliter::Split(input);
    std::vector<std::string> sanitizdInput = Sanitizer::Sanitize(splitInput);
    int exit = Decoder::GetFunction(sanitizdInput[0])(sanitizdInput);

    return exit;
}

void Parser::Init() {
    Executer::Init();
}
