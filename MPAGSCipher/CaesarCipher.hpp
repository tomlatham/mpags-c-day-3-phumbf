#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include<cstddef>
#include<vector>
#include<string>

#include "CaesarMode.hpp"

class CaesarCipher {
public:
    /**Can create a new instance of CaesarCipher using a key. 
 * \param key is the value for the key
 * */
    CaesarCipher(const size_t key);
    
/**Applies the cipher after inputting text and encryption boolean
 * \param inputText is the text to be encrypted or decrypted
 * \param encrypt is a boolean which decides whether to e3ncrypt or decrypt.
 * */
    std::string applyCipher(const std::string& inputText, const CipherMode encrypt);
    
    
private:
    size_t key_;
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
};


#endif // MPAGSCIPHER_MPAGSCIPHER_CAESARCIPHER_HPP
