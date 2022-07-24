#include "CharacterTable.h"
#include <fstream>

//Constructors---------------------------------------------------------------------------------------------------------------
CharacterTable::CharacterTable(std::string DecompressedFilePath)
{
	//Open file for reading binary
	std::ifstream fileReader;
	fileReader.open(DecompressedFilePath);

	//If file unable to open, throw an error
	if (!fileReader)
	{
		throw std::invalid_argument("Unable to open " + DecompressedFilePath);
	}

	//Read every byte of the file and record their frequencies in the map
	unsigned char currentByte;
	while (fileReader >> currentByte)
	{
		CharacterMap[currentByte]++;
	}

	//Close up the file stream
	fileReader.close();
}