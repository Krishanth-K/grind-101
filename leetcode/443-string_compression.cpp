// diff:

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int compress(vector<char> &chars)
	{
		int n = chars.size();
		int write = 0; // Where we write the result
		int read = 0;  // Where we read the original data

		while (read < n)
		{
			char currentChar = chars[read];
			int count = 0;

			// 1. Count the occurrences of the current group
			while (read < n && chars[read] == currentChar)
			{
				read++;
				count++;
			}

			// 2. Write the character itself
			chars[write++] = currentChar;

			// 3. If count > 1, convert the count to string and write digits
			if (count > 1)
			{
				string countStr = std::to_string(count);
				for (char c : countStr)
				{
					chars[write++] = c;
				}
			}
		}

		return write; // 'write' is the new length of the compressed array
	}
};

int main()
{
	Solution soln;

	vector<char> a = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	soln.compress(a);

	for (int x : a)
		std::cout << x << ' ';
	return 0;
}
