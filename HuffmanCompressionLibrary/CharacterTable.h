#pragma once

#include "CharacterTableNode.h"
#include <unordered_map>
#include <string>

class CharacterTable
{
private:
	std::unordered_map<unsigned char, CharacterTableNode> CharacterMap;

	//Private functions----------------------------------------------------------------------------------------------------------
	/// <summary>
	/// If the key already exists within CharacterMap, will return reference to the node. If the key doesn't exist, it calls the 
	/// CharacterTableNode constructor with the key and creates an entry in the map.
	/// </summary>
	/// <param name="">The key for the map</param>
	/// <returns>A reference to the value tied to the key</returns>
	CharacterTableNode& GetChar(unsigned char key);

public:
	//Constructors---------------------------------------------------------------------------------------------------------------
	CharacterTable(std::string DecompressedFilePath);

	//Operator overloads---------------------------------------------------------------------------------------------------------
	CharacterTableNode& operator[](unsigned char key);

};