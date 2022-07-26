#pragma once

#include "CharacterTable.h"

class TreeNode
{
private:
	unsigned char Character;
	size_t Frequency;
	TreeNode* Left;
	TreeNode* Right;

	//Private functions----------------------------------------------------------------------------------------------------------
	void RetrieveBinaryCodes_Aux(CharacterTable& table, std::vector<bool> currentBits) const;

public:
	//Constructors and Deconstructors--------------------------------------------------------------------------------------------
	TreeNode(unsigned char newChar, size_t newFreq);
	TreeNode(TreeNode* leftNode, TreeNode* rightNode);
	~TreeNode();

	//Public functions-----------------------------------------------------------------------------------------------------------
	/// <summary>
	/// Gets the binary code for each character and inserts it into the table.
	/// </summary>
	/// <param name="table">Table that carries each character, frequency and binary representation</param>
	void RetrieveBinaryCodes(CharacterTable& table) const;
};