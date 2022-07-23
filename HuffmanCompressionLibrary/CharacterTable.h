#pragma once

#include "CharacterTableNode.h"
#include <unordered_map>
#include <string>

class CharacterTable
{
private:
	std::unordered_map<unsigned char, CharacterTableNode> CharacterMap;

public:
	//Constructors---------------------------------------------------------------------------------------------------------------
	CharacterTable(std::string DecompressedFilePath);

	//Operator overloads---------------------------------------------------------------------------------------------------------
	CharacterTableNode operator[](unsigned char key) const; //Use map "at" function to keep it const
	CharacterTableNode& operator[](unsigned char key);

};