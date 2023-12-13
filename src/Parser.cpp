#include "Parser.hpp"


std::vector<std::string> Parser::SplitCommand(const std::string input) {
    std::vector<std::string> rtrn;
    std::string buffer;

    for (auto c : input) {
        if (' ' == c) {
            rtrn.push_back(buffer);
            buffer.clear();
            continue;
        } else {
            buffer = buffer + c;
            continue;
        }
    }

    rtrn.push_back(buffer);

    return rtrn;
}


int Parser::Parse(const std::string input, const sqlite3* DataBase) {
    std::vector<std::string> splitInput = SplitCommand(input);

    if ("Create" == splitInput[0]) {
        std::vector<std::string> parents(splitInput.begin() + 2, splitInput.end());
        Executer::Create(splitInput[1], parents);
    } else if ("Add" == splitInput[0]) {
        Executer::Add(splitInput[1], splitInput[2], splitInput[3]);
    } else if ("Remove" == splitInput[0]) {
        Executer::Remove(splitInput[1], splitInput[2], splitInput[3]);
    } else if ("Fetch" == splitInput[0]) {
        Executer::Fetch(splitInput[1], splitInput[2], splitInput[3]);
    } else {
        return 400;
    }

    return 200;
}
