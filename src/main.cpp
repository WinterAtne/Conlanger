#include <iostream>
#include <string>


#include "Dictionary.hpp"

// int main() {
//     std::cout << "Hello World" << std::endl;
//     return 0;
// }


int main() {
    Dictionary dict = Dictionary();
    dict.Insert("bungus");
    dict.Insert("bun");
    dict.Insert("a");
    dict.Insert("an");
    dict.Insert("and");
    dict.Insert("anderson");



    std::vector<Lexeme*> lss = dict.ReadDictionary(dict.root);

    for (auto lex : lss) {
        std::cout << lex->word << std::endl;
    }

    return 0;
}
