#pragma once

#include "CharacterTableNode.h"
#include <unordered_map>
#include <string>

class CharacterTable
{
public:
	std::unordered_map<unsigned char, CharacterTableNode> CharacterMap;

	//Constructors---------------------------------------------------------------------------------------------------------------
	//Creates a literally empty table.
	CharacterTable(); 

	//Creates character table out of file to be compressed
	CharacterTable(std::string decompressedFilePath); 

	//Creates character table out of file being decompressed
	CharacterTable(std::ifstream& compressedFileReader);

	//Operator overloads---------------------------------------------------------------------------------------------------------
	CharacterTableNode operator[](unsigned char key) const;
	CharacterTableNode& operator[](unsigned char key);
};