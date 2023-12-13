#include <iostream>
#include <string>
#include <sqlite3.h>

#include "Parser.hpp"

int main() {
    bool program_should_close = false;

    sqlite3* DataBase; 
    int exit = 0; 
    exit = sqlite3_open("languages.db", &DataBase);

    
    while(!program_should_close) {
        //If we error out sql, we should probably just close the program and return an error
        if (exit != SQLITE_OK) {
            program_should_close = true;
            std::cout << "An Error has occured in SQLite; it is possible your database has been corrupted, or your command was invalid and the Conlanger Parser simply failled to realize. The program will now close automatically" << std::endl;
            sqlite3_close(DataBase); 
            return exit;
        }
        std::string input;
        std::getline(std::cin, input);

        Parser::Parse(input, DataBase);

    }


    sqlite3_close(DataBase); 
    return 0;
}
