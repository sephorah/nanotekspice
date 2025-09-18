/*
** EPITECH PROJECT, 2024
** ElementaryComponents
** File description:
** NTS
*/

#include "GatesComponents.hpp"
#include "PinsExceptions.hpp"

nts::NorComponent::NorComponent() :
    _orGate(std::make_unique<nts::OrComponent>()),
    _notGate(std::make_unique<nts::NotComponent>()),
    AComponent({
        {1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {2, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {3, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)}
    })
{
    this->_orGate->setLink(1, this->getComponent(), 1);
    this->_orGate->setLink(2, this->getComponent(), 2);
    this->_notGate->setLink(1, this->_orGate->getComponent(), 3);
    this->setLink(3, this->_notGate->getComponent(), 2);
}

nts::NorComponent::~NorComponent() {}

nts::Tristate nts::NorComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 3) {
        throw PinsExceptions();
    }
    this->_pins[pin]->_state = this->getLink(3);
    return this->_pins[pin]->_state;
}