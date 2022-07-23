#pragma once

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
	void CreateTree();

public:
	//Public members-------------------------------------------------------------------------------------------------------------
	TreeNode* HuffmanTree;

	//Constructors---------------------------------------------------------------------------------------------------------------
	PriorityQueue(CharacterTable& table);
};