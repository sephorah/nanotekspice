/*
** EPITECH PROJECT, 2024
** TrueComponent
** File description:
** NTS
*/

#include "SpecialComponents.hpp"

nts::TrueComponent::TrueComponent() : AComponent({{1, std::make_shared<Pin>(nts::True, nullptr, nts::Input)}}) {}

nts::TrueComponent::~TrueComponent() {}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::exception();
        return nts::Undefined;
    }
    return nts::True;
}
