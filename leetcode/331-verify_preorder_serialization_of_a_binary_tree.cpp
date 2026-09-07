#include <iostream>
#include <sstream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	bool isValidSerialization(string preorder)
	{
		std::stringstream ss(preorder);
		string token;

		int slots = 1;

		while (getline(ss, token, ','))
		{
			// No position available for this token
			if (slots == 0)
				return false;

			// Consume one slot
			slots--;

			// Non-null node creates two new slots
			if (token != "#")
				slots += 2;
		}

		return slots == 0;
	}
};

int main()
{
	Solution soln;
	return 0;
}
