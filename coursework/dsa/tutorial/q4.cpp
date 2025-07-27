// Given an array of + ve / -ve integers, find the smallest positive missing
// number;

#include <iostream>
#include <vector>

using std::cout, std::endl;

std::vector<int> getPositiveIntegers(std::vector<int> &arr)
{
	std::vector<int> ans;
	for (const auto &e : arr)
	{
		if (e >= 0)
			ans.push_back(e);
	}

	return ans;
}

int main()
{
	std::vector<int> arr = {-3, 4, -1, 0, 2, 5};
	std::vector<int> posArr = getPositiveIntegers(arr);

	int n = posArr.size();

	for (const auto e : posArr)
	{
		cout << e << ", ";
	}
}
