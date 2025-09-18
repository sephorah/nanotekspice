/*
** EPITECH PROJECT, 2024
** OOP - nanotekspice
** File description:
** Parsing header
*/

#ifndef __PARSING_HPP__
    #define __PARSING_HPP__

#include <vector>
#include <string>
#include <regex>
#include <sstream>
#include <unordered_map>
#include "Chipset.hpp"
#include "Link.hpp"
#include "Output.hpp"
#include "Input.hpp"

#define __CHIPSETS_REGEX__ "^[\\s]*([a-zA-Z0-9]+)[\\s]+(\\w+)"
#define __LINKS_REGEX__ "^[\\s]*(\\w+):(\\d+)[\\s]+(\\w+):(\\d+)"
#define __INPUTS_REGEX__ "(?:(input|clock)\\s+)([a-zA-Z0-9_]+)"
#define __OUTPUTS_REGEX__ "(?:output\\s+)([a-zA-Z0-9_]+)"

class Parsing {
public:
    Parsing() = default;
    void parse(const std::string& file);
    void checkSections(const std::string& file);
    const std::vector<Chipset>& getChipsets() const;
    const std::vector<Link>& getLinks() const;
    const std::vector<Input>& getInputs() const;
    const std::vector<Output>& getOutputs() const;
    ~Parsing();

private:
    void parseChipset(const std::smatch& match);
    void parseLink(const std::smatch& match);
    void parseInput(const std::smatch& match);
    void parseOutput(const std::smatch& match);

    std::vector<Chipset> chipsets;
    std::vector<Link> links;
    std::vector<Input> inputs;
    std::vector<Output> outputs;

    std::unordered_map<std::string, std::function<void(const std::smatch&)>> parsers {
        {__CHIPSETS_REGEX__, [this](const std::smatch& match) { parseChipset(match); }},
        {__LINKS_REGEX__, [this](const std::smatch& match) { parseLink(match); }},
        {__INPUTS_REGEX__, [this](const std::smatch& match) { parseInput(match); }},
        {__OUTPUTS_REGEX__, [this](const std::smatch& match) { parseOutput(match); }},
    };

    bool foundChipsetsSection = false;
    bool foundLinksSection = false;
};

#endif // __PARSING_HPP__
