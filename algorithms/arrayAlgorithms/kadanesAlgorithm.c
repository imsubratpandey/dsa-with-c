#include <stdio.h>
#include <stdlib.h>

int max(int numA, int numB)
{
    return numA > numB ? numA : numB;
}

int maximumSubArraySum(int *array, int elementsCount)
{
    int maxCurrent = array[0], maxGlobal = array[0];
    for (int i = 1; i < elementsCount; i++)
    {
        maxCurrent = max(array[i], maxCurrent + array[i]);
        if (maxCurrent > maxGlobal)
            maxGlobal = maxCurrent;
    }
    return maxGlobal;
}

int main()
{
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    printf("Maximum subarray sum of the given array is... %d\n", maximumSubArraySum(array, sizeof(array) / sizeof(int)));
    return 0;
}