#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include<cstddef>
#include<vector>
#include<string>

#include "CaesarMode.hpp"

/**
 * \file CaesarCipher.hpp
 * \brief Contains the declaration of the CaesarCipher class
 */

/**
 * \class CaesarCipher
 * \brief Encrypt or decrypt text using the Caesar cipher with the given key
 */
class CaesarCipher {
public:
    /**Can create a new instance of CaesarCipher using a key. 
     * \param key is the value for the key
     */
    CaesarCipher(const size_t key);
    
    /**Applies the cipher after inputting text and encryption boolean
     * \param inputText is the text to be encrypted or decrypted
     * \param mode is a enumeration which specifies whether to encrypt or decrypt.
     * \return the encrypted text
     */
    std::string applyCipher(const std::string& inputText, const CipherMode mode);

    
private:
    /// The cipher key
    size_t key_;
    /// The alphabet
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
};


#endif // MPAGSCIPHER_CAESARCIPHER_HPP
