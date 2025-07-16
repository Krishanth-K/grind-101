#include <iostream>

using std::cout;

int *allocMemory(int size) { return (int *)malloc(size); }

class List {
  public:
	List(int size) : size(size), length(0) { memory = allocMemory(size); }
	~List() { free(memory); }

  private:
	int length;
	int size;
	int *memory;

  public:
	bool append(int value)
	{
		if (length == size)
		{
			cout << "List already full \n";
			return false;
		}
		memory[length] = value;
		length++;

		return true;
	}
};

int main()
{
	List list(3);
	if (list.append(2))
		cout << "yes! \n";
}
