#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>

class Executer {
private:
    static sqlite3* Database;
    static int sqlExitCode;
    static char* messageError;
    
public:
    static int Init(); //Special initialization function that gets called once

    static int Error(std::vector<std::string> args); // Special error function that gets called for bad commands.

    static int Close(std::vector<std::string> args); 
    static int Create(std::vector<std::string> args); // Creates a new language of name, with parents;
    static int Add(std::vector<std::string> args); // Adds something to language 's property
    static int Remove(std::vector<std::string> args); // Removes something from a language 's property
    static int Fetch(std::vector<std::string> args); // Fetches something from language 's property 
};
