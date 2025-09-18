/*
** EPITECH PROJECT, 2024
** FalseComponent
** File description:
** NTS
*/

#include "SpecialComponents.hpp"

nts::FalseComponent::FalseComponent() : AComponent({{1, std::make_shared<Pin>(nts::False, nullptr, nts::Input)}}) {}

nts::FalseComponent::~FalseComponent() {}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
     if (pin != 1) {
        throw std::exception();
        return nts::Undefined;
    }
    return nts::False;
}
