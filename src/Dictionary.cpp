#include "Dictionary.hpp"

using std::string;
using std::vector;

#include <iostream>

Dictionary::Dictionary() {
    root = new Lexeme(nullptr);
}

void Dictionary::Insert(string wrd) {
    Lexeme *node = root;
    for (auto letter : wrd) {
        if (node->child.find(letter) == node->child.end()) {
            node->child.insert({letter, new Lexeme(node)});
        } 
        node = node->child[letter];
    }
    node->RealizeWord(wrd, wordCount);

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

std::vector<Lexeme*> Dictionary::ReadDictionary(Lexeme* node) {
    std::vector<Lexeme*> outList;
    for (const auto& [key, lex] : node->child) {
        if (lex->word != "") outList.push_back(lex);;
        std::vector<Lexeme*> childOutList = ReadDictionary(lex);
        std::move(childOutList.begin(), childOutList.end(), std::back_inserter(outList));
    }

    return outList;
}
