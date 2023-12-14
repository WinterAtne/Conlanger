#include "Parser.hpp"
#include "Spliter.hpp"
#include "Decoder.hpp"


int Parser::Parse(const std::string input) {
    std::vector<std::string> splitInput = Spliter::Split(input);
    //There is probably a cleanerway to initialize the rest of these but for now it is tech debt;
    if (splitInput[0] == "Init") {
        Decoder::AddFunction("Init", Executer::Init);
    }
    Decoder::GetFunction(splitInput[0])(splitInput);

    return 200;
}
