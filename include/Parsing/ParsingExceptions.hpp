/*
** EPITECH PROJECT, 2024
** OOP - nanotekspice
** File description:
** Parsing Exceptions
*/

#ifndef __PARSING_EXCEPTIONS__
    #define __PARSING_EXCEPTIONS__
#include <iostream>

class ParsingExceptions : public std::exception {
    public:
        std::string exceptions() {
            return "Bad format of .nts";
        }
};

#endif /* __PARSING_EXCEPTIONS__ */