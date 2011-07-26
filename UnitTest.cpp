#include "Bitset.h"
#include <cassert>
#include <iostream>

namespace test
{
	using bitset::Bitset;
	using std::cout;
	using std::endl;

	void initTest()
	{
		cout << "Initialization test\t\t";
		Bitset bitset(100000000);
		for(int i = 0; i < 100000000; i++)
		{
			assert(1 == bitset[i]);
		}
		cout << "[SUCCESS]" << endl;
	}

	void invertTest()
	{
		cout << "Inverting test\t\t\t";
		Bitset bitset(100000000);
		for(int i = 0; i < 100000000; i++)
		{
			bitset.invert(i);
		}

		for(int i = 0; i < 100000000; i++)
		{
			assert(0 == bitset[i]);
		}

		cout << "[SUCCESS]" << endl;
	}

	void getTest()
	{
		cout << "Getting bit test\t\t";
		Bitset bitset(1000);
		bitset.invert(40);

		assert(0 == bitset[40]);

		cout << "[SUCCESS]" << endl;
	}

	void unitTest()
	{
		cout << "Start unit testing" << endl;
		cout << "====================================" << endl;
		initTest();
		invertTest();
		getTest();
		cout << "=====================================" << endl;
		cout << "All test are SUCCESSFULLY FINISHED" << endl;
	}
}
