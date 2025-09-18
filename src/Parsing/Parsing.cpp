/*
** EPITECH PROJECT, 2024
** OOP - nanotekspice
** File description:
** Parsing function
*/

#include <regex>
#include <sstream>
#include "Parsing/Parsing.hpp"

void Parsing::parse(const std::string& file)
{
    std::stringstream stream(file);
    std::string line;

    checkSections(file);

    while (std::getline(stream, line)) {
        if (line == ".chipsets:") {
            continue;
        }
        if (line == ".links:") {
            continue;
        }

        for (const auto& [regexPattern, parserFunc] : parsers) {
            std::regex pattern(regexPattern);
            std::smatch match;
            if (std::regex_match(line, match, pattern)) {
                parserFunc(match);
                break;
            }
        }
    }
}

void Parsing::checkSections(const std::string& file)
{
    std::stringstream stream(file);
    std::string line;

    while (std::getline(stream, line)) {
        if (line == ".chipsets:") {
            foundChipsetsSection = true;
        }
        if (line == ".links:") {
            foundLinksSection = true;
        }
    }

    if (!foundChipsetsSection || !foundLinksSection) {
        throw std::invalid_argument(": Missing sections .chipsets or/and .links");
    }
}


void Parsing::parseChipset(const std::smatch& match)
{
    Chipset chipset;

    chipset.number = match[1];
    chipset.op = match[2];
    chipsets.push_back(chipset);
}

// TODO: fix error pour récuperer l'input quand il est en 2e
void Parsing::parseLink(const std::smatch& match)
{
    Link link;

    link.InputName = match[1];
    link.InputValue = std::stoi(match[2]);
    link.OperatorName = match[3];
    link.OperatorValue = std::stoi(match[4]);
    links.push_back(link);
}

void Parsing::parseInput(const std::smatch& match)
{
    Input input;

    input.name = match[2];
    input.op = match[1];
    inputs.push_back(input);
}

void Parsing::parseOutput(const std::smatch& match)
{
    Output output;

    output.name = match[1];
    outputs.push_back(output);
}

const std::vector<Chipset>& Parsing::getChipsets() const
{
    return chipsets;
}

const std::vector<Link>& Parsing::getLinks() const
{
    return links;
}

const std::vector<Input>& Parsing::getInputs() const
{
    return inputs;
}

const std::vector<Output>& Parsing::getOutputs() const
{
    return outputs;
}

Parsing::~Parsing() {}

