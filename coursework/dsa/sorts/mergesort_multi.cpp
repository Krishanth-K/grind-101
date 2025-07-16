#include <iostream>
#include <vector>

std::vector<int> merge_two_arrays(std::vector<int> &a, std::vector<int> &b)
{
	int l1 = a.size();
	int l2 = b.size();

	int i = 0;
	int j = 0;
	int k = 0;

	std::vector<int> c;

	while ((i < l1) && (j < l2))
	{
		if (a[i] <= b[j])
		{
			c.push_back(a[i]);
			i++;
		}
		else if (a[i] > b[j])
		{
			c.push_back(b[j]);
			j++;
		}
	}

	while (i < l1)
	{

		c.push_back(a[i]);
		i++;
	}
	while (j < l2)
	{
		c.push_back(b[j]);
		j++;
	}

	return c;
}

std::vector<int> merge_k_arrays(std::vector<std::vector<int>> &arrays)
{
	std::vector<int> out;
	for (int i = 0; i < arrays.size(); i++)
	{
		out = merge_two_arrays(arrays[i], out);
	}

	return out;
}

int main()
{
	std::vector<int> a{1, 2, 8};
	std::vector<int> b{3, 5, 20};
	std::vector<int> c{4, 6, 21};

	std::vector<std::vector<int>> arrays{a, b, c};
	std::vector<int> out;

	out = merge_k_arrays(arrays);

	for (int i : out)
	{
		std::cout << i << std::endl;
	}
}
