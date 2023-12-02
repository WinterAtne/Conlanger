 #include <map>
 #include <string>
 #include <vector>

class Lexeme {
public:
    std::string word;
    std::map<char, Lexeme*> child;
};

class Dictionary {
private:
    Lexeme* root;
public:
    Dictionary();
    void Insert(std::string word);
    Lexeme* Search(std::string word);
};