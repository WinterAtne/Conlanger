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
    std::vector<std::string> broke = SplitCommand(input);
    

    return 200;
}
