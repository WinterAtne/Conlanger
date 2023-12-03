 #include <map>
 #include <string>
 #include <vector>

 #include "Lexeme.hpp"

class Dictionary {
private:
    uint wordCount = 0;
    std::vector<std::string[2]> properties;


public:
    Lexeme* root;
    
    Dictionary();
    void Insert(std::string word);
    Lexeme* Search(std::string word);
    int DefineLexeme(Lexeme* lex, std::string property, std::string value, bool overWrite);
    std::string SearchProperties(std::string property);
    std::vector<Lexeme*> ReadDictionary(Lexeme* node);
};
