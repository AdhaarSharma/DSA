#include <stdio.h>
 
// Function to find the last occurrence of a given number
// in a sorted integer array
int findLastOccurrence(int A[], int N, int x)
{
    // search space is `A[low…high]`
    int low = 0, high = N - 1;
 
    // initialize the result by -1
    int result = -1;
 
    // loop till the search space is exhausted
    while (low <= high)
    {
        // find the mid-value in the search space and compares it with the target
        int mid = (low + high)/2;
 
        // if the target is located, update the result and
        // search towards the right (higher indices)
        if (x == A[mid])
        {
            result = mid;
            low = mid + 1;
        }
 
        // if the target is less than the middle element, discard the right half
        else if (x < A[mid]) {
            high = mid - 1;
        }
        // if the target is more than the middle element, discard the left half
        else {
            low = mid + 1;
        }
    }
 
    // return the leftmost index, or -1 if the element is not found
    return result;
}
 
int main(void)
{
    int A[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int n = sizeof(A)/sizeof(A[0]);
 
    int target = 5;
 
    int index = findLastOccurrence(A, n, target);
 
    if (index != -1)
    {
        printf("The first occurrence of element %d is located at index %d",
                target, index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}