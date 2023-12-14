#include "Spliter.hpp"


std::vector<std::string> Spliter::Split(const std::string input) {
    std::vector<std::string> rtrn;
    std::string buffer;

    bool ignoreSpaces = false;
    bool controlCharacter = false;

    for (auto c : input) {
        // if we aren't ignoring spaces check for them, then check if we should ignore spaces
        if (!ignoreSpaces) {
            if (' ' == c) {
                rtrn.push_back(buffer);
                buffer.clear();
                continue;
            } else if ('\"' == c) {
                ignoreSpaces = true;
                continue;
            }
        }

        if ('\"' == c) {
            ignoreSpaces = false;
            continue;
        }

        // if none of the control characters are found, add this to the buffer.
        buffer = buffer + c;
    }

    rtrn.push_back(buffer);

    return rtrn;
}