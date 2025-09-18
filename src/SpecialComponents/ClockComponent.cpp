/*
** EPITECH PROJECT, 2024
** SpecialComponents.cpp
** File description:
** NTS
*/

#include "SpecialComponents.hpp"

nts::ClockComponent::ClockComponent() : InputComponent() {}

nts::ClockComponent::~ClockComponent() {}

void nts::ClockComponent::invertValue()
{
    if (this->_pins[1]->_state == nts::True) {
        this->_pins[1]->_state = nts::False;
        return;
    }
    if (this->_pins[1]->_state == nts::False) {
        this->_pins[1]->_state = nts::True;
    }
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    this->invertValue();
}

std::string nts::ClockComponent::getType()
{
    return "clock";
}