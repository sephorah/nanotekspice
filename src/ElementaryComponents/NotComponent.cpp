/*
** EPITECH PROJECT, 2024
** NotComponent
** File description:
** NTS
*/

#include "ElementaryComponents.hpp"
#include "PinsExceptions.hpp"

nts::NotComponent::NotComponent() : AComponent(
    {{1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
    {2, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)}}) {}

nts::NotComponent::~NotComponent() {}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    nts::Tristate input;

    input = this->getLink(1);
    if (pin != 1 && pin != 2) {
        throw PinsExceptions();
    }
    if (pin == 1) {
        return this->_pins[pin]->_state;
    }
    if (input == nts::True) {
        return nts::False;
    }
    if (input == nts::False) {
        return nts::True;
    }
    return nts::Undefined;
}
