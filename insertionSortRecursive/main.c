#include <stdio.h>
#include <stdlib.h>
#define max 100

void insRec(int a[],int n)             //     T(n)
{
    int key, j, co = 0, k;                      //   n
    if(n == 0)                         // 1
        return;                         //1
    else                               // n-1
    {
           insRec(a,n-1);                   //T(n-1)
           key = a[n];                  //1
           j=n-1;                       //1
           while(j >= 0 && a[j] > key)  //?
           {
               a[j+1] = a[j];
               j--;
               co++;
           }
          // k = n - co;
           a[n-co] = key;              //1
           return;
    }
}


int main()
{
    int a[max],n;
    scanf("%i",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%i",&a[i]);
    }
    insRec(a,n);
    for(int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
    a:
    return 0;
}
