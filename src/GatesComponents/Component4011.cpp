/*
** EPITECH PROJECT, 2024
** Component4011
** File description:
** NTS
*/

#include "GatesComponents.hpp"
#include "PinsExceptions.hpp"

nts::Component4011::Component4011() :
    _nandGate1(std::make_unique<nts::NandComponent>()),
    _nandGate2(std::make_unique<nts::NandComponent>()),
    _nandGate3(std::make_unique<nts::NandComponent>()),
    _nandGate4(std::make_unique<nts::NandComponent>()),
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
        {13, std::make_shared<Pin>(nts::Undefined, nullptr, nts::Input)}})
{
    this->_nandGate1->setLink(1, this->getComponent(), 1);
    this->_nandGate1->setLink(2, this->getComponent(), 2);
    this->setLink(3, this->_nandGate1->getComponent(), 3);
    this->setLink(4, this->_nandGate2->getComponent(), 3);
    this->_nandGate2->setLink(1, this->getComponent(), 5);
    this->_nandGate2->setLink(2, this->getComponent(), 6);
    this->_nandGate3->setLink(1, this->getComponent(), 8);
    this->_nandGate3->setLink(2, this->getComponent(), 9);
    this->setLink(10, this->_nandGate3->getComponent(), 3);
    this->setLink(11, this->_nandGate4->getComponent(), 3);
    this->_nandGate4->setLink(1, this->getComponent(), 12);
    this->_nandGate4->setLink(2, this->getComponent(), 13);
}

nts::Component4011::~Component4011() {}

nts::Tristate nts::Component4011::compute(std::size_t pin)
{
    if (pin < 1 || pin > 13 || pin == 7) {
        throw PinsExceptions();
    }
    this->_pins[pin]->_state = this->getLink(pin);
    return this->_pins[pin]->_state;
}
