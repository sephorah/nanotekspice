/*
** EPITECH PROJECT, 2024
** OOP - nanotekspice
** File description:
** readfile functions
*/

#include <fstream>
#include <sstream>
#include "Parsing/ReadFile.hpp"
#include "Parsing/Parsing.hpp"

bool ReadFile::readFile(const std::string& filename, std::string& content)
{
    std::ifstream file(filename);

    if (file.is_open()) {
        std::stringstream buffer;
        std::string line;

        while (std::getline(file, line))
            buffer << line << '\n';
        content = buffer.str();
        file.close();
        return true;
    }
    return false;
}

ReadFile::~ReadFile() {}