#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"
#include "CaesarMode.hpp"

//Tests check for correct responses given input.

std::vector<std::string> testargs{};
ProgramSettings settings { false, false, "", "", "", CipherMode::encrypt}; 

TEST_CASE("User asks for help"){

  testargs = {"./mpags-cipher", "-h"}; 
  processCommandLine(testargs, settings);
  REQUIRE( settings.helpRequested == true  );    
  
}

TEST_CASE("User asks for version"){
  
  testargs = {"./mpags-cipher", "--version"}; 
  processCommandLine(testargs, settings);
  REQUIRE( settings.versionRequested == true  );
}

TEST_CASE("Encrypt mode activated"){
  
  testargs = {"./mpags-cipher", "--encrypt"};
  processCommandLine(testargs, settings);
  REQUIRE( settings.encrypt == CipherMode::encrypt  );
}

TEST_CASE("Decrypt mode deactivated"){
  
  testargs = {"./mpags-cipher", "--decrypt"}; 
  processCommandLine(testargs, settings);
  REQUIRE( settings.encrypt == CipherMode::decrypt  );
}

TEST_CASE("Key entered with no key specified"){
  
  testargs = {"./mpags-cipher", "-k"}; 
  REQUIRE( processCommandLine(testargs, settings) == false);
}

TEST_CASE("Key entered with key specified"){
  
  testargs = {"./mpags-cipher", "-k", "4"}; 
  processCommandLine(testargs, settings);
  REQUIRE( settings.cipher_key == testargs[2]);
}

TEST_CASE("Input file declared without using input file"){
  
  testargs = {"./mpags-cipher", "-i"}; 
  processCommandLine(testargs, settings);
  REQUIRE( processCommandLine(testargs, settings) == false);
}

TEST_CASE("Input file declared"){
  
  testargs = {"./mpags-cipher", "-i", "input.txt"}; 
  processCommandLine(testargs, settings);
  REQUIRE( settings.inputFile == testargs[2]);
}

TEST_CASE("Output file declared without specifying output file"){
  
  testargs = {"./mpags-cipher", "-o"}; 
  processCommandLine(testargs, settings);
  REQUIRE( processCommandLine(testargs, settings) == false);
}

TEST_CASE("Output file declared"){
  
  testargs = {"./mpags-cipher", "-o", "output.txt"}; 
  processCommandLine(testargs, settings);
  REQUIRE( settings.outputFile == testargs[2]);
}