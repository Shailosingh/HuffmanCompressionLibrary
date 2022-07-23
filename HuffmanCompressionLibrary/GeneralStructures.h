#pragma once

/// <summary>
/// A structure that will simply carry the character and
/// its frequency in the decompressed file together.
/// </summary>
typedef struct CharInfo
{
	unsigned char Character;
	size_t Frequency;
} CharInfo;