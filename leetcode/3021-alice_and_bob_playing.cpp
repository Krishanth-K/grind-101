// tag

// diff: medium

// url:
// https://leetcode.com/problems/alice-and-bob-playing-flower-game/description

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
  public:
	long long flowerGame(int n, int m)
	{
		long long m_even, m_odd;
		long long n_even, n_odd;

		if (m % 2 == 0)
		{
			m_even = m / 2;
			m_odd = m / 2;
		}
		else
		{
			m_even = m / 2;
			m_odd = m / 2 + 1;
		}

		if (n % 2 == 0)
		{
			n_even = n / 2;
			n_odd = n / 2;
		}
		else
		{
			n_even = n / 2;
			n_odd = n / 2 + 1;
		}

		return m_even * n_odd + n_even * m_odd;
	}
};

int main()
{
	Solution soln;
	return 0;
}
