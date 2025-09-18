/*
** EPITECH PROJECT, 2024
** Simulator.hpp
** File description:
** NTS
*/

#ifndef SIMULATOR_HPP_
#define SIMULATOR_HPP_
#include <set>
#include <cstdlib>
#include <csignal>

#include "Circuit.hpp"
#include "Parsing/ReadFile.hpp"
#include "Parsing/Parsing.hpp"
#define EXIT_SUCCESS 0
#define EXIT_FAIL 84

struct InputData {
    nts::Tristate state;
    bool toUpdate;
};

class Simulator {
    public:
        Simulator(const Parsing &parser);
        ~Simulator();
        void display();
        void simulate();
        void loop();
        void updateInput(const std::string &name, nts::Tristate value);
        void start();

    private:
        std::size_t _tick;
        std::unique_ptr<Circuit> _circuit;
        std::unordered_map<std::string, InputData> _inputs;
        std::unordered_map<std::string, nts::Tristate> _outputs;
        void handleUserInputs(const std::string &line);
};

#endif /* !SIMULATOR_HPP_ */
