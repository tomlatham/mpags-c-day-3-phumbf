//! Unit tests for MPAGSCIPHER transformChar interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TransformChar.hpp"
#include <cctype>



TEST_CASE("Characters are uppercased", "[alphanumeric]") {
  
  const std::vector<char> loweralphabet_ = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  std::string out_text{""};
  
  for(int i=0; i<26; i++)
  {
    out_text = alphabet_[i];
    REQUIRE( transformChar(loweralphabet_[i]) == out_text );
  }
  
}

TEST_CASE("Digits are transliterated", "[alphanumeric]") {
    REQUIRE( transformChar('0') == "ZERO");
    REQUIRE( transformChar('1') == "ONE");
    REQUIRE( transformChar('2') == "TWO");
    REQUIRE( transformChar('3') == "THREE");
    REQUIRE( transformChar('4') == "FOUR");
    REQUIRE( transformChar('5') == "FIVE");
    REQUIRE( transformChar('6') == "SIX");
    REQUIRE( transformChar('7') == "SEVEN");
    REQUIRE( transformChar('8') == "EIGHT");
    REQUIRE( transformChar('9') == "NINE");
}

TEST_CASE("Special characters are removed", "[punctuation]") {
  
    REQUIRE( transformChar('!') == "");
    REQUIRE( transformChar('+') == "");
    REQUIRE( transformChar('&') == "");
    REQUIRE( transformChar('$') == "");
}

