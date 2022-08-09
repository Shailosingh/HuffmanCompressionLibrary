#pragma once

#include "CharacterTable.h"

class TreeNode
{
private:
	unsigned char Character;
	uint64_t Frequency;
	TreeNode* Left;
	TreeNode* Right;

	void RetrieveBinaryCodes_Aux(CharacterTable& table, std::vector<bool> currentBits) const;

public:
	TreeNode(unsigned char newChar, uint64_t newFreq);
	TreeNode(TreeNode* leftNode, TreeNode* rightNode);
	TreeNode(TreeNode* loneNodeException);
	~TreeNode();
	
	/// <summary>
	/// Gets the binary code for each character and inserts it into the table.
	/// </summary>
	/// <param name="table">Table that carries each character, frequency and binary representation</param>
	void RetrieveBinaryCodes(CharacterTable& table) const;

	/// <summary>
	/// Takes fileReader handle (pointed at start of huffman code) and interprets the coding
	/// with the tree to write the decompressed bytes to the outputWriter.
	/// </summary>
	/// <param name="fileReader">Open file handle pointed to the huffman coding of the input file</param>
	/// <param name="outputWriter">Open file handle to the new decompressed file</param>
	/// <param name="totalBits">Total number of expected huffman coded bits</param>
	/// <returns>True if everything is successful. False if something goes bad</returns>
	bool WriteDecompressedFile(std::ifstream& fileReader, std::ofstream& outputWriter, uint64_t totalBits);

	bool operator<(const TreeNode& other) const;
};