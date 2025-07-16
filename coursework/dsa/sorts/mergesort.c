#include <stdbool.h>
#include <stdio.h>

int a[3] = {1, 2, 4};
int b[3] = {3, 5, 6};
int c[7] = {0};

int l1 = sizeof(a) / sizeof(a[0]);
int l2 = sizeof(b) / sizeof(b[0]);
int l3 = sizeof(c) / sizeof(c[0]);

bool mergeSort()
{
	int i = 0;
	int j = 0;
	int k = 0;

	if (l1 + l2 > l3)
	{
		return false;
	}

	while ((i < l1) && (j < l2))
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else if (a[i] > b[j])
		{
			c[k] = b[j];
			j++;
			k++;
		}
	}

	while (i < l1)
	{

		c[k] = a[i];
		k++;
		i++;
	}
	while (j < l2)
	{
		c[k] = b[j];
		k++;
		j++;
	}

	return true;
}

int main()
{
	mergeSort();
	for (int i = 0; i < l3; i++)
	{
		printf("%d\n", c[i]);
	}
}
