#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>
#include <sstream>
#include "SpecialComponents.hpp"
#include "ElementaryComponents.hpp"
#include "GatesComponents.hpp"
#include "Parsing/ReadFile.hpp"
#include "Parsing/Parsing.hpp"
#include "Circuit.hpp"
#include "Simulator.hpp"

void handleSimulation(const Parsing &parser)
{
    Simulator simulator(parser);
    simulator.start();
}

int main(int argc, char* argv[])
{
    ReadFile r;
    std::string fileContent;
    Parsing parser;

    try {
        if (argc < 2 || (argv[1][0] == '-' && argv[1][1] == 'h')) {
            throw std::exception();
            std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
            return 1;
        }

        if (!r.readFile(argv[1], fileContent)) {
            throw std::exception();
            return 1;
        }
        parser.parse(fileContent);
        handleSimulation(parser);
    } catch (const std::exception &e) {
        std::cout << "Error " << e.what() << std::endl;
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
