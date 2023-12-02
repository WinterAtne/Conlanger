cmake_minimum_required(VERSION 3.13.0)
project(Conlanger)

set (CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "src/*.cpp")

add_executable(Conlanger ${SOURCES})
target_include_directories(Conlanger PUBLIC "include/")
set_target_properties(
    Conlanger
    PROPERTIES
        LINKER_LANGUAGE CXX
        OUTPUT_NAME "Conlanger"
        SUFFIX ".o"   
)