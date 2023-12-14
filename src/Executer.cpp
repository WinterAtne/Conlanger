#include "Executer.hpp"
#include <Decoder.hpp>

#include <iostream>

sqlite3 *Executer::Database;
int Executer::sqlExitCode = 0;

int Executer::Init(std::vector<std::string> args) {
    Decoder::AddFunction("Create", Create);
    Decoder::AddFunction("Add", Add);
    Decoder::AddFunction("Remove", Remove);
    Decoder::AddFunction("Fetch", Fetch);
    return sqlite3_open(args[1].c_str(), &Database);
}
int Executer::Close(std::vector<std::string> args) {
    sqlite3_close(Database);
    return 200;
}
int Executer::Create(std::vector<std::string> args) {
    std::cout << args[1] << std::endl;
    return 200;
}
int Executer::Add(std::vector<std::string> args) {
    std::cout << args[1] << std::endl;
    return 200;
}
int Executer::Remove(std::vector<std::string> args) {
    std::cout << args[1] << std::endl;
    return 200;
}
int Executer::Fetch(std::vector<std::string> args) {
    std::cout << args[1] << std::endl;
    return 200;
}