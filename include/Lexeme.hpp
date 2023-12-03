 #include <map>
 #include <string>
 #include <vector>

class Lexeme {
public:
    std::string word;
    uint id = 0;
    std::vector<std::string*> properties;
    std::map<char, Lexeme*> child;


    void RealizeWord(std::string rootLexeme, uint ID);
    int DefineProperty(std::string property, std::string value, bool overWrite);
};