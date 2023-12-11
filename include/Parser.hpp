#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>

class Parser {
private:
    static std::vector<std::string> SplitCommand(const std::string input);
public:
    static int Parse(const std::string input, const sqlite3* DataBase);
};
