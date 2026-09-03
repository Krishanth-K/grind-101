#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int trap(vector<int> &height)
	{
		int fwd_pass = scan(height);
		int bwd_pass = scan(height, true);

		return fwd_pass + bwd_pass;
		// return fwd_pass;
		// return bwd_pass;
	}

	int getNext(vector<int> &arr, int current, bool rev = false)
	{
		if (!rev)
			return current + 1;
		else
			return current - 1;
	}

	int scan(vector<int> &arr, bool rev = false)
	{
		int current;
		int ans = 0;
		int n = arr.size();

		if (!rev)
			current = 0;
		else
			current = n - 1;

		int in_between = 0;
		int next = current;

		while (true)
		{
			int next = getNext(arr, next, rev);

			if (next < 0 || next >= n)
				break;

			if (arr[next] >= arr[current])
			{
				ans += ((std::abs(next - current) + 1) * arr[current]) -
				       in_between;
				in_between = 0;
				current = next;
			}
			else if (arr[next] < arr[current])
				in_between += arr[next];
		}

		return ans;
	}
};

int main()
{
	Solution soln;
	return 0;
}
