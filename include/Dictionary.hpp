 #include <map>
 #include <string>
 #include <vector>

 #include "Lexeme.hpp"

class Dictionary {
private:
    Lexeme* root;
    std::vector<std::string[2]> properties;


public:
    Dictionary();
    void Insert(std::string word);
    Lexeme* Search(std::string word);
    int DefineLexeme(Lexeme* lex, std::string property, std::string value, bool overWrite);
    std::string SearchProperties(std::string property);
};