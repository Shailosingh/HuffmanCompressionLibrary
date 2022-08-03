#include "TreeNode.h"

//Constructors and Deconstructors--------------------------------------------------------------------------------------------
TreeNode::TreeNode(unsigned char newChar, uint64_t newFreq)
{
	Character = newChar;
	Frequency = newFreq;
	Left = nullptr;
	Right = nullptr;
}

TreeNode::TreeNode(TreeNode* leftNode, TreeNode* rightNode)
{
	Character = NULL;
	Frequency = leftNode->Frequency + rightNode->Frequency;
	Left = leftNode;
	Right = rightNode;
}

TreeNode::TreeNode(TreeNode* loneNodeException)
{
	Character = NULL;
	Frequency = loneNodeException->Frequency;
	Left = nullptr;
	Right = loneNodeException;
}

TreeNode::~TreeNode()
{
	//Clear values
	Character = NULL;
	Frequency = NULL;

	//Free memory of children
	delete Left;
	Left = nullptr;
	delete Right;
	Right = nullptr;
}

//Public functions-----------------------------------------------------------------------------------------------------------
void TreeNode::RetrieveBinaryCodes(CharacterTable& table) const
{
	//If the tree isn't just a head, go down its branches and record the proper binary code for each char
	if (Left != nullptr)
	{
		std::vector<bool> leftBitRep;
		leftBitRep.reserve(8);
		leftBitRep.push_back(false);
		Left->RetrieveBinaryCodes_Aux(table, leftBitRep);
	}

	if (Right != nullptr)
	{
		std::vector<bool> rightBitRep;
		rightBitRep.reserve(8);
		rightBitRep.push_back(true);
		Right->RetrieveBinaryCodes_Aux(table, rightBitRep);
	}
}

//Private functions----------------------------------------------------------------------------------------------------------
void TreeNode::RetrieveBinaryCodes_Aux(CharacterTable& table, std::vector<bool> currentBits) const
{
	//If both the left and right node are nullptr, we are at a character and should record the binary code
	if (Left == nullptr && Right == nullptr)
	{
		table[Character].BitRepresentation = currentBits;
		return;
	}

	//Continue down the non null branches
	if (Left != nullptr)
	{
		std::vector<bool> leftBitRep = currentBits;
		leftBitRep.push_back(false);
		Left->RetrieveBinaryCodes_Aux(table, leftBitRep);
	}

	if (Right != nullptr)
	{
		std::vector<bool> rightBitRep = currentBits;
		rightBitRep.push_back(true);
		Right->RetrieveBinaryCodes_Aux(table, rightBitRep);
	}
}

//Operator overloads---------------------------------------------------------------------------------------------------------
bool TreeNode::operator<(const TreeNode& other) const
{
	return ((this->Frequency) < (other.Frequency));
}