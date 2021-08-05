// C++ program to check fixed point
// in an array using linear search
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(arr[i] == i)
			return i;
	}

	/* If no fixed point present then return -1 */
	return -1;
}

/* Driver code */
int main()
{
	int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Fixed Point is " << linearSearch(arr, n);
	return 0;
}

// C++ program to check fixed point
// in an array using binary search
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high)
{
	if(high >= low)
	{
		int mid = (low + high)/2; /*low + (high - low)/2;*/
		if(mid == arr[mid])
			return mid;
		if(mid > arr[mid])
			return binarySearch(arr, (mid + 1), high);
		else
			return binarySearch(arr, low, (mid -1));
	}

	/* Return -1 if there is no Fixed Point */
	return -1;
}

/* Driver code */
int main()
{
	int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Fixed Point is "<< binarySearch(arr, 0, n-1);
	return 0;
}

// This code is contributed by rathbhupendra
