#include <iostream>
#include <cmath>
#include <vector>

//#include "UnitTest.h"
#include "Bitset.h"

using namespace std;
using namespace bitset;

vector<size_t> primesBefore(int topval) {
    size_t n = topval / 2;
    Bitset s(n);

    size_t itop = ceil((sqrt(2 * n + 1) - 1) / 2);

    for(size_t i = 1; i <= itop; i++)
        if(s[i])
            for(size_t j = 2 * i * (i + 1); j < n; j += i + i + 1)
                if(s[j])
                    s.invert(j);

    vector<size_t> primes;

    primes.push_back(2);
    for(size_t i = 1; i < n; i++)
        if(s[i])
            primes.push_back(2 * i + 1);

    return primes;
}

int main() {
    const size_t n = 10000000;

//	test::unitTest();
    vector<size_t> primes = primesBefore(n);
/*
    for(size_t i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";
*/
    cout << primes.back();
    cout << endl;

	return 0;
}
