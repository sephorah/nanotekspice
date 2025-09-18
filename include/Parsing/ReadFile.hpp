/*
** EPITECH PROJECT, 2024
** OOP - nanotekspice
** File description:
** read file
*/

#ifndef __READFILE_HPP__
    #define __READFILE_HPP__

#include <string>

class ReadFile {
public:
    ReadFile() = default;
    bool readFile(const std::string& filename, std::string& content);
    ~ReadFile();
private:
};

#endif // __READFILE_HPP__
