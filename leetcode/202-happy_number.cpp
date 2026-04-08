// diff: easy

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<int> GetDigits(int n)
	{
		vector<int> digits;

		while (n > 0)
		{
			int rem = n % 10;
			digits.push_back(rem);
			n /= 10;
		}

		std::reverse(digits.begin(), digits.end());
		return digits;
	}

	int GetSum(vector<int> digits)
	{
		int sum = 0;
		for (auto &n : digits)
			sum += n * n;

		return sum;
	}

	bool isHappy(int n)
	{
		std::unordered_map<int, int> map;
		while (true)
		{
			if (n == 1)
				return true;

			if (map.find(n) == map.end())
				map[n] = 0;

			map[n]++;

			if (map[n] > 1)
				return false;

			n = GetSum(GetDigits(n));
		}
	}
};

int main()
{
	Solution soln;

	// for

	return 0;
}
