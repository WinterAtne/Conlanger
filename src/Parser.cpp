#include "Parser.hpp"


std::vector<std::string> Parser::SplitCommand(const std::string input) {
    std::vector<std::string> rtrn;
    std::string buffer;

    bool ignoreSpaces = false;
    bool controlCharacter = false;

    for (auto c : input) {
        // if we aren't ignoring spaces check for them, then check if we should ignore spaces
        if (!ignoreSpaces) {
            if (' ' == c) {
                rtrn.push_back(buffer);
                buffer.clear();
                continue;
            } else if ('\"' == c) {
                ignoreSpaces = true;
                continue;
            }
        }

        if ('\"' == c) {
            ignoreSpaces = false;
            continue;
        }

        // if none of the control characters are found, add this to the buffer.
        buffer = buffer + c;
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
