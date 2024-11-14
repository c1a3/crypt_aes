#include <iostream>
#include <string>
#include "crypto_utils.h"
#include <unistd.h>

int main() {
    std::cout << R"(                                                    
                         _                            
  ____  ____ _   _ ____ | |_          ____  ____  ___ 
 / ___)/ ___) | | |  _ \|  _)        / _  |/ _  )/___)
( (___| |   | |_| | | | | |__ ______( ( | ( (/ /|___ |
 \____)_|    \__  | ||_/ \___|_______)_||_|\____|___/ 
            (____/|_|                        )" << std::endl;
    std::cout << "           " "Secure your files with ease!" << std::endl;
    sleep(2.5); 
    std::cout << "" << std::endl;
    std::cout << "How would you like to proceed?" << std::endl;
    std::cout << "1. Encrypt a file" << std::endl;
    std::cout << "2. Decrypt a file" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    std::string input_path, output_path, password;

    std::cout << "Enter the input file path: ";
    std::getline(std::cin, input_path);

    std::cout << "Enter the password: ";
    std::getline(std::cin, password);

    if (choice == 1) {
        output_path = input_path + ".enc";
        std::cout << "Encrypting file..." << std::endl;
        encrypt_file(input_path, output_path, password);
        std::cout << "File encrypted successfully. Output: " << output_path << std::endl;
    } else if (choice == 2) {
        if (input_path.substr(input_path.length() - 4) == ".enc") {
            output_path = input_path.substr(0, input_path.length() - 4);
        } else {
            output_path = input_path + ".dec";
        }
        std::cout << "Decrypting file..." << std::endl;
        decrypt_file(input_path, output_path, password);
        std::cout << "File decrypted successfully. Output: " << output_path << std::endl;
    } else {
        std::cout << "Invalid choice. Please run the program again." << std::endl;
        return 1;
    }

    return 0;
}
