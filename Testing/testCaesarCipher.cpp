#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CaesarMode.hpp"

//Tests check whether simple cases of the encryption/decryption with and without wrap around work using a given input and key. 


TEST_CASE("Encryption without wrap around"){
  
    std::string testlett{"A"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::Encrypt)};
    REQUIRE( ciphertest == "F");
    
}

TEST_CASE("Encryption with wrap around"){
  
    std::string testlett{"Z"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::Encrypt)};
    REQUIRE( ciphertest == "E");
    
}

TEST_CASE("Decryption with wrap around"){
  
    std::string testlett{"A"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::Decrypt)};
    REQUIRE( ciphertest == "V");
    
}

TEST_CASE("Decryption without wrap around"){
  
    std::string testlett{"Z"};
    CaesarCipher cipher{5};
    std::string ciphertest{cipher.applyCipher(testlett, CipherMode::Decrypt)};
    REQUIRE( ciphertest == "U");
    
}
