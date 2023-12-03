#include "Dictionary.hpp"

using std::string;
using std::vector;



Dictionary::Dictionary() {
    root = new Lexeme();
}

void Dictionary::Insert(string wrd) {
    Lexeme *node = root;
    for (auto letter : wrd) {
        if (node->child.find(letter) == node->child.end()) {
            node->child.insert({letter, new Lexeme()});
        } 
        node = node->child[letter];
    }
    node->RealizeWord(wrd, 0);

}

Lexeme* Dictionary::Search(string wrd) {
    Lexeme *node = root;
    for (auto letter : wrd) {
        if (node->child.find(letter) == node->child.end()) return nullptr;
        node = node->child[letter];
    }
    if (node->word != "") return node;
    else return nullptr;
}

std::string Dictionary::SearchProperties(std::string property) {
    for (auto prop : properties) {
        if (prop[0] == property) {
            return prop[1];
        }
    }

    return "";
}

int Dictionary::DefineLexeme(Lexeme* lex, std::string property, std::string value, bool overWrite) {
    if (SearchProperties(property) == "") return 1;

    lex->DefineProperty(property, value, overWrite);
    return 0;
}