#pragma once
#include <vector>

namespace bitset
{
	class Bitset
	{
	private:
		std::vector<unsigned long> set;
		int numberOfParts;
		unsigned long size;
	
		struct Position
		{
			int numberOfPart;
			int positionInPart;
		};

		Bitset();
		Position getPosition(const unsigned long& number) const;
	public:
		Bitset(const unsigned long& size);
		~Bitset();
		void invert(const unsigned long& number);
		short operator[](const unsigned long& number) const;
	};
}
