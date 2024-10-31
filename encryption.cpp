#include "crypto_utils.h"
#include <fstream>
#include <openssl/evp.h>
#include <openssl/rand.h>

void encrypt_file(const std::string& input_path, const std::string& output_path, const std::string& password) {
    std::vector<unsigned char> key = derive_key(password);
    std::vector<unsigned char> iv(BLOCK_SIZE);
    RAND_bytes(iv.data(), BLOCK_SIZE);

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data());

    std::ifstream input_file(input_path, std::ios::binary);
    std::ofstream output_file(output_path, std::ios::binary);

    output_file.write(reinterpret_cast<const char*>(iv.data()), iv.size());

    std::vector<unsigned char> buffer(1024), out_buffer(1024 + EVP_MAX_BLOCK_LENGTH);
    int out_len;

    while (input_file.good()) {
        input_file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
        std::streamsize bytes_read = input_file.gcount();

        EVP_EncryptUpdate(ctx, out_buffer.data(), &out_len, buffer.data(), bytes_read);
        output_file.write(reinterpret_cast<const char*>(out_buffer.data()), out_len);
    }

    EVP_EncryptFinal_ex(ctx, out_buffer.data(), &out_len);
    output_file.write(reinterpret_cast<const char*>(out_buffer.data()), out_len);

    EVP_CIPHER_CTX_free(ctx);
}

/Encryption Algorithm
