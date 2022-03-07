#include <stdio.h>
#include <stdlib.h>
#define max 100
void exchange(int a[], int e1, int e2)
{
    int t = a[e1];
    a[e1] = a[e2];
    a[e2] = t;
}

int main()
{
    int a[max],n;
    scanf("%i",&n);
    for(int i = 0; i < n; i++)
    {
       scanf("%i",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j > i; j--)
        {
           if(a[j]<a[j-1])
               exchange(a,j,j-1);
           for(int i = 0; i < n; i++)
            {
                printf("%i ",a[i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
