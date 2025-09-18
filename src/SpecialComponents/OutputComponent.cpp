/*
** EPITECH PROJECT, 2024
** OutputComponent
** File description:
** NTS
*/

#include "SpecialComponents.hpp"

nts::OutputComponent::OutputComponent() : AComponent({{1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)}}) {}

nts::OutputComponent::~OutputComponent() {}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::exception();
        return nts::Undefined;
    }
    this->_pins[pin]->_state = this->getLink(1);
    return this->_pins[pin]->_state;
}

std::string nts::OutputComponent::getType()
{
    return "output";
}