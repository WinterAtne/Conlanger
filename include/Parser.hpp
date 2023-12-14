#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>
#include "Executer.hpp"

class Parser {
public:
    static int Parse(const std::string input);
};
