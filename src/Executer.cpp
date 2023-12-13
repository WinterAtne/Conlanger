#include "Executer.hpp"

#include <iostream>

int Executer::Create(std::string name, std::vector<std::string> parents) {
    std::cout << "create " << name << std::endl;
    return 200;
}
int Executer::Add(std::string language, std::string property, std::string addition) {
    std::cout << "add to " << language << " a " << property << "  " <<  addition << std::endl;
    return 200;
}
int Executer::Remove(std::string language, std::string property, std::string ID) {
    std::cout << "remove from " << language << " a " << property << " " << ID << std::endl;
    return 200;
}
int Executer::Fetch(std::string language, std::string property, std::string mods) {
    std::cout << "get from " << language << " a " << property << std::endl;
    return 200;
}