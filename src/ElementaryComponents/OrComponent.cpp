/*
** EPITECH PROJECT, 2024
** OrComponent
** File description:
** NTS
*/

#include "ElementaryComponents.hpp"
#include "PinsExceptions.hpp"

nts::OrComponent::OrComponent() : AComponent(
    {{1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
    {2, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
    {3, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)}}) {}

nts::OrComponent::~OrComponent() {}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
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
    if (input1 == nts::True || input2 == nts::True) {
        return nts::True;
    }
    if ((input1 == nts::Undefined && input2 != nts::True)
        ||(input1 != nts::True && input2 == nts::Undefined)) {
        return nts::Undefined;
    }
    return nts::False;
}