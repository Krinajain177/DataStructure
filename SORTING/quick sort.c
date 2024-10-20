#include <stdio.h>
#include <time.h>
int partition(int a[], int start, int end)
{
    int pivot = a[end]; // pivot element
    int i = (start - 1);
    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than the pivot
        if (a[j] < pivot)
        {
            i++; // increment index of smaller element
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    return (i + 1);
}
// Function to perform Quick Sort
void quick(int a[], int start, int end)
{
    if (start < end)
    {
        int p = partition(a, start, end); // p is the partitioning index
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
}
// Function to print the array
void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
// Main function
int main()
{
    // Default code
    printf("Practial-9.1\n");
    printf("Enrollment NO. :-230130107052 \n");
    printf("Krina Jain\n");
    printf("9.1 Write a program to implement Quick Sort.\n");
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Unsorted array: \n");
    printArr(a, n);
    quick(a, 0, n - 1);
    printf("\nSorted array: \n");
    printArr(a, n);
    return 0;
}