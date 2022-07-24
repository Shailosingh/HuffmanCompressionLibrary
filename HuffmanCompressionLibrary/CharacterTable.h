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
};