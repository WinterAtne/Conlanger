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
    node->word = wrd;
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