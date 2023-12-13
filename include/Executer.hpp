#pragma once

#include <string>
#include <vector>

class Executer {
friend class Parser;
private:
    static int Create(std::string name, std::vector<std::string> parents); // Creates a new language of name, with parents;
    static int Add(std::string language, std::string property, std::string addition); // Adds something to language 's property
    static int Remove(std::string language, std::string property, std::string ID); // Removes something from a language 's property

    // Fetch will be the most complicated to impliment and will come last, despite possibly being the most important
    static int Fetch(std::string language, std::string property, std::string mods); // Fetches something from language 's property 
};
