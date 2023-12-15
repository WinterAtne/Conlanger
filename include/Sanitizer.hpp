#include <string>
#include <vector>
#include <tuple>


class Sanitizer {
public:
    static std::vector<std::string> Sanitize(const std::vector<std::string> uncleanInput); //Detects invalidating factors and attempts to correct them using a limited number of preset rules
}; 