#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include<cstddef>
#include<vector>
#include<string>



class CaesarCipher {
public:
    CaesarCipher(const size_t key);
    std::string applyCipher(const std::string& inputText, const bool encrypt);
    
    
private:
    size_t key_;
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
};


#endif // MPAGSCIPHER_MPAGSCIPHER_CAESARCIPHER_HPP
