#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(int arr[], int odd_even, int size, int key)
{
   if (size >= odd_even)
   {
        int mid = odd_even + (size - odd_even)/2;

        // If the element is present at the middle itself
        if (arr[mid] == key)  {
            return mid;
        }
        // If element is smaller than mid, then it can only be present
        // in left side
        if (arr[mid] > key){
                return binarySearch(arr, odd_even, mid-1, key);
        }
        // check right side (key > mid)
        return binarySearch(arr, mid+1, size, key);
   }

   // Key not Found
   return -1;
}
void merge(int arr[], int first, int median, int last)
{
    int i, j, k;
    int n1 = median - first + 1;
    int n2 =  last - median;

    /* create temp arrays */
    int First[n1], Last[n2];

    /* Copy data to temp arrays first[] and last[] */
    for (i = 0; i < n1; i++)
        First[i] = arr[first + i];
    for (j = 0; j < n2; j++)
        Last[j] = arr[median + 1+ j];

    /* Merge the temp arrays back into arr[first..last]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = first; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (First[i] <= Last[j])
        {
            arr[k] = First[i];
            i++;
        }
        else
        {
            arr[k] = Last[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of first[], if there
       are any */
    while (i < n1)
    {
        arr[k] = First[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of last[], if there
       are any */
    while (j < n2)
    {
        arr[k] = Last[j];
        j++;
        k++;
    }
}

/* first is for left index and last is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        // Same as (first+last)/2, but avoids overflow for
        // large first and h
        int median = first+(last-first)/2;

        // Sort first and second halves
        mergeSort(arr, first, median);
        mergeSort(arr, median+1, last);

        merge(arr, first, median, last);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << A[i] << endl;

}

/* Driver program to test above functions */

int main(void)
{
   int arr[] = {50, 25, 2, 3, 4, 10, 60, 40};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array is \n" << endl;
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is " << endl;
    printArray(arr, arr_size);

   int size = sizeof(arr)/ sizeof(*arr);


   int search_key = 40;
   int odd_even = (size)%2;
   int result = binarySearch(arr, odd_even, size, search_key);
   if (result == -1){
            cout << "Element is not present in array" << endl;
   }
                 else{
            cout << "Element is present at index " << result << endl;
                 }
   return 0;
}
