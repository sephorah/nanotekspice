/*
** EPITECH PROJECT, 2024
** AComponent
** File description:
** NTS
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include <cstddef>
#include <memory>
#include <unordered_map>
#include <string>
#include "IComponent.hpp"

namespace nts {
    enum TypePin { Input, Output };
    class Link {
        public:
            Link(std::size_t pin, nts::IComponent &component);
            ~Link();
            IComponent &_component;
            std::size_t _pin;
    };
    class Pin {
        public:
            Pin(nts::Tristate state, std::shared_ptr<Link> link, TypePin type);
            ~Pin();

            nts::Tristate _state;
            TypePin _type;
            std::shared_ptr<Link> _link;
    };

    class AComponent : public nts::IComponent {
        public:
            AComponent(const std::unordered_map<std::size_t, std::shared_ptr<Pin>> pins);
            virtual ~AComponent();
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate getLink(std::size_t pin) override;
            nts::IComponent &getComponent(void) final;
            std::string getType() override;
            void setValue(nts::Tristate value) override;

        protected:
            std::unordered_map<std::size_t, std::shared_ptr<Pin>> _pins;
    };
};

#endif /* !ACOMPONENT_HPP_ */
