#pragma once

#include "CharacterTableNode.h"
#include <unordered_map>
#include <string>

class CharacterTable
{
public:
	std::unordered_map<unsigned char, CharacterTableNode> CharacterMap;

	//Constructors---------------------------------------------------------------------------------------------------------------
	CharacterTable(std::string DecompressedFilePath);

	//Operator overloads---------------------------------------------------------------------------------------------------------
	CharacterTableNode operator[](unsigned char key) const;
	CharacterTableNode& operator[](unsigned char key);
};