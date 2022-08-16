#pragma once

#include "CharacterTableNode.h"
#include <map> //NEVER CHANGE THIS TO "unordered_map." It won't work because the CharacterTable order needs to be the exact same during compression and decompression, for the huffman trees to be identical.
#include <string>

class CharacterTable
{
public:
	std::map<unsigned char, CharacterTableNode> CharacterMap;

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