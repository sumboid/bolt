#include "Bitset.h"
#include <vector>
#include <limits>
#include <cassert>

namespace
{
	const short NUMBER_OF_BITS = 8;
	const short BITS_IN_LONG = sizeof(unsigned long)*NUMBER_OF_BITS;
}

namespace bitset
{
	Bitset::Bitset(const unsigned long& _size): size(_size)
	{
		numberOfParts = size/BITS_IN_LONG;
		if(size%BITS_IN_LONG != 0)
		{
			++numberOfParts;
		}

		set.resize(numberOfParts, std::numeric_limits<unsigned long>::max());
	}

	Bitset::~Bitset() {}

	Bitset::Position Bitset::getPosition(const unsigned long& number) const
	{
		Position position;
		position.numberOfPart = number/BITS_IN_LONG;
		position.positionInPart = number%BITS_IN_LONG;

		return position;
	}

	void Bitset::invert(const unsigned long& number)
	{
		Position position = getPosition(number);
		unsigned long invert = 1;
		invert <<= BITS_IN_LONG - position.positionInPart;
		set[position.numberOfPart] ^= invert;
	}
	
	short Bitset::operator[](const unsigned long& number) const
	{
		Position position = getPosition(number);
		return ((set[position.numberOfPart] << (position.positionInPart-1)) >> (BITS_IN_LONG - 1));
	}
}

