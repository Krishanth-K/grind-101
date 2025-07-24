#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
	int maximumLength(vector<int> &nums)
	{
		int n = nums.size();

		int oddodd = 0;
		int eveneven = 0;
		int evenodd = 0;
		int oddeven = 0;

		for (int i = 0; i < n - 1; i++)
		{
			int prev = nums[i];

			for (int j = i + 1; j < n; j++)
			{
				int next = nums[j];

				// even-* case
				if (prev % 2 == 0)
				{
					// even-even case
					if (next % 2 == 0)
					{
						if (eveneven == 0)
							eveneven += 2;
						else
							eveneven++;
					}

					// even-odd case
					else
					{
						if (evenodd == 0)
							evenodd += 2;
						else
							evenodd++;
					}
				}
				// odd-* case
				else if (prev % 2 == 1)
				{
					// odd-odd case
					if (next % 2 == 1)
					{
						if (oddodd == 0)
							oddodd += 2;
						else
							oddodd++;
					}

					// odd-even case
					else
					{
						if (oddeven == 0)
							oddeven += 2;
						else
							oddeven++;
					}
				}
			}

			// std::cout << "oddodd: " << oddodd << std::endl;
			// std::cout << "eveneven: " << eveneven << std::endl;
			// std::cout << "oddeven: " << oddeven << std::endl;
			// std::cout << "evenodd: " << evenodd << std::endl;
		}
		// the number of numbers => 2 * pairs
		return max(max(oddodd, eveneven), max(oddeven, evenodd));
	}
};

int main()
{
	// vector<int> nums = {1, 2, 3, 4};
	vector<int> nums = {1, 2, 1, 1, 2, 1, 2};

	Solution soln;
	int max = soln.maximumLength(nums);
	std::cout << max;
}
