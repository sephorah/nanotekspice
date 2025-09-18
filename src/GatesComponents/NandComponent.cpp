/*
** EPITECH PROJECT, 2024
** NandComponent
** File description:
** NTS
*/

#include "GatesComponents.hpp"
#include "PinsExceptions.hpp"

nts::NandComponent::NandComponent() : 
    _andGate(std::make_unique<nts::AndComponent>()),
    _notGate(std::make_unique<nts::NotComponent>()),
    AComponent({
        {1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {2, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {3, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)}
    })
{
    this->_andGate->setLink(1, this->getComponent(), 1);
    this->_andGate->setLink(2, this->getComponent(), 2);
    this->_notGate->setLink(1, this->_andGate->getComponent(), 3);
    this->setLink(3, this->_notGate->getComponent(), 2);
}

nts::NandComponent::~NandComponent() {}

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 3) {
        throw PinsExceptions();
    }
    this->_pins[pin]->_state = this->getLink(3);
    return this->_pins[pin]->_state;
}