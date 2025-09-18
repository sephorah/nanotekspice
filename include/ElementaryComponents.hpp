/*
** EPITECH PROJECT, 2024
** ElementaryComponents
** File description:
** NTS
*/

#ifndef ELEMENTARY_COMPONENTS_HPP_
#define ELEMENTARY_COMPONENTS_HPP_
#include "AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            AndComponent();
            ~AndComponent();
            nts::Tristate compute(std::size_t pin) final;
    };

    class OrComponent : public AComponent {
        public:
            OrComponent();
            ~OrComponent();
            nts::Tristate compute(std::size_t pin) final;
    };

    class XorComponent : public AComponent {
        public:
            XorComponent();
            ~XorComponent();
            nts::Tristate compute(std::size_t pin) final;
    };

    class NotComponent : public AComponent {
        public:
            NotComponent();
            ~NotComponent();
            nts::Tristate compute(std::size_t pin) final;
    };
};

#endif /* !ELEMENTARY_COMPONENTS_HPP_ */
