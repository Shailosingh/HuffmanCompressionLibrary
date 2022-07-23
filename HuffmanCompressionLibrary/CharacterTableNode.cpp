#include "CharacterTableNode.h"

//Constructors---------------------------------------------------------------------------------------------------------------
CharacterTableNode::CharacterTableNode()
{
	Frequency = 0;
}

//Operator overloads---------------------------------------------------------------------------------------------------------
void CharacterTableNode::operator++(int incrementAmount)
{
	Frequency += incrementAmount;
}

//Public functions-----------------------------------------------------------------------------------------------------------
size_t CharacterTableNode::GetFrequency() const
{
	return Frequency;
}