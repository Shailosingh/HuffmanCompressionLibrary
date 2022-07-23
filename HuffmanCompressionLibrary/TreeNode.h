#pragma once

#include "GeneralStructures.h"
#include "CharacterTable.h"

class TreeNode
{
private:
	CharInfo CharacterInfo;
	TreeNode* Left;
	TreeNode* Right;

public:
	//Constructors and Deconstructors--------------------------------------------------------------------------------------------
	TreeNode(unsigned char Character, size_t Frequency);
	TreeNode(TreeNode* LeftNode, TreeNode* RightNode);
	~TreeNode();

	//Public functions-----------------------------------------------------------------------------------------------------------
	/// <summary>
	/// Gets the binary code for each character and inserts it into the table.
	/// </summary>
	/// <param name="table">Table that carries each character, frequency and binary representation</param>
	void RetrieveBinaryCodes(CharacterTable& table) const;
};