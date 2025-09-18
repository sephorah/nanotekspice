/*
** EPITECH PROJECT, 2024
** Circuit
** File description:
** NTS
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_
#include <vector>
#include <functional>
#include <iostream>
#include "SpecialComponents.hpp"
#include "ElementaryComponents.hpp"
#include "GatesComponents.hpp"
#include "Parsing/Parsing.hpp"

#define ___SET_INPUT_REGEX___ "(.+)=(.+)"

class Circuit {
    public:
        Circuit(const Parsing &circuitData);
        ~Circuit();
        void addComponent(const std::string &name, const std::string &type);
        nts::IComponent &findComponent(const std::string &name);
        void simulate(std::size_t tick);
        void display();
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> getComponents() const;
        class ComponentFactory {
            public:
                ComponentFactory();
                ~ComponentFactory();
                std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

            private:
                std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _factory;
        };

    private:
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> _components;
        ComponentFactory _factory;
        void setupComponents(const std::vector<Chipset> &chipsets, const std::vector<Input> &inputs, const std::vector<Output> &outputs);
        void setupLinks(const std::vector<Link> &links);
};

#endif /* !CIRCUIT_HPP_ */
