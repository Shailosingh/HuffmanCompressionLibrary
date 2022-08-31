#include <iostream>
#include "HuffmanCompressor.h"
#include "HuffmanDecompressor.h"
#include <thread>
#include <iostream>

//Function declarations
void ManageCompressionProcess(std::wstring inputFilePath, std::wstring outputFolderPath);
void ManageDecompressionProcess(std::wstring inputFilePath, std::wstring outputFolderPath);

int main()
{
    //Initialize paths for compression
    std::wstring compression_InputFilePath = L"C:\\Users\\compu\\Desktop\\Random Docs\\HuffmanCompression Library Test\\Original\\miserables.txt";
    std::wstring compression_OutputFolderPath = L"C:\\Users\\compu\\Desktop\\Random Docs\\HuffmanCompression Library Test\\Compressed";

    //Spin up thread that will manage compression and its status
    std::thread compressionManagementThread(ManageCompressionProcess, compression_InputFilePath, compression_OutputFolderPath);
    compressionManagementThread.join();
    std::cout << "Compression Complete!\n\n";

    //Initialize paths for decompression
    std::wstring decompression_InputFilePath = L"C:\\Users\\compu\\Desktop\\Random Docs\\HuffmanCompression Library Test\\Compressed\\miserables.ShailoHuff64";
    std::wstring decompression_OutputFolderPath = L"C:\\Users\\compu\\Desktop\\Random Docs\\HuffmanCompression Library Test\\Decompressed";

    //Spin up thread that will manage decompression and its status
    std::thread decompressionManagementThread(ManageDecompressionProcess, decompression_InputFilePath, decompression_OutputFolderPath);
    decompressionManagementThread.join();
    std::cout << "Decompression Complete!";

    return 0;
}

void ManageCompressionProcess(std::wstring inputFilePath, std::wstring outputFolderPath)
{
    HuffmanCompressor compressorObject;

    //Since BeginCompression() is not a static function, I must offer a pointer to the function and its object as the first two arguments
    std::thread compressionThread(&HuffmanCompressor::BeginCompression, &compressorObject, inputFilePath, outputFolderPath);

    std::cout << "Paths being validated...\n";
    while (!compressorObject.IsFinished && !compressorObject.FileAndDirectoryValidated);
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::wcout << compressorObject.StatusMessage;
        return;
    }

    std::cout << "Character table being created...\n";
    while (!compressorObject.IsFinished && !compressorObject.CharacterTableFinished);
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::wcout << compressorObject.StatusMessage;
        return;
    }

    std::cout << "Binary codes being generated and recorded...\n";
    while (!compressorObject.IsFinished && !compressorObject.BinaryCodesFound);
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::wcout << compressorObject.StatusMessage;
        return;
    }

    std::cout << "Building compressed file...\n";
    while (!compressorObject.IsFinished)
    {
        int percentProgress = (compressorObject.BitCounter*100)/compressorObject.TotalBitCount;
        std::cout << "\rProgress: " << percentProgress << "%";
    }
    std::cout << "\n";
    if (compressorObject.ExitError)
    {
        compressionThread.join();
        std::wcout << compressorObject.StatusMessage;
        return;
    }

    compressionThread.join();
}

void ManageDecompressionProcess(std::wstring inputFilePath, std::wstring outputFolderPath)
{
    HuffmanDecompressor decompressorObject;

    //Since BeginDecompression() is not a static function, I must offer a pointer to the function and its object as the first two arguments
    std::thread decompressionThread(&HuffmanDecompressor::BeginDecompression, &decompressorObject, inputFilePath, outputFolderPath);

    std::cout << "Paths being validated...\n";
    while (!decompressorObject.IsFinished && !decompressorObject.FileAndDirectoryValidated);
    if (decompressorObject.ExitError)
    {
        decompressionThread.join();
        std::wcout << decompressorObject.StatusMessage;
        return;
    }

    std::cout << "Getting the file extension...\n";
    while (!decompressorObject.IsFinished && !decompressorObject.RecordedFileExtension);
    if (decompressorObject.ExitError)
    {
        decompressionThread.join();
        std::wcout << decompressorObject.StatusMessage;
        return;
    }

    std::cout << "Generating the character table...\n";
    while (!decompressorObject.IsFinished && !decompressorObject.CharacterTableFinished);
    if (decompressorObject.ExitError)
    {
        decompressionThread.join();
        std::wcout << decompressorObject.StatusMessage;
        return;
    }

    std::cout << "Constructing the huffman tree...\n";
    while (!decompressorObject.IsFinished && !decompressorObject.TreeConstructed);
    if (decompressorObject.ExitError)
    {
        decompressionThread.join();
        std::wcout << decompressorObject.StatusMessage;
        return;
    }

    std::cout << "Building decompressed file...\n";
    while (!decompressorObject.IsFinished)
    {
        int percentProgress = (decompressorObject.BitCounter * 100) / decompressorObject.TotalBitCount;
        std::cout << "\rProgress: " << percentProgress << "%";
    }
    std::cout << "\n";
    if (decompressorObject.ExitError)
    {
        decompressionThread.join();
        std::wcout << decompressorObject.StatusMessage;
        return;
    }

    decompressionThread.join();
}