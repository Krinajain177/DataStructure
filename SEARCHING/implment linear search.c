#include <stdio.h>
#include <time.h>
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == target)
        {
            return i; // Found the target at index i
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Practical 8.1\n");
    printf("Enrollment no. :230130107052\n ");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n]; // Declare an array of size n
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Enter the value to search: ");
    scanf("%d", &target);
    int result = linearSearch(arr, n, target);
    if (result != -1)
    {
        printf("Element %d found at index %d.\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}