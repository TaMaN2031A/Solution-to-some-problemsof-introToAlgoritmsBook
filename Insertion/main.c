#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10], key, j;
    for(int i = 0; i < 10; i++)
    {
        scanf("%i",&a[i]);
    }
    for(int i = 1; i < 10; i++)
    {
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    for(int i = 0;i < 10; i++)
    {
        printf("%i ",a[i]);
    }
    return 0;
}
