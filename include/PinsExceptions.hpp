/*
** EPITECH PROJECT, 2024
** OOP - nanotekspice
** File description:
** Pin Exceptions
*/

#ifndef __PIN_EXCEPTIONS__
    #define __PIN_EXCEPTIONS__
#include <iostream>

class PinsExceptions : public std::exception {
    public:
        std::string exceptions() const {
            return "Error: pins not in range.";
        }
};

#endif /* __PIN_EXCEPTIONS__ */