/*
** EPITECH PROJECT, 2024
** Component4001.hpp
** File description:
** NTS
*/

#ifndef GATES_COMPONENTS_HPP_
#define GATES_COMPONENTS_HPP_
#include "ElementaryComponents.hpp"

namespace nts {
    class NorComponent : public AComponent {
        public: 
            NorComponent();
            ~NorComponent();
            nts::Tristate compute(std::size_t pin) final;

        private:
            std::unique_ptr<nts::IComponent> _orGate;
            std::unique_ptr<nts::IComponent> _notGate;
    };

    class NandComponent : public AComponent {
        public: 
            NandComponent();
            ~NandComponent();
            nts::Tristate compute(std::size_t pin) final;

        private:
            std::unique_ptr<nts::IComponent> _andGate;
            std::unique_ptr<nts::IComponent> _notGate;
    };

    class Component4001 : public AComponent {
        public:
            Component4001();
            ~Component4001();
            nts::Tristate compute(std::size_t pin) final;
            
        private:
            std::unique_ptr<nts::IComponent> _norGate1;
            std::unique_ptr<nts::IComponent> _norGate2;
            std::unique_ptr<nts::IComponent> _norGate3;
            std::unique_ptr<nts::IComponent> _norGate4;
    };

    class Component4011 : public AComponent {
        public:
            Component4011();
            ~Component4011();
            nts::Tristate compute(std::size_t pin) final;
            
        private:
            std::unique_ptr<nts::IComponent> _nandGate1;
            std::unique_ptr<nts::IComponent> _nandGate2;
            std::unique_ptr<nts::IComponent> _nandGate3;
            std::unique_ptr<nts::IComponent> _nandGate4;
    };

    class Component4030 : public AComponent {
        public:
            Component4030();
            ~Component4030();
            nts::Tristate compute(std::size_t pin) final;
            
        private:
            std::unique_ptr<nts::IComponent> _xorGate1;
            std::unique_ptr<nts::IComponent> _xorGate2;
            std::unique_ptr<nts::IComponent> _xorGate3;
            std::unique_ptr<nts::IComponent> _xorGate4;
    };

    class Component4069 : public AComponent {
        public:
            Component4069();
            ~Component4069();
            nts::Tristate compute(std::size_t pin) final;
            
        private:
            std::unique_ptr<nts::IComponent> _notGate1;
            std::unique_ptr<nts::IComponent> _notGate2;
            std::unique_ptr<nts::IComponent> _notGate3;
            std::unique_ptr<nts::IComponent> _notGate4;
            std::unique_ptr<nts::IComponent> _notGate5;
            std::unique_ptr<nts::IComponent> _notGate6;
    };

    class Component4071 : public AComponent {
        public:
            Component4071();
            ~Component4071();
            nts::Tristate compute(std::size_t pin) final;
            
        private:
            std::unique_ptr<nts::IComponent> _orGate1;
            std::unique_ptr<nts::IComponent> _orGate2;
            std::unique_ptr<nts::IComponent> _orGate3;
            std::unique_ptr<nts::IComponent> _orGate4;
    };

    class Component4081 : public AComponent {
        public:
            Component4081();
            ~Component4081();
            nts::Tristate compute(std::size_t pin) final;
            
        private:
            std::unique_ptr<nts::IComponent> _andGate1;
            std::unique_ptr<nts::IComponent> _andGate2;
            std::unique_ptr<nts::IComponent> _andGate3;
            std::unique_ptr<nts::IComponent> _andGate4;
    };
};

#endif /* !GATES_COMPONENTS_HPP_ */
