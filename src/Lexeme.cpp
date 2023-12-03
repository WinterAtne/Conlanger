#include "Lexeme.hpp"



void Lexeme::RealizeWord(std::string rootLexeme, uint ID) {
    word = rootLexeme;
    id = ID;
}


int Lexeme::DefineProperty(std::string property, std::string value, bool overWrite) {
    std::string prop[2] = { property, value };
    properties.push_back(prop);

    return 0;
}