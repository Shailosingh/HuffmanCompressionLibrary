#pragma once
//Remember to have an special case for when there is only one unique char
#include "TreeNode.h"
#include <list>

class PriorityQueue
{
private:
	std::list<TreeNode*> Queue;

	//Private functions----------------------------------------------------------------------------------------------------------
	
	/// <summary>
	/// Inserts the new node and maintains the least frequency to greatest frequency order of the queue.
	/// </summary>
	/// <param name="newNode">TreeNode pointer to be inserted</param>
	void SortedInsert(TreeNode* newNode);
	
	/// <summary>
	/// Turns the priority queue into a huffman tree and sets the pointer to the  head of the tree to "HuffmanTree"
	/// </summary>
	/// <returns>Pointer to the head of the huffman tree</returns>
	TreeNode* CreateTree();

public:
	TreeNode* HuffmanTree;

	//Constructors and Destructors-----------------------------------------------------------------------------------------------
	PriorityQueue(CharacterTable& table, bool doRetrieveBinaryCode);
	~PriorityQueue();
};