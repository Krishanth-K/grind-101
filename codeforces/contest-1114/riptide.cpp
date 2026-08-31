#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parse_input()
{
	int a, b, c;
	cin >> a >> b >> c;
	return {a, b, c};
}

int main()
{
	int testcase;
	cin >> testcase;
	int count = 0;

	while (testcase > 0)
	{
		vector<int> tokens = parse_input();
		count = 0;

		while (true)
		{
			sort(tokens.begin(), tokens.end());

			if (tokens[0] == tokens[1] || tokens[1] == tokens[2])
			{
				cout << count << "\n";
				break;
			}

			tokens[2]--;
			tokens[0]++;

			count++;
		}

		testcase--;
	}

	return 0;
}
