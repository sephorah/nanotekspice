/*
** EPITECH PROJECT, 2024
** AComponent
** File description:
** NanoTekSpice
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::unordered_map<std::size_t, std::shared_ptr<Pin>> pins) :
    _pins(pins) {}

nts::AComponent::~AComponent() {}

nts::Pin::Pin(nts::Tristate state, std::shared_ptr<Link> link, nts::TypePin type) : _state(state), _link(link), _type(type) {}

nts::Pin::~Pin() {}

nts::Link::Link(std::size_t pin, nts::IComponent &component) : _pin(pin), _component(component) {}

nts::Link::~Link() {}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    return nts::Undefined;
}

void nts::AComponent::simulate(std::size_t tick) {}

void nts::AComponent::setValue(nts::Tristate value) {}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_pins[pin]->_link = std::make_shared<nts::Link>(otherPin, other);
    this->_pins[pin]->_state = this->_pins[pin]->_link->_component.compute(otherPin);
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    if (this->_pins[pin]->_link == nullptr) {
        return this->_pins[pin]->_state;
    }
    return this->_pins[pin]->_link->_component.compute(this->_pins[pin]->_link->_pin);
}

nts::IComponent &nts::AComponent::getComponent(void)
{
    return *this;
}

std::string nts::AComponent::getType()
{
    return "";
}