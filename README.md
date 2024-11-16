# crypt_aes: File Encryption/Decryption Tool

## Overview
The File Encryption/Decryption Tool is a C++ application that allows users to encrypt and decrypt files using AES-256 encryption. This tool provides a secure way to protect sensitive information stored in files.

## Features
* **Encrypt Files**: Securely encrypt files using AES-256 encryption.
* **Decrypt Files**: Decrypt previously encrypted files with the correct password.
* **Command-line Interface**: Easy-to-use command-line interface for file operations.

## Folder Structure
```
.
├── crypt_aes
│   └── src/
│       ├── crypto_utils.h   # Header file for encryption functions    
│       ├── main.cpp         # Main application
│       ├── encryption.cpp   # Implementation of encryption functions
│       ├── decryption.cpp   # Implementation of decryption functions
│       └── key.cpp          # Key derivation
│
├── CMakeLists.txt           # CMake configuration file
└── README.md                # README               
```

## Prerequisites
Before running the application, ensure you have the following installed:

1. **C++ Compiler**: A C++ compiler supporting C++11 or later. You can check if it's installed using:
   ```
   g++ --version
   ```

2. **CMake**: Version 3.10 or later. Check the installed version with:
   ```
   cmake --version
   ```

3. **OpenSSL**: The OpenSSL library for encryption. Installation depends on your operating system:
   - On RHEL/Fedora: `sudo dnf install openssl openssl-devel`
   - On macOS with Homebrew: `brew install openssl`
   - On Windows: Download and install from https://slproweb.com/products/Win32OpenSSL.html

4. **IDE or Text Editor**: Any C++ compatible IDE or text editor. We recommend Visual Studio Code with the C/C++ extension.

## How to Build and Run

1. Clone or download the project files to your local machine.

2. Open a terminal in the `crypt_aes/` directory.

3. Create a build directory and navigate to it:
   ```
   mkdir build
   cd build
   ```

4. Generate the build files with CMake:
   ```
   cmake ..
   ```

5. Build the project:
   ```
   make
   ```

6. Run the application:
   ```
   ./crypt_aes
   ```

## Security Note
This tool is for educational purposes only. For real-world applications, consider using more robust encryption methods and secure key management practices.
