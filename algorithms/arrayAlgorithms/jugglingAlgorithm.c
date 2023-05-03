#include <stdio.h>
#include <stdlib.h>

void showArray(int *array, int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\n");
}

int gcd(int n, int k)
{
    return k == 0 ? n : gcd(k, n % k);
}

void rotateByJuggle(int *array, int n, int k)
{
    for (int i = 0; i < gcd(n, k); i++)
    {
        int j = 0;
        int x = array[i];
        while (1)
        {
            array[((i + (j * k)) % n)] = array[((i + ((j + 1) * k)) % n)];
            j++;
            if (((i + ((j + 1) * k)) % n) == i)
            {
                array[((i + j * k) % n)] = x;
                break;
            }
        }
    }
}

int main()
{
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};
    int k;
    printf("Enter position to rotate...");
    scanf("%d", &k);
    printf("Array before rotation...\n");
    showArray(array, sizeof(array) / sizeof(int));
    rotateByJuggle(array, sizeof(array) / sizeof(int), k);
    printf("Array after rotation...\n");
    showArray(array, sizeof(array) / sizeof(int));
    return 0;
}
