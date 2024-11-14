cmake_minimum_required(VERSION 3.10)
project(crypt_aes)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenSSL REQUIRED)

add_executable(crypt_aes
	src/encryption.cpp
	src/decryption.cpp
	src/key.cpp
	src/main.cpp
)

target_include_directories(crypt_aes PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(crypt_aes PRIVATE OpenSSL::Crypto)
