#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		string a, b;

		cin >> n;
		cin >> a; // Reads the entire string 'a' at once
		cin >> b; // Reads the entire string 'b' at once

		int odd_a = 0, odd_b = 0, even_a = 0, even_b = 0;

		// Use a standard loop and % to safely handle both even and odd 'n'
		for (int i = 0; i < n; i++)
		{
			if (a[i] == '1')
			{
				if (i % 2 == 0)
					even_a++;
				else
					odd_a++;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (b[i] == '1')
			{
				if (i % 2 == 0)
					even_b++;
				else
					odd_b++;
			}
		}

		if ((odd_a == odd_b) && (even_a == even_b))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
