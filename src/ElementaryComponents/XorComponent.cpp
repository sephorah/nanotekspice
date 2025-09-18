/*
** EPITECH PROJECT, 2024
** XorComponent
** File description:
** NTS
*/

#include "ElementaryComponents.hpp"
#include "PinsExceptions.hpp"

nts::XorComponent::XorComponent() : AComponent(
    {{1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
    {2, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
    {3, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)}}) {}

nts::XorComponent::~XorComponent() {}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    nts::Tristate input1;
    nts::Tristate input2;

    if (this->_pins[1]->_link != nullptr) {
        this->_pins[1]->_state = this->_pins[1]->_link->_component.getLink(this->_pins[1]->_link->_pin);
    }
    if (this->_pins[2]->_link != nullptr) {
        this->_pins[2]->_state = this->_pins[2]->_link->_component.getLink(this->_pins[2]->_link->_pin);
    }
    input1 = this->_pins[1]->_state;
    input2 = this->_pins[2]->_state;
    if (pin < 1 || pin > 3) {
        throw PinsExceptions();
    }
    if (pin == 1 || pin == 2) {
        return this->_pins[pin]->_state;
    }
    if ((input1 == nts::False && input2 == nts::False) ||
        (input1 == nts::True && input2 == nts::True)) {
        return nts::False;
    }
    if ((input1 == nts::True && input2 == nts::False) ||
        (input1 == nts::False && input2 == nts::True)) {
        return nts::True;
    }
    return nts::Undefined;
}