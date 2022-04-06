#include <iostream>
using namespace std;

int min_int(int arr[], int size);
int min_int2(int arr[], int low, int high);

int main()
{
    int arr[10] = {9, -200, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;

    res1 = min_int(arr, 10);
    res2 = min_int2(arr, 0, 9);
    cout << res1 << " " << res2 << endl;  // Expect -9 for both

    res3 = min_int2(arr, 2, 5);
    res4 = min_int(arr + 2, 4);  // arr + 2 is equivalent to &(arr[2])
    cout << res3 << " " << res4 << endl;  // Expect 3 for both

    return 0;
}

// Version 2
int min_int2(int arr[], int low, int high)
{
    int min = arr[low];
    // Base Case
    if (low == high)
    {
        return min;
    }
        // Recursive Case
    else
    {
        min = min_int2(arr, low, high - 1);
        if (arr[high - 1] < min)
        {
            min = arr[high - 1];
        }
        return min;
    }
}
// Version 2 Iterative Implementation
// int min_int2(int arr[], int low, int high)
// {
//   int min = arr[low];
//   for (int i = low; i <= high; i++)
//   {
//     if (arr[i] < min)
//     {
//       min = arr[i];
//     }
//   }
//   return min;
// }

// Version 1
int min_int(int arr[], int size)
{
    int min = arr[0];
    // Base Case
    if (size == 1)
    {
        return min;
    }
        // Recursive Case
    else
    {
        min = min_int(arr, size - 1);
        if (arr[size - 1] < min)
        {
            min = arr[size - 1];
        }
        return min;
    }
}
// Version 1 Iterative Implementation
// int min_int(int arr[], int size)
// {
//   int min = arr[0];
//   for (int i = 0; i < size; i++)
//   {
//     if (arr[i] < min)
//     {
//       min = arr[i];
//     }
//   }
//   return min;
// }