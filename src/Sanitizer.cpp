#include "Sanitizer.hpp"
#include "Decoder.hpp"
#include <cctype>

std::vector<std::string> Sanitizer::Sanitize(const std::vector<std::string> rawInput) {
    std::vector<std::string> cleanInput = rawInput;
    
    // Ensure the first entry is a valid command
    cleanInput[0][0] = toupper(rawInput[0][0]); // Capitalizes first letter if it is not already
    bool validTopLevelCommand = false;
    for (auto valid : Decoder::GetFunctionKeys()) {
        if (valid == cleanInput[0]) {
            validTopLevelCommand = true;
            break;
        }
    }
    if (!validTopLevelCommand) {
        cleanInput.clear();
        cleanInput.push_back("Error");
        cleanInput.push_back(rawInput[0]);
        return cleanInput;
    }



    return cleanInput;
}
