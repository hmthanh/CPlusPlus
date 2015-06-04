#include <iostream>

using namespace std;

// Find maximum element of array
int FindMax(int *Array, int n)
{
	// return last element if array just have one element
	if (n == 1)
	{
		return Array[0];
	}

	int currentMin = Array[n - 1];         // Set min is a element at n th
	int beforeMin = FindMax(Array, n - 1); // Get min element from 1 ... n-1

	if (currentMin > beforeMin)
	{
		return currentMin;
	}
	else
	{
		return beforeMin;
	}
}

// Find minimum element of array
int FindMin(int *Array, int n)
{
	// return if last element
	if (n == 1)
	{
		return Array[0];
	}

	int currentMin = Array[n - 1];         // Set min is a element at n th
	int beforeMin = FindMin(Array, n - 1); // Get min element from 1 ... n-1

	if (currentMin < beforeMin)
	{
		return currentMin;
	}
	else
	{
		return beforeMin;
	}
}

int main()
{
	int Array[5] = { 5, 1, 3, 2, 4 };         // My array
	int size = (sizeof(Array) / sizeof(*Array)); // 5 - size of array

	cout << "Mang : ";
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "\nNho nhat la : " << FindMin(Array, size) << endl;
	cout << "Lon nhat la : " << FindMax(Array, size) << endl;

	return 0;
}