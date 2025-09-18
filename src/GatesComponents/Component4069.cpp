/*
** EPITECH PROJECT, 2024
** Component4069
** File description:
** NTS
*/


#include "GatesComponents.hpp"
#include "PinsExceptions.hpp"

nts::Component4069::Component4069() :
    _notGate1(std::make_unique<nts::NotComponent>()),
    _notGate2(std::make_unique<nts::NotComponent>()),
    _notGate3(std::make_unique<nts::NotComponent>()),
    _notGate4(std::make_unique<nts::NotComponent>()),
    _notGate5(std::make_unique<nts::NotComponent>()),
    _notGate6(std::make_unique<nts::NotComponent>()),
    AComponent({
        {1, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {2, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {3, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)},
        {4, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)},
        {5, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {6, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {8, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {9, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {10, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)},
        {11, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Output)},
        {12, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)},
        {13, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)}
    })
{
    this->_notGate1->setLink(1, this->getComponent(), 1);
    this->setLink(2, this->_notGate1->getComponent(), 2);
    this->_notGate2->setLink(1, this->getComponent(), 3);
    this->setLink(4, this->_notGate2->getComponent(), 2);
    this->_notGate3->setLink(1, this->getComponent(), 5);
    this->setLink(6, this->_notGate3->getComponent(), 2);
    this->setLink(8, this->_notGate4->getComponent(), 2);
    this->_notGate4->setLink(1, this->getComponent(), 9);
    this->setLink(10, this->_notGate5->getComponent(), 2);
    this->_notGate5->setLink(1, this->getComponent(), 11);
    this->setLink(12, this->_notGate6->getComponent(), 2);
    this->_notGate6->setLink(1, this->getComponent(), 13);
}

nts::Component4069::~Component4069() {}

nts::Tristate nts::Component4069::compute(std::size_t pin)
{
    if (pin < 1 || pin > 13 || pin == 7) {
        throw PinsExceptions();
    }
    this->_pins[pin]->_state = this->getLink(pin);
    return this->_pins[pin]->_state;
}
