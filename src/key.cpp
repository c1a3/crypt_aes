#include "crypto_utils.h"
#include <openssl/sha.h>

std::vector<unsigned char> derive_key(const std::string& password) {
    std::vector<unsigned char> key(32);
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.length(), key.data());
    return key;
}


// Key Derivation
