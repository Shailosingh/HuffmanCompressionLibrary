#pragma once

#include <vector>

class CharacterTableNode
{
private:
	uint64_t Frequency;

public:
	std::vector<bool> BitRepresentation;

	CharacterTableNode();
	CharacterTableNode(uint64_t frequency);

	/// <summary>
	/// Increments the frequency of the the character
	/// </summary>
	/// <param name="incrementAmount">The amount the frequency shall be incrmented by</param>
	void operator++(int incrementAmount);

	uint64_t GetFrequency() const;
};