/*
** EPITECH PROJECT, 2024
** Circuit
** File description:
** NTS
*/

#include "Circuit.hpp"

Circuit::Circuit(const Parsing &circuitData) : _components({}), _factory(ComponentFactory())
{
    setupComponents(circuitData.getChipsets(), circuitData.getInputs(), circuitData.getOutputs());
    setupLinks(circuitData.getLinks());
}

Circuit::~Circuit() {}

Circuit::ComponentFactory::ComponentFactory() : _factory({})
{
    this->_factory.emplace("input", [] { return std::make_unique<nts::InputComponent>(); });
    this->_factory.emplace("output", [] { return std::make_unique<nts::OutputComponent>(); });
    this->_factory.emplace("true", [] { return std::make_unique<nts::TrueComponent>(); });
    this->_factory.emplace("false", [] { return std::make_unique<nts::FalseComponent>(); });
    this->_factory.emplace("clock", [] { return std::make_unique<nts::ClockComponent>(); });
    this->_factory.emplace("and", [] { return std::make_unique<nts::AndComponent>(); });
    this->_factory.emplace("or", [] { return std::make_unique<nts::OrComponent>(); });
    this->_factory.emplace("xor", [] { return std::make_unique<nts::XorComponent>(); });
    this->_factory.emplace("not", [] { return std::make_unique<nts::NotComponent>(); });
    this->_factory.emplace("4001", [] { return std::make_unique<nts::Component4001>(); });
    this->_factory.emplace("4011", [] { return std::make_unique<nts::Component4011>(); });
    this->_factory.emplace("4030", [] { return std::make_unique<nts::Component4030>(); });
    this->_factory.emplace("4069", [] { return std::make_unique<nts::Component4069>(); });
    this->_factory.emplace("4071", [] { return std::make_unique<nts::Component4071>(); });
    this->_factory.emplace("4081", [] { return std::make_unique<nts::Component4081>(); });
}

Circuit::ComponentFactory::~ComponentFactory() {}

std::unique_ptr<nts::IComponent> Circuit::ComponentFactory::createComponent(const std::string &type)
{
    return this->_factory[type]();
}

void Circuit::setupComponents(const std::vector<Chipset> &chipsets, const std::vector<Input> &inputs, const std::vector<Output> &outputs)
{
    for (Input input : inputs) {
        this->addComponent(input.name, input.op);
    }
    for (Output output : outputs) {
        this->addComponent(output.name, "output");
    }
    for (Chipset chipset : chipsets) {
        this->addComponent(chipset.op, chipset.number);
    }
}

void Circuit::addComponent(const std::string &name, const std::string &type)
{
    this->_components.emplace(name, this->_factory.createComponent(type));
}

nts::IComponent &Circuit::findComponent(const std::string &name)
{
    if (this->_components.find(name) == this->_components.end()) {
        throw std::exception();
    }
    return (*this->_components[name]);
}

void Circuit::setupLinks(const std::vector<Link> &links)
{
    for (Link link: links) {
        if (this->findComponent(link.InputName).getType() == "output") {
            this->findComponent(link.InputName).setLink(link.InputValue,
            this->findComponent(link.OperatorName), link.OperatorValue);
            continue;
        }
        if (this->findComponent(link.OperatorName).getType() == "output") {
            this->findComponent(link.OperatorName).setLink(link.OperatorValue,
            this->findComponent(link.InputName), link.InputValue);
            continue;
        }
        this->_components[link.OperatorName]->setLink(link.OperatorValue,
        this->_components[link.InputName]->getComponent(), link.InputValue);
    }
}

void Circuit::display()
{
}

std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> Circuit::getComponents() const
{
    return this->_components;
}