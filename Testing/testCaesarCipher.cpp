#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CaesarMode.hpp"

const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const size_t alphabetSize = alphabet.size();


//Tests check whether simple cases of the encryption/decryption with and without wrap around work using a given input and key. 


TEST_CASE("Encryption without wrap around"){
  
    std::string testlett{"A"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::encrypt)};
    REQUIRE( ciphertest == "F");
    
}

TEST_CASE("Encryption with wrap around"){
  
    std::string testlett{"Z"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::encrypt)};
    REQUIRE( ciphertest == "E");
    
}

TEST_CASE("Decryption with wrap around"){
  
    std::string testlett{"A"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::decrypt)};
    REQUIRE( ciphertest == "V");
    
}

TEST_CASE("Decryption without wrap around"){
  
    std::string testlett{"Z"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::decrypt)};
    REQUIRE( ciphertest == "U");
    
}