# - Build sub-script for the MPAGSCipher library unit tests

# Most basic tests
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# Create inferface library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# First Catch-based test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch)

#TransformChar test
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-TransformChar COMMAND testTransformChar)

#ProcessCommandLine test
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine MPAGSCipher Catch)
add_test(NAME test-ProcessCommandLine COMMAND testProcessCommandLine)

#CaesarCipher test
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-CaesarCipher COMMAND testCaesarCipher)