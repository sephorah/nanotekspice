/*
** EPITECH PROJECT, 2024
** SpecialComponents.hpp
** File description:
** NTS
*/

#ifndef SPECIAL_COMPONENTS_HPP_
#define SPECIAL_COMPONENTS_HPP_
#include "AComponent.hpp"

namespace nts {
    class InputComponent : public AComponent {
        public:
            InputComponent();
            ~InputComponent();
            nts::Tristate compute(std::size_t pin) final;
            void setValue(nts::Tristate value) final;
            std::string getType() override;
    };

    class OutputComponent : public AComponent {
        public:
            OutputComponent();
            ~OutputComponent();
            nts::Tristate compute(std::size_t pin) final;
            std::string getType() final;
    };

    class TrueComponent : public AComponent {
        public:
            TrueComponent();
            ~TrueComponent();
            nts::Tristate compute(std::size_t pin) final;
    };

    class FalseComponent : public AComponent {
        public:
            FalseComponent();
            ~FalseComponent();
            nts::Tristate compute(std::size_t pin) final;
    };

    class ClockComponent : public InputComponent {
        public:
            ClockComponent();
            ~ClockComponent();
            void invertValue();
            void simulate(std::size_t tick);
            std::string getType() final;
    };
};

#endif /* !SPECIAL_COMPONENTS_HPP_ */
