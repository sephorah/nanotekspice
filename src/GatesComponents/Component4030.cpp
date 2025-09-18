/*
** EPITECH PROJECT, 2024
** Component4030
** File description:
** NTS
*/

#include "GatesComponents.hpp"
#include "PinsExceptions.hpp"

nts::Component4030::Component4030() :
    _xorGate1(std::make_unique<nts::XorComponent>()),
    _xorGate2(std::make_unique<nts::XorComponent>()),
    _xorGate3(std::make_unique<nts::XorComponent>()),
    _xorGate4(std::make_unique<nts::XorComponent>()),
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
    this->_xorGate1->setLink(1, this->getComponent(), 1);
    this->_xorGate1->setLink(2, this->getComponent(), 2);
    this->setLink(3, this->_xorGate1->getComponent(), 3);;
    this->setLink(4, this->_xorGate2->getComponent(), 3);
    this->_xorGate2->setLink(1, this->getComponent(), 5);
    this->_xorGate2->setLink(2, this->getComponent(), 6);
    this->_xorGate3->setLink(1, this->getComponent(), 8);
    this->_xorGate3->setLink(2, this->getComponent(), 9);
    this->setLink(10, this->_xorGate3->getComponent(), 3);
    this->setLink(11, this->_xorGate4->getComponent(), 3);
    this->_xorGate4->setLink(1, this->getComponent(), 12);
    this->_xorGate4->setLink(2, this->getComponent(), 13);
}

nts::Component4030::~Component4030() {}

nts::Tristate nts::Component4030::compute(std::size_t pin)
{
    if (pin < 1 || pin > 13 || pin == 7) {
        throw PinsExceptions();
    }
    this->_pins[pin]->_state = this->getLink(pin);
    return this->_pins[pin]->_state;
}
