/*
** EPITECH PROJECT, 2024
** IComponent
** File description:
** NanoTekSpice
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_
#include <cstddef>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual nts::IComponent &getComponent(void) = 0;
            virtual nts::Tristate getLink(std::size_t pin) = 0;
            virtual std::string getType() = 0;
            virtual void setValue(nts::Tristate value) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
