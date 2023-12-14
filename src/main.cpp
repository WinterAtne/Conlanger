#include <iostream>
#include <string>

#include "Parser.hpp"

int main() {
    bool program_should_close = false;
    
    
    while(!program_should_close) {
        std::string input;
        std::getline(std::cin, input);

        Parser::Parse(input);

    }
    return 0;
}
