#include <iostream>
#include "HuffmanCompressor.h"
#include <thread>
#include <iostream>

//Function declarations
void ManageCompressionProcess(std::string inputFilePath, std::string outputFolderPath);

int main()
{
    //Initialize paths
    std::string inputFilePath = "C:\\Users\\compu\\Desktop\\Random Docs\\HuffmanCompression Library Test\\Original\\miserables.txt";
    std::string outputFolderPath = "C:\\Users\\compu\\Desktop\\Random Docs\\HuffmanCompression Library Test\\Compressed";

    //Spin up thread that will manage compression and its status
    std::thread compressionManagementThread(ManageCompressionProcess, inputFilePath, outputFolderPath);
    compressionManagementThread.join();

    return 0;
}

void ManageCompressionProcess(std::string inputFilePath, std::string outputFolderPath)
{
    HuffmanCompressor compressorObject;

    //Since BeginCompression() is not a static function, I must offer a pointer to the function and its object as the first two arguments
    std::thread compressionThread(&HuffmanCompressor::BeginCompression, &compressorObject, inputFilePath, outputFolderPath);

    std::cout << "Paths being validated...\n";
    while (!compressorObject.IsFinished && !compressorObject.FileAndDirectoryValidated);
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::cout << compressorObject.StatusMessage;
        return;
    }

    std::cout << "Character table being created...\n";
    while (!compressorObject.IsFinished && !compressorObject.CharacterTableFinished);
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::cout << compressorObject.StatusMessage;
        return;
    }

    std::cout << "Binary codes being generated and recorded...\n";
    while (!compressorObject.IsFinished && !compressorObject.BinaryCodesFound);
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::cout << compressorObject.StatusMessage;
        return;
    }

    std::cout << "Building compressed file...\n";
    while (!compressorObject.IsFinished);
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::cout << compressorObject.StatusMessage;
        return;
    }

    compressionThread.join();
}