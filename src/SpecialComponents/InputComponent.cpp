/*
** EPITECH PROJECT, 2024
** InputComponent
** File description:
** NTS
*/

#include "SpecialComponents.hpp"

nts::InputComponent::InputComponent() : AComponent({{1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)}}) {}

nts::InputComponent::~InputComponent() {}


void nts::InputComponent::setValue(nts::Tristate value)
{
    this->_pins[1]->_state = value;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::exception();
        return nts::Undefined;
    }
    return this->_pins[pin]->_state;
}

std::string nts::InputComponent::getType()
{
    return "input";
}