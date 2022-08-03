#include "CharacterTable.h"
#include <fstream>

//Constructors---------------------------------------------------------------------------------------------------------------
CharacterTable::CharacterTable(std::string decompressedFilePath)
{
	//Open file for reading binary
	std::ifstream fileReader;
	fileReader.open(decompressedFilePath, std::ios::binary);

	//If file unable to open, throw an error
	if (!fileReader)
	{
		throw std::invalid_argument("Unable to open input file to be compressed\n");
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

CharacterTable::CharacterTable()
{
	//Does nothing
}

//Operator overloads---------------------------------------------------------------------------------------------------------
CharacterTableNode CharacterTable::operator[](unsigned char key) const
{
	return CharacterMap.at(key);
}

CharacterTableNode& CharacterTable::operator[](unsigned char key)
{
	return CharacterMap.at(key);
}