# HuffmanCompressionLibrary
The Huffman Compression Library is a C++ library which offers a simple way to compress and decompress files, using Huffman Coding.

## Requirements
- Currently requires Windows. May be changed at a later date to be more portable
- At least, ISO C++17 Standard Compiler (library tested using Microsoft Visual C++)

## Quick Start
The following is a VERY basic explanation of how to quickly compress or decompress a file in a single thread.

1. Include header ```HuffmanCompressor.h``` if you wish to compress a file. If you wish to decompress a file, include header ```HuffmanDecompressor.h```
2. Initialize a ```HuffmanCompressor``` object if you wish to compress a file, or initialize a ```HuffmanDecompressor``` object if you wish to decompress a file.
3. To begin the compression process of a file at path ```std::wstring inputFilePath``` and output the compressed file at folder path ```std::wstring outputFolderPath```, call function ```void BeginCompression(std::wstring inputFilePath, std::wstring outputFolderPath)```. Similarly to decompress file ```std::wstring inputFilePath``` and output the decompressed file at folder ```std::wstring outputFolderPath```, call function ```void BeginDecompression(std::wstring inputFilePath, std::wstring outputFolderPath)```
4. After the function is done executing, you can check if there was an error by checking the compressor/decompressor's datafield, ```bool ExitError```. If it is true, that means something went wrong and a description of the error will be in ```std::wstring StatusMessage```

To get more information on how to use the library in a multithreaded environment, error handling and common errors, please visit the wiki.
