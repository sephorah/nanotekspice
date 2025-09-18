/*
** EPITECH PROJECT, 2024
** Simulator
** File description:
** NTS
*/

#include "Simulator.hpp"
#include "LoopOn.hpp"

std::ostream &operator<<(std::ostream &s, nts::Tristate v)
{
    std::string state = "U";

    if (v == nts::True) {
        state = "1";
    }
    if (v == nts::False) {
        state = "0";
    }
    std::cout << state;
    return s;
}

Simulator::Simulator(const Parsing &parser) :
    _circuit(std::make_unique<Circuit>(parser)),
    _inputs({}), _outputs({}), _tick(0)
{
    for (Input input : parser.getInputs()) {
        this->_inputs[input.name] = {nts::Undefined, false};
    }
    for (Output output : parser.getOutputs()) {
        this->_outputs.emplace(output.name, nts::Undefined);
    }
}

Simulator::~Simulator() {}

void Simulator::display()
{
    std::set<std::string> sortedInputs;
    std::set<std::string> sortedOutputs;

    for (auto &[name, value] : this->_inputs) {
        sortedInputs.insert(name);
    }
    for (auto &[name, value] : this->_outputs) {
        sortedOutputs.insert(name);
    }
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (std::string input : sortedInputs) {
        std::cout << "  " << input << ": " << this->_circuit->findComponent(input).compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (std::string output : sortedOutputs) {
        std::cout << "  " << output << ": " << this->_circuit->findComponent(output).compute(1) << std::endl;
    }
}

void Simulator::updateInput(const std::string &name, nts::Tristate value)
{
    if (this->_inputs.find(name) == this->_inputs.end()) {
        throw std::exception();
    }
    this->_inputs[name] = {value, true};
}

void Simulator::simulate()
{
    this->_tick += 1;

    for (auto &[name, value] : this->_circuit->getComponents()) {
        this->_circuit->findComponent(name).simulate(this->_tick);
    }
    for (auto &[name, value] : this->_inputs) {
        if (value.toUpdate) {
            this->_circuit->findComponent(name).setValue(value.state);
            this->_inputs[name].toUpdate = false;
        }
    }
}

void sig_handler(int signal)
{
    isLoopOn = false;
}

void Simulator::loop()
{
    std::signal(SIGINT, sig_handler);

    isLoopOn = true;
    while (isLoopOn) {
        this->simulate();
        this->display();
    }
}

void Simulator::handleUserInputs(const std::string &line)
{
    std::regex chipsetRegex(___SET_INPUT_REGEX___);
    std::smatch chipsetMatch;
    nts::Tristate state;

    if (line == "display") {
        this->display();
    }
    if (line == "simulate") {
        this->simulate();
    }
    if (line == "loop") {
        this->loop();
    }
    if (std::regex_match(line, chipsetMatch, chipsetRegex)) {
        state = nts::Undefined;
        if (chipsetMatch[2] == "1") {
            state = nts::True;
        }
        if (chipsetMatch[2] == "0") {
            state = nts::False;
        }
        this->updateInput(chipsetMatch[1], state);
   }
}

void Simulator::start()
{
    std::string line;

    std::cout << "> ";
    while (std::getline(std::cin, line)) {
        // if (line != "exit" && line != "simulate" && line != "display" && line != "loop") {
        //     std::cout << "Error: Invalid argument." << std::endl;
        // }
        if (line == "exit") {
            return;
        }
        this->handleUserInputs(line);
        std::cout << "> ";
    }
}