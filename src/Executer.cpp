#include "Executer.hpp"
#include <Decoder.hpp>

#include <iostream>

sqlite3 *Executer::Database;
int Executer::sqlExitCode = 0;
char* Executer::messageError;

#define STANDARD_RETURN() { \
    if (sqlExitCode != SQLITE_OK) { \
        std::cerr << messageError << std::endl; \
    } \
    return sqlExitCode; \
}

int Executer::Init() {
    Decoder::AddFunction("Create", Create);
    Decoder::AddFunction("Add", Add);
    Decoder::AddFunction("Remove", Remove);
    Decoder::AddFunction("Fetch", Fetch);
    Decoder::AddFunction("Error", Error);
    Decoder::AddFunction("Close", Close);

    sqlExitCode = sqlite3_open("languages.db", &Database);

    STANDARD_RETURN();
}

int Executer::Close(std::vector<std::string> args) {
    sqlite3_close(Database);
    return -1;
}

int Executer::Create(std::vector<std::string> args) {
    // For ease of reading, the following arguments are gonna get names.
    std::string language = args[1];

    std::string sql = "CREATE TABLE " + language + "_Lexicon("
                      "WordID INT, "
                      "Definition TEXT, "
                      "PartOfSpeech TEXT "
                      ");";

    sqlExitCode = sqlite3_exec(Database, sql.c_str(), NULL, 0, &messageError);

    STANDARD_RETURN();
}

int Executer::Add(std::vector<std::string> args) {
    // For ease of reading, the following arguments are gonna get names.
    std::string table_name = args[1] + "_" + args[2];

    std::string sql = "INSERT INTO " + table_name + "(" + args[3] + ") VALUES (" + args[4] + ");";


    sqlExitCode = sqlite3_exec(Database, sql.c_str(), NULL, 0, &messageError);

    STANDARD_RETURN();
}
int Executer::Remove(std::vector<std::string> args) {
    std::cout << args[1] << std::endl;
    return 200;
}
int Executer::Fetch(std::vector<std::string> args) {
    std::cout << args[1] << std::endl;
    return 200;
}
int Executer::Error(std::vector<std::string> args) {
    std::cout << "Bad Command " << args[1] << std::endl; 
    return 200;
}