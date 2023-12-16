#include <iostream>
#include <string>

#include "Parser.hpp"

int main() {
    bool programShouldClose = false;
    Parser::Init();
    
    
    while(!programShouldClose) {
        std::string input;
        std::getline(std::cin, input);

        int exit = Parser::Parse(input);

        if (-1 == exit) {
            programShouldClose = true;
            std::cout << "All Changes Saved, Closing Program" << std::endl;
            break;
        }
    }
    return 0;
}
