#include <iostream>
#include <vector>

void swap(std::vector<int> &arr, int one, int two)
{
    int temp = arr[one];
    arr[one] = arr[two];
    arr[two] = temp;
}

class Qsort
{
public:
    int sort(std::vector<int> &arr, int start = -1, int end = -1)
    {
        if (start == -1 && end == -1)
        {
            start = 0;
            end = arr.size();
        }

        int pivot = start;
        int slow = start;
        int fast = start + 1;

        while (fast < end)
        {
            if (arr[fast] < arr[pivot])
            {
                swap(arr, slow + 1, fast);
                slow++;
            }
            fast++;
        }

        swap(arr, slow, start);

        int mid = slow;

        sort(arr, start, mid);
        sort (arr, mid+1, end);

        return slow;
    }

};

int main()
{
    std::vector<int> arr{10, 3, 5, 21, 1};

    Qsort q;
    int mid = q.sort(arr);

    for (const auto &e : arr)
    {
        std::cout << " " << e << std::endl;
    }

    std::cout << "\n\n mid = " << mid;
}
