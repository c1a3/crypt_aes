#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <string>
#include <vector>

const int BLOCK_SIZE = 16;

std::vector<unsigned char> derive_key(const std::string& password);
void encrypt_file(const std::string& input_path, const std::string& output_path, const std::string& password);
void decrypt_file(const std::string& input_path, const std::string& output_path, const std::string& password);

#endif // CRYPTO_UTILS_H