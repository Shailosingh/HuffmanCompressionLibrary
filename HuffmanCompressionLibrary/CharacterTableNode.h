#pragma once

#include <vector>

class CharacterTableNode
{
private:
	uint64_t Frequency;

public:
	//Public members-------------------------------------------------------------------------------------------------------------
	std::vector<bool> BitRepresentation;

	//Constructors---------------------------------------------------------------------------------------------------------------
	CharacterTableNode();
	CharacterTableNode(uint64_t frequency);

	//Operator overloads---------------------------------------------------------------------------------------------------------
	
	/// <summary>
	/// Increments the frequency of the the character
	/// </summary>
	/// <param name="incrementAmount">The amount the frequency shall be incrmented by</param>
	void operator++(int incrementAmount);

	//Public functions-----------------------------------------------------------------------------------------------------------
	uint64_t GetFrequency() const;
};