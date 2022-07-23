#pragma once

#include <vector>

class CharacterTableNode
{
private:
	size_t Frequency;

public:
	//Public members-------------------------------------------------------------------------------------------------------------
	std::vector<bool> BitRepresentation;

	//Constructors---------------------------------------------------------------------------------------------------------------
	CharacterTableNode();

	//Operator overloads---------------------------------------------------------------------------------------------------------
	/// <summary>
	/// Increments the frequency of the the character
	/// </summary>
	/// <param name="incrementAmount">The amount the frequency shall be incrmented by</param>
	void operator++(int incrementAmount);

	//Public functions-----------------------------------------------------------------------------------------------------------
	size_t GetFrequency() const;
};