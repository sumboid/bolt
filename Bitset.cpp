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

	void Bitset::getPosition(const unsigned long& number, int& numberOfPart, int& positionInPart) const
	{
		numberOfPart = number/BITS_IN_LONG;
		positionInPart = number%BITS_IN_LONG;
	}

	void Bitset::invert(const unsigned long& number)
	{
		int numberOfPart, positionInPart;
		getPosition(number, numberOfPart, positionInPart);
		unsigned long invert = 1;
		invert <<= BITS_IN_LONG - positionInPart;
		set[numberOfPart] ^= invert;
	}
	
	short Bitset::operator[](const unsigned long& number) const
	{
		int numberOfPart, positionInPart;
		getPosition(number, numberOfPart, positionInPart);
	
		return ((set[numberOfPart] << (positionInPart-1)) >> (BITS_IN_LONG - 1));
	}
}

