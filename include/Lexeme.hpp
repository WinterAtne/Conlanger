 #include <map>
 #include <string>
 #include <vector>

class Lexeme {
public:
    std::string word;
    uint id = 0;
    std::vector<std::string*> properties;
    
    //tree stuff
    std::map<char, Lexeme*> child;
    Lexeme* parent;

    Lexeme(Lexeme* parent);

    void RealizeWord(std::string rootLexeme, uint ID);
    int DefineProperty(std::string property, std::string value, bool overWrite);
};