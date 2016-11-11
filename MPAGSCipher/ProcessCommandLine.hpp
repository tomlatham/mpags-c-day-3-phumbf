#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "CaesarMode.hpp"

/**
 * \file ProcessCommandLine.hpp
 * \brief Contains the declarations of the data structures and functions associated with the processing of command-line arguments
 */

/**
 * \struct ProgramSettings
 * \brief Holds the settings of the program that can be modified by command-line arguments
 */
struct ProgramSettings {
    bool helpRequested;
    bool versionRequested;
    std::string inputFile;
    std::string outputFile;
    std::string cipherKey;
    CipherMode cipherMode;    
};

/**
 * \brief Processes the command-line arguments and modifies accordingly the program settings
 *
 * \param args the command-line arguments to be processed
 * \param settings the program settings to be modified based upon the arguments received
 * \return true if the arguments could be successfully parsed, false otherwise
 */
bool processCommandLine(const std::vector<std::string>& args, ProgramSettings& settings);

    

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
